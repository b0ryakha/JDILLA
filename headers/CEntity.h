#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "CTile.h"

class CEntity
{
private:
    std::string m_sName;
    sf::Vector2f m_position { 0, 0 };

    CSprite m_sprite { *g_spriteList["ERROR"] };

public:
    CEntity(const std::string& sName, const CSprite& sprite);
    CEntity(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position);

    std::string getName() const;
    void setName(const std::string& sName);

    CSprite getSprite() const;
    void setSprite(const CSprite& sprite);

    sf::Vector2f getPosition() const;
    void setPosition(float fX, float fY);

    void update();
    void draw(sf::RenderWindow& pWindow) const;
};