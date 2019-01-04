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
	class Game_Over_State_2 : public State
	{
	public:
		Game_Over_State_2(GameDataRef data, long long int score1, long long int score2);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		int _selectedOption;
		int _enter;
		long long int _score1;
		long long int _score2;

		std::vector <sf::Text> _options;
	};
}
