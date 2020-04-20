#ifndef COLOR_HPP
#define COLOR_HPP

#include "Rendering/Color8.hpp"

namespace bs
{
	struct Color
	{
		float R, G, B, A;

		Color();
		Color(const float& r, const float& g, const float& b, const float& a = 1);

		const Color8 AsColor8() const;
	};
}

#endif // !COLOR_HPP