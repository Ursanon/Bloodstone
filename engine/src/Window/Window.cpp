#include "Window/Window.hpp"

bs::Window::Window(const std::string& name, const math::Vec2i& size, const WindowMode mode)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.X, size.Y, SDL_WINDOW_SHOWN);
}

bs::Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool bs::Window::PoolEvents(Event& event)
{
    SDL_Event nativeEvent;
    const bool nextEventAvailable = SDL_PollEvent(&nativeEvent);

    switch (nativeEvent.type)
    {
    case SDL_QUIT:
        event.Type = Event::EventType::WindowClose;
        break;
    case SDL_KEYUP:
        {
            event.Type = Event::EventType::KeyReleased;
            switch (nativeEvent.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                event.Key.Code = Keyboard::Key::Escape;
                break;
            }
            break;
        }
    }

	return nextEventAvailable;
}