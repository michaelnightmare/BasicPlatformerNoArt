#pragma once
#include <SFML/Graphics.hpp>

class GameEngine
{
public:
	GameEngine();
	void Start();
	void Update(float dtAsSeconds);
	void Input();
	void Draw();
private:
	sf::RenderWindow m_Window;
	sf::CircleShape Shape; // This is just to test everything to make sure it is working. Delete this once we get going on the project
};