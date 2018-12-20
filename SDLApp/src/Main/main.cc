#include <input/Keys.hh>
#include <screen/Display.hh>
#include <system/ErrorCodes.hh>

#include <stdio.h>

int main(int argc, char *args[])
{
	bool quit = false;
	SDL_Event e;
	Uint8 r = 255;
	Uint8 g = 255;
	Uint8 b = 255;

	screen::Display* display = new screen::Display();

	if (display->loadSprites())
	{
		while(!quit)
		{
			display->renderSpriteSheetTexture(r, g, b);

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
							r += 5;
							break;
						case SDLK_DOWN:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN);
							r -= 5;
							break;
						case SDLK_LEFT:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_LEFT);
							g -= 5;
							break;
						case SDLK_RIGHT:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_RIGHT);
							g -= 5;
							break;
						case SDLK_m:
							b += 5;
							break;
						case SDLK_n:
							b -= 5;
							break;
						case SDLK_ESCAPE:
						case SDLK_q:
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
		exit(ErrorCode::TEXTURE_LOAD_FAILED);
	}

	return ErrorCode::OK;
}