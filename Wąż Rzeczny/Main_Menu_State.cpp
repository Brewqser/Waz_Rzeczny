#include "Main_Menu_State.h"
#include "Choose_Game_State.h"
#include "High_Scores_State.h"

#include <iostream>


namespace Brewque
{
	Main_Menu_State::Main_Menu_State(GameDataRef data) : _data(data)
	{

	}

	void Main_Menu_State::Init()
	{
		this->_selectedOption = 0;
		this->_enter = -1;
		this->_data->assets.LoadFont("Comic_Sans", ChooseGameState_FontFilepath);

		sf::Text tmp;
		tmp.setFont(this->_data->assets.GetFont("Comic_Sans"));
		tmp.setString("Play");
		this->_options.push_back(tmp);
		tmp.setString("High Scores");
		this->_options.push_back(tmp);
		tmp.setString("Exit");
		this->_options.push_back(tmp);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_options[i].setPosition((SCREEN_WIDHT / 2) - (this->_options[i].getGlobalBounds().width / 2), (SCREEN_HEIGHT * (i + 1) / (this->_options.size() + 1)) - this->_options[i].getGlobalBounds().height / 2);
		}

		_options[_selectedOption].setFillColor(sf::Color::Red);
	}

	void Main_Menu_State::HandleInput()
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

	void Main_Menu_State::Update(float dt)
	{
		if (_enter == 0)
		{
			_data->machine.AddState(StateRef(new Choose_Game_State(this->_data)), 1);
		}
		if (_enter == 1)
		{
			_data->machine.AddState(StateRef(new High_Scores_State(this->_data)), 0);
			_enter = -1;
		}
		if (_enter == 2)
		{
			this->_data->window.close();
		}
	}

	void Main_Menu_State::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_data->window.draw(this->_options[i]);
		}

		this->_data->window.display();
	}
}
