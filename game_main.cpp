#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <random>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <iostream>
#include <bangtal>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace bangtal;

extern void beg_main();
extern void prac_main();

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	ScenePtr firstScene = Scene::create("", "Images/ÇÐ±³¾Õ.png");
	ObjectPtr start_game = Object::create("Images/clock1.png", firstScene, 500, 360);
	start_game->setOnMouseCallback([&](auto p, auto x, auto y, auto action)->bool
		{
			beg_main();
			return 0;
		});

	startGame(firstScene);
}