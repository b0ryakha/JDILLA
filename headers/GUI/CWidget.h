#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
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

    class CWidgetSettings
    {
public:
        static sf::Color m_fillColor;
        static sf::Color m_fillColorHovered;
        static sf::Color m_fillColorPressed;
        static sf::Color m_fontColor;
        static sf::Font m_mainFont;
        static sf::Vector2f m_buttonSize;
    };

    class CWidget
    {
    private:
        sf::Text m_sLabel;
        sf::Vector2f m_position { 0, 0 };
        sf::Vector2f m_size { 0, 0 };

        widgetState m_eState;
        bool m_bIsVisible;

        sf::Shape *m_shape;

        bool isHovered() const;

    public: 
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