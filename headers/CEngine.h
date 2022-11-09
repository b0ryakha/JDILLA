#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <cstddef>
#include <thread>

class CEngine
{
private:
    sf::RenderWindow *m_pWindow;
    sf::Event m_event;

    unsigned short int m_iWidth = 1920;
    unsigned short int m_iHeight = 1080;

    std::thread *m_tRender = nullptr;
    std::thread *m_tUpdate = nullptr;
    std::thread *m_tInput = nullptr;

public:
    void Input();
    void Update();
    void Render();

    void Start();

    CEngine();
    ~CEngine();
};