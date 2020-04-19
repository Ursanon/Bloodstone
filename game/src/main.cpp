#include <cstdio>

#include "SDL.h"

extern "C"
int main(int argc, char* argv[])
{
    printf("hello!");
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Quit();
    return 0;
}