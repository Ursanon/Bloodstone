#include "Resources/ResourceManager.hpp"

#include "Components/SpriteRenderer.hpp"

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

	auto entity = std::unique_ptr<GameEntity>(new GameEntity(0));
	std::shared_ptr<IEntityComponent> component = std::make_shared<SpriteRenderer>(textures_[0].get());
	entity->AddComponent(component);
	fakeScene->AddEntity(std::move(entity));

	return fakeScene;
}