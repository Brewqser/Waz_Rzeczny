#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "DEFFINITIONS.h"
#include "State.h"
#include "Game.h"

namespace Brewque
{
	class Game_Over_State : public State
	{
	public:
		Game_Over_State(GameDataRef data, int previous, long long int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		int _selectedOption;
		int _enter;
		int _previous;
		long long int _score;

		std::vector <sf::Text> _options;
	};
}
