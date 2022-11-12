#pragma once

#include "CEntity.h"
#include "CCharacteristic.h"

class CPlayer : public CEntity
{
private:
    CCharacteristic m_characteristic;

public:
    CPlayer(const std::string& sName, const CSprite& sprite, const CCharacteristic& characteristic);
    CPlayer(const std::string& sName, const CSprite& sprite, const CCharacteristic& characteristic, const sf::Vector2f& position);

    void listenInput();
    float getCharacteristic(const Characteristic& characteristicName) const;
    void setCharacteristic(const Characteristic& characteristicName, float value);
};