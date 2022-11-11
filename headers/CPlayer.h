#pragma once

#include "CEntity.h"

class CPlayer : public CEntity
{
private:
    float m_fExp = 0;
    size_t m_iLevel = 1;

public:
    void listenInput();

    CPlayer(const std::string& sName, const CSprite& sprite);
    CPlayer(const std::string& sName, const CSprite& sprite, const sf::Vector2f& position);
};