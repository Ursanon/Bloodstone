#ifndef ENGINE_CONFIGURATION_HPP
#define ENGINE_CONFIGURATION_HPP

#include <string>
#include "Core/Math/Vec2.hpp"

namespace bs
{
	struct EngineConfiguration
	{
	public:
		float TargetFPS;
		std::string Name;
		Resolution Resolution;
	};
}

#endif // !ENGINE_CONFIGURATION_HPP