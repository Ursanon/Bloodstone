#ifndef RENDER_WINDOW_HPP
#define RENDER_WINDOW_HPP

#include "Window/Window.hpp"
#include "Rendering/Color.hpp"
#include "Rendering/IDrawable.hpp"
#include "Rendering/IRenderTarget.hpp"

namespace bs
{
	class RenderWindow sealed
		: public Window
		, public IRenderTarget
	{
	public:
		RenderWindow(const std::string& name, const math::Vec2i& size, const WindowMode mode = WindowMode::Windowed);

		virtual ~RenderWindow();

		void Clear(const Color& color);
		void Draw(const IDrawable& drawable);

		void Display();

	private:
		SDL_Renderer* renderer_;
	};
}

#endif // !RENDER_WINDOW_HPP