#ifndef IDRAWABLE_COMPONENT_HPP
#define IDRAWABLE_COMPONENT_HPP

#include "Components/Component.hpp"
#include "Rendering/IDrawable.hpp"

namespace bs
{
	class IDrawableComponent
		: public Component
		, public IDrawable
	{
	public:
		IDrawableComponent(GameEntity* entity)
			: Component(entity)
		{
		}

		virtual void Draw(const IRenderTarget& target) = 0;
	};
}

#endif // !IDRAWABLE_COMPONENT_HPP
