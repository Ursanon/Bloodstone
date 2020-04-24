#include "Components/GameEntity.hpp"

#include <cstdio>

bs::GameEntity::GameEntity(int id)
	: id_(id)
{
}

int bs::GameEntity::GetId() const
{
	return id_;
}

void bs::GameEntity::Update(const float& deltaTime)
{
	printf("Updating %d", id_);
}

void bs::GameEntity::Draw(const IRenderTarget& target)
{
	printf("Rendering entity [%d]", id_);
}

void bs::GameEntity::AddComponent(std::shared_ptr<IEntityComponent>& component)
{
	components_.push_back(component);
}