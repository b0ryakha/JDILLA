#include "CEngine.h"

void CEngine::updateTime()
{
    std::lock_guard<std::mutex> lock(m_timeMutex);
    m_fTime = m_clock.getElapsedTime().asMicroseconds() / 800.f;
    m_clock.restart();
}

void CEngine::initAssets()
{
    g_spriteList["ERROR"] = new CSprite(g_sGamePath + "assets/error.png", sf::Vector2f(0, 0));
    g_spriteList["ghost"] = new CSprite(g_sGamePath + "assets/ghost.png", sf::Vector2f(0, 0));
    g_spriteList["cowboy"] = new CSprite(g_sGamePath + "assets/cowboy.png", sf::Vector2f(0, 0));
}

void CEngine::initPath()
{
    #ifdef _WIN32
        g_sGamePath = "D:/Games/";
    #endif

    #ifdef linux
        g_sGamePath = "~/";
    #endif

    g_sGamePath += "JDILLA/";
}

void CEngine::initObjects()
{
    m_map.loadFromFile(g_sGamePath + "map/tiles.map");

    m_localPlayer = new CPlayer("Human", *g_spriteList["cowboy"], sf::Vector2f(100, 100));

    m_entities.push_back(new CPlayer("Booloy", *g_spriteList["ghost"], sf::Vector2f(500, 500)));
}

void CEngine::inputThread()
{
    m_tInput = new std::thread([&]
    {
        while (m_window.isOpen())
        {
            m_localPlayer->listenInput(m_fTime);
        }
    });

    m_tInput->detach();
}

void CEngine::updateThread()
{
    m_tUpdate = new std::thread([&]
    {
        while (m_window.isOpen())
        {
            while (m_window.pollEvent(m_event))
            {
                if (m_event.type == sf::Event::Closed)
                    m_window.close();
            }

            //updateTime();

            for (auto* entity : m_entities)
                entity->update();

            m_localPlayer->update();
        }
    });

    m_tUpdate->detach();
}

void CEngine::renderThread()
{
    m_tRender = new std::thread([&]
    {
        while (m_window.isOpen())
        {
            updateTime();
            m_window.clear(sf::Color(200, 200, 200));
            
            m_map.draw(m_window);

            for (auto* entity : m_entities)
                entity->draw(m_window);

            m_localPlayer->draw(m_window);

            m_window.display();
        }
    });

    m_tRender->detach();
}

size_t CEngine::getScreenWidth() const
{
    return m_iWidth;
}

size_t CEngine::getScreenHeight() const
{
    return m_iHeight;
}

CEngine::CEngine()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    m_window.create(sf::VideoMode(m_iWidth, m_iHeight), "JDILLA", sf::Style::Default, settings);
    m_window.setFramerateLimit(100);
    m_window.setActive(false);

    initPath();
    initAssets();
    initObjects();

    renderThread();
    updateThread();
    inputThread();

    while (m_window.isOpen()) {}
}

CEngine::~CEngine()
{
    delete m_tRender;
    delete m_tUpdate;
    delete m_tInput;

    m_window.close();
}