#pragma once

#define SplashState_ShowTime 3

#define Board_Size 29
#define Part_Size 15.f 
#define Score_Hight 30
#define SCREEN_WIDHT (Board_Size*(int)Part_Size)
#define SCREEN_HEIGHT (Board_Size*Part_Size + Score_Hight)
#define GAME_NAME "Waz Rzeczny"

#define Start_Size 3
#define Snake_Base_Speed 300

#define SplashState_FontFilepath "Resources/Fonts/Comic Sans.ttf"
#define ChooseGameState_FontFilepath "Resources/Fonts/Comic Sans.ttf"
#define Score_FontFilepath "Resources/Fonts/Comic Sans.ttf"

#define HighScores_Filepath "Resources/High Scores.txt"
#define HighScores_lines 6

enum Directions
{
	Down,
	Up,
	Left,
	Right,
};

enum GameStates
{
	Ready,
	Playing,
	Over,
};
