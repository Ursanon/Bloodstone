#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Core/Math/Vec2.hpp"
#include "Components/Component.hpp"

namespace bs
{
	class Transform
		: public Component
	{
	public:
		Transform(GameEntity* entity);

		const Vec2f& GetPosition();
		const float& GetRotation();

		void SetPosition(const Vec2f& position);
		void SetRotation(const float& rotation);

		virtual void Update(const float& deltaTime) override;

	private:
		Vec2f position_;
		float rotation_;
	};
}

#endif // !TRANSFORM_HPP