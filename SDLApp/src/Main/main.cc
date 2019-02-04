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
	Uint8 a = 255;

	screen::Display* display = new screen::Display();

	if (display->loadBlendedTextures())
	{
		while(!quit)
		{
			display->renderBlendedTextures(a);

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
							if (r+5 > 255) { r = 255; } else { r += 5; }
							if (a+5 > 255) { a = 255; } else { a += 5; }
							break;
						case SDLK_DOWN:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN);
							if (r-5 < 0) { r = 0; } else { r -= 5; }
							if (a-5 < 0) { a = 0; } else { a -= 5; }
							break;
						case SDLK_LEFT:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_LEFT);
							if (g-5 < 0) { g = 0; } else { g -= 5; }
							break;
						case SDLK_RIGHT:
							display->setCurrentSurface(KeyPressSurfaces::KEY_PRESS_SURFACE_RIGHT);
							if (g+5 > 255) { g = 255; } else { g += 5; }
							break;
						case SDLK_m:
							if (b+5 > 255) { b = 255; } else { b += 5; }
							break;
						case SDLK_n:
							if (b-5 < 0) { b = 0; } else { b -= 5; }
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
		printf("Unable to load textures!\n");
		exit(ErrorCode::TEXTURE_LOAD_FAILED);
	}

	return ErrorCode::OK;
}