#include "Components/GameEntity.hpp"

#include <cstdio>

bs::GameEntity::GameEntity(int id)
	: Component(this)
	, id_(id)
{
	transform_ = std::make_shared<Transform>(this);

	components_.push_back(transform_);
}

bs::GameEntity::~GameEntity()
{
	printf("\nDestroying entity: { %d }", id_);
}

int bs::GameEntity::GetId() const
{
	return id_;
}

bs::Transform* bs::GameEntity::GetTransform()
{
	return transform_.get();
}

void bs::GameEntity::Update(const float& deltaTime)
{
	printf("Updating %d", id_);

	for (auto&& component : components_)
	{
		component->Update(deltaTime);
	}
}

const std::vector<std::shared_ptr<bs::IDrawableComponent>> bs::GameEntity::GetDrawableComponents()
{
	std::vector<std::shared_ptr<bs::IDrawableComponent>> drawables;

	for (auto&& component : components_)
	{
		auto drawable = std::dynamic_pointer_cast<IDrawableComponent>(component);

		if (drawable)
		{
			drawables.push_back(drawable);
		}
	}

	return drawables;
}

void bs::GameEntity::AddComponent(std::shared_ptr<IEntityComponent>& component)
{
	components_.push_back(component);
}