#include "Components/Transform.hpp"

bs::Transform::Transform(GameEntity* entity)
	: Component(entity)
	, rotation_(0)
	, scale_(bs::Vec2f::One())
{
}

bs::Vec2f bs::Transform::GetScale() const
{
	return scale_;
}

bs::Vec2f bs::Transform::GetOrigin() const
{
	return origin_;
}

bs::Vec2f bs::Transform::GetPosition() const
{
	return position_;
}

float bs::Transform::GetRotation() const
{
	return rotation_;
}

void bs::Transform::SetScale(const Vec2f& scale)
{
	scale_ = scale;
}

void bs::Transform::SetOrigin(const bs::Vec2f& origin)
{
	origin_ = origin;
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
