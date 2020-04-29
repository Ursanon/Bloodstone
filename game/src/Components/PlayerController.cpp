#include "Components/PlayerController.hpp"

#include "Components/GameEntity.hpp"
#include "Window/Keyboard.hpp"

bs::game::PlayerController::PlayerController(GameEntity* entity, const float& speed)
	: Component(entity)
	, speed_(speed)
{
	transform_ = entity->GetTransform();
}

void bs::game::PlayerController::Update(const float& deltaTime)
{
	auto direction = HandleInput();

	if (direction != Vec2f::Zero())
	{
		auto& positon = transform_->GetPosition();
		auto newPositon = positon + direction * deltaTime * speed_;

		transform_->SetPosition(newPositon);
	}
}

bs::Vec2f bs::game::PlayerController::HandleInput() const
{
	Vec2f direction;
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		direction = Vec2f(-1, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		direction = Vec2f::Right();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{
		direction += Vec2f(0, -1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		direction += Vec2f::Up();
	}
	else
	{
		//idle
	}

	return direction;
}