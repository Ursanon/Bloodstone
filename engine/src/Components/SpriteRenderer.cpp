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
	auto transform = entity_->GetTransform();
	auto pos = transform->GetPosition();
	sprite_->setPosition(pos.X, pos.Y);

	auto rot = transform->GetRotation();

	sprite_->setRotation(rot);

	target.draw(*sprite_, states);
}