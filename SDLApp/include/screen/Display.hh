#pragma once

#include <screen/Constants.hh>
#include <screen/Texture.hh>

#include <string>
#include <vector>

namespace screen {

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
    bool loadColorKeyedTextures();
    bool loadSprites();
    
    bool updateWindow();
    bool renderTexture();
    bool renderGeometry();
    bool renderViewPortTopLeft();
    bool renderViewPortTopRight();
    bool renderViewPortBottom();
    bool renderColorKeyedTexture();
    bool renderSpriteSheetTexture();
    bool renderSpriteSheetTexture(Uint8 red, Uint8 green, Uint8 blue);

    void setCurrentSurface(int);
private:
    SDL_Window* m_window;
    SDL_Surface* m_screenSurface;
    std::vector<SDL_Surface*> m_medias;
    std::vector<Texture*> m_textures;
    Texture fooTexture;
    Texture backgroundTexture;
    SDL_Rect m_spriteClips[4];
    Texture m_spriteSheetTexture;
    SDL_Renderer* m_renderer;
    int m_currentSurface;
    int m_imgFlags;
};

} //namespace screen
