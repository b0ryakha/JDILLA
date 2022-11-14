#include "CPlayer.h"

extern float g_time;

CPlayer::CPlayer(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position)
    : CEntity(sName, sprite, position)
{}

void CPlayer::listenInput(float time)
{
    float normilizeSpeed = static_cast<float>(m_speed) / 10000;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        setPosition(getPosition().x, getPosition().y - normilizeSpeed * time);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        setPosition(getPosition().x, getPosition().y + normilizeSpeed * time);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        setPosition(getPosition().x - normilizeSpeed * time, getPosition().y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        setPosition(getPosition().x + normilizeSpeed * time, getPosition().y);
    }
}

int CPlayer::getHealth() const
{
    return m_health;
}

void CPlayer::setHealth(int value)
{
    m_health = (value < 0 ? 0 : value);
}

int CPlayer::getMaxHealth() const
{
    return m_maxHealth;
}

void CPlayer::setMaxHealth(int value)
{
    m_maxHealth = (value < 0 ? 0 : value);

    if (m_health > m_maxHealth)
        m_health = m_maxHealth;
}

int CPlayer::getArmor() const
{
    return m_armor;
}

void CPlayer::setArmor(int value)
{
    m_armor = (value < 0 ? 0 : value);
}

int CPlayer::getMaxArmor() const
{
    return m_maxArmor;
}

void CPlayer::setMaxArmor(int value)
{
    m_maxArmor = (value < 0 ? 0 : value);

    if (m_armor > m_maxArmor)
        m_armor = m_maxArmor;
}

int CPlayer::getSpeed() const
{
    return m_speed;
}

void CPlayer::setSpeed(int value)
{
    m_speed = (value < 0 ? 0 : value);
}

int CPlayer::getXp() const
{
    return m_xp;
}

void CPlayer::setXp(int value)
{
    m_xp = (value < 0 ? 0 : value);
}

int CPlayer::getLvl() const
{
    return m_lvl;
}

void CPlayer::setLvl(int value)
{
    m_lvl = (value < 0 ? 0 : value);
}

int CPlayer::getMaxLvl() const
{
    return m_maxLvl;
}

void CPlayer::setMaxLvl(int value)
{
    m_maxLvl = (value < 0 ? 0 : value);

    if (m_lvl > m_maxLvl)
        m_lvl = m_maxLvl;
}