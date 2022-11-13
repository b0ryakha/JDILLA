#pragma once

#include <SFML/Graphics.hpp>

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
        sf::Vector2f m_position { 0, 0 };
        sf::Vector2f m_size { 0, 0 };

        sf::Shape *m_shape = nullptr;

        widgetState m_eState;
        bool m_bIsVisible;

        bool isHovered() const;
    public: 
        CWidget();
        ~CWidget();

        sf::Text getLabel() const;
        void setLabel(const std::string& sLabel);

        bool getVisibility() const;
        
        sf::Vector2f getSize() const;
        void setSize(float fX, float fY);
        
        sf::Vector2f getPosition() const;
        void setPosition(float fX, float fY);

        widgetState getState();
        void setState(const widgetState& eWidgetState);

        void show();
        void hide();

        void checkState();
        void renderWidget(sf::RenderWindow& pWindow);
    };
}