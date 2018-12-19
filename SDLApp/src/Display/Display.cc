#include <screen/Display.hh>
#include <input/Keys.hh>

#include <assert.h>
#include <sstream>

namespace screen {

Display::Display()
{
    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(2);
    }

    m_screenSurface = SDL_GetWindowSurface(m_window);
}

Display::~Display()
{
    SDL_FreeSurface(m_screenSurface);
    SDL_DestroyWindow(m_window);

    m_screenSurface = nullptr;
    m_window = nullptr;
}

SDL_Surface* Display::loadSurface(std::string mediaPath)
{
    printf("Display::loadMedia: %s\n", mediaPath.c_str());
    SDL_Surface* optimizedSurface = nullptr;
    SDL_Surface* loadedSurface = SDL_LoadBMP(mediaPath.c_str());
    if (loadedSurface == nullptr)
    {
        printf("Error, image not found: %s\n", mediaPath.c_str());
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface(loadedSurface, m_screenSurface->format, NULL);
        SDL_FreeSurface(loadedSurface);
    }
    return optimizedSurface;
}

bool Display::loadMedia()
{
    for (int i = KeyPressSurfaces::KEY_PRESS_SURFACE_DEFAULT;
         i < KeyPressSurfaces::KEY_PRESS_SURFACE_TOTAL;
         i++)
    {
        std::stringstream ss;
        ss << i << ".bmp";
        m_medias.push_back(loadSurface(ss.str()));
    }
}

bool Display::updateWindow()
{
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;
    SDL_BlitScaled(m_medias[m_currentSurface], NULL, m_screenSurface, &stretchRect);
    SDL_UpdateWindowSurface(m_window);
}

void Display::setCurrentSurface(int surface)
{
    m_currentSurface = surface;
}

}
