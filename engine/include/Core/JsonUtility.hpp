#ifndef JSON_UTILITY_HPP
#define JSON_UTILITY_HPP

#include "ThirdParty/json.hpp"
#include "EngineConfiguration.hpp"

namespace bs
{
	template <typename T>
	void from_json(const nlohmann::json& json, Vec2<T>& resolution)
	{
		json.at("X").get_to(resolution.X);
		json.at("Y").get_to(resolution.Y);
	}

	void from_json(const nlohmann::json& json, EngineConfiguration& config)
	{
		json.at("Name").get_to(config.Name);
		json.at("TargetFPS").get_to(config.TargetFPS);
		json.at("Resolution").get_to(config.Resolution);
	}
}

#endif //!JSON_UTILITY_HPP