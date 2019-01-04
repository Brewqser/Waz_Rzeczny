#include "Splash_State.h"
#include "Main_Menu_State.h"

namespace Brewque
{
	Splash_State::Splash_State(GameDataRef data) : _data(data)
	{

	}

	void Splash_State::Init()
	{
		this->_data->assets.LoadFont("Comic_Sans", SplashState_FontFilepath);
		_txt1.setFont(this->_data->assets.GetFont("Comic_Sans"));
		_txt1.setString("Game");
		_txt1.setCharacterSize(20);
		_txt2.setFont(this->_data->assets.GetFont("Comic_Sans"));
		_txt2.setString("made by");
		_txt2.setCharacterSize(20);
		_txt3.setFont(this->_data->assets.GetFont("Comic_Sans"));
		_txt3.setString("Michal 'Brewka' Czwornog");
		_txt3.setCharacterSize(20);
		this->_txt1.setFillColor(sf::Color(255, 255, 255, 0));
		this->_txt2.setFillColor(sf::Color(255, 255, 255, 0));
		this->_txt3.setFillColor(sf::Color(255, 255, 255, 0));
		this->_txt1.setPosition((SCREEN_WIDHT / 2) - (this->_txt1.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2 - this->_txt1.getGlobalBounds().height / 2 - 20));
		this->_txt2.setPosition((SCREEN_WIDHT / 2) - (this->_txt2.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2 - this->_txt2.getGlobalBounds().height / 2));
		this->_txt3.setPosition((SCREEN_WIDHT / 2) - (this->_txt3.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2 - this->_txt3.getGlobalBounds().height / 2 + 20));
	}

	void Splash_State::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void Splash_State::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() < SplashState_ShowTime * 2.0f / 3.0f)
		{
			int trnasparency = 255 * this->_clock.getElapsedTime().asSeconds() / (SplashState_ShowTime * 2 / 3);
			this->_txt1.setFillColor(sf::Color(255, 255, 255, trnasparency));
			this->_txt2.setFillColor(sf::Color(255, 255, 255, trnasparency));
			this->_txt3.setFillColor(sf::Color(255, 255, 255, trnasparency));
		}
		if (this->_clock.getElapsedTime().asSeconds() > SplashState_ShowTime )
		{
			_data->machine.AddState(StateRef(new Main_Menu_State(this->_data)), 1);
		}
	}

	void Splash_State::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(_txt1);
		this->_data->window.draw(_txt2);
		this->_data->window.draw(_txt3);

		this->_data->window.display();
	}
}
