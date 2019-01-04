#pragma once

#include <SFML/Graphics.hpp>

namespace Brewque
{
	class InputManager
	{
	public:
		InputManager() { }
		~InputManager() { }

		bool IsSpriteCliced(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool IsCursorOnSprite(sf::Sprite object, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);

	};
}