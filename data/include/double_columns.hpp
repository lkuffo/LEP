#ifndef DOUBLE_COLUMNS_HPP
#define DOUBLE_COLUMNS_HPP

#include "column.hpp"

namespace alp_bench {

inline std::array<Column, 30> get_alp_dataset() {
	static std::array<Column, 30> ALP_DATASET = {{

	    {1,
	     "Air-Pressure",
	     get_paths().alp_dataset_csv_path + "neon_air_pressure.csv",
	     get_paths().alp_dataset_binary_dir_path + "neon_air_pressure.bin",
	     14,
	     9,
	     3,
	     16},

	    {2,
	     "Arade/4",
	     get_paths().alp_dataset_csv_path + "arade4.csv",
	     get_paths().alp_dataset_binary_dir_path + "arade4.bin",
	     14,
	     10,
	     8,
	     24},

	    {3,
	     "Basel-Temp",
	     get_paths().alp_dataset_csv_path + "basel_temp_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "basel_temp_f.bin",
	     14,
	     7,
	     47,
	     28},

	    {4,
	     "Basel-Wind",
	     get_paths().alp_dataset_csv_path + "basel_wind_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "basel_wind_f.bin",
	     14,
	     7,
	     9,
	     29},

	    {5,
	     "Bird-Mig",
	     get_paths().alp_dataset_csv_path + "bird_migration_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "bird_migration_f.bin",
	     14,
	     9,
	     2,
	     17},

	    {6,
	     "Btc-Price",
	     get_paths().alp_dataset_csv_path + "bitcoin_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "bitcoin_f.bin",
	     14,
	     10,
	     10,
	     25},

	    {7,
	     "Blockchain",
	     get_paths().alp_dataset_csv_path + "bitcoin_transactions_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "bitcoin_transactions_f.bin",
	     14,
	     10,
	     11,
	     30},

	    {8,
	     "City-Temp",
	     get_paths().alp_dataset_csv_path + "city_temperature_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "city_temperature_f.bin",
	     14,
	     13,
	     0,
	     11},

	    {9,
	     "CMS/1",
	     get_paths().alp_dataset_csv_path + "cms1.csv",
	     get_paths().alp_dataset_binary_dir_path + "cms1.bin",
	     14,
	     5,
	     10,
	     41},

	    {10,
	     "CMS/9",
	     get_paths().alp_dataset_csv_path + "cms9.csv",
	     get_paths().alp_dataset_binary_dir_path + "cms9.bin",
	     16,
	     16,
	     2,
	     10},

	    {11,
	     "CMS/25",
	     get_paths().alp_dataset_csv_path + "cms25.csv",
	     get_paths().alp_dataset_binary_dir_path + "cms25.bin",
	     14,
	     4,
	     6,
	     42},

	    {12,
	     "Dew-Temp",
	     get_paths().alp_dataset_csv_path + "neon_dew_point_temp.csv",
	     get_paths().alp_dataset_binary_dir_path + "neon_dew_point_temp.bin",
	     14,
	     11,
	     6,
	     13},

	    {13,
	     "Bio-Temp",
	     get_paths().alp_dataset_csv_path + "neon_bio_temp_c.csv",
	     get_paths().alp_dataset_binary_dir_path + "neon_bio_temp_c.bin",
	     14,
	     12,
	     0,
	     10},

	    {14,
	     "Food-prices",
	     get_paths().alp_dataset_csv_path + "food_prices.csv",
	     get_paths().alp_dataset_binary_dir_path + "food_prices.bin",
	     16,
	     12,
	     46,
	     20},

	    {15,
	     "Gov/10",
	     get_paths().alp_dataset_csv_path + "gov10.csv",
	     get_paths().alp_dataset_binary_dir_path + "gov10.bin",
	     3,
	     1,
	     72,
	     27},

	    {16,
	     "Gov/26",
	     get_paths().alp_dataset_csv_path + "gov26.csv",
	     get_paths().alp_dataset_binary_dir_path + "gov26.bin",
	     18,
	     18,
	     0,
	     0},

	    {17,
	     "Gov/30",
	     get_paths().alp_dataset_csv_path + "gov30.csv",
	     get_paths().alp_dataset_binary_dir_path + "gov30.bin",
	     18,
	     18,
	     4,
	     0},

	    {18,
	     "Gov/31",
	     get_paths().alp_dataset_csv_path + "gov31.csv",
	     get_paths().alp_dataset_binary_dir_path + "gov31.bin",
	     18,
	     18,
	     1,
	     0},

	    {19,
	     "Gov/40",
	     get_paths().alp_dataset_csv_path + "gov40.csv",
	     get_paths().alp_dataset_binary_dir_path + "gov40.bin",
	     18,
	     18,
	     3,
	     0},

	    {20,
	     "Medicare/1",
	     get_paths().alp_dataset_csv_path + "medicare1.csv",
	     get_paths().alp_dataset_binary_dir_path + "medicare1.bin",
	     14,
	     5,
	     37,
	     38},

	    {21,
	     "Medicare/9",
	     get_paths().alp_dataset_csv_path + "medicare9.csv",
	     get_paths().alp_dataset_binary_dir_path + "medicare9.bin",
	     16,
	     16,
	     3,
	     10},

	    {22,
	     "PM10-dust",
	     get_paths().alp_dataset_csv_path + "neon_pm10_dust.csv",
	     get_paths().alp_dataset_binary_dir_path + "neon_pm10_dust.bin",
	     14,
	     11,
	     0,
	     8},

	    {23,
	     "NYC/29",
	     get_paths().alp_dataset_csv_path + "nyc29.csv",
	     get_paths().alp_dataset_binary_dir_path + "nyc29.bin",
	     14,
	     1,
	     5,
	     42},

	    {24,
	     "POI-lat",
	     get_paths().alp_dataset_csv_path + "poi_lat.csv",
	     get_paths().alp_dataset_binary_dir_path + "poi_lat.bin",
	     16,
	     0,
	     157,
	     55,
	     true},

	    {25,
	     "POI-lon",
	     get_paths().alp_dataset_csv_path + "poi_lon.csv",
	     get_paths().alp_dataset_binary_dir_path + "poi_lon.bin",
	     16,
	     0,
	     199,
	     56,
	     true},

	    {26,
	     "SD-bench",
	     get_paths().alp_dataset_csv_path + "ssd_hdd_benchmarks_f.csv",
	     get_paths().alp_dataset_binary_dir_path + "ssd_hdd_benchmarks_f.bin",
	     14,
	     13,
	     0,
	     17},

	    {27,
	     "Stocks-DE",
	     get_paths().alp_dataset_csv_path + "stocks_de.csv",
	     get_paths().alp_dataset_binary_dir_path + "stocks_de.bin",
	     14,
	     11,
	     5,
	     10

	    },

	    {28,
	     "Stocks-UK",
	     get_paths().alp_dataset_csv_path + "stocks_uk.csv",
	     get_paths().alp_dataset_binary_dir_path + "stocks_uk.bin",
	     14,
	     13,
	     0,
	     9},

	    {29,
	     "Stocks-USA",
	     get_paths().alp_dataset_csv_path + "stocks_usa_c.csv",
	     get_paths().alp_dataset_binary_dir_path + "stocks_usa_c.bin",
	     14,
	     12,
	     0,
	     7},

	    {30,
	     "Wind-dir",
	     get_paths().alp_dataset_csv_path + "neon_wind_dir.csv",
	     get_paths().alp_dataset_binary_dir_path + "neon_wind_dir.bin",
	     14,
	     12,
	     0,
	     16},

	}};
	return ALP_DATASET;
};

inline std::array<Column, 1> get_double_test_dataset() {
	static std::array<Column, 1> DOUBLE_TEST_DATASET = {{
	    {0, "test_0", CMAKE_SOURCE_DIR "/data/double/test_0.csv", "", 0, 0, 0, 0},
	}};

	return DOUBLE_TEST_DATASET;
}

} // namespace alp_bench
#endif