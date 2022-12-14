#include "CSprite.h"

CSprite::CSprite(const std::string& texturePath, const sf::Vector2f& texturePosition)
{
	constexpr size_t weight = 64;
	constexpr size_t height = 64;

	if (!m_texture.loadFromFile(texturePath, sf::IntRect(texturePosition.x, texturePosition.y, weight, height)))
	{
		throw "File can't find or open!";
	}

	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
}

void CSprite::setPosition(const float& x, const float& y)
{
	m_sprite.setPosition(x, y);
}

sf::Sprite CSprite::getSprite() const
{
	return m_sprite;
}

CSprite& CSprite::operator =(const CSprite& sprite)
{
    if (this == &sprite)
        return *this;

	m_sprite = sprite.getSprite();

    return *this;
}

CSprite::operator sf::Sprite() const
{
	return m_sprite;
}