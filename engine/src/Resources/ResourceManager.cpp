#include "Resources/ResourceManager.hpp"

bs::ResourceManager::ResourceManager(SDL_Renderer* renderer)
	: renderer_(renderer)
{
	assetsToLoad_.emplace(0, "Assets/Textures/player.bmp");
}

void bs::ResourceManager::PreloadAssets()
{
	printf("Loading assets\n");

	for (auto&& asset : assetsToLoad_)
	{
		printf("Loading %d _ path: %s", asset.first, asset.second.c_str());

		auto texture = Texture::LoadFromFile(asset.second, renderer_);

		textures_.emplace(asset.first, std::move(texture));

		printf("..... DONE\n");
	}
}