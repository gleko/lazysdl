#include <screen/Display.hh>

#include <input/Keys.hh>
#include <system/ErrorCodes.hh>

#include <sstream>

namespace screen {

Display::Display()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init failed\n");
        exit(ErrorCode::INIT_FAILED);
    }
    m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(ErrorCode::CREATE_WINDOW_FAILED);
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer)
    {
        printf("Create renderer failed");
        exit(ErrorCode::CREATE_RENDERER_FAILED);
    }

    m_imgFlags = IMG_INIT_PNG;
    if (!IMG_Init(m_imgFlags) &&
        !m_imgFlags)
    {
        printf("IMG Flags problem: %s\n", SDL_GetError());
        exit(ErrorCode::INVALID_IMG_FLAGS);
    }
    //m_screenSurface = SDL_GetWindowSurface(m_window);
}

Display::~Display()
{
    SDL_FreeSurface(m_screenSurface);
    SDL_DestroyWindow(m_window);

    m_screenSurface = nullptr;
    m_window = nullptr;
    m_renderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}

SDL_Surface* Display::loadSurface(std::string mediaPath)
{
    printf("Display::loadSurface: %s\n", mediaPath.c_str());
    SDL_Surface* optimizedSurface = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(mediaPath.c_str());
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

SDL_Texture* Display::loadTexture(std::string texturePath)
{
    printf("Display::loadTexture: %s\n", texturePath.c_str());
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
    if (loadedSurface == nullptr)
    {
        printf("Error, texture not found: %s\n", texturePath.c_str());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

bool Display::loadMedia()
{
    for (int i = KeyPressSurfaces::KEY_PRESS_SURFACE_DEFAULT;
         i < KeyPressSurfaces::KEY_PRESS_SURFACE_TOTAL;
         i++)
    {
        std::stringstream ss;
        ss << i << ".png";
        m_medias.push_back(loadSurface(ss.str()));
        if (!m_medias[i])
        {
            return false;
        }
    }
    return true;
}

bool Display::loadTextures()
{
    for (int i = KeyPressSurfaces::KEY_PRESS_SURFACE_DEFAULT;
         i < KeyPressSurfaces::KEY_PRESS_SURFACE_TOTAL;
         i++)
    {
        std::stringstream ss;
        ss << i << ".png";
        m_textures.push_back(loadTexture(ss.str()));
        if (!m_textures[i])
        {
            return false;
        }
    }
    return true;
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

bool Display::renderTexture()
{
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_textures[m_currentSurface], NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Display::setCurrentSurface(int surface)
{
    m_currentSurface = surface;
}

}
