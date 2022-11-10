#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <filesystem>
#include <iterator>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
#include <sstream>

#include <iostream>

#include "CEntity.h"
#include "CTile.h"

namespace fs = std::filesystem;

class CMap
{
private:
	std::vector<CTile> m_field;
	std::vector<CEntity*> m_entities;

public:
	CMap();
	CMap(const std::vector<CTile>& field);

	void draw(sf::RenderWindow* m_pWindow) const;
	void loadFromFile(const std::string& file_path);
};