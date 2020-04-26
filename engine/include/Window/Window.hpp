#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include "SDL.h"
#include "Window/Event.hpp"
#include "Core/Math/Vec2.hpp"
#include "Window/WindowMode.hpp"

namespace bs
{
	class Window
	{
	public:
		Window(const std::string& name, const Resolution& size, const WindowMode mode = WindowMode::Windowed);

		virtual ~Window();

		bool PoolEvents(Event& event);

	protected:
		SDL_Window* window;
	};
}

#endif // !WINDOW_HPP