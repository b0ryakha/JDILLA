#include "GUI/CWidget.h"

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
    m_sLabel.setString(sLabel);
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
    m_size = { fX, fY };
}

sf::Vector2f graphics::CWidget::getPosition() const
{
    return m_position;
}

void graphics::CWidget::setPosition(float fX, float fY)
{
    m_position = { fX, fY };
}

void graphics::CWidget::show()
{
    m_bIsVisible = true;
}

void graphics::CWidget::hide()
{
    m_bIsVisible = false;
}

bool graphics::CWidget::isHovered() const
{
    return (sf::Mouse::getPosition().x > m_position.x &&
        sf::Mouse::getPosition().x < (sf::Mouse::getPosition().x + m_position.x)); 
}

void graphics::CWidget::checkState()
{
    if (!m_bIsVisible || m_eState == widgetState::DISABLED)
        return;
    
    if (isHovered())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_eState = widgetState::PRESSED;
        }
        else
        {
            m_eState = widgetState::HOVERED;
        }
    }
    else
    {
        m_eState = widgetState::ENABLED;
    }
}

graphics::widgetState graphics::CWidget::getState()
{
    return m_eState;
}

void graphics::CWidget::setState(const widgetState& eWidgetState)
{
    m_eState = eWidgetState;
}

void graphics::CWidget::renderWidget(sf::RenderWindow& pWindow)
{
    
}