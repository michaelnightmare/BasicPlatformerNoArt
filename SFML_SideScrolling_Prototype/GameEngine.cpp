#include "GameEngine.h"

#define resolutionX 1280
#define resolutionY 720

GameEngine::GameEngine() : Shape(50.0f)
{
	m_Window.create(sf::VideoMode(resolutionX, resolutionY), "First Club Project!", sf::Style::Default);
	Shape.setFillColor(sf::Color(100, 250, 50));
	Shape.setOrigin(Shape.getRadius()/2, Shape.getRadius()/2);
	Shape.setPosition(resolutionX / 2, resolutionY / 2);
}

void GameEngine::Start()
{
	sf::Clock clock; // Timing
	while (m_Window.isOpen())
	{
		sf::Time dt = clock.restart(); // Restart the clock and save the elapsed time into dt
		float dtAsSeconds = dt.asSeconds(); // Converting Delta Time to Seconds initially

		Input(); // Take in user's keyboard inputs
		Update(dtAsSeconds); // The update member function
		Draw(); // Draw to screen
	}
}

void GameEngine::Update(float dtAsSeconds)
{
	// This is where we will update our objects
}

void GameEngine::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Use ESC to close program
	{
		m_Window.close();
	}
}

void GameEngine::Draw()
{
	m_Window.clear();
	// This is where you draw shit
	m_Window.draw(Shape);
	m_Window.display();
}