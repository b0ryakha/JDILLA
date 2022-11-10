#pragma once

#include <SFML/Graphics.hpp>
#include "CSprite.h"

class CTile
{
private:
	sf::Vector2f m_position { 0, 0 };
	CSprite m_sprite;

public:
	CTile(const sf::Vector2f& position, const CSprite& sprite);

	void setPosition(const sf::Vector2f& position);
	void draw(sf::RenderWindow* pWindow) const;
};

inline std::map<std::string, CSprite*> g_spriteList;