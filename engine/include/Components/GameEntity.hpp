#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <memory>
#include <vector>
#include "Rendering/IDrawable.hpp"
#include "Components/IEntityComponent.hpp"

namespace bs
{
	class GameEntity : IEntityComponent, IDrawable
	{
	public:
		explicit GameEntity(int id);

		int GetId() const;

		void AddComponent(std::shared_ptr<IEntityComponent>& component);

		virtual void Update(const float& deltaTime) override;
		virtual void Draw(const IRenderTarget& target) override;

	private:
		int id_;

		std::vector<std::shared_ptr<IEntityComponent>> components_;
	};
}

#endif // !GAME_ENTITY_HPP