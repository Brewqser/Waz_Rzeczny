#include "Score.h"

namespace Brewque
{
	Score::Score(GameDataRef data, int offset) : _data(data), _offset(offset)
	{
		this->_data->assets.LoadFont("Comic_Sans", ChooseGameState_FontFilepath);
		_line[0].position = sf::Vector2f(_offset, SCREEN_HEIGHT - Score_Hight);
		_line[1].position = sf::Vector2f(SCREEN_WIDHT + _offset , SCREEN_HEIGHT - Score_Hight);
		this->_points = 0;
	}

	void Score::Add(int n)
	{
		_points += n;
	}

	long long int Score::getScore()
	{
		return _points;
	}

	void Score::Draw()
	{
		sf::Text tmp;
		std::string tmp1 = "SCORE: ";
		std::string ret;
		long long int a = _points;
		if (a == 0)  ret = '0' + ret;
		while (a > 0)
		{
			ret = (char)(a % 10 + 48) + ret;
			a /= 10;
		}
		tmp1 = tmp1 + ret;
		tmp.setFont(this->_data->assets.GetFont("Comic_Sans"));
		tmp.setString(tmp1);
		tmp.setCharacterSize(20);
		tmp.setOrigin(tmp.getGlobalBounds().width / 2, tmp.getGlobalBounds().height / 2);
		tmp.setPosition(SCREEN_WIDHT / 2 + _offset, SCREEN_HEIGHT - Score_Hight / 2 - 5);
		_data->window.draw(tmp);
		_data->window.draw(_line, 2, sf::Lines);
	}
}