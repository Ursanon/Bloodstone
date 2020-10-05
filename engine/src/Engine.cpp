
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
        renderStopwatch.Stop();
        lastRenderTime = time::Now();

        const double renderTime = renderStopwatch.GetElapsedTime<std::milli>();

        while (time::ElapsedFrom<std::milli>(lastRenderTime) < timePerFrame_ - renderTime
               && time::ElapsedFrom<std::milli>(lastUpdateTime) < timePerFrame_ - renderTime)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(0));
        }
	}

    window_->close();
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
    auto context = sf::ContextSettings();
    context.antialiasingLevel = 2;

    window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(config_.Resolution.X, config_.Resolution.Y), config_.Name, 7U, context);

    resources_ = std::make_unique<ResourceManager>();
    resources_->PreloadAssets();

    scene_ = std::move(resources_->LoadScene());

    timePerFrame_ = (1.f / config_.TargetFPS) * 1000.f;
}

void bs::Engine::ProcessEvents()
{
    sf::Event event;

    while (window_->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            quitRequested_ = true;
            break;
        case sf::Event::KeyReleased:
            quitRequested_ = event.key.code == sf::Keyboard::Escape;
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
    auto clearColor = sf::Color(38, 38, 204);

    window_->clear(clearColor);

    auto& entities = scene_->GetEntities();
	for (auto&& entity : entities)
	{
		auto drawables = entity->GetDrawableComponents();
		for (std::shared_ptr<sf::Drawable>&& drawable : drawables)
		{
            window_->draw(*drawable);
		}
	}

    window_->display();
}