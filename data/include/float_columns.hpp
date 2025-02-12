#ifndef FLOAT_COLUMNS_HPP
#define FLOAT_COLUMNS_HPP

#include "column.hpp"

namespace alp_bench {
inline auto get_sp_datasets() {
	static std::array<Column, 4> SP_DATASETS = {{
	    {1, "Dino-Vitb16", "", get_paths().alp_dataset_binary_dir_path + "sp_dino_vitb16.bin", 0, 0, 0, 0, true},
	    {2, "GPT2", "", get_paths().alp_dataset_binary_dir_path + "sp_gpt2.bin", 0, 0, 0, 0, true},
	    {3,
	     "Grammarly-lg",
	     "",
	     get_paths().alp_dataset_binary_dir_path + "sp_grammarly_coedit_lg.bin",
	     0,
	     0,
	     0,
	     0,
	     true},
	    {4, "WAV2VEC", "", get_paths().alp_dataset_binary_dir_path + "sp_wav2vec2_base_960h.bin", 0, 0, 0, 0, true},

	}};

	return SP_DATASETS;
}

inline auto get_float_test_dataset() {
	static std::array<Column, 5> FLOAT_TEST_DATASET = {{
	    {0, "Arade/4", get_paths().alp_dataset_csv_path + "arade4.csv", "", 0, 0, 0, 0},
	    {1, "test_0", CMAKE_SOURCE_DIR "/data/float/test_0.csv", "", 0, 0, 0, 4},
	    {2, "test_1", CMAKE_SOURCE_DIR "/data/float/test_1.csv", "", 0, 0, 0, 10},
	    {3, "test_2", CMAKE_SOURCE_DIR "/data/float/test_2.csv", "", 0, 0, 0, 17},
	    {4, "test_3", CMAKE_SOURCE_DIR "/data/float/test_3.csv", "", 0, 0, 0, 0},

	}};
	return FLOAT_TEST_DATASET;
}

} // namespace alp_bench
#endif
