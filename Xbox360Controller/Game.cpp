// author Aoife Powders
//Time Taken:10 hours
//Date Started: 11/10/17

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 1000, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	m_xboxController.connect();
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

// handle user and system events/ input
// get key presses/ mouse moves etc.
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}

	}
}

// Update the game world
void Game::update(sf::Time t_deltaTime)
{
	m_xboxController.update();
	if (sf::Joystick::isButtonPressed(0, 6))
	{
		m_exitGame = true;
	}

	m_xboxController.m_previousStateString;
	if (m_exitGame)
	{
		m_window.close();
	}
	
}

// draw the frame and then switch bufers
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_logoSprite);
	m_window.draw(m_xboxController.m_previousStateString);
	m_window.draw(m_xboxController.m_connected);

	for (int i = 0; i < 19; i++)
	{
		if (m_xboxController.m_Pressed[i] == true)
		{
			m_window.draw(m_xboxController.m_textArray[i]);
		}
	}
	m_window.display();
}

//sets up all the text and text arrays
void Game::setupFontAndText()
{
	//loads in font
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\futurist .ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	for (int i = 0; i < 19; i++)
	{
		m_xboxController.m_textArray[i].setFont(m_ArialBlackfont);
		m_xboxController.m_textArray[i].setCharacterSize(20);
		m_xboxController.m_textArray[i].setColor(sf::Color::Black);
	}

	m_xboxController.m_previousStateString.setFont(m_ArialBlackfont);
	m_xboxController.m_previousStateString.setCharacterSize(20);
	m_xboxController.m_previousStateString.setColor(sf::Color::Black);
	m_xboxController.m_previousStateString.setPosition(600, 100);
	m_xboxController.m_previousStateString.setString("Last Button Pressed is: ");

	m_xboxController.m_connected.setFont(m_ArialBlackfont);
	m_xboxController.m_connected.setCharacterSize(20);
	m_xboxController.m_connected.setColor(sf::Color::Black);
	m_xboxController.m_connected.setPosition(350, 100);
	m_xboxController.m_connected.setString("Connected " + std::to_string(m_xboxController.sf_Joystick_index));

	m_xboxController.m_textArray[9].setPosition(100, 200);
	m_xboxController.m_textArray[10].setPosition(100, 220);
	m_xboxController.m_textArray[11].setPosition(520, 520);
	m_xboxController.m_textArray[12].setPosition(520, 540);
	m_xboxController.m_textArray[13].setPosition(380, 520);
	m_xboxController.m_textArray[14].setPosition(270, 520);
	m_xboxController.m_textArray[15].setPosition(330, 480);
	m_xboxController.m_textArray[16].setPosition(330, 570);
	m_xboxController.m_textArray[17].setPosition(600, 50);
	m_xboxController.m_textArray[18].setPosition(200, 50);
}


/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\controller.jpg"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(5.0f, 5.0f);
}
