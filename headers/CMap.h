#pragma once

#include <SFML/Graphics.hpp>
#include "CEntity.h"
#include "CTile.h"
#include <vector>

class CMap
{
private:
	std::vector<std::vector<CTile>> m_field;
	std::vector<CEntity*> m_entities;

public:
	CMap(const std::vector<std::vector<CTile>>& field);

};