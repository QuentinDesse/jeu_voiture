#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Jeu de la voiture");
	sf::RectangleShape Route(sf::Vector2f(1280.f, 720.f));
	Route.setFillColor(sf::Color::Green);
	window.setFramerateLimit(20);

										
														//voiture

	sf::Texture textureVoiture;
	textureVoiture.loadFromFile("lamborghini.png", sf::IntRect(0, 0, 100, 207));
	sf::Sprite spriteVoiture;
	spriteVoiture.setTexture(textureVoiture);
	textureVoiture.loadFromFile("lamborghini.png");
	spriteVoiture.setPosition(590.f, 512.f);


														//route

	sf::Texture textureRoute;
	textureRoute.loadFromFile("route1.png", sf::IntRect(0, 0, 1280, 1440));
	sf::Sprite spriteRoute;
	spriteRoute.setTexture(textureRoute);
	textureRoute.loadFromFile("route1.png");
	spriteRoute.setPosition(0.f, -720.f);


														//route2

	sf::Texture textureRoute2;
	textureRoute2.loadFromFile("route2.png", sf::IntRect(0, 0, 1280, 1440));
	sf::Sprite spriteRoute2;
	spriteRoute2.setTexture(textureRoute2);
	textureRoute2.loadFromFile("route2.png");
	spriteRoute2.setPosition(0.f, -1440.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


														//mouvement route	

		if (spriteRoute.getPosition().y == 720) spriteRoute.setPosition(0.f, -720.f);
		spriteRoute.move(0.f, 30.f);

		if (spriteRoute2.getPosition().y == 0)	spriteRoute2.setPosition(0.f, -1440.f);
		spriteRoute2.move(0.f, 30.f);


														//mouvement voiture gauche	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (spriteVoiture.getPosition().x < 11)	spriteVoiture.move(0.f, 0.f);
			else spriteVoiture.move(-20.f, 0.f);
		}


														//mouvement voiture droite

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (spriteVoiture.getPosition().x > 1169)	spriteVoiture.move(0.f, 0.f);
			else spriteVoiture.move(20.f, 0.f);
		}

		window.draw(spriteRoute);
		window.draw(spriteRoute2);
		window.draw(spriteVoiture);
		window.display();
	}

	return 0;
}