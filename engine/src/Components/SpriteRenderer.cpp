#include "Components/SpriteRenderer.hpp"

bs::SpriteRenderer::SpriteRenderer(Sprite* sprite)
	: sprite_(sprite)
{
}

void bs::SpriteRenderer::Update(const float& deltaTime)
{
}

void bs::SpriteRenderer::Draw(const IRenderTarget& target)
{
	auto renderer = target.GetRenderer();
	auto texture = sprite_->GetTexture()->GetNativeHandle();

	auto& spriteRect = sprite_->GetRect();

	SDL_Rect rect;

	rect.x = spriteRect.X;
	rect.y = spriteRect.Y;
	rect.w = spriteRect.Width;
	rect.h = spriteRect.Height;

	SDL_RenderCopy(renderer, texture, &rect, nullptr);
}