#include "Components/PlayerController.hpp"
#include "Components/GameEntity.hpp"

bs::game::PlayerController::PlayerController(GameEntity* entity, const float& speed, const float& angularSpeed)
	: Component(entity)
	, speed_(speed)
	, angularSpeed_(angularSpeed)
{
	transform_ = entity->GetTransform();
}

void bs::game::PlayerController::Update(const float& deltaTime)
{
	auto rotation = HandleRotation();

	if (rotation != 0.f)
	{
		auto oldRotation = transform_->GetRotation();

		const float newRotation = oldRotation + rotation * angularSpeed_ * deltaTime;

		transform_->SetRotation(newRotation); 
	}

	auto direction = HandleMovement();

	if (direction != Vec2f::Zero())
	{
		auto currentRotation = transform_->GetRotation();

		direction.Rotate(currentRotation);

		auto position = transform_->GetPosition();
		auto newPosition = position + direction * speed_;

		auto newPos = Vec2f::Lerp(position, newPosition, deltaTime);

		transform_->SetPosition(newPos);
	}
}

bs::Vec2f bs::game::PlayerController::HandleMovement() const
{
	Vec2f direction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction += Vec2f(0, -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction += Vec2f::Up();
	}
	else
	{
		//idle
	}

	return direction.Normalized();
}

float bs::game::PlayerController::HandleRotation() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		return -1.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return 1.f;
	}

	return 0.f;
}