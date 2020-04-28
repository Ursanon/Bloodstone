#include "Components/Component.hpp"

bs::Component::Component(GameEntity* entity)
	: entity_(entity)
{
}

bs::GameEntity* bs::Component::GetEntity()
{
	return entity_;
}

void bs::Component::Update(const float& deltaTime)
{
}