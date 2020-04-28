#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <memory>
#include <vector>
#include "Components/IDrawableComponent.hpp"
#include "Components/Component.hpp"
#include "Components/Transform.hpp"

namespace bs
{
	class GameEntity
		: public Component
	{
	public:
		explicit GameEntity(int id);

		virtual ~GameEntity();

		int GetId() const;

		Transform* GetTransform();

		void AddComponent(std::shared_ptr<IEntityComponent>& component);

		virtual void Update(const float& deltaTime) override;

		const std::vector<std::shared_ptr<IDrawableComponent>> GetDrawableComponents();

	private:
		int id_;
		
		std::shared_ptr<Transform> transform_;
		std::vector<std::shared_ptr<IEntityComponent>> components_;
	};
}

#endif // !GAME_ENTITY_HPP