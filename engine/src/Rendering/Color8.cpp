#include "Rendering/Color8.hpp"

uint8_t bs::Color8::MaxValue = std::numeric_limits<uint8_t>::max();

bs::Color8::Color8()
	: R(0)
	, G(0)
	, B(0)
	, A(1)
{
}

bs::Color8::Color8(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a)
	: R(r)
	, G(g)
	, B(b)
	, A(a)
{
}