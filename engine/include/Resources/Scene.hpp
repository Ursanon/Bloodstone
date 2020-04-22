#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "Rendering/IDrawable.hpp"
#include "Components/GameEntity.hpp"

namespace bs
{
	// TODO: #5
	class Scene : IDrawable
	{
	public:
		void Update(float deltaTime);

		virtual void Draw(const IRenderTarget& target) override;

		void AddEntity(const GameEntity& entity);

	private:
		std::vector<GameEntity> entities_;
	};
}

#endif // !SCENE_HPP