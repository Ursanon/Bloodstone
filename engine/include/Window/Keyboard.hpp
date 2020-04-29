#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

namespace bs
{
	class Keyboard
	{
	public:
		enum class Key
		{
			W = 26,
			S = 22,
			A = 4,
			D = 7,
			Escape = 41
		};

		static bool isKeyPressed(const Key& key);
	};
}

#endif // !KEYBOARD_HPP