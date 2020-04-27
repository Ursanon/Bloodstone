#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <memory>
#include "Core/Math/Rect.hpp"
#include "SDL.h"
#include "Rendering/IDrawable.hpp"

namespace bs
{
	class Texture
	{
	public:
		static std::unique_ptr<bs::Texture> LoadFromFile(const std::string& path, IRenderTarget& context);

		~Texture();

		SDL_Texture* GetNativeHandle();

	protected:
		explicit Texture(SDL_Texture* texture);

	private:
		SDL_Texture* nativeTexture_;
	};
}

#endif // !TEXTURE_HPP