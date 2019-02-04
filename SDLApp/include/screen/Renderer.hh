#pragma once

#include <system/Base.hh>

namespace screen {

class Renderer
{
public:
    Renderer();
    ~Renderer();
    static Renderer* getInstance();
    SDL_Renderer* getRenderer();
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};

}