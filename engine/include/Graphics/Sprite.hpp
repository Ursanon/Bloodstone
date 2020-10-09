#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics/Texture.hpp>
#include "Core/Math/Rect.hpp"

namespace bs
{
	class Sprite
	{
	public:
		Sprite(sf::Texture* texture, Rect<int> rect);

		Rect<int> GetRect() const;

		const sf::Texture* GetTexture() const;

		void SetRect(const Rect<int>& rect);

		void SetTexture(const sf::Texture* texture);

	private:
		Rect<int> rect_;
		const sf::Texture* texture_;
	};
}

#endif // !SPRITE_HPP