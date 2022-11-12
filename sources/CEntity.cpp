#include "CEntity.h"

CEntity::CEntity(const std::string& sName, const CSprite& sprite)
    : m_sName(sName), m_sprite(sprite)
{}

CEntity::CEntity(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position)
    : m_sName(sName), m_sprite(sprite), m_position(position)
{}

std::string CEntity::getName() const
{
    return m_sName;
}

void CEntity::setName(const std::string& sName)
{
    m_sName = sName;
}

CSprite CEntity::getSprite() const
{
    return m_sprite;
}

void CEntity::setSprite(const CSprite& sprite)
{
    m_sprite = sprite;
}


sf::Vector2f CEntity::getPosition() const
{
    return m_position;
}

void CEntity::setPosition(float fX, float fY)
{
    m_sprite.setPosition(fX, fY);
}

void CEntity::updateState()
{
    m_sprite.setPosition(m_position.x, m_position.y);
}

void CEntity::draw(sf::RenderWindow& m_window) const
{
    m_window.draw(m_sprite);
}