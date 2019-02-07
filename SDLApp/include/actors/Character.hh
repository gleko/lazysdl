#pragma once

#include <screen/Texture.hh>

class Character
{
public:
    Character(std::string, int, int);
    ~Character() = default;
private:
    int m_animationPhase;
    int m_animationDirection;
    int m_maxVerticalSprite;
    int m_maxHorizontalSprite;
    Texture* m_texture;
    SDL_Rect m_spriteClips[];
};
