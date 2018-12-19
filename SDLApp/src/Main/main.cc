#include <screen/Display.hh>

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

int main(int argc, char *args[])
{
	//The window we'll be rendering to
	SDL_Window *gWindow = nullptr;

	//The surface contained by the window
	SDL_Surface *gScreenSurface = nullptr;
	SDL_Surface *gHelloWorld = nullptr;

	bool quit = false;
	SDL_Event e;

	screen::Display* display = new screen::Display();

	if (display->loadMedia("hello_world.bmp"))
	{
		while(!quit)
		{
			display->updateWindow();
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
		}
	}

	return 0;
}