#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include "DEFFINITIONS.h"
#include "Game.h"

namespace Brewque
{
	class Snake
	{
	public:
		Snake(GameDataRef data,int r,int g,int b,int offset);

		void Draw();
		void Update( );
		void SetDirection(int newdirection);
		void SetIncrease(int newIncrease);
		void ReduceSnakeSize(int n);

		int getHeadX();
		int getHeadY();
		int getDirection();
		const std::vector < std::pair < int, int > > &GetSnake() const;
		
	private:
		GameDataRef _data;

		std::vector < std::pair < int, int > > _parts;

		int _direction;
		int _increase;
		int _r;
		int _g;
		int _b;
		int _offset;
	};
}