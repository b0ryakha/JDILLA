#include "CEngine.h"

void CEngine::Input()
{
    m_tInput = new std::thread([&]()
    {
        while(m_pWindow->isOpen()) 
        {

        }
    });

    m_tInput->detach();
}

void CEngine::Update()
{
    m_tUpdate = new std::thread([&]()
    {
        while(m_pWindow->isOpen())
        {
            while(m_pWindow->pollEvent(m_event))
            {
                if (m_event.type == sf::Event::Closed)
                    m_pWindow->close();
            }
        }
    });

    m_tUpdate->detach();
}

void CEngine::Render()
{
    m_tRender = new std::thread([&]()
    {
        while(m_pWindow->isOpen())
        {
            m_pWindow->clear(sf::Color(44, 53, 59));
            m_pWindow->display();
            m_map.draw(m_pWindow);
        }
    });

    m_tRender->detach();
}

size_t CEngine::getScreenWidth() const {
    return m_iWidth;
}

size_t CEngine::getScreenHeight() const {
    return m_iHeight;
}

CEngine::CEngine()
{
    m_pWindow = new sf::RenderWindow(sf::VideoMode(m_iWidth, m_iHeight), "JDILLA");

    m_pWindow->setActive(false);

    this->Render();
    this->Update();
    this->Input();

    m_pWindow->setFramerateLimit(60);

    while(m_pWindow->isOpen())
    {

    }
}

CEngine::~CEngine()
{
    delete m_tRender;
    delete m_tUpdate;
    delete m_tInput;
    delete m_pWindow;

    m_tInput = nullptr;
    m_tRender = nullptr;
    m_tUpdate = nullptr;
    m_pWindow = nullptr;
}