#include "SDL2\SDL.h"
#include <cassert>
#include <iostream>
#include "Engine.h"


static SDL_Window* Window;
static SDL_Renderer* Renderer;

static bool IsOpen = false;


void engineInitialization()
{
	SDL_Init(SDL_INIT_VIDEO);
	Window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	if (!Renderer)
	{
		std::cout << SDL_Error << std::endl;
	}

	IsOpen = true;

}

void engineUpdate()
{
	SDL_RenderPresent(Renderer);
	engineClear();

	//delay ?
}

void engineClose()
{
	IsOpen = false;
}

void engineDestroy()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);

	Renderer = nullptr;
	Window = nullptr;

	SDL_Quit();
}

void engineClear()
{
	SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(Renderer);
}
