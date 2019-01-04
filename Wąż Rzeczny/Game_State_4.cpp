#include "Game_State_4.h"
#include "Game_Over_State_2.h"
#include <iostream>

namespace Brewque
{
	Game_State_4::Game_State_4(GameDataRef data) : _data(data)
	{

	}

	void Game_State_4::Init()
	{
		sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		this->_data->window.close();
		_data->window.create(sf::VideoMode((unsigned int)SCREEN_WIDHT *2, (unsigned int)SCREEN_HEIGHT, desktop.bitsPerPixel), GAME_NAME, sf::Style::Close | sf::Style::Titlebar);
		snake1 = new Snake(_data, 0, 255, 0, 0);
		fruit1 = new Fruit(_data, 0);
		score1 = new Score(_data, 0);
		snake2 = new Snake(_data, 0, 0, 255, SCREEN_WIDHT);
		fruit2 = new Fruit(_data, SCREEN_WIDHT);
		score2 = new Score(_data, SCREEN_WIDHT);

		_line[0].position = sf::Vector2f(SCREEN_WIDHT, 0);
		_line[1].position = sf::Vector2f(SCREEN_WIDHT, SCREEN_HEIGHT);
	
		fruit1->Update(snake1->GetSnake());
		fruit2->Update(snake2->GetSnake());

		_newdirection1 = Directions::Up;
		_gamestate1 = GameStates::Ready;
		_newdirection2 = Directions::Up;
		_gamestate2 = GameStates::Ready;
		_gameover = 0;
		_clock1.restart();
		_clock2.restart();
	}

	void Game_State_4::HandleInput()
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
			if (_gamestate1 != GameStates::Over)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					_gamestate1 = GameStates::Playing;
				}
			}
			if (_gamestate2 != GameStates::Over)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					_gamestate2 = GameStates::Playing;
				}
			}
			if (_gamestate1 == GameStates::Playing)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					_newdirection1 = Directions::Left;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					_newdirection1 = Directions::Right;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					_newdirection1 = Directions::Up;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					_newdirection1 = Directions::Down;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					_gamestate1 = GameStates::Over;
				}
			}
			if (_gamestate2 == GameStates::Playing)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					_newdirection2 = Directions::Left;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					_newdirection2 = Directions::Right;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					_newdirection2 = Directions::Up;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					_newdirection2 = Directions::Down;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
				{
					_gamestate2 = GameStates::Over;
				}
			}
		}
	}

	void Game_State_4::Update(float dt)
	{
		if (_gamestate1 == GameStates::Playing)
		{
			if (_clock1.getElapsedTime().asMilliseconds() > Snake_Base_Speed)
			{
				if (_gamestate1 != GameStates::Over)
				{
					if (snake1->getDirection() == Directions::Up && _newdirection1 != Directions::Down)
					{
						snake1->SetDirection(_newdirection1);
					}
					if (snake1->getDirection() == Directions::Down && _newdirection1 != Directions::Up)
					{
						snake1->SetDirection(_newdirection1);
					}
					if (snake1->getDirection() == Directions::Right && _newdirection1 != Directions::Left)
					{
						snake1->SetDirection(_newdirection1);
					}
					if (snake1->getDirection() == Directions::Left && _newdirection1 != Directions::Right)
					{
						snake1->SetDirection(_newdirection1);
					}
					std::vector < std::pair < int, int > > tmpSnake = snake1->GetSnake();
					bool increase = collision.CheckIsFruitOnWay(fruit1->getX(), fruit1->getY(), tmpSnake, snake1->getDirection());
					if (increase == 1)
					{
						fruit1->setEaten(1);
						snake1->SetIncrease(1);
						score1->Add(1);
					}
					int over = collision.CheckSnakeError2(snake1->GetSnake(), snake1->getDirection());
					if (over == 1)
					{
						_gamestate1 = GameStates::Over;
					}
					else
					{
						snake1->Update();
						fruit1->Update(tmpSnake);
					}
					_clock1.restart();
				}
			}
		}

		if (_gamestate2 == GameStates::Playing)
		{
			if (_clock2.getElapsedTime().asMilliseconds() > Snake_Base_Speed)
			{
				if (_gamestate2 != GameStates::Over)
				{
					if (snake2->getDirection() == Directions::Up && _newdirection2 != Directions::Down)
					{
						snake2->SetDirection(_newdirection2);
					}
					if (snake2->getDirection() == Directions::Down && _newdirection2 != Directions::Up)
					{
						snake2->SetDirection(_newdirection2);
					}
					if (snake2->getDirection() == Directions::Right && _newdirection2 != Directions::Left)
					{
						snake2->SetDirection(_newdirection2);
					}
					if (snake2->getDirection() == Directions::Left && _newdirection2 != Directions::Right)
					{
						snake2->SetDirection(_newdirection2);
					}
					std::vector < std::pair < int, int > > tmpSnake = snake2->GetSnake();
					bool increase = collision.CheckIsFruitOnWay(fruit2->getX(), fruit2->getY(), tmpSnake, snake2->getDirection());
					if (increase == 1)
					{
						fruit2->setEaten(1);
						snake2->SetIncrease(1);
						score2->Add(1);
					}
					int over = collision.CheckSnakeError2(snake2->GetSnake(), snake2->getDirection());
					if (over == 1)
					{
						_gamestate2 = GameStates::Over;
					}
					else
					{
						snake2->Update();
						fruit2->Update(tmpSnake);
					}	
				}
				_clock2.restart();
			}
		}

		if (_gamestate1 == GameStates::Over && _gamestate2 == GameStates::Over)
		{
			sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
			this->_data->window.close();
			_data->window.create(sf::VideoMode((unsigned int)SCREEN_WIDHT, (unsigned int)SCREEN_HEIGHT, desktop.bitsPerPixel), GAME_NAME, sf::Style::Close | sf::Style::Titlebar);
			_data->machine.AddState(StateRef(new Game_Over_State_2(this->_data, score1->getScore(), score2->getScore())), 1);
		}
	}

	void Game_State_4::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		snake1->Draw();
		fruit1->Draw();
		score1->Draw();
		snake2->Draw();
		fruit2->Draw();
		score2->Draw();
		_data->window.draw(_line, 2, sf::Lines);

		this->_data->window.display();
	}
}
