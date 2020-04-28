#ifndef IENTITY_COMPONENT_HPP
#define IENTITY_COMPONENT_HPP

namespace bs
{
	class GameEntity;

	class IEntityComponent
	{
	public:
		virtual void Update(const float& deltaTime) = 0;

		virtual GameEntity* GetEntity() = 0;
	};
}

#endif // !IENTITY_COMPONENT_HPP