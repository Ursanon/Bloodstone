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

void bs::GameEntity::Update(float deltaTime)
{
	printf("Updating %d", id_);
}