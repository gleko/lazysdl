#include <actors/Character.hh>

Character::Character(std::string filename) :
    m_animationPhase(0)
{
    m_texture = new Texture();
    m_texture->loadFromFile(filename, getMeARenderer);
}