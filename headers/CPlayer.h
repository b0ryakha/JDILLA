#pragma once

#include "CEntity.h"

class CPlayer : public CEntity
{
private:
    int m_health = 100;
    int m_maxHealth = 100;
    int m_armor = 0;
    int m_maxArmor = 50;
    int m_speed = 2;
    int m_xp = 0;
    int m_lvl = 1;
    int m_maxLvl = 100;

public:
    CPlayer(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position = sf::Vector2f(0, 0));

    void listenInput(float time);

    int getHealth() const;
    void setHealth(int value);

    int getMaxHealth() const;
    void setMaxHealth(int value);

    int getArmor() const;
    void setArmor(int value);

    int getMaxArmor() const;
    void setMaxArmor(int value);

    int getSpeed() const;
    void setSpeed(int value);

    int getXp() const;
    void setXp(int value);

    int getLvl() const;
    void setLvl(int value);

    int getMaxLvl() const;
    void setMaxLvl(int value);
};