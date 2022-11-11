#include "CEntity.h"

CEntity::CEntity()
    : m_sprite(*g_spriteList["ERROR"])
{}

CEntity::CEntity(const std::string& sName, const CSprite& sprite)
    : m_sName(sName), m_sprite(sprite)
{}

void CEntity::setName(const std::string& sName)
{
    m_sName = sName;
}

void CEntity::setHealth(float fHealth)
{
    m_fHealth = fHealth;
}

void CEntity::setArmor(float fArmor)
{
    m_fArmor = fArmor;
}

void CEntity::setSpeed(float fSpeed)
{
    m_fSpeed = fSpeed;
}

void CEntity::setSprite(const CSprite& sprite)
{
    m_sprite = sprite;
}

std::string CEntity::getName() const
{
    return m_sName;
}

float CEntity::getHealth() const
{
    return m_fHealth;
}

float CEntity::getArmor() const
{
    return m_fArmor;
}

float CEntity::getSpeed() const
{
    return m_fSpeed;
}

CSprite CEntity::getSprite() const
{
    return m_sprite;
}

void CEntity::updateState()
{
    m_sprite.setPosition(m_position.x, m_position.y);
}

void CEntity::draw(sf::RenderWindow& m_window) const
{
    m_window.draw(m_sprite);
}

void CEntity::setPosition(float fX, float fY)
{
    m_sprite.setPosition(fX, fY);
}

void CEntity::movePosition(const moveSide& direction)
{
    switch (direction)
    {
        case moveSide::up:
            m_position.y -= m_fSpeed;
            break;
        case moveSide::down:
            m_position.y += m_fSpeed;
            break;
        case moveSide::left:
            m_position.x -= m_fSpeed;
            break;
        case moveSide::right:
            m_position.x += m_fSpeed;
            break;
        default:
            throw "Unknown move type!";
    }
}