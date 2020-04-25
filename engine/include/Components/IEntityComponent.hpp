#ifndef IENTITY_COMPONENT_HPP
#define IENTITY_COMPONENT_HPP

namespace bs
{
	class IEntityComponent
	{
	public:
		virtual void Update(const float& deltaTime) = 0;
	};
}

#endif // !IENTITY_COMPONENT_HPP