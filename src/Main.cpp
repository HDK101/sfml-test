#include <random>
#include "Main.hpp"

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

	window.setKeyRepeatEnabled(false);
#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	sf::Color color(sf::Color::Red);

	std::uniform_int_distribution<int> randomColorRange(0, 255);
	std::random_device rd;
	std::mt19937 randomNumbers(rd());

	sf::Event event;
	sf::Clock clock;

	sf::CircleShape circle(200);
	circle.setFillColor(color);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::EventType::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					color.r = randomColorRange(randomNumbers);
					circle.setFillColor(color);
					circle.setPosition(randomColorRange(randomNumbers),randomColorRange(randomNumbers));
				}
			}
		}
		window.clear();
		window.draw(circle);
		window.display();
	}

	return 0;
}
