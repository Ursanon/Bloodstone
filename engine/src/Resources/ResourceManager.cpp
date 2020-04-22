#include "Resources/ResourceManager.hpp"

bs::ResourceManager::ResourceManager(IRenderTarget& context)
	: context_(context)
{
	assetsToLoad_.emplace(0, "Assets/Textures/player.bmp");
}

void bs::ResourceManager::PreloadAssets()
{
	printf("Loading assets\n");

	for (auto&& asset : assetsToLoad_)
	{
		printf("Loading %d _ path: %s", asset.first, asset.second.c_str());

		auto texture = Texture::LoadFromFile(asset.second, context_);

		textures_.emplace(asset.first, std::move(texture));

		printf("..... DONE\n");
	}
}

std::unique_ptr<bs::Scene> bs::ResourceManager::LoadScene()
{
	auto fakeScene = std::make_unique<Scene>();

	auto entity = GameEntity(0);

	fakeScene->AddEntity(entity);

	return fakeScene;
}