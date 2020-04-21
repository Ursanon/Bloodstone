#ifndef IDRAWABLE_HPP
#define IDRAWABLE_HPP

#include "IRenderTarget.hpp"

namespace bs
{
	class IDrawable
	{
	public:
		virtual void Draw(const IRenderTarget& target) = 0;
	};
}

#endif // !IDRAWABLE_HPP