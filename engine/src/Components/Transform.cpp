#include "Components/Transform.hpp"

const bs::Vec2f& bs::Transform::GetPosition()
{
	return position_;
}

void bs::Transform::SetPosition(const Vec2f& position)
{
	position_ = position;
}

void bs::Transform::Update(const float& deltaTime)
{
}
