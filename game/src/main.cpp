#include <cstdio>
#include <string>

#include "SDL.h"

extern "C"
int main(int argc, char* argv[])
{
    printf("hello!");
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Hello!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    char* base_path = SDL_GetBasePath();

    std::string image_path = std::string(base_path) + "Assets/Textures/player.bmp";
    SDL_Surface* player_surf = SDL_LoadBMP(image_path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, player_surf);
    SDL_free(player_surf);

    SDL_Event event;
    bool isQuitRequested = false;

    while (!isQuitRequested)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isQuitRequested = true;
                break;
            case SDLK_ESCAPE:
                isQuitRequested = true;
                break;
            default:
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }

    SDL_free(base_path);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}