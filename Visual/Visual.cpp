#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std; 
int main()
{
	float x = 0, y = 0;
	sf::Vector2f movement(x, y);
	float vx = 8, vy = 8;
	int reset = true; 
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithms", sf::Style::Default, settings);
	window.setFramerateLimit(70);
	sf::Event event; 

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	window.clear(sf::Color::White);
	sf::CircleShape shape(10, 30);
	cout << "x: " << movement.x << ", y: " << movement.y << endl;

	if (reset) {
		cout << "true";
		shape.setPosition(x, y);
		reset = false; 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= 5.f;
		cout << x << endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += 5.f;
		cout << x << endl; 
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= 5.f;
		cout << x << endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += 5.f;
		cout << x << endl;
		shape.move(sf::Vector2f(x, y));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	}
	shape.move(movement);
	shape.setFillColor(sf::Color(100, 250, 50));
	window.draw(shape);
	window.display();
	}

}
