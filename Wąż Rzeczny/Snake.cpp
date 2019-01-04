#include "Snake.h"

namespace Brewque
{
	Snake::Snake(GameDataRef data, int r, int g, int b, int offset) : _data(data), _r(r), _g(g), _b(b), _offset(offset)
	{
		_direction = Directions::Up;
		for (int i = Start_Size -1 ; i >= 0; i--)
		{
			_parts.push_back(std::make_pair(Board_Size / 2, Board_Size / 2 + i));
		}
	}

	void Snake::Draw()
	{
		sf::RectangleShape rectangle(sf::Vector2f(Part_Size, Part_Size));
		for (unsigned int i = 0; i < _parts.size(); i++)
		{
			rectangle.setFillColor(sf::Color(_r, _g, _b, 64 + (255 - 64) * i / _parts.size() ));
			rectangle.setPosition(_parts[i].first * Part_Size + _offset, _parts[i].second * Part_Size);
			_data->window.draw(rectangle);
		}
	}

	void Snake::Update( )
	{
		if (_increase == 0)
		{
			_parts.erase(_parts.begin());
		}
		else
		{
			_increase = 0;
		}
		if (_direction == Up)
		{
			std::pair < int, int > tmp (_parts[_parts.size() - 1].first, (_parts[_parts.size() - 1].second - 1 + Board_Size) % Board_Size);
			_parts.push_back(tmp);
		}
		if (_direction == Down)
		{
			std::pair < int, int > tmp(_parts[_parts.size() - 1].first, (_parts[_parts.size() - 1].second + 1 + Board_Size) % Board_Size);
			_parts.push_back(tmp);
		}
		if (_direction == Left)
		{
			std::pair < int, int > tmp((_parts[_parts.size() - 1].first - 1 + Board_Size) % Board_Size, _parts[_parts.size() - 1].second );
			_parts.push_back(tmp);
		}
		if (_direction == Right)
		{
			std::pair < int, int > tmp((_parts[_parts.size() - 1].first + 1 + Board_Size) % Board_Size, _parts[_parts.size() - 1].second);
			_parts.push_back(tmp);
		}
	}

	void Snake::SetDirection(int newdirection)
	{
		_direction = newdirection;
	}
	
	void Snake::SetIncrease( int newIncrease)
	{
		_increase = newIncrease;
	}

	void Snake::ReduceSnakeSize(int n)
	{
		std::vector < std::pair < int, int > > _newparts;
		if (n < _parts.size() && n != -1 )
		{
			for (unsigned int i = n; i < _parts.size(); i++)
			{
				_newparts.push_back(std::make_pair(_parts[i].first, _parts[i].second));
			}
			_parts = _newparts;
		}
	}

	int Snake::getHeadX()
	{
		return _parts[_parts.size()-1].first;
	}

	int Snake::getHeadY()
	{
		return _parts[_parts.size()-1].second;
	}

	int Snake::getDirection()
	{
		return _direction;
	}

	const std::vector < std::pair < int, int > > &Snake::GetSnake() const
	{
		return _parts;
	}
}
