#include "CMap.h"

CMap::CMap()
{}

CMap::CMap(const std::vector<CTile>& field)
	: m_field(field)
{}

void CMap::draw(sf::RenderWindow& m_window) const
{
	for (const auto& tile : m_field)
		tile.draw(m_window);

	for (auto entity : m_entitys)
		entity->draw(m_window);
}

void CMap::loadFromFile(const std::string& file_path)
{
	if (!fs::exists(file_path))
		throw "File of tiles for map can't find!";

	std::ifstream file(file_path, std::ios::binary);
	std::vector<char> file_contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	float x = 0;
	float y = 0;
	std::string tmp_s;

	//is_tile, is_pos, is_y, is_pos_done, is_name, is_name_done
	std::array<bool, 6> flags { false };

	for (const auto& symbol : file_contents)
	{
		if (flags[0])
		{
			if (flags[1])
			{
				if (flags[2] ? (symbol != '}') : (symbol != ','))
				{
					tmp_s += symbol;
				}
				else
				{
					if (flags[2])
					{
						try { y = std::stof(tmp_s); }
						catch (...) { y = 0; }

						flags[2] = false;
						flags[1] = false;
						flags[3] = true;
					}
					else
					{
						try { x = std::stof(tmp_s); }
						catch (...) { x = 0; }

						flags[2] = true;
					}

					tmp_s.clear();
				}
			}
			else
			{
				if (symbol == '{') flags[1] = true;
				if (flags[4])
				{
					if (symbol != '\"') tmp_s += symbol;
					else
					{
						flags[4] = false;
						flags[5] = true;
					}
				}
				else
				{
					if (flags[5])
					{
						if (symbol == '}')
						{
							if (g_spriteList.count(tmp_s) <= 0) tmp_s = "ERROR";
							else
							{
								for (auto& ch : tmp_s)
									ch = std::tolower(ch);
							}

							m_field.push_back(std::move(CTile(sf::Vector2f(x, y), *g_spriteList[tmp_s])));

							x = 0;
							y = 0;
							tmp_s.clear();

							flags[5] = false;
							flags[0] = false;
						}
					}
					else if (symbol == '\"') flags[4] = true;
				}
			}
		}
		else if (symbol == '{') flags[0] = true;
	}
}

void CMap::addEntity(CEntity* entity)
{
	m_entitys.push_back(entity);
}