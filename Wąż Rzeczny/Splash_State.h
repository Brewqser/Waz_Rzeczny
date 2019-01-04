#pragma once

#include <SFML/Graphics.hpp>
#include "DEFFINITIONS.h"
#include "State.h"
#include "Game.h"

namespace Brewque
{
	class Splash_State : public State
	{
	public:
		Splash_State(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;
		sf::Text _txt1;
		sf::Text _txt2;
		sf::Text _txt3;
	};
}
