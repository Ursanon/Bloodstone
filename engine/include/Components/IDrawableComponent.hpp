#ifndef IDRAWABLE_COMPONENT_HPP
#define IDRAWABLE_COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Components/Component.hpp"

namespace bs
{
	class IDrawableComponent
		: public Component
		, public sf::Drawable
	{
	public:
		IDrawableComponent(GameEntity* entity)
			: Component(entity)
		{
		}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	};
}

#endif // !IDRAWABLE_COMPONENT_HPP
