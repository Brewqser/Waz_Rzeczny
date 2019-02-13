#pragma once

#include <SFML/Graphics.hpp>
#include "DEFFINITIONS.h"

namespace Brewque
{
	class Collision
	{

	public:
		Collision( );
		
		bool CheckIsFruitEaten(int fx , int fy , int sx ,int sy);
		bool CheckIsFruitOnWay(int fx, int fy, std::vector < std::pair < int, int > > Snake_parts , int direction);
		bool CheckSnakeError(std::vector < std::pair < int, int > > _parts, int direction);
		bool CheckSnakeError2(std::vector < std::pair < int, int > > _parts, int direction);
		int CheckSnakeError3(std::vector < std::pair < int, int > > _parts, int direction);
	};
}