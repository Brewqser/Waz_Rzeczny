#include "SplashState.h"

namespace Brewque
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{

	}

	void SplashState::HandleInput()
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

	void SplashState::Update(float dt)
	{

	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);


		this->_data->window.display();
	}
}
