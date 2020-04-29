#ifndef PLAYER_CONTROLLER_HPP
#define PLAYER_CONTROLLER_HPP

#include "Components/Component.hpp"
#include "Components/Transform.hpp"

namespace bs::game
{
	class PlayerController
		: public Component
	{
	public:
		PlayerController(GameEntity* entity, const float& speed);

		virtual void Update(const float& deltaTime) override;

	private:
		Vec2f HandleInput() const;

	private:
		float speed_;

		Transform* transform_;
	};
}

#endif // !PLAYER_CONTROLLER_HPP