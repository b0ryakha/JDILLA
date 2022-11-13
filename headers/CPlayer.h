#pragma once

#include "CEntity.h"

class CPlayer : public CEntity
{
private:
    float m_health = 80;
    float m_maxHealth = 100;
    float m_armor = 0;
    float m_maxArmor = 50;
    float m_speed = 10;
    float m_xp = 0;
    float m_lvl = 1;
    float m_maxLvl = 100;

public:
    CPlayer(const std::string& sName, const CSprite& sprite);
    CPlayer(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position);

    void listenInput();

    float getHealth() const;
    void setHealth(float value);

    float getMaxHealth() const;
    void setMaxHealth(float value);

    float getArmor() const;
    void setArmor(float value);

    float getMaxArmor() const;
    void setMaxArmor(float value);

    float getSpeed() const;
    void setSpeed(float value);

    float getXp() const;
    void setXp(float value);

    float getLvl() const;
    void setLvl(float value);

    float getMaxLvl() const;
    void setMaxLvl(float value);
};