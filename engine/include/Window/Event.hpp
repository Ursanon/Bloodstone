#ifndef EVENT_HPP
#define EVENT_HPP

#include "Window/Keyboard.hpp"

namespace bs
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

	struct Event
	{
		EventType Type;

		union
		{
			KeyEvent Key;
		};
	};
}

#endif // !EVENT_HPP