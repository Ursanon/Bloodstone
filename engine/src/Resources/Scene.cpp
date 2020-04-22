#include "Resources/Scene.hpp"

void bs::Scene::Update(float deltaTime)
{
}

void bs::Scene::Draw(const IRenderTarget& target)
{
}

void bs::Scene::AddEntity(const GameEntity& entity)
{
	entities_.push_back(entity);
}