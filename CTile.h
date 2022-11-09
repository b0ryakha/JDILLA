#pragma once
#include <SFML/Graphics.hpp>

class CTile
{
private:
	sf::Vector2f m_position { 0, 0 };
	sf::Sprite m_sprite;

public:
	CTile(const sf::Vector2f& position, const sf::Texture& texture);

	void set_pos(const sf::Vector2f& position);
};