#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <memory>
#include <string>
#include "Resources/Scene.hpp"

namespace bs
{
	class ResourceManager sealed
	{
	public:
		ResourceManager();

		void PreloadAssets();

		std::unique_ptr<Scene> LoadScene();

	private:

		// TODO: #3
		std::map<int, std::string> assetsToLoad_;
		std::map<int, std::unique_ptr<sf::Sprite>> sprites_;
		std::map<int, std::unique_ptr<sf::Texture>> textures_;
	};
}

#endif // !RESOURCE_MANAGER_HPP