#include "Engine.hpp"

#include <chrono>
#include <thread>
#include "Core/Time/Stopwatch.hpp"

bs::Engine::Engine()
	: quitRequested_(false)
{
}

void bs::Engine::Run()
{
    LoadConfig();
    const double timePerFrame = (1.0 / 60.0) * 1000.0;

    double accelerator = 0;
    TimePoint lastUpdateTime;
    TimePoint lastRenderTime;
    Stopwatch frameStopwatch;
    Stopwatch renderStopwatch;

    while (!quitRequested_)
	{
        ProcessEvents();

        frameStopwatch.Stop();
        const double lastFrameTime = frameStopwatch.GetElapsedTime<std::milli>();
        frameStopwatch.Restart();

        printf("Frametime: %.4f [ms] || ", lastFrameTime);

        accelerator += lastFrameTime;
        while (accelerator > timePerFrame)
        {
            accelerator -= timePerFrame;

            ProcessEvents();

            Update(timePerFrame);

            lastUpdateTime = Time::Now();
        }

        renderStopwatch.Restart();

        Render();
        lastRenderTime = Time::Now();
        renderStopwatch.Stop();

        const double renderTime = renderStopwatch.GetElapsedTime<std::milli>();
        printf("Render: %.4f [ms]\n", renderTime);

        while (Time::ElapsedFrom<std::milli>(lastRenderTime) < timePerFrame - renderTime
               && Time::ElapsedFrom<std::milli>(lastUpdateTime) < timePerFrame)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(0));
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