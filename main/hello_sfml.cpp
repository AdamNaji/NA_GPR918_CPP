#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Sprite spritetest;
	sf::Texture texturetest;

	if (!texturetest.loadFromFile("data/other_play.png"))
	{
		return EXIT_FAILURE;
	}
	spritetest.setTexture(texturetest);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

		window.clear(sf::Color::Black);
		window.draw(spritetest);				
		window.display();
    }
    return EXIT_SUCCESS;
}