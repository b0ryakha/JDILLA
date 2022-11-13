#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <string>
#include "CMap.h"

#include "CPlayer.h"

class CEngine
{
private:
    sf::RenderWindow m_window;
    sf::Event m_event;

    size_t m_iWidth = 1280;
    size_t m_iHeight = 720;

    std::thread* m_tRender = nullptr;
    std::thread* m_tUpdate = nullptr;
    std::thread* m_tInput = nullptr;

    CMap m_map;
    std::vector<CEntity*> m_entities;
    CPlayer* m_localPlayer = nullptr;

public:
    void initPath();
    void initAssets();
    void initObjects();

    void inputThread();
    void updateThread();
    void renderThread();

    size_t getScreenWidth() const;
    size_t getScreenHeight() const;

    CEngine();
    ~CEngine();
};

inline std::string g_sGamePath;