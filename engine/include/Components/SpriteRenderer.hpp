#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include "Rendering/Sprite.hpp"
#include "Components/IDrawableComponent.hpp"

namespace bs
{
	class SpriteRenderer
		: public IDrawableComponent
	{
	public:
		explicit SpriteRenderer(Sprite* texture);

		virtual void Update(const float& deltaTime) override;

		virtual void Draw(const IRenderTarget& target) override;

	private:
		Sprite* sprite_;
	};
}

#endif // !SPRITE_RENDERER_HPP