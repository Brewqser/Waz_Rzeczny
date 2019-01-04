#include "Choose_Game_State.h"
#include "Main_Menu_State.h"
#include "Game_State.h"
#include "Game_State_2.h"
#include "Game_State_3.h"
#include "Game_State_4.h"

#include <iostream>


namespace Brewque
{
	Choose_Game_State::Choose_Game_State(GameDataRef data) : _data(data)
	{

	}

	void Choose_Game_State::Init()
	{
		this->_selectedOption = 0;
		this->_enter = -1;
		this->_data->assets.LoadFont("Comic_Sans", ChooseGameState_FontFilepath);

		sf::Text tmp;
		tmp.setFont(this->_data->assets.GetFont("Comic_Sans"));
		tmp.setString("Regular Snake");
		this->_options.push_back(tmp);
		tmp.setString("Snake 2.0");
		this->_options.push_back(tmp);
		tmp.setString("Endless Snake");
		this->_options.push_back(tmp);
		tmp.setString("2-Player Snake");
		this->_options.push_back(tmp);
		tmp.setString("Back");
		this->_options.push_back(tmp);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_options[i].setPosition((SCREEN_WIDHT / 2) - (this->_options[i].getGlobalBounds().width / 2), (SCREEN_HEIGHT * (i + 1) / (this->_options.size() + 1)) - this->_options[i].getGlobalBounds().height / 2);
		}

		_options[_selectedOption].setFillColor(sf::Color::Red);
	}

	void Choose_Game_State::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					_options[_selectedOption].setFillColor(sf::Color::White);
					_selectedOption--;
					_selectedOption = (_selectedOption + _options.size()) % _options.size();
					_options[_selectedOption].setFillColor(sf::Color::Red);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					_options[_selectedOption].setFillColor(sf::Color::White);
					_selectedOption++;
					_selectedOption = (_selectedOption + _options.size()) % _options.size();
					_options[_selectedOption].setFillColor(sf::Color::Red);
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					_enter = _selectedOption;
				}
			}
		}
	}

	void Choose_Game_State::Update(float dt)
	{
		if (_enter == 0)
		{
			_data->machine.AddState(StateRef(new Game_State(this->_data)), 1);
		}
		if (_enter == 1)
		{
			_data->machine.AddState(StateRef(new Game_State_2(this->_data)), 1);
		}
		if (_enter == 2)
		{
			_data->machine.AddState(StateRef(new Game_State_3(this->_data)), 1);
		}
		if (_enter == 3)
		{
			_data->machine.AddState(StateRef(new Game_State_4(this->_data)), 1);
		}
		if (_enter == 4)
		{
			_data->machine.AddState(StateRef(new Main_Menu_State(this->_data)), 1);
		}
	}

	void Choose_Game_State::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_data->window.draw(this->_options[i]);
		}

		this->_data->window.display();
	}
}
