#include "Collision.h"

namespace Brewque
{
	Collision::Collision()
	{

	}

	bool Collision::CheckIsFruitEaten( int fx , int fy , int sx , int sy)
	{
		if (fx == sx && fy == sy)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool Collision::CheckIsFruitOnWay(int fx, int fy, std::vector < std::pair < int, int > > _parts, int direction)
	{
		if (direction == Directions::Up)
		{
			if (_parts[_parts.size() - 1].first == fx && (_parts[_parts.size() - 1].second - 1 + Board_Size ) % Board_Size == fy) return 1;
			else return 0;
		}
		if (direction == Directions::Down)
		{
			if (_parts[_parts.size() - 1].first == fx && (_parts[_parts.size() - 1].second + 1 + Board_Size) % Board_Size == fy) return 1;
			else return 0;
		}
		if (direction == Directions::Left)
		{
			if ((_parts[_parts.size() - 1].first - 1 + Board_Size) % Board_Size == fx && _parts[_parts.size() - 1].second == fy) return 1;
			else return 0;
		}
		if (direction == Directions::Right)
		{
			if ((_parts[_parts.size() - 1].first + 1 + Board_Size) % Board_Size == fx && _parts[_parts.size() - 1].second == fy) return 1;
			else return 0;
		}
		
		return 0;
	}

	bool Collision::CheckSnakeError(std::vector < std::pair < int, int > > _parts , int direction)
	{
		if (direction == Directions::Up)
		{
			if ( _parts[_parts.size() - 1].second - 1 < 0 ) return 1;
		}
		if (direction == Directions::Down)
		{
			if ( _parts[_parts.size() - 1].second + 1 >= Board_Size ) return 1;
		}
		if (direction == Directions::Left)
		{
			if (_parts[_parts.size() - 1].first - 1 <0 ) return 1;
		}
		if (direction == Directions::Right)
		{
			if (_parts[_parts.size() - 1].first + 1 >= Board_Size ) return 1;
		}

		for (unsigned int i = 1; i < _parts.size() - 1 ; i++)
		{
			if (direction == Directions::Up)
			{
				if (_parts[_parts.size() - 1].first == _parts[i].first && _parts[_parts.size() - 1].second - 1 == _parts[i].second) return 1;
			}
			if (direction == Directions::Down)
			{
				if (_parts[_parts.size() - 1].first == _parts[i].first && _parts[_parts.size() - 1].second + 1 == _parts[i].second) return 1;
			}
			if (direction == Directions::Left)
			{
				if (_parts[_parts.size() - 1].first - 1== _parts[i].first && _parts[_parts.size() - 1].second == _parts[i].second) return 1;
			}
			if (direction == Directions::Right)
			{
				if (_parts[_parts.size() - 1].first + 1 == _parts[i].first && _parts[_parts.size() - 1].second == _parts[i].second) return 1;
			}
		}
		return 0;
	}

	bool Collision::CheckSnakeError2(std::vector < std::pair < int, int > > _parts, int direction)
	{
		for (unsigned int i = 1; i < _parts.size() - 1; i++)
		{
			if (direction == Directions::Up)
			{
				if (_parts[_parts.size() - 1].first == _parts[i].first && _parts[_parts.size() - 1].second - 1 == _parts[i].second) return 1;
			}
			if (direction == Directions::Down)
			{
				if (_parts[_parts.size() - 1].first == _parts[i].first && _parts[_parts.size() - 1].second + 1 == _parts[i].second) return 1;
			}
			if (direction == Directions::Left)
			{
				if (_parts[_parts.size() - 1].first - 1 == _parts[i].first && _parts[_parts.size() - 1].second == _parts[i].second) return 1;
			}
			if (direction == Directions::Right)
			{
				if (_parts[_parts.size() - 1].first + 1 == _parts[i].first && _parts[_parts.size() - 1].second == _parts[i].second) return 1;
			}
		}
		return 0;
	}

	int Collision::CheckSnakeError3(std::vector < std::pair < int, int > > _parts, int direction)
	{
		for (unsigned int i = 1; i < _parts.size() - 1; i++)
		{
			if (direction == Directions::Up)
			{
				if (_parts[_parts.size() - 1].first == _parts[i].first && _parts[_parts.size() - 1].second - 1 == _parts[i].second) return i;
			}
			if (direction == Directions::Down)
			{
				if (_parts[_parts.size() - 1].first == _parts[i].first && _parts[_parts.size() - 1].second + 1 == _parts[i].second) return i;
			}
			if (direction == Directions::Left)
			{
				if (_parts[_parts.size() - 1].first - 1 == _parts[i].first && _parts[_parts.size() - 1].second == _parts[i].second) return i;
			}
			if (direction == Directions::Right)
			{
				if (_parts[_parts.size() - 1].first + 1 == _parts[i].first && _parts[_parts.size() - 1].second == _parts[i].second) return i;
			}
		}
		return -1;
	}
}