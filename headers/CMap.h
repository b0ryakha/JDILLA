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

#include "CEntity.h"
#include "CPlayer.h"
#include "CTile.h"

namespace fs = std::filesystem;

class CMap
{
private:
	std::vector<CTile> m_field;

public:
	CMap();
	CMap(const std::vector<CTile>& field);
	
	void draw(sf::RenderWindow& m_window) const;
	void loadFromFile(const std::string& file_path);
};