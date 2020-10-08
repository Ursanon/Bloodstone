#include "Components/Transform.hpp"

bs::Transform::Transform(GameEntity* entity)
	: Component(entity)
	, rotation_(0)
{
}

bs::Vec2f bs::Transform::GetPosition() const
{
	return position_;
}

float bs::Transform::GetRotation() const
{
	return rotation_;
}

void bs::Transform::SetPosition(const bs::Vec2f& position)
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
