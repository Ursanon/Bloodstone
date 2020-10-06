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
	auto transform = entity_->GetTransform();
	auto position = transform->GetPosition();

	states.texture = sprite_->getTexture();

	sf::VertexArray vertices(sf::TriangleStrip, 4);

	vertices[0].position = sf::Vector2f(position.X, position.Y);
	vertices[1].position = sf::Vector2f(position.X, position.Y + rect.height);
	vertices[2].position = sf::Vector2f(position.X + rect.width, position.Y);
	vertices[3].position = sf::Vector2f(position.X + rect.width, position.Y + rect.height);

	float left = static_cast<float>(rect.left);
	float right = left + rect.width;
	float top = static_cast<float>(rect.top);
	float bottom = top + rect.height;

	vertices[0].texCoords = sf::Vector2f(left, top);
	vertices[1].texCoords = sf::Vector2f(left, bottom);
	vertices[2].texCoords = sf::Vector2f(right, top);
	vertices[3].texCoords = sf::Vector2f(right, bottom);

	target.draw(vertices, states);
	/*
	auto transform = entity_->GetTransform();
	auto pos = transform->GetPosition();
	sprite_->setPosition(pos.X, pos.Y);

	auto rot = transform->GetRotation();

	sprite_->setRotation(rot);

	target.draw(*sprite_, states);
	*/
}