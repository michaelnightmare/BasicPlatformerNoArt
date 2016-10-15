#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>



class Player {
public:
	Player(sf::Vector2f size) {
		
		
	}
	sf::Sprite m_sprite;
	


	void drawTo(sf::RenderWindow &window) {
		window.draw(player);
	}

	void move(sf::Vector2f distance) {
		player.move(distance);
	}

	void setPos(sf::Vector2f newPos) {
		player.setPosition(newPos);
	}

	int getY() {
		return player.getPosition().y;
	}

	

	
private:
	sf::RectangleShape player;
	sf::Texture m_texture;
};
