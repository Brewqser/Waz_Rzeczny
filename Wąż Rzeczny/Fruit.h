#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "DEFFINITIONS.h"
#include "Game.h"

namespace Brewque
{
	class Fruit
	{
	public:
		Fruit(GameDataRef data,int offset);

		void Draw();
		void Update( std::vector < std::pair < int, int > > Snake_parts);

		int getEaten();
		void setEaten(int newEaten);
		int getX();
		int getY();

	private:
		GameDataRef _data;

		int _x;
		int _y;
		int _eaten;
		int _offset;
	};
}