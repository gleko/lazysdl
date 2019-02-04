#pragma once

#include <screen/Texture.hh>

class Character
{
public:
    Character(std::string);
    ~Character() = default;
private:
    int m_animationPhase;
    Texture* m_texture;
};
