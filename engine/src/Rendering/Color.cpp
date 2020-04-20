#include "Rendering/Color.hpp"

bs::Color::Color()
	: R(0)
	, G(0)
	, B(0)
	, A(1)
{
}

bs::Color::Color(const float& r, const float& g, const float& b, const float& a)
	: R(r)
	, G(g)
	, B(b)
	, A(a)
{
}

const bs::Color8 bs::Color::AsColor8() const
{
	auto maxValue = Color8::MaxValue;
	return Color8(R * maxValue, G * maxValue, B * maxValue, A * maxValue);
}