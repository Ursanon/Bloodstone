#include "Rendering/RenderWindow.hpp"

bs::RenderWindow::RenderWindow(const std::string& name, const math::Vec2i& size, const WindowMode mode)
	: Window(name, size, mode)
{
	renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

bs::RenderWindow::~RenderWindow()
{
	SDL_DestroyRenderer(renderer_);
}

void bs::RenderWindow::Clear(const Color& color)
{
	auto color8 = color.AsColor8();

	SDL_SetRenderDrawColor(renderer_, color8.R, color8.G, color8.B, color8.A);
	SDL_RenderClear(renderer_);
}

void bs::RenderWindow::Draw(const IDrawable& drawable)
{
}

void bs::RenderWindow::Display()
{
	SDL_RenderPresent(renderer_);
}

SDL_Renderer* bs::RenderWindow::GetRenderer()
{
	return renderer_;
}