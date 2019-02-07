#include <actors/Character.hh>

#include <screen/Renderer.hh>

Character::Character(std::string filename, int maxVerticalSprites, int maxHorizontalSprites) :
    m_animationPhase(0),
    m_animationDirection(0),
    m_maxVerticalSprite(maxVerticalSprites),
    m_maxHorizontalSprite(maxHorizontalSprites)
{
    m_texture = new Texture();
    m_texture->loadFromFile(filename, screen::Renderer::getInstance()->getRenderer());

    m_spriteClips = new SDL_Rect[m_maxVerticalSprite * m_maxHorizontalSprite];

    int horizontalSteps = m_texture->getWidth() / m_maxHorizontalSprite;
    int verticalSteps = m_texture->getHeight() / m_maxVerticalSprite;
    for (int i = 0; i < m_maxHorizontalSprite; ++i)
    {
        for (int j = 0; j < m_maxVerticalSprite; ++j)
        {
            m_spriteClips[ i + j*m_maxVerticalSprite ].x = i*horizontalSteps;
            m_spriteClips[ i + j*m_maxVerticalSprite ].y = j*verticalSteps;
            m_spriteClips[ i + j*m_maxVerticalSprite ].w = m_texture->getWidth() / m_maxHorizontalSprite;
            m_spriteClips[ i + j*m_maxVerticalSprite ].h = m_texture->getHeight() / m_maxVerticalSprite;
        }
    }
}

/*
Main:
Load Character
    |
    \
     --> Load Texture
Display -> show scene
    |
    \
     --> render texture of characters
*/