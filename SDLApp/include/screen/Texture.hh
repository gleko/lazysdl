#pragma once

#include <system/Base.hh>

#include <string>

class Texture
{
public:
    Texture();
    ~Texture();
    bool loadFromFile(std::string, SDL_Renderer*);
    void free();
    void render(SDL_Renderer*, int, int);

    int getWidth();
    int getHeight();
private:
    SDL_Texture* m_texture;
    int m_width;
    int m_height;
};