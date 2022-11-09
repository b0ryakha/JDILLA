#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class CEntity
{
private:
    std::string m_sName;
    //std::string m_sTexturePath;

    float m_fHealth;
    float m_fArmor;
    float m_fSpeed;

    float m_fMaxHealth;
    float m_fMaxArmor;

    sf::Sprite *m_sprite;

    sf::Vector2f m_position;

public:

    CEntity();
    ~CEntity();

    void setName(std::string m_sName);

    void setHealth(float m_fHealth);
    void setArmor(float m_fArmor);
    void setSpeed(float m_fSpeed);

    void setSprite(sf::Sprite *m_sprite);

    std::string getName();

    float getHealth();
    float getArmor();
    float getSpeed();

    sf::Sprite getSprite();

    void updateState();

    void loadTexture(std::string m_sTexturePath);
    void drawEntity(sf::RenderWindow *m_pWindow);

    void setPosition(float fX, float fY);
    void movePosition(char cDirection);
};