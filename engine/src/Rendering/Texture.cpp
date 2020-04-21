#include "Rendering/Texture.hpp"

std::unique_ptr<bs::Texture> bs::Texture::LoadFromFile(const std::string& path, IRenderTarget& context)
{
	SDL_Surface* const surface = SDL_LoadBMP(path.c_str());

	SDL_Texture* const tex = SDL_CreateTextureFromSurface(context.GetRenderer(), surface);

	SDL_FreeSurface(surface);

	return std::unique_ptr<Texture>(new Texture(tex));
}

bs::Texture::~Texture()
{
	printf("Destroing texture!");
	SDL_DestroyTexture(texture_);
}

bs::Texture::Texture(SDL_Texture* texture)
	: texture_(texture)
{
}