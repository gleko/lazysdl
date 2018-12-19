#include <screen/Display.hh>

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
	bool quit = false;
	SDL_Event e;

	screen::Display* display = new screen::Display();

	if (display->loadMedia("press.bmp"))
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
	else
	{
		printf("Ajjajjaj!\n");
	}

	return 0;
}