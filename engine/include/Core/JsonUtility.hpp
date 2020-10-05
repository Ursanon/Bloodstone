#ifndef JSON_UTILITY_HPP
#define JSON_UTILITY_HPP

#include "ThirdParty/json.hpp"
#include "EngineConfiguration.hpp"
#include "Graphics/TextureMeta.hpp"

namespace bs
{
	template <typename T>
	void from_json(const nlohmann::json& json, sf::Rect<T>& rect)
	{
		json.at("X").get_to(rect.left);
		json.at("Y").get_to(rect.top);
		json.at("Width").get_to(rect.width);
		json.at("Height").get_to(rect.height);
	}

	template <typename T>
	void from_json(const nlohmann::json& json, Vec2<T>& resolution)
	{
		json.at("X").get_to(resolution.X);
		json.at("Y").get_to(resolution.Y);
	}

	inline void from_json(const nlohmann::json& json, bs::MyIntRect& rect)
	{
		json.at("X").get_to(rect.X);
		json.at("Y").get_to(rect.Y);
		json.at("Width").get_to(rect.Width);
		json.at("Height").get_to(rect.Height);
	}

	inline void from_json(const nlohmann::json& json, EngineConfiguration& config)
	{
		json.at("Name").get_to(config.Name);
		json.at("TargetFPS").get_to(config.TargetFPS);
		json.at("Resolution").get_to(config.Resolution);
	}

	inline void from_json(const nlohmann::json& json, SpriteMeta& meta)
	{
		json.at("Id").get_to(meta.Id);
		json.at("Rect").get_to(meta.Rect);
	}

	inline void from_json(const nlohmann::json& json, TextureMeta& meta)
	{
		json.at("Id").get_to(meta.Id);
		json.at("Sprites").get_to(meta.Sprites);
	}
}

#endif // !JSON_UTILITY_HPP