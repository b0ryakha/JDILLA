#include "CMap.h"

CMap::CMap(const std::vector<CTile>& field)
	: m_field(field)
{}

void CMap::draw(sf::RenderWindow* m_pWindow) const
{
	for (const auto& tile : m_field)
	{
		tile.draw(m_pWindow);
	}
}