#include "Resources/ResourceManager.hpp"

#include <iostream>
#include <fstream>
#include "Core/JsonUtility.hpp"
#include "Components/SpriteRenderer.hpp"

bs::ResourceManager::ResourceManager(IRenderTarget& context)
	: context_(context)
{
	assetsToLoad_.emplace(0, "Assets/Textures/player_fly");
}

void bs::ResourceManager::PreloadAssets()
{
	printf("Loading assets\n");

	for (auto&& asset : assetsToLoad_)
	{
		printf("Loading %d _ path: %s", asset.first, asset.second.c_str());

		auto bmpPath = asset.second + ".bmp";
		auto metaPath = asset.second + ".json";

		auto texture = Texture::LoadFromFile(bmpPath, context_);

		std::ifstream stream;
		stream.open(metaPath);

		if (!stream.is_open())
		{
			throw std::exception("Cannot load config file!");
		}

		auto json = nlohmann::json::parse(stream);
		stream.close();

		auto meta = json.get<TextureMeta>();

		textures_.emplace(meta.Id, std::move(texture));

		auto texturePtr = textures_[meta.Id].get();

		for (auto&& spriteMeta : meta.Sprites)
		{
			auto sprite = std::make_unique<Sprite>(texturePtr, spriteMeta.Rect);
			sprites_.emplace(spriteMeta.Id, std::move(sprite));
		}

		printf("..... DONE\n");
	}

	assetsToLoad_.clear();
}

std::unique_ptr<bs::Scene> bs::ResourceManager::LoadScene()
{
	auto fakeScene = std::make_unique<Scene>();

	auto entity = std::unique_ptr<GameEntity>(new GameEntity(0));
	std::shared_ptr<IEntityComponent> component = std::make_shared<SpriteRenderer>(entity.get(), sprites_[101].get());
	entity->AddComponent(component);
	fakeScene->AddEntity(std::move(entity));

	return fakeScene;
}