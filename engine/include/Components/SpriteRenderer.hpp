#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include "Components/IDrawableComponent.hpp"
#include "Graphics/Sprite.hpp"

namespace bs
{
	class SpriteRenderer
		: public IDrawableComponent
	{
	public:
		explicit SpriteRenderer(GameEntity* entity, Sprite* sprite);

		void SpriteRenderer::Update(const float& deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Sprite* sprite_;
		sf::VertexArray vertices_;

		GameEntity * const entity_;
	};
}

#endif // !SPRITE_RENDERER_HPP