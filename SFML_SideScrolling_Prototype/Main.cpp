// Engine.cpp : Defines the entry point for the console application.

#include <iostream>
#include "stdafx.h"
#include "SFML\Graphics.hpp"

#include "Player.h"

#include <sstream>

int main()
{	
	sf::RenderWindow window;
	sf::Clock clock;

	window.create(sf::VideoMode(720, 600), "Metroid Clone", sf::Style::Titlebar | sf::Style::Close);
	
	sf::Texture texture;
	if (!texture.loadFromFile("Art/Samus1.png"))
	{
		std::cout << "texture wont load";
	}
	

	int test = 42;
	//Player Object:
	Player player({ 40, 40 });
	player.setPos({ 50, 500 });



	Samus.setTexture(texture);
	Samus.setTextureRect(sf::IntRect(43, 0, 20, 40));
	Samus.setPosition(sf::Vector2f(7.5, 450));
	Samus.setScale(sf::Vector2f(3.f, 3.f));

	//Gravity Variables:
	const int groundHeight = 500;
	const float gravitySpeed = 0.7;
	
	bool isJumping = false;

	//Main Loop:
	while (window.isOpen()) {

		sf::Event Event;

		sf::Time dt = clock.restart(); // Restart the clock and save the elapsed time into dt
		float dtAsSeconds = dt.asSeconds(); // Converting Delta Time to Seconds initially

		const float moveSpeed = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& !isJumping) {
			Samus.move({ 0, -moveSpeed - 100000 * dtAsSeconds });
			isJumping = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			Samus.move({ moveSpeed, 0 });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			Samus.move({ -moveSpeed, 0 });
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Use ESC to close program
		{
			window.close();
		}

		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();

			case sf::Event::KeyReleased:
				isJumping = false;
			}
		}

		//Gravity Logic:
		if (player.getY() < groundHeight && isJumping == false) {
			player.move({ 0, gravitySpeed });
		}

	

		window.clear();
		window.draw(Samus);
		window.display();
	}
	return 0;
}



	


