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