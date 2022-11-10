#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class CSprite
{
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::Sprite getSprite() const;
public:
	CSprite(const std::string& texturePath, const sf::Vector2f& texturePosition);

	void setPosition(const sf::Vector2f& position);

	CSprite& operator =(const CSprite& sprite);
	operator sf::Sprite() const;
};