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

namespace bs {
sf::Transform& operator *=(sf::Transform& left, const bs::Transform& right)
{
	const auto scale = right.GetScale();
	const auto origin = right.GetOrigin();
	const auto position = right.GetPosition();
	const auto rotation = right.GetRotation();

	return left.scale(scale.X, scale.Y, origin.X, origin.Y)
			   .translate(position.X - origin.X, position.Y - origin.Y)
			   .rotate(rotation * bs::RAD_TO_DEG, origin.X, origin.Y);
}
}