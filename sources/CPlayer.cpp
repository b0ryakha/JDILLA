#include "CPlayer.h"

void CPlayer::listenInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->movePosition('U');
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->movePosition('D');
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->movePosition('L');
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->movePosition('R');
    }
}

CPlayer::CPlayer()
{

    this->setSpeed(0.03f);

}

CPlayer::~CPlayer()
{

}