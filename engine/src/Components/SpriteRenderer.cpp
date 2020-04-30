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
	auto* renderer = target.GetRenderer();
	auto* texture = sprite_->GetTexture()->GetNativeHandle();

	auto& spriteRect = sprite_->GetRect();

	spriteRect_.x = spriteRect.X;
	spriteRect_.y = spriteRect.Y;
	spriteRect_.w = spriteRect.Width;
	spriteRect_.h = spriteRect.Height;

	auto* transform = GetEntity()->GetTransform();
	auto& position = transform->GetPosition();

	positionRect_.x = position.X;
	positionRect_.y = position.Y;
	positionRect_.w = spriteRect.Width;
	positionRect_.h = spriteRect.Height;

	auto& rotation = transform->GetRotation();

	SDL_RenderCopyEx(renderer, texture, &spriteRect_, &positionRect_, rotation, nullptr, SDL_FLIP_NONE);
}