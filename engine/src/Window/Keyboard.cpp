#include "Window/Keyboard.hpp"

#include "SDL.h"

bool bs::Keyboard::isKeyPressed(const Key& key)
{
	const Uint8 keyNum = (Uint8)key;
	auto* keyboardState = SDL_GetKeyboardState(nullptr);
	
	return keyboardState[keyNum];
}