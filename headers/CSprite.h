#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class CSprite
{
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::Sprite getSprite() const;
public:
	CSprite(const std::string& texturePath, const sf::Vector2f& texturePosition);

	CSprite& operator =(const CSprite& sprite);
	operator sf::Sprite() const;
};