#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "Components/GameEntity.hpp"

namespace bs
{
	// TODO: #5
	class Scene
	{
	public:
		void AddEntity(std::unique_ptr<GameEntity>& entity);

		std::vector<std::unique_ptr<GameEntity>>& GetEntities();

	private:
		std::vector<std::unique_ptr<GameEntity>> entities_;
	};
}

#endif // !SCENE_HPP