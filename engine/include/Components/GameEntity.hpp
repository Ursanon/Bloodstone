#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include "IEntityComponent.hpp"

namespace bs
{
	class GameEntity : IEntityComponent
	{
	public:
		explicit GameEntity(int id);

		int GetId() const;

		virtual void Update(float deltaTime) override;

	private:
		int id_;
	};
}

#endif // !GAME_ENTITY_HPP