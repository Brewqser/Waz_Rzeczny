#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFFINITIONS.h"
#include "State.h"
#include "Game.h"

namespace Brewque
{
	class Main_Menu_State : public State
	{
	public:
		Main_Menu_State(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		int _selectedOption;
		int _enter;

		std::vector <sf::Text> _options;
	};
}
