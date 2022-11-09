#pragma once
#include <SFML/Graphics.hpp>
#include <thread>

class CEngine
{
private:
    sf::RenderWindow *m_pWindow;
    sf::Event m_event;

    size_t m_iWidth = 1920;
    size_t m_iHeight = 1080;

    std::thread *m_tRender = nullptr;
    std::thread *m_tUpdate = nullptr;
    std::thread *m_tInput = nullptr;

public:
    void Input();
    void Update();
    void Render();

    size_t screenWidth() const;
    size_t screenHeight() const;

    CEngine();
    ~CEngine();
};