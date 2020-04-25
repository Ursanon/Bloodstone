#include "Components/SpriteRenderer.hpp"

bs::SpriteRenderer::SpriteRenderer(Texture* texture)
	: texture_(texture)
{
}

void bs::SpriteRenderer::Update(const float& deltaTime)
{
}

void bs::SpriteRenderer::Draw(const IRenderTarget& target)
{
	texture_->Draw(target);
}