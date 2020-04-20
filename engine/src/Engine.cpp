#include "Engine.hpp"

bs::Engine::Engine()
	: quitRequested_(false)
{
}

void bs::Engine::Run()
{
    LoadConfig();

	while (!quitRequested_)
	{
        ProcessEvents();

        Update(-1);

        Render();
	}
}

void bs::Engine::LoadConfig()
{
    const bs::math::Vec2i resolution(640, 480);
    const WindowMode mode = WindowMode::Windowed;
    const std::string title = "Bloodstone Engine";

    window_ = std::make_unique<RenderWindow>(title, resolution, mode);
}

void bs::Engine::ProcessEvents()
{
    // TODO: move to window
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            quitRequested_ = true;
            break;
        case SDL_KEYUP:
            quitRequested_ = event.key.keysym.sym == SDLK_ESCAPE;
            break;
        default:
            break;
        }
    }
}

void bs::Engine::Update(float deltaTime)
{
}

void bs::Engine::Render()
{
    auto clearColor = Color(30.f / 255.f, 30.f / 255.f, 160.f / 255.f);
    window_->Clear(clearColor);

    window_->Display();
}