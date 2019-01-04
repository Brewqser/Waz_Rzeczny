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
	class Game_State_4 : public State
	{
	public:
		Game_State_4(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock1;
		sf::Clock _clock2;

		Snake *snake1;
		Fruit *fruit1;
		Score *score1;
		Snake *snake2;
		Fruit *fruit2;
		Score *score2;
		Collision collision;

		sf::Vertex _line[2];
		int _newdirection1;
		int _gamestate1;
		int _newdirection2;
		int _gamestate2;
		int _gameover;
	};
}
