#ifndef LEP_ENCODER_HPP
#define LEP_ENCODER_HPP

#include "../alp/common.hpp"
#include "../alp/decoder.hpp"
#include "../alp/encoder.hpp"
#include "decoder.hpp"
#include <cmath>
#include <cstdint>

/*
 * LEP Encoding
 */
namespace lep {

struct state {
	// LEP
	uint8_t                          exp {};
};

template <typename PT>
struct encoder {
	using UT = typename alp::inner_t<PT>::ut;
	using ST = typename alp::inner_t<PT>::st;

	//! Scalar encoding a single value with ALP
	template <bool SAFE = true>
	static ST encode_value(const PT value, const alp::exponent_idx_t exponent_idx) {
		PT tmp_encoded_value = value * alp::Constants<PT>::EXP_ARR[exponent_idx];
		if constexpr (SAFE) {
			if (is_impossible_to_encode(tmp_encoded_value)) { return alp::ENCODING_UPPER_LIMIT; }
		}
		tmp_encoded_value = tmp_encoded_value + alp::Constants<PT>::MAGIC_NUMBER - alp::Constants<PT>::MAGIC_NUMBER;
		return static_cast<ST>(tmp_encoded_value);
	}

	static inline void encode_simdized(const PT*            		input_vector,
	                                   ST*                  		encoded_integers,
	                                   const alp::exponent_idx_t 	exponent_idx) {
		alignas(64) static PT       ENCODED_DBL_ARR[1024];
		alignas(64) static PT       DBL_ARR_WITHOUT_SPECIALS[1024];
		alignas(64) static uint64_t TMP_INDEX_ARR[1024];

		// make copy of input with all special values replaced by  ENCODING_UPPER_LIMIT
		const auto* tmp_input = reinterpret_cast<const UT*>(input_vector);
		for (size_t i {0}; i < alp::config::VECTOR_SIZE; i++) {
			const auto is_special =
			    ((tmp_input[i] & alp::Constants<PT>::SIGN_BIT_MASK) >=
			     alp::Constants<PT>::EXPONENTIAL_BITS_MASK) // any NaN, +inf and -inf
			                                           // (https://stackoverflow.com/questions/29730530/)
			    || tmp_input[i] == alp::Constants<PT>::NEGATIVE_ZERO;

			if (is_special) {
				DBL_ARR_WITHOUT_SPECIALS[i] = alp::ENCODING_UPPER_LIMIT;
			} else {
				DBL_ARR_WITHOUT_SPECIALS[i] = input_vector[i];
			}
		}

#pragma clang loop vectorize_width(64)
		for (size_t i {0}; i < alp::config::VECTOR_SIZE; i++) {
			auto const actual_value = DBL_ARR_WITHOUT_SPECIALS[i];
			const ST encoded_value = encode_value<false>(actual_value, exponent_idx);
			encoded_integers[i]    = encoded_value;
		}
	}

	static inline void encode(const PT*  input_vector,
	                          ST*        encoded_integers,
	                          state& stt,
	                          uint8_t exp) {
		stt.exp = exp;
		encode_simdized(
		    input_vector, encoded_integers, stt.exp);
	}
};

} // namespace alp

#endif // LEP_ENCODER_HPP
