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
    Event event;

    while (window_->PoolEvents(event))
    {
        switch (event.Type)
        {
        case Event::EventType::WindowClose:
            quitRequested_ = true;
            break;
        case Event::EventType::KeyReleased:
            quitRequested_ = event.Key.Code == Keyboard::Key::Escape;
            break;
        }
    }
}

void bs::Engine::Update(float deltaTime)
{
}

void bs::Engine::Render()
{
    auto clearColor = Color(0.15f, 0.15f, 0.8f);
    window_->Clear(clearColor);

    window_->Display();
}