#ifndef COLOR_HPP
#define COLOR_HPP

namespace bs
{
	struct Color
	{
		float R, G, B, A;

		Color();
		Color(const float& r, const float& g, const float& b, const float& a = 1);
	};
}

#endif // !COLOR_HPP