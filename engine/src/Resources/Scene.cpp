#include "Resources/Scene.hpp"

void bs::Scene::Update(float deltaTime)
{
	for (auto&& entity : entities_)
	{
		entity.Update(deltaTime);
	}
}

void bs::Scene::Draw(const IRenderTarget& target)
{
	for (auto&& entity : entities_)
	{
	}
}

void bs::Scene::AddEntity(const GameEntity& entity)
{
	entities_.push_back(entity);
}