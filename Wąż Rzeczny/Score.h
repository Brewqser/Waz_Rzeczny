#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "DEFFINITIONS.h"
#include "Game.h"

namespace Brewque
{
	class Score
	{
	public:
		Score(GameDataRef data,int offset);
		
		void Draw();

		void Add(int n);
		long long int getScore();

	private:
		GameDataRef _data;

		long long int _points;
		sf::Vertex _line[2];
		int _offset;
	};
}