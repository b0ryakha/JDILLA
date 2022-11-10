#pragma once

#include <SFML/Graphics.hpp>
#include "CSprite.h"

class CTile
{
private:
	CSprite m_sprite;

public:
	CTile(const sf::Vector2f& position, const CSprite& sprite);

	void draw(sf::RenderWindow* pWindow) const;
};

inline std::map<std::string, CSprite*> g_spriteList;