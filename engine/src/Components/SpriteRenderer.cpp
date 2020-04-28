#include "Components/SpriteRenderer.hpp"
#include "Components/GameEntity.hpp"

bs::SpriteRenderer::SpriteRenderer(GameEntity* entity, Sprite* sprite)
	: IDrawableComponent(entity)
	, sprite_(sprite)
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

	auto* transform = GetEntity()->GetTransform();
	auto& position = transform->GetPosition();

	SDL_Rect renderRect;

	renderRect.x = position.X;
	renderRect.y = position.Y;
	renderRect.w = spriteRect.Width;
	renderRect.h = spriteRect.Height;

	SDL_RenderCopy(renderer, texture, &rect, &renderRect);
}