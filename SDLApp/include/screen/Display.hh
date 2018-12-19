#pragma once

#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>
#include <vector>

namespace screen {

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Display
{
public:
    Display();
    ~Display();

    SDL_Surface* loadSurface(std::string);
    SDL_Texture* loadTexture(std::string);
    
    bool loadMedia();
    bool loadTextures();
    bool loadGeometry();
    
    bool updateWindow();
    bool renderTexture();
    bool renderGeometry();
    void setCurrentSurface(int);
private:
    SDL_Window* m_window;
    SDL_Surface* m_screenSurface;
    std::vector<SDL_Surface*> m_medias;
    std::vector<SDL_Texture*> m_textures;
    //SDL_Texture* m_texture;
    SDL_Renderer* m_renderer;
    int m_currentSurface;
    int m_imgFlags;
};

} //namespace screen
