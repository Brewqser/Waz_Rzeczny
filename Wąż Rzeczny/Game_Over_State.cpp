#include "Game_Over_State.h"
#include "Main_Menu_State.h"
#include "Game_State.h"
#include "Game_State_2.h"
#include "Game_State_3.h"
#include "Choose_Game_State.h"


namespace Brewque
{
	Game_Over_State::Game_Over_State(GameDataRef data, int previous,long long int score) : _data(data) , _previous(previous) , _score(score)
	{

	}

	void Game_Over_State::Init()
	{
		std::vector <std::string> V;
		std::string txt;
		std::fstream plik;
		plik.open(HighScores_Filepath, std::ios::in);
		while (!plik.eof())
		{
			std::getline(plik, txt);
			V.push_back(txt);
		}
		plik.close();

		std::string ret;
		long long int a = _score;
		if (a == 0)  ret = '0' + ret;
		while (a > 0)
		{
			ret = (char)(a % 10 + 48) + ret;
			a /= 10;
		}
		if (_previous == 1)
		{
			V[1] = std::max(V[1], ret);
		}
		if (_previous == 2)
		{
			V[3] = std::max(V[3], ret);
		}
		if (_previous == 3)
		{
			V[5] = std::max(V[5], ret);
		}
		plik.open(HighScores_Filepath, std::ios::out);
		for (unsigned int i = 0; i < HighScores_lines; i++)
		{
			std::cout << V[i] << std::endl;
			plik << V[i];
			if (i != HighScores_lines - 1) plik << std::endl;
		}
		plik.close();

		this->_selectedOption = 0;
		this->_enter = -1;
		this->_data->assets.LoadFont("Comic_Sans", ChooseGameState_FontFilepath);

		sf::Text tmp;
		tmp.setFont(this->_data->assets.GetFont("Comic_Sans"));
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

		_options[_selectedOption].setFillColor(sf::Color::Red);
	}

	void Game_Over_State::HandleInput()
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

	void Game_Over_State::Update(float dt)
	{
		if (_enter == 0)
		{
			if (_previous == 1)
			{
				_data->machine.AddState(StateRef(new Game_State(this->_data)), 1);
			}
			if (_previous == 2)
			{
				_data->machine.AddState(StateRef(new Game_State_2(this->_data)), 1);
			}
			if (_previous == 3)
			{
				_data->machine.AddState(StateRef(new Game_State_3(this->_data)), 1);
			}
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

	void Game_Over_State::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		for (unsigned int i = 0; i < _options.size(); i++)
		{
			this->_data->window.draw(this->_options[i]);
		}

		this->_data->window.display();
	}
}
