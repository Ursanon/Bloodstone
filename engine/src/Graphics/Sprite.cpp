#include "Graphics/Sprite.hpp"

bs::Sprite::Sprite(sf::Texture* texture, bs::Rect<int> rect)
	:rect_(rect)
	,texture_(texture)
{
}

bs::Rect<int> bs::Sprite::GetRect() const
{
	return rect_;
}

const sf::Texture* bs::Sprite::GetTexture() const
{
	return texture_;
}

void bs::Sprite::SetRect(const bs::Rect<int>& rect)
{
	rect_ = rect;
}

void bs::Sprite::SetTexture(const sf::Texture* texture)
{
	texture_ = texture;
}