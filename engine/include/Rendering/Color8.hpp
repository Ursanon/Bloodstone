#ifndef COLOR8_HPP
#define COLOR8_HPP

#include <limits>
#include <cstdint>

namespace bs
{
	struct Color8
	{
		static uint8_t MaxValue;

		uint8_t R, G, B, A;

		Color8();
		Color8(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a = MaxValue);
	};
}

#endif // !COLOR8_HPP