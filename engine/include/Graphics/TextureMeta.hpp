#ifndef TEXTURE_META_HPP
#define TEXTURE_META_HPP

#include <SFML/Graphics.hpp>

namespace bs
{
	struct MyIntRect
	{
		int X;
		int Y;
		int Width;
		int Height;

		operator sf::IntRect()
		{
			return sf::IntRect(X, Y, Width, Height);
		}
	};

	struct SpriteMeta
	{
		int Id = -1;
		MyIntRect Rect;
	};

	struct TextureMeta
	{
		int Id = -1;
		std::vector<SpriteMeta> Sprites;
	};
}

#endif // !TEXTURE_META_HPP