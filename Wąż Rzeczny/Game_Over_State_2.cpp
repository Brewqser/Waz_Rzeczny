#include "Game_Over_State_2.h"
#include "Main_Menu_State.h"
#include "Game_State_4.h"
#include "Choose_Game_State.h"


namespace Brewque
{
	Game_Over_State_2::Game_Over_State_2(GameDataRef data,long long int score1, long long int score2) : _data(data), _score1(score1), _score2(score2)
	{

	}

	void Game_Over_State_2::Init()
	{
		std::cout << _score1 << " " << _score2 << std::endl;
		this->_selectedOption = 0;
		this->_enter = -1;
		this->_data->assets.LoadFont("Comic_Sans", ChooseGameState_FontFilepath);

		sf::Text tmp;
		tmp.setFont(this->_data->assets.GetFont("Comic_Sans"));
		if (_score1 == _score2)
		{
			tmp.setString("REMIS");
			this->_options.push_back(tmp);
		}
		else if (_score1 > _score2)
		{
			tmp.setString("Player 1 Won");
			this->_options.push_back(tmp);
		}
		else
		{
			tmp.setString("Player 2 Won");
			this->_options.push_back(tmp);
		}
		tmp.setString("Restart");
		this->_options.push_back(tmp);
		tmp.setString("Choose Game");
		this->_options.push_back(tmp);
		tmp.setString("Main Menu");
		this->_options.push_back(tmp);
		tmp.setString("Exit");
		this->_options.push_back(tmp);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_options[i].setPosition((SCREEN_WIDHT / 2) - (this->_options[i].getGlobalBounds().width / 2), (SCREEN_HEIGHT * (i + 1) / (this->_options.size() + 1)) - this->_options[i].getGlobalBounds().height / 2);
		}

		_options[_selectedOption + 1].setFillColor(sf::Color::Red);
	}

	void Game_Over_State_2::HandleInput()
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
					_options[_selectedOption + 1].setFillColor(sf::Color::White);
					_selectedOption--;
					_selectedOption = (_selectedOption + (_options.size() -1 )) % (_options.size() - 1);
					_options[_selectedOption + 1].setFillColor(sf::Color::Red);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					_options[_selectedOption + 1].setFillColor(sf::Color::White);
					_selectedOption++;
					_selectedOption = (_selectedOption + (_options.size() - 1)) % (_options.size() - 1);
					_options[_selectedOption + 1].setFillColor(sf::Color::Red);
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					_enter = _selectedOption;
				}
			}
		}
	}

	void Game_Over_State_2::Update(float dt)
	{
		if (_enter == 0)
		{
			_data->machine.AddState(StateRef(new Game_State_4(this->_data)), 1);
		}
		if (_enter == 1)
		{
			_data->machine.AddState(StateRef(new Choose_Game_State(this->_data)), 1);
		}
		if (_enter == 2)
		{
			_data->machine.AddState(StateRef(new Main_Menu_State(this->_data)), 1);
		}
		if (_enter == 3)
		{
			this->_data->window.close();
		}
	}

	void Game_Over_State_2::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_data->window.draw(this->_options[i]);
		}

		this->_data->window.display();
	}
}