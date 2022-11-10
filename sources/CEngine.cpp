#include "CEngine.h"

void CEngine::InitAssets()
{
    g_spriteList["ERROR"] = new CSprite(GAME_PATH + "assets/error.png", sf::Vector2f(0, 0));
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
        if (!m_pWindow->isOpen()) return;
    });

    m_tInput->detach();
}

void CEngine::Update()
{
    m_tUpdate = new std::thread([&]
    {
        if (!m_pWindow->isOpen()) return;

        while (m_pWindow->pollEvent(m_event))
        {
            switch (m_event.type)
            {
            case sf::Event::Closed:
                m_pWindow->close();
                break;
            case sf::Event::LostFocus:
                m_pWindow->setActive(false);
                // need hide window function.
                break;
            case sf::Event::GainedFocus:
                m_pWindow->setActive(true);
                break;
            }
        }
    });

    m_tUpdate->detach();
}

void CEngine::Render()
{
    m_tRender = new std::thread([&]
    {
        if (!m_pWindow->isOpen()) return;
        
        m_pWindow->clear(sf::Color(200, 200, 200));

        m_map.draw(m_pWindow);

        m_pWindow->display();
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
    m_pWindow = new sf::RenderWindow(sf::VideoMode(m_iWidth, m_iHeight), "JDILLA");
    m_pWindow->setActive(false);

    InitPath();
    InitAssets();

    m_map.loadFromFile(GAME_PATH + "map/tiles.map");

    m_pWindow->setFramerateLimit(60);

    Render();
    Update();
    Input();
}

CEngine::~CEngine()
{
    delete m_tRender;
    delete m_tUpdate;
    delete m_tInput;

    delete m_pWindow;
}