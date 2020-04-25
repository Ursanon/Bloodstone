#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <memory>
#include "SDL.h"
#include "Rendering/IDrawable.hpp"

namespace bs
{
	class Texture
		: public IDrawable
	{
	public:
		static std::unique_ptr<bs::Texture> LoadFromFile(const std::string& path, IRenderTarget& context);

		~Texture();

		virtual void Draw(const IRenderTarget& target) override;

	protected:
		explicit Texture(SDL_Texture* texture);

	private:
		SDL_Texture* const texture_;
	};
}

#endif // !TEXTURE_HPP