#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include "Rendering/RenderWindow.hpp"
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

		void ProcessEvents();

		void Render();

		void Update(float deltaTime);

	private:
		bool quitRequested_;

		float timePerFrame_;

		std::unique_ptr<Scene> scene_;
		std::unique_ptr<RenderWindow> window_;
		std::unique_ptr<ResourceManager> resources_;
	};
}

#endif // !ENGINE_HPP