#include "CEntity.h"

CEntity::CEntity()
{
    m_position.x = 0;
    m_position.y = 0;
}

CEntity::~CEntity()
{
    delete m_sprite;
    m_sprite = nullptr;
}

void CEntity::setName(const std::string& m_sName)
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

void CEntity::setSprite(sf::Sprite* m_sprite)
{
    this->m_sprite = m_sprite;
}

std::string CEntity::getName() const
{
    return this->m_sName;
}

float CEntity::getHealth() const
{
    return this->m_fHealth;
}

float CEntity::getArmor() const
{
    return this->m_fArmor;
}

float CEntity::getSpeed() const
{
    return this->m_fSpeed;
}

sf::Sprite CEntity::getSprite() const
{
    return *this->m_sprite;
}

void CEntity::updateState()
{
    m_sprite->setPosition(m_position.x, m_position.y);
}

void CEntity::loadTexture(const std::string& m_sTexturePath) {
    // TODO
}

void CEntity::draw(sf::RenderWindow* m_pWindow) const
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