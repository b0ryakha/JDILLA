#include "CPlayer.h"

void CPlayer::listenInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movePosition(moveSide::up);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movePosition(moveSide::down);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movePosition(moveSide::left);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movePosition(moveSide::right);
    }
}

CPlayer::CPlayer(const std::string& sName, const CSprite& sprite)
{
    setSpeed(0.03f);
    setName(sName);
    setSprite(sprite);
}