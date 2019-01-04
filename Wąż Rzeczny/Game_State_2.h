#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Snake.h"
#include "Fruit.h"
#include "Score.h"
#include "Collision.h"

namespace Brewque
{
	class Game_State_2 : public State
	{
	public:
		Game_State_2(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		Snake *snake;
		Fruit *fruit;
		Score *score;
		Collision collision;

		int _newdirection;
		int _gamestate;
	};
}
