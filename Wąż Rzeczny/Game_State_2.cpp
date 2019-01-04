#include "Game_State_2.h"
#include "Game_Over_State.h"
#include <iostream>

namespace Brewque
{
	Game_State_2::Game_State_2(GameDataRef data) : _data(data)
	{

	}

	void Game_State_2::Init()
	{
		snake = new Snake(_data, 0, 255, 0, 0);
		fruit = new Fruit(_data, 0);
		score = new Score(_data, 0);

		fruit->Update(snake->GetSnake());
		_newdirection = Directions::Up;
		_gamestate = GameStates::Ready;
		_clock.restart();
	}

	void Game_State_2::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				system("pause");
			}
			if (_gamestate != GameStates::Over)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					_gamestate = GameStates::Playing;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					_gamestate = GameStates::Playing;
				}
			}
			if (_gamestate == GameStates::Playing)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					_newdirection = Directions::Left;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					_newdirection = Directions::Right;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					_newdirection = Directions::Up;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					_newdirection = Directions::Down;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					_gamestate = GameStates::Over;
				}
			}
		}
	}

	void Game_State_2::Update(float dt)
	{
		if (_gamestate == GameStates::Playing)
		{
			if (_clock.getElapsedTime().asMilliseconds() > Snake_Base_Speed)
			{
				if (_gamestate != GameStates::Over)
				{
					if (snake->getDirection() == Directions::Up && _newdirection != Directions::Down)
					{
						snake->SetDirection(_newdirection);
					}
					if (snake->getDirection() == Directions::Down && _newdirection != Directions::Up)
					{
						snake->SetDirection(_newdirection);
					}
					if (snake->getDirection() == Directions::Right && _newdirection != Directions::Left)
					{
						snake->SetDirection(_newdirection);
					}
					if (snake->getDirection() == Directions::Left && _newdirection != Directions::Right)
					{
						snake->SetDirection(_newdirection);
					}
					std::vector < std::pair < int, int > > tmpSnake = snake->GetSnake();
					bool increase = collision.CheckIsFruitOnWay(fruit->getX(), fruit->getY(), tmpSnake, snake->getDirection());
					if (increase == 1)
					{
						fruit->setEaten(1);
						snake->SetIncrease(1);
						score->Add(1);
					}
					int over = collision.CheckSnakeError2(snake->GetSnake(), snake->getDirection());
					if (over == 1)
					{
						_gamestate = GameStates::Over;
					}
					else
					{
						snake->Update();
						fruit->Update(tmpSnake);
					}
					_clock.restart();
				}
			}
		}

		if (_gamestate == GameStates::Over)
		{
			_data->machine.AddState(StateRef(new Game_Over_State(this->_data, 2,score->getScore())), 1);
		}
	}

	void Game_State_2::Draw(float dt)
	{

		this->_data->window.clear(sf::Color::Black);

		snake->Draw();
		fruit->Draw();
		score->Draw();

		this->_data->window.display();

	}
}
