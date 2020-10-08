#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <SFML\Graphics\Transformable.hpp>

#include "Core/Math/Vec2.hpp"
#include "Components/Component.hpp"

namespace bs
{
	class Transform
		: public Component
	{
	public:
		Transform(GameEntity* entity);

		Vec2f GetPosition() const;

		float GetRotation() const;

		void SetPosition(const Vec2f& position);

		void SetRotation(const float& rotation);

		virtual void Update(const float& deltaTime) override;

	private:
		float rotation_;
		Vec2f position_;
	};
}

#endif // !TRANSFORM_HPP