#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

bool init(SDL_Window *&window, SDL_Surface *&screenSurface)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL initialize error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}

	return success;
}

bool loadMedia(SDL_Surface *&helloWorld)
{
	bool success = true;

	helloWorld = SDL_LoadBMP("hello_world.bmp");
	if (helloWorld == nullptr)
	{
		printf("Unable to load image! %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void close(SDL_Window *&window, SDL_Surface *&screenSurface, SDL_Surface *&helloWorld)
{
	SDL_FreeSurface(helloWorld);
	SDL_FreeSurface(screenSurface);
	helloWorld = nullptr;
	screenSurface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}

int main(int argc, char *args[])
{
	//The window we'll be rendering to
	SDL_Window *gWindow = nullptr;

	//The surface contained by the window
	SDL_Surface *gScreenSurface = nullptr;
	SDL_Surface *gHelloWorld = nullptr;

	bool quit = false;
	SDL_Event e;

	//Initialize SDL
	if (!init(gWindow, gScreenSurface))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!loadMedia(gHelloWorld))
		{
			printf("Unable to load media\n");
		}
		else
		{
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	close(gWindow, gScreenSurface, gHelloWorld);

	return 0;
}