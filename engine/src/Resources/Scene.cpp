#include "Resources/Scene.hpp"

void bs::Scene::AddEntity(std::unique_ptr<GameEntity>& entity)
{
	entities_.push_back(std::move(entity));
}

std::vector<std::unique_ptr<bs::GameEntity>>& bs::Scene::GetEntities()
{
	return entities_;
}