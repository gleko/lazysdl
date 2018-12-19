#include <input/Keys.hh>
#include <screen/Display.hh>

#include <stdio.h>

int main(int argc, char *args[])
{
	bool quit = false;
	SDL_Event e;

	screen::Display* display = new screen::Display();

	if (display->loadTextures())
	{
		while(!quit)
		{
			display->renderGeometry();
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch( e.key.keysym.sym )
					{
						case SDLK_UP:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_UP);
							break;
						case SDLK_DOWN:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN);
							break;
						case SDLK_LEFT:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_LEFT);
							break;
						case SDLK_RIGHT:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_RIGHT);
							break;
						case SDLK_ESCAPE:
							return 0;
						default:
							break;
					}
				}
				else if (e.type == SDL_KEYUP)
				{
					display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_DEFAULT);
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