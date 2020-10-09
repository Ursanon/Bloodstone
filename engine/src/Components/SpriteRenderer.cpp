#include "Components/SpriteRenderer.hpp"
#include "Components/GameEntity.hpp"

bs::SpriteRenderer::SpriteRenderer(GameEntity* entity, Sprite* sprite)
	: IDrawableComponent(entity)
	, sprite_(sprite)
	, entity_(entity)
	, vertices_(sf::PrimitiveType::TriangleStrip, 4)
{
	const auto rect = sprite_->GetRect();

	const auto top = static_cast<float>(rect.X);
	const auto left = static_cast<float>(rect.Y);
	const auto width = static_cast<float>(rect.Width);
	const auto height = static_cast<float>(rect.Height);

	const auto right = left + width;
	const auto bottom = top + height;

	vertices_[0].position = sf::Vector2f(0, 0);
	vertices_[1].position = sf::Vector2f(0, height);
	vertices_[2].position = sf::Vector2f(width, 0);
	vertices_[3].position = sf::Vector2f(width, height);

	vertices_[0].texCoords = sf::Vector2f(left, top);
	vertices_[1].texCoords = sf::Vector2f(left, bottom);
	vertices_[2].texCoords = sf::Vector2f(right, top);
	vertices_[3].texCoords = sf::Vector2f(right, bottom);

	const auto transform = entity_->GetTransform();
	
	const auto origin = bs::Vec2f(width /2.f, height / 2.f);
	transform->SetOrigin(origin);
}

void bs::SpriteRenderer::Update(const float& deltaTime)
{
}

void bs::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const auto transform = entity_->GetTransform();
	const auto position = transform->GetPosition();
	const auto rotation = transform->GetRotation();

	const auto scale = transform->GetScale();
	const auto origin = transform->GetOrigin();

	const auto angle = -rotation;
	const auto cosine = static_cast<float>(std::cos(angle));
	const auto sine = static_cast<float>(std::sin(angle));
	const auto sxc = scale.X * cosine;
	const auto syc = scale.Y * cosine;
	const auto sxs = scale.X * sine;
	const auto sys = scale.Y * sine;
	const auto tx = -origin.X * sxc - origin.Y * sys + position.X;
	const auto ty = origin.X * sxs - origin.Y * syc + position.Y;

	states.transform *= sf::Transform(sxc, sys, tx, -sxs, syc, ty, 0.f, 0.f, 1.f);
	states.texture = sprite_->GetTexture();

	target.draw(vertices_, states);
}