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