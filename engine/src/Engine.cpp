#include "Engine.hpp"

#include <chrono>
#include <thread>

bs::Engine::Engine()
	: quitRequested_(false)
{
}

void bs::Engine::Run()
{
    LoadConfig();

    double accelerator = 0;
    const double timePerFrame = (1.0 / 60.0) * 1000.0;

    auto start = std::chrono::high_resolution_clock::now();

    auto lastRenderTime = std::chrono::steady_clock::time_point::min();
    auto lastUpdateTime = std::chrono::steady_clock::time_point::min();

    while (!quitRequested_)
	{
        ProcessEvents();

        auto end = std::chrono::high_resolution_clock::now();
        auto msTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        auto ms = std::chrono::duration<double, std::milli>(end - start);

        start = std::chrono::high_resolution_clock::now();

        printf("%.4f [ms]\n", ms.count());

        accelerator += ms.count();
        while (accelerator > timePerFrame)
        {
            accelerator -= timePerFrame;

            ProcessEvents();

            Update(timePerFrame);

            lastUpdateTime = std::chrono::high_resolution_clock::now();
        }

        lastRenderTime = std::chrono::high_resolution_clock::now();
        Render();

        while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - lastRenderTime).count() < timePerFrame
            && std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - lastUpdateTime).count() < timePerFrame)
        {
            std::this_thread::yield();
        }
	}
}

void bs::Engine::LoadConfig()
{
    const bs::math::Vec2i resolution(640, 480);
    const WindowMode mode = WindowMode::Windowed;
    const std::string title = "Bloodstone Engine";

    window_ = std::make_unique<RenderWindow>(title, resolution, mode);

    auto target = static_cast<IRenderTarget*>(window_.get());
    resources_ = std::make_unique<ResourceManager>(*target);
    resources_->PreloadAssets();

    scene_ = std::move(resources_->LoadScene());
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