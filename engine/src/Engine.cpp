#include "Engine.hpp"

#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <exception>
#include "Core/JsonUtility.hpp"
#include "Core/Time/Stopwatch.hpp"

using json = nlohmann::json;

bs::Engine::Engine()
	: quitRequested_(false)
{
}

void bs::Engine::Run()
{
    LoadConfig();
    InitializeWindow();

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

            lastUpdateTime = time::Now();
        }

        renderStopwatch.Restart();
        Render();
        lastRenderTime = time::Now();
        renderStopwatch.Stop();

        const double renderTime = renderStopwatch.GetElapsedTime<std::milli>();

        while (time::ElapsedFrom<std::milli>(lastRenderTime) < timePerFrame_ - renderTime
               && time::ElapsedFrom<std::milli>(lastUpdateTime) < timePerFrame_ - renderTime)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(0));
        }
	}
}

void bs::Engine::LoadConfig()
{
    std::ifstream stream;
    stream.open("Assets/config.json");

    if (!stream.is_open())
    {
        throw std::exception("Cannot load config file!");
    }

    json json;
    stream >> json;
    stream.close();

    config_ = json.get<EngineConfiguration>();
}

void bs::Engine::InitializeWindow()
{
    const WindowMode mode = WindowMode::Windowed;
    window_ = std::make_unique<RenderWindow>(config_.Name, config_.Resolution, mode);

    auto target = static_cast<IRenderTarget*>(window_.get());
    resources_ = std::make_unique<ResourceManager>(*target);
    resources_->PreloadAssets();

    scene_ = std::move(resources_->LoadScene());

    timePerFrame_ = (1.f / config_.TargetFPS) * 1000.f;
}

void bs::Engine::ProcessEvents()
{
    Event event;

    while (window_->PoolEvents(event))
    {
        switch (event.Type)
        {
        case EventType::WindowClose:
            quitRequested_ = true;
            break;
        case EventType::KeyReleased:
            quitRequested_ = event.Key.Code == Keyboard::Key::Escape;
            break;
        }
    }
}

void bs::Engine::Update(const float& deltaMilliseconds)
{
    auto deltaSeconds = deltaMilliseconds / 1000;

    auto& entities = scene_->GetEntities();
    for (auto&& entity : entities)
    {
        entity->Update(deltaSeconds);
    }
}

void bs::Engine::Render()
{
    auto clearColor = Color(0.15f, 0.15f, 0.8f);
    window_->Clear(clearColor);

    auto& entities = scene_->GetEntities();
	for (auto&& entity : entities)
	{
		auto drawables = entity->GetDrawableComponents();
		for (auto&& drawable : drawables)
		{
			drawable->Draw(*window_);
		}
	}

    window_->Display();
}