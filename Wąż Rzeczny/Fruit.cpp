#include "Fruit.h"

namespace Brewque
{
	Fruit::Fruit(GameDataRef data, int offset) : _data(data), _offset(offset)
	{
		_eaten = 1;
		_x = 0;
		_y = 0;
		srand((unsigned int)time(NULL));
	}

	void Fruit::Draw()
	{
		sf::RectangleShape rectangle(sf::Vector2f(Part_Size, Part_Size));
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(_x * Part_Size + _offset, _y * Part_Size);
		_data->window.draw(rectangle);
	}

	void Fruit::Update( std::vector < std::pair < int, int > > Snake_parts)
	{
		if (_eaten == 1)
		{
			// losuj nowy;
			bool tmp;
			do
			{
				_x = rand() % Board_Size;
				_y = rand() % Board_Size;
				tmp = 0;
				for (unsigned int i = 0; i < Snake_parts.size(); i++)
				{
					if (_x == Snake_parts[i].first && _y == Snake_parts[i].second)
					{
						tmp = 1;
						break;
					}
				}
			} while (tmp);
			
			_eaten = 0;
		}
	}

	int Fruit::getEaten()
	{
		return _eaten;
	}

	void Fruit::setEaten(int newEaten)
	{
		_eaten = newEaten;
	}

	int Fruit::getX()
	{
		return _x;
	}

	int Fruit::getY()
	{
		return _y;
	}
}
