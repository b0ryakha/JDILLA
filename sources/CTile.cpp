#include "CTile.h"

CTile::CTile(const sf::Vector2f& position, const CSprite& sprite)
	: m_position(position), m_sprite(sprite)
{}

void CTile::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}

void CTile::draw(sf::RenderWindow* pWindow) const
{
	pWindow->draw(m_sprite);
}