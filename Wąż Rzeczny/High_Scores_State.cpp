#include "High_Scores_State.h"

#include <string>
#include <iostream>
#include <fstream>

//using namespace std;


namespace Brewque
{
	High_Scores_State::High_Scores_State(GameDataRef data) : _data(data)
	{

	}

	void High_Scores_State::Init()
	{

		this->_enter = -1;
		this->_data->assets.LoadFont("Comic_Sans", ChooseGameState_FontFilepath);

		std::fstream plik;
		plik.open(HighScores_Filepath , std::ios::in);

		sf::Text tmp;
		std::string txt;
		tmp.setFont(this->_data->assets.GetFont("Comic_Sans"));

		while (!plik.eof())
		{
			std::getline( plik , txt);
			tmp.setString(txt);
			this->_options.push_back(tmp);

		}
		plik.close();

		tmp.setString("Back");
		this->_options.push_back(tmp);

		this->_selectedOption = _options.size() - 1;
		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_options[i].setPosition((SCREEN_WIDHT / 2) - (this->_options[i].getGlobalBounds().width / 2), (SCREEN_HEIGHT * (i + 1) / (this->_options.size() + 1)) - this->_options[i].getGlobalBounds().height / 2);
			std::cout << _options[i].getPosition().y << std::endl;
		}

		_options[_selectedOption].setFillColor(sf::Color::Red);
	}

	void High_Scores_State::HandleInput()
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
				if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape)
				{
					_enter = _selectedOption;
				}
			}
		}
	}

	void High_Scores_State::Update(float dt)
	{
		if (_enter == _options.size() - 1)
		{
			_data->machine.RemoveState();
		}
	}

	void High_Scores_State::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_data->window.draw(this->_options[i]);
		}

		this->_data->window.display();
	}
}
