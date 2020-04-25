#ifndef IDRAWABLE_COMPONENT_HPP
#define IDRAWABLE_COMPONENT_HPP

#include "Components/IEntityComponent.hpp"
#include "Rendering/IDrawable.hpp"

namespace bs
{
	class IDrawableComponent
		: public IEntityComponent
		, public IDrawable
	{
	public:
		virtual void Update(const float& deltaTime) = 0;

		virtual void Draw(const IRenderTarget& target) = 0;
	};
}

#endif // !IDRAWABLE_COMPONENT_HPP
