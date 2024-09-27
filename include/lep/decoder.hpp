#ifndef LEP_DECODER_HPP
#define LEP_DECODER_HPP

#include "../alp/constants.hpp"
#include "../alp/decoder.hpp"
#include <cstdint>

namespace lep {

template <class PT>
struct decoder {
	using UT = typename alp::inner_t<PT>::ut;
	using ST = typename alp::inner_t<PT>::st;

	//! Scalar decoding a single value with ALP
	static inline PT decode_value(const ST encoded_value, const const uint8_t exponent) {
		const PT decoded_value = encoded_value * alp::Constants<PT>::FRAC_ARR[exponent];
		return decoded_value;
	}

	//! Scalar decoding of an ALP vector
	static inline void decode(const ST* encoded_integers, const uint8_t exp_idx, PT* output) {
		for (size_t i {0}; i < alp::config::VECTOR_SIZE; i++) {
			output[i] = decode_value(encoded_integers[i], exp_idx);
		}
	}

};

} // namespace lep

#endif // LEP_DECODER_HPP
