#include "CTile.h"

CTile::CTile(const sf::Vector2f& position, const sf::Texture& texture)
	: m_position(position), m_sprite(texture)
{}

void CTile::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}

void CTile::draw(sf::RenderWindow* m_pWindow) const
{
	m_pWindow->draw(m_sprite);
}