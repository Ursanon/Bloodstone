#include "Components/Transform.hpp"

bs::Transform::Transform(GameEntity* entity)
	: Component(entity)
{
}

bs::Vec2f bs::Transform::GetPosition() const
{
	auto pos = this->getPosition();
	return bs::Vec2f(pos.x, pos.y);
}

float bs::Transform::GetRotation() const
{
	return this->getRotation();
}

void bs::Transform::SetPosition(const bs::Vec2f& position)
{
	this->setPosition(sf::Vector2f(position.X, position.Y));
}

void bs::Transform::SetRotation(const float& rotation)
{
	this->setRotation(rotation);
}

void bs::Transform::Update(const float& deltaTime)
{
}
