#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

namespace bs
{
	class Window
	{
	public:
		Window(std::string name, WindowMode mode = WindowMode::Windowed, );

		virtual ~Window();
	};

	enum class WindowMode
	{
		Windowed = 0
	};
}

#endif // !WINDOW_HPP