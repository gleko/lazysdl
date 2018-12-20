#include <screen/Texture.hh>

Texture::Texture() :
    m_texture(nullptr),
    m_width(0),
    m_height(0)
{}

Texture::~Texture()
{
    free();
}

bool Texture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
    free();
    SDL_Texture* newTexture;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (!loadedSurface)
    {
        printf("Unable to load image: %s, SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (!newTexture)
        {
            printf("Unable to create texture from %s, SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            m_width = loadedSurface->w;
            m_height = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }

    m_texture = newTexture;
    return m_texture != nullptr;
}

void Texture::free()
{
    if (m_texture)
    {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
        m_width = 0;
        m_height = 0;
    }
}

void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = nullptr)
{
    SDL_Rect renderQuad = {x, y, m_width, m_height};

    if (clip)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy(renderer, m_texture, clip, &renderQuad);
}

void Texture::setColorModulation(Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetTextureColorMod(m_texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(m_texture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(m_texture, alpha);
}

int Texture::getHeight()
{
    return m_height;
}

int Texture::getWidth()
{
    return m_width;
}
