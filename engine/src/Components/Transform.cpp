#include "Components/Transform.hpp"

bs::Transform::Transform(GameEntity* entity)
	: Component(entity)
	, rotation_(0.f)
{
}

const bs::Vec2f& bs::Transform::GetPosition()
{
	return position_;
}

const float& bs::Transform::GetRotation()
{
	return rotation_;
}

void bs::Transform::SetPosition(const Vec2f& position)
{
	position_ = position;
}

void bs::Transform::SetRotation(const float& rotation)
{
	rotation_ = rotation;
}

void bs::Transform::Update(const float& deltaTime)
{
}
