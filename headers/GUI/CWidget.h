#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include <string>

namespace graphics
{
    enum class widgetState
    {
        ENABLED,
        HOVERED,
        PRESSED,
        DISABLED
    };

    class CWidget
    {
private:
        sf::Text m_sLabel;

        bool m_bIsVisible;

        sf::Vector2f m_position;
        sf::Vector2f m_size;

        sf::Shape *m_shape;

        widgetState m_eState;

        bool isHovered() const;
public: 
        CWidget();
        ~CWidget();

        sf::Text getLabel() const;
        void setLabel(const std::string &sLabel);

        bool getVisibility() const;
        
        sf::Vector2f getSize() const;
        void setSize(float fX, float fY);
        
        sf::Vector2f getPosition() const;
        void setPosition(float fX, float fY);

        widgetState getWidgetState();
        void setWidgetState(const widgetState &eWidgetState);

        void show();
        void hide();

        void checkState();
        void renderWidget(sf::RenderWindow *pWindow);
    };
}