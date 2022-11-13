#include "CEngine.h"

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

void CEngine::inputThread()
{
    m_tInput = new std::thread([&]
    {
        while (m_window.isOpen())
        {
        
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
                switch (m_event.type)
                {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::LostFocus:
                    m_window.setActive(false);
                    // need hide window function.
                    break;
                case sf::Event::GainedFocus:
                    m_window.setActive(true);
                    break;
                }
            }

            m_map.update();
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
            m_window.clear(sf::Color(200, 200, 200));

            m_map.draw(m_window);

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

    m_map.loadFromFile(g_sGamePath + "map/tiles.map");

    m_map.addEntity(CPlayer("Booloy", *g_spriteList["ghost"], sf::Vector2f(500, 500)));
    m_map.addEntity(CPlayer("Holbuy", *g_spriteList["cowboy"], sf::Vector2f(500, 470)));

    renderThread();
    updateThread();
    inputThread();
}

CEngine::~CEngine()
{
    delete m_tRender;
    delete m_tUpdate;
    delete m_tInput;

    m_window.close();
}