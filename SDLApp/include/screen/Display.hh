#pragma once

#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>

namespace screen {

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Display
{
public:
    Display();
    ~Display();
    bool loadMedia(std::string);
    bool updateWindow();
private:
    SDL_Window* m_window;
    SDL_Surface* m_screenSurface;
    SDL_Surface* m_media;
};

} //namespace screen
