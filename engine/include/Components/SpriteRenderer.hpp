#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include "Rendering/Texture.hpp"
#include "Components/IDrawableComponent.hpp"

namespace bs
{
	class SpriteRenderer
		: public IDrawableComponent
	{
	public:
		SpriteRenderer(Texture* texture);

		virtual void Update(const float& deltaTime) override;

		virtual void Draw(const IRenderTarget& target) override;


	private:
		Texture* texture_;
	};
}

#endif // !SPRITE_RENDERER_HPP