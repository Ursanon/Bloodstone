#ifndef EVENT_HPP
#define EVENT_HPP

#include "Window/Keyboard.hpp"

namespace bs
{
	struct Event
	{
		enum class EventType
		{
			WindowClose,
			KeyPressed,
			KeyReleased,
		};

		struct KeyEvent
		{
			Keyboard::Key Code;
		};

		EventType Type;

		union
		{
			KeyEvent Key;
		};
	};
}

#endif // !EVENT_HPP