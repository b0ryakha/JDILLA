#include "CEngine.h"

void CEngine::InitAssets()
{
    g_spriteList["ERROR"] = new CSprite(GAME_PATH + "assets/error.png", sf::Vector2f(0, 0));
    g_spriteList["player"] = new CSprite(GAME_PATH + "assets/player.png", sf::Vector2f(0, 0));
}

void CEngine::InitPath()
{
    #ifdef _WIN32
        GAME_PATH = "D:/Games/";
    #endif

    #ifdef linux
        GAME_PATH = "";
    #endif

    GAME_PATH += "JDILLA/";
}

void CEngine::Input()
{
    m_tInput = new std::thread([&]
    {
        while (m_window.isOpen())
        {
        
        }
    });

    m_tInput->detach();
}

void CEngine::Update()
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
        }
    });

    m_tUpdate->detach();
}

void CEngine::Render()
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

    InitPath();
    InitAssets();

    m_map.loadFromFile(GAME_PATH + "map/tiles.map");
    m_map.addEntity(new CPlayer("Player", *g_spriteList["player"]));

    Render();
    Update();
    Input();
}

CEngine::~CEngine()
{
    delete m_tRender;
    delete m_tUpdate;
    delete m_tInput;

    m_window.close();
}