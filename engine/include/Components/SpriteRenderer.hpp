#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include "Components/IDrawableComponent.hpp"

namespace bs
{
	class SpriteRenderer
		: public IDrawableComponent
	{
	public:
		explicit SpriteRenderer(GameEntity* entity, sf::Sprite* sprite);

		void SpriteRenderer::Update(const float& deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Sprite* sprite_;

		GameEntity * const entity_;
	};
}

#endif // !SPRITE_RENDERER_HPP