#ifndef IRENDER_TARGET_HPP
#define IRENDER_TARGET_HPP

#include "SDL.h"

namespace bs
{
	class IRenderTarget
	{
	public:
		virtual SDL_Renderer* GetRenderer() = 0;
	};
}

#endif // !IRENDER_TARGET_HPP