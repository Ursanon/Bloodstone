#include "Components/SpriteRenderer.hpp"
#include "Components/GameEntity.hpp"

bs::SpriteRenderer::SpriteRenderer(GameEntity* entity, sf::Sprite* sprite)
	: IDrawableComponent(entity)
	, sprite_(sprite)
	, entity_(entity)
{
}

void bs::SpriteRenderer::Update(const float& deltaTime)
{
}

void bs::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	auto rect = sprite_->getTextureRect();
	auto entityTransform = entity_->GetTransform();
	auto position = entityTransform->GetPosition();
	auto rotation = entityTransform->GetRotation();

	sf::VertexArray vertices(sf::TriangleStrip, 4);
	sf::Transform transform;

	auto origin = sf::Vector2f(rect.width, rect.height) / 2.f;
	auto scale = sf::Vector2f(1.f, 1.f);

	float angle = -rotation * 3.141592654f / 180.f;
	float cosine = static_cast<float>(std::cos(angle));
	float sine = static_cast<float>(std::sin(angle));
	float sxc = scale.x * cosine;
	float syc = scale.y * cosine;
	float sxs = scale.x * sine;
	float sys = scale.y * sine;
	float tx = -origin.x * sxc - origin.y * sys + position.X;
	float ty = origin.x * sxs - origin.y * syc + position.Y;

	transform = sf::Transform(sxc, sys, tx, -sxs, syc, ty, 0.f, 0.f, 1.f);
	vertices[0].position = sf::Vector2f(0, 0);
	vertices[1].position = sf::Vector2f(0, rect.height);
	vertices[2].position = sf::Vector2f(rect.width, 0);
	vertices[3].position = sf::Vector2f(rect.width, rect.height);

	auto left = static_cast<float>(rect.left);
	auto right = left + rect.width;
	auto top = static_cast<float>(rect.top);
	auto bottom = top + rect.height;

	vertices[0].texCoords = sf::Vector2f(left, top);
	vertices[1].texCoords = sf::Vector2f(left, bottom);
	vertices[2].texCoords = sf::Vector2f(right, top);
	vertices[3].texCoords = sf::Vector2f(right, bottom);

	states.transform *= transform;
	states.texture = sprite_->getTexture();

	target.draw(vertices, states);
}