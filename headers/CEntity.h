#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "CTile.h"

enum class moveSide {
    up, down, left, right
};

class CEntity
{
private:
    std::string m_sName;

    float m_fHealth = 0;
    float m_fArmor = 0;
    float m_fSpeed = 0;

    float m_fMaxHealth = 0;
    float m_fMaxArmor = 0;

    CSprite m_sprite;
    sf::Vector2f m_position { 0, 0 };

public:
    CEntity();
    CEntity(const std::string& sName, const CSprite& sprite);
    CEntity(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position);

    void setName(const std::string& sName);

    void setHealth(float fHealth);
    void setArmor(float fArmor);
    void setSpeed(float fSpeed);

    void setSprite(const CSprite& sprite);

    std::string getName() const;

    float getHealth() const;
    float getArmor() const;
    float getSpeed() const;

    CSprite getSprite() const;
    sf::Vector2f getPosition() const;

    void updateState();

    void draw(sf::RenderWindow& pWindow) const;

    void setPosition(float fX, float fY);
    void movePosition(const moveSide& direction);
};