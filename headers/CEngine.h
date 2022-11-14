#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <string>
#include <mutex>

#include "CMap.h"
#include "GUI/CWidget.h"
#include "CPlayer.h"

class CEngine
{
private:
    sf::RenderWindow m_window;
    sf::Event m_event;

    size_t m_iWidth = 1280;
    size_t m_iHeight = 720;

    std::mutex m_timeMutex;

    std::thread* m_tRender = nullptr;
    std::thread* m_tUpdate = nullptr;
    std::thread* m_tInput = nullptr;

    sf::Clock m_clock;
    float m_fTime = 0;

    CMap m_map;
    std::vector<CEntity*> m_entities;
    CPlayer* m_localPlayer = nullptr;

    void updateTime();
public:
    void initPath();
    void initAssets();
    void initObjects();
    void initWidgets();

    void inputThread();
    void updateThread();
    void renderThread();

    size_t getScreenWidth() const;
    size_t getScreenHeight() const;

    CEngine();
    ~CEngine();
};

inline std::string g_sGamePath;