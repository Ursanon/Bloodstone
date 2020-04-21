#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <memory>
#include <string>
#include "SDL.h"
#include "Rendering/Texture.hpp"

namespace bs
{
	class ResourceManager sealed
	{
	public:
		explicit ResourceManager(IRenderTarget& context);

		void PreloadAssets();

	private:
		IRenderTarget& const context_;

		// TODO: #3
		std::map<int, std::string> assetsToLoad_;
		std::map<int, std::unique_ptr<Texture>> textures_;
	};
}

#endif // !RESOURCE_MANAGER_HPP