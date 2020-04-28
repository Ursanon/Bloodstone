#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Components/IEntityComponent.hpp"

namespace bs
{
	class GameEntity;

	class Component
		: public IEntityComponent
	{
	public:
		Component(GameEntity* entity);

		virtual void Update(const float& deltaTime) override;

		virtual GameEntity* GetEntity() override;

	private:
		GameEntity* entity_;
	};
}

#endif // !COMPONENT_HPP