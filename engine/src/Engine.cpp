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

    float accelerator = 0;
    TimePoint lastUpdateTime;
    TimePoint lastRenderTime;
    Stopwatch frameStopwatch;
    Stopwatch renderStopwatch;

    while (!quitRequested_)
	{
        ProcessEvents();

        frameStopwatch.Stop();
        const float lastFrameTime = frameStopwatch.GetElapsedTime<std::milli>();
        frameStopwatch.Restart();

        printf("Frametime: %.4f [ms] \n", lastFrameTime);

        accelerator += lastFrameTime;
        while (accelerator > timePerFrame_)
        {
            accelerator -= timePerFrame_;

            ProcessEvents();

            Update(timePerFrame_);

            lastUpdateTime = Time::Now();
        }

        renderStopwatch.Restart();

        Render();
        lastRenderTime = Time::Now();
        renderStopwatch.Stop();

        const double renderTime = renderStopwatch.GetElapsedTime<std::milli>();

        while (Time::ElapsedFrom<std::milli>(lastRenderTime) < timePerFrame_ - renderTime
               && Time::ElapsedFrom<std::milli>(lastUpdateTime) < timePerFrame_)
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

    timePerFrame_ = (1.f / 60.f) * 1000.f;
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