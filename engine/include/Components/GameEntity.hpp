#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <memory>
#include <vector>
#include "Components/IDrawableComponent.hpp"
#include "Components/IEntityComponent.hpp"

namespace bs
{
	class GameEntity
		: public IEntityComponent
	{
	public:
		explicit GameEntity(int id);

		virtual ~GameEntity();

		int GetId() const;

		void AddComponent(std::shared_ptr<IEntityComponent>& component);

		virtual void Update(const float& deltaTime) override;

		const std::vector<std::shared_ptr<IDrawableComponent>> GetDrawableComponents();

	private:
		int id_;

		std::vector<std::shared_ptr<IEntityComponent>> components_;
	};
}

#endif // !GAME_ENTITY_HPP