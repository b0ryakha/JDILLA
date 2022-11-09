#include "CEntity.h"

CEntity::CEntity()
{
    m_position.x = 0;
    m_position.y = 0;
}

CEntity::~CEntity()
{

}

void CEntity::setName(std::string m_sName)
{
    this->m_sName = m_sName;
}

void CEntity::setHealth(float m_fHealth)
{
    this->m_fHealth = m_fHealth;
}

void CEntity::setArmor(float m_fArmor)
{
    this->m_fArmor = m_fArmor;
}

void CEntity::setSpeed(float m_fSpeed)
{
    this->m_fSpeed = m_fSpeed;
}

void CEntity::setSprite(sf::Sprite *m_sprite)
{
    this->m_sprite = m_sprite;
}

std::string CEntity::getName()
{
    return this->m_sName;
}

float CEntity::getHealth()
{
    return this->m_fHealth;
}

float CEntity::getArmor()
{
    return this->m_fArmor;
}

float CEntity::getSpeed()
{
    return this->m_fSpeed;
}

sf::Sprite CEntity::getSprite()
{
    return *this->m_sprite;
}

void CEntity::updateState()
{
    m_sprite->setPosition(m_position.x, m_position.y);
}

void CEntity::drawEntity(sf::RenderWindow *m_pWindow)
{

    m_pWindow->draw(*m_sprite);

}

void CEntity::setPosition(float fX, float fY)
{
    m_sprite->setPosition(fX, fY);
}

void CEntity::movePosition(char cDirection)
{
    switch(cDirection)
    {
        case 'U':
            m_position.y -= this->m_fSpeed;
            break;
        case 'D':
            m_position.y += this->m_fSpeed;
            break;
        case 'L':
            m_position.x -= this->m_fSpeed;
            break;
        case 'R':
            m_position.x += this->m_fSpeed;
            break;
    }
}