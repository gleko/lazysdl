#include <screen/Renderer.hh>

#include <screen/Constants.hh>
#include <system/ErrorCodes.hh>

namespace screen
{

Renderer::Renderer()
{
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
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(m_window);
}

Renderer* Renderer::getInstance()
{
    static Renderer* instance;

    if (instance == 0)
    {
        instance = new Renderer();
    }

    return instance;
}

SDL_Renderer* Renderer::getRenderer()
{
    return m_renderer;
}

}