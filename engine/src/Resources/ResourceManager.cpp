#include "Resources/ResourceManager.hpp"

#include <iostream>
#include <fstream>
#include "Core/JsonUtility.hpp"
#include "Components/SpriteRenderer.hpp"

#include "Gameplay/Gameplay.hpp"

bs::ResourceManager::ResourceManager()
{
	assetsToLoad_.emplace(0, "Assets/Textures/player_fly");
	assetsToLoad_.emplace(1, "Assets/Textures/bg");
}

void bs::ResourceManager::PreloadAssets()
{
	printf("Loading assets\n");

	for (auto&& asset : assetsToLoad_)
	{
		printf("Loading %d _ path: %s", asset.first, asset.second.c_str());

		auto bmpPath = asset.second + ".bmp";
		auto metaPath = asset.second + ".json";

		auto texture = sf::Texture();
		texture.loadFromFile(bmpPath);

		std::ifstream stream;
		stream.open(metaPath);

		if (!stream.is_open())
		{
			throw std::exception("Cannot load config file!");
		}

		auto json = nlohmann::json::parse(stream);
		stream.close();

		auto meta = json.get<TextureMeta>();

		textures_.emplace(meta.Id, std::make_unique<sf::Texture>(texture));

		auto texturePtr = textures_[meta.Id].get();

		for (auto&& spriteMeta : meta.Sprites)
		{
			auto sprite = std::make_unique<sf::Sprite>(*texturePtr, spriteMeta.Rect);

			sprite->setOrigin(spriteMeta.Rect.Width / 2.f, spriteMeta.Rect.Height / 2.f);
			sprites_.emplace(spriteMeta.Id, std::move(sprite));
		}

		printf("..... DONE\n");
	}

	assetsToLoad_.clear();
}

std::unique_ptr<bs::Scene> bs::ResourceManager::LoadScene()
{
	auto fakeScene = std::make_unique<Scene>();

	auto backgroundEntity = std::unique_ptr<GameEntity>(new GameEntity(0));
	std::shared_ptr<IEntityComponent> bgRenderer = std::make_shared<SpriteRenderer>(backgroundEntity.get(), sprites_[110].get());
	backgroundEntity->AddComponent(bgRenderer);
	fakeScene->AddEntity(std::move(backgroundEntity));

	auto playerEntity = std::unique_ptr<GameEntity>(new GameEntity(1));
	std::shared_ptr<IEntityComponent> spriteRenderer = std::make_shared<SpriteRenderer>(playerEntity.get(), sprites_[101].get());
	playerEntity->AddComponent(spriteRenderer);

	const float speed = 100.f;
	const float angularSpeed = 100.f;
	std::shared_ptr<IEntityComponent> playerController = std::make_shared<game::PlayerController>(playerEntity.get(), speed, angularSpeed);
	playerEntity->AddComponent(playerController);

	fakeScene->AddEntity(std::move(playerEntity));

	return fakeScene;
}