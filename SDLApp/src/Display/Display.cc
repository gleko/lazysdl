#include <screen/Display.hh>

#include <assert.h>

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

bool Display::loadMedia(std::string mediaPath)
{
    m_media = SDL_LoadBMP(mediaPath.c_str());

    if (m_media == nullptr)
    {
        return false;
    }
    return true;
}

bool Display::updateWindow()
{
    SDL_BlitSurface(m_media, NULL, m_screenSurface, NULL);
    SDL_UpdateWindowSurface(m_window);
}

}
