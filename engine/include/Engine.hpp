#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include "Rendering/RenderWindow.hpp"

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

		std::unique_ptr<RenderWindow> window_;
	};
}

#endif // !ENGINE_HPP