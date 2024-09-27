#include "fastlanes/ffor.hpp"
#include "fastlanes/unffor.hpp"
#include "lep/decoder.hpp"
#include "lep/encoder.hpp"
#include <cstring>
#include <fstream>
#include <gtest/gtest.h>
#include <ios>
#include <string>

class lep_test : public ::testing::Test {};

void test_column(const std::string& path_to_csv, uint8_t exp) {
	using UT = typename alp::inner_t<float>::ut;
	using ST = typename alp::inner_t<float>::st;

	alp::bw_t bit_width {};
	ST base {};

	std::vector<float> input(1024);
	std::vector<float> output(1024);
	std::vector<ST> encoded(1024);
	std::vector<ST> decoded(1024);
	std::vector<ST> ffor_vector(1024);

	auto* input_arr        = input.data();
	auto* output_arr       = output.data();
	auto* encoded_arr      = encoded.data();
	auto* decoded_arr 	   = decoded.data();
	auto* ffor_arr         = ffor_vector.data();

	std::ifstream file(path_to_csv, std::ios::in);
	if (!file) { throw std::runtime_error(path_to_csv + " : " + std::strerror(errno)); }

	lep::state stt;
	size_t         tuples_count {alp::config::VECTOR_SIZE};
	size_t         rowgroup_offset {0};

	double      value_to_encode;
	std::string val_str;
	// keep storing values from the text file so long as data exists:
	size_t row_idx {0};
	while (file >> val_str) {
		value_to_encode = std::stof(val_str);

		input_arr[row_idx] = value_to_encode;
		row_idx += 1;
	}

	// Encode
	lep::encoder<float>::encode(input_arr, encoded_arr, stt, exp);
	alp::encoder<float>::analyze_ffor(encoded_arr, bit_width, &base);
	ffor::ffor(encoded_arr, ffor_arr, bit_width, &base);

	// Decode
	unffor::unffor(ffor_arr, decoded_arr, bit_width, &base);
	lep::decoder<float>::decode(decoded_arr, stt.exp, output_arr);

	// validation
	float expected_precision = 1 / std::pow(10, exp);
	for (size_t i = 0; i < alp::config::VECTOR_SIZE; ++i) {
		ASSERT_TRUE(std::abs(input_arr[i] - output_arr[i]) < expected_precision);
	}


	std::cout << "\033[32m-- " << path_to_csv << '\n';

	file.close();
}

TEST_F(lep_test, test_glove25) {
	uint8_t exp = 3;
	std::string glove25_csv_path        = std::string {CMAKE_SOURCE_DIR} + "/data/lep/samples/glove25.csv";
	test_column(glove25_csv_path, exp);
}
