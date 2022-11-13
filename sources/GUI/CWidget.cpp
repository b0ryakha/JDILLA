#include "GUI/CWidget.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

graphics::CWidget::CWidget()
{ 

}

graphics::CWidget::~CWidget()
{

}

sf::Text graphics::CWidget::getLabel() const
{
    return m_sLabel;
}

void graphics::CWidget::setLabel(const std::string& sLabel)
{
    this->m_sLabel.setString(sLabel);
}

bool graphics::CWidget::getVisibility() const
{
    return m_bIsVisible;
}

sf::Vector2f graphics::CWidget::getSize() const
{
    return m_size;
}

void graphics::CWidget::setSize(float fX, float fY)
{
    this->m_size.x = fX;
    this->m_size.y = fY;
}

sf::Vector2f graphics::CWidget::getPosition() const
{
    return m_position;
}

void graphics::CWidget::setPosition(const float fX, const float fY)
{
    this->m_position.x = fX;
    this->m_position.y = fY;
}

void graphics::CWidget::show()
{
    this->m_bIsVisible = true;
}

void graphics::CWidget::hide()
{
    this->m_bIsVisible = false;
}

bool graphics::CWidget::isHovered() const
{
    return (sf::Mouse::getPosition().x > m_position.x 
    && sf::Mouse::getPosition().x < (sf::Mouse::getPosition().x + m_position.x)); 
}

void graphics::CWidget::checkState()
{
    if(m_bIsVisible)
    {
        if (m_eState != widgetState::DISABLED)
        {
            if(this->isHovered())
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))        
                {
                    this->m_eState = widgetState::PRESSED;
                } 
                else
                {
                    this->m_eState = widgetState::HOVERED;
                }
            }
            else
            {
                this->m_eState = widgetState::ENABLED;
            }
        }

    }
        
}

void graphics::CWidget::renderWidget(sf::RenderWindow *pWindow)
{
    
}