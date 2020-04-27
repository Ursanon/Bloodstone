#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>
#include "Core/Math/Rect.hpp"
#include "Rendering/Texture.hpp"

namespace bs
{
	class Sprite
	{
	public:
		Sprite(Texture* texture, const Rectf& rect);

		const Rectf& GetRect() const;
		Texture* GetTexture() const;

		void SetRect(const Rectf& rect);

	private:
		Rectf rect_;
		Texture* texture_;
	};

	struct SpriteMeta
	{
		int Id;
		Rectf Rect;
	};

	struct TextureMeta
	{
		int Id;
		std::vector<SpriteMeta> Sprites;
	};
}

#endif // !SPRITE_HPP