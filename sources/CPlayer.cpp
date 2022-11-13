#include "CPlayer.h"

CPlayer::CPlayer(const std::string& sName, const CSprite& sprite)
    : CEntity(sName, sprite)
{}

CPlayer::CPlayer(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position)
    : CEntity(sName, sprite, position)
{}

void CPlayer::listenInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        setPosition(getPosition().x, getPosition().y - m_speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        setPosition(getPosition().x, getPosition().y + m_speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        setPosition(getPosition().x - m_speed, getPosition().y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        setPosition(getPosition().x + m_speed, getPosition().y);
    }
}

float CPlayer::getHealth() const
{
    return m_health;
}

void CPlayer::setHealth(float value)
{
    m_health = (value < 0 ? 0 : value);
}

float CPlayer::getMaxHealth() const
{
    return m_maxHealth;
}

void CPlayer::setMaxHealth(float value)
{
    m_maxHealth = (value < 0 ? 0 : value);

    if (m_health > m_maxHealth)
        m_health = m_maxHealth;
}

float CPlayer::getArmor() const
{
    return m_armor;
}

void CPlayer::setArmor(float value)
{
    m_armor = (value < 0 ? 0 : value);
}

float CPlayer::getMaxArmor() const
{
    return m_maxArmor;
}

void CPlayer::setMaxArmor(float value)
{
    m_maxArmor = (value < 0 ? 0 : value);

    if (m_armor > m_maxArmor)
        m_armor = m_maxArmor;
}

float CPlayer::getSpeed() const
{
    return m_speed;
}

void CPlayer::setSpeed(float value)
{
    m_speed = (value < 0 ? 0 : value);
}

float CPlayer::getXp() const
{
    return m_xp;
}

void CPlayer::setXp(float value)
{
    m_xp = (value < 0 ? 0 : value);
}

float CPlayer::getLvl() const
{
    return m_lvl;
}

void CPlayer::setLvl(float value)
{
    m_lvl = (value < 0 ? 0 : value);
}

float CPlayer::getMaxLvl() const
{
    return m_maxLvl;
}

void CPlayer::setMaxLvl(float value)
{
    m_maxLvl = (value < 0 ? 0 : value);

    if (m_lvl > m_maxLvl)
        m_lvl = m_maxLvl;
}