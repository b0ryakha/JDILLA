#include "CPlayer.h"

CPlayer::CPlayer(const std::string& sName, const CSprite& sprite, const CCharacteristic& characteristic)
    : CEntity(sName, sprite), m_characteristic(characteristic)
{}

CPlayer::CPlayer(const std::string& sName, const CSprite& sprite, const CCharacteristic& characteristic, const sf::Vector2f& position)
    : CEntity(sName, sprite, position), m_characteristic(characteristic)
{}

void CPlayer::listenInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        setPosition(getPosition().x, getPosition().y - m_characteristic.speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        setPosition(getPosition().x, getPosition().y + m_characteristic.speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        setPosition(getPosition().x - m_characteristic.speed, getPosition().y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        setPosition(getPosition().x + m_characteristic.speed, getPosition().y);
    }
}

float CPlayer::getCharacteristic(const Characteristic& characteristicName) const
{
    switch (characteristicName)
    {
    case Characteristic::Health:
        return m_characteristic.health;
        break;

    case Characteristic::MaxHealth:
        return m_characteristic.maxHealth;
        break;

    case Characteristic::Armor:
        return m_characteristic.armor;
        break;

    case Characteristic::MaxArmor:
        return m_characteristic.maxArmor;
        break;

    case Characteristic::Speed:
        return m_characteristic.speed;
        break;

    case Characteristic::Xp:
        return m_characteristic.xp;
        break;

    case Characteristic::Lvl:
        return m_characteristic.lvl;
        break;

    case Characteristic::MaxLvl:
        return m_characteristic.maxLvl;
        break;
    }
}

void CPlayer::setCharacteristic(const Characteristic& characteristicName, float value)
{
    if (value < 0) value = 0;

    switch (characteristicName)
    {
    case Characteristic::Health:
        m_characteristic.health = value;
        break;

    case Characteristic::MaxHealth:
        m_characteristic.maxHealth = value;
        if (m_characteristic.health > m_characteristic.maxHealth)
            m_characteristic.health = m_characteristic.maxHealth;
        break;

    case Characteristic::Armor:
        m_characteristic.armor = value;
        break;

    case Characteristic::MaxArmor:
        m_characteristic.maxArmor = value;
        if (m_characteristic.armor > m_characteristic.maxArmor)
            m_characteristic.armor = m_characteristic.maxArmor;
        break;

    case Characteristic::Speed:
        m_characteristic.speed = value;
        break;

    case Characteristic::Xp:
        m_characteristic.xp = value;
        break;

    case Characteristic::Lvl:
        m_characteristic.lvl = value;
        break;

    case Characteristic::MaxLvl:
        m_characteristic.maxLvl = value;
        if (m_characteristic.lvl > m_characteristic.maxLvl)
            m_characteristic.lvl = m_characteristic.maxLvl;
        break;
    }
}