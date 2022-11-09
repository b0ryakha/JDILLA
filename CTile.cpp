#include "CTile.h"

CTile::CTile(const sf::Vector2f& position, const sf::Texture& texture)
	: m_position(position), m_sprite(texture)
{}

void CTile::set_pos(const sf::Vector2f& position) {
	m_position = position;
}