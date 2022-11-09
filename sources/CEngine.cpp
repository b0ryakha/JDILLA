#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <random>
#include <ctime>
#include <thread>
#include <memory>

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


        }
    });

    m_tRender->detach();
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
}