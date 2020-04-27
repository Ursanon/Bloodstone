#include "Rendering/Sprite.hpp"

bs::Sprite::Sprite(Texture* texture, const Rectf& rect)
	: rect_(rect)
	, texture_(texture)
{
}

const bs::Rectf& bs::Sprite::GetRect() const
{
	return rect_;
}

bs::Texture* bs::Sprite::GetTexture() const
{
	return texture_;
}

void bs::Sprite::SetRect(const Rectf& rect)
{
	rect_ = rect;
}