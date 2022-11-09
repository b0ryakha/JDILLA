#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include "CMap.h"

class CEngine
{
private:
    sf::RenderWindow* m_pWindow;
    sf::Event m_event;
    CMap m_map;

    size_t m_iWidth = 1920;
    size_t m_iHeight = 1080;

    std::thread* m_tRender = nullptr;
    std::thread* m_tUpdate = nullptr;
    std::thread* m_tInput = nullptr;

public:
    void Input();
    void Update();
    void Render();

    size_t getScreenWidth() const;
    size_t getScreenHeight() const;

    CEngine();
    ~CEngine();
};