#include "CTile.h"

CTile::CTile(const sf::Vector2f& position, const CSprite& sprite)
	: m_sprite(sprite)
{
	m_sprite.setPosition(position.x, position.y);
}

void CTile::draw(sf::RenderWindow* pWindow) const
{
	pWindow->draw(m_sprite);
}