#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "EngineConfiguration.hpp"
#include "Resources/Scene.hpp"
#include "Resources/ResourceManager.hpp"

namespace bs
{
	class Engine
	{
	public:
		Engine();

		void Run();

	private:
		void LoadConfig();

		void InitializeWindow();

		void ProcessEvents();
		void Update(const float& deltaTime);
		void Render();

	private:
		bool quitRequested_;

		float timePerFrame_;

		EngineConfiguration config_;

		std::unique_ptr<Scene> scene_;
		std::unique_ptr<sf::RenderWindow> window_;
		std::unique_ptr<ResourceManager> resources_;
	};
}

#endif // !ENGINE_HPP