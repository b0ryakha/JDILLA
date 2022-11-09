#pragma once

#include <SFML/Graphics.hpp>
#include "CEntity.h"
#include "CTile.h"
#include <vector>

class CMap
{
private:
	std::vector<CTile> m_field;
	std::vector<CEntity*> m_entities;

public:
	CMap(const std::vector<CTile>& field);

	void draw(sf::RenderWindow* m_pWindow);
};