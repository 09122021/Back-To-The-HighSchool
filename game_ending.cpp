#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <bangtal>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace bangtal;

ScenePtr you_win, you_lose;

ObjectPtr ending_text_box[14];
int ending_idx = 1;

ObjectPtr quiet_t;

ScenePtr ending_scene(int idx)
{
	if (idx <= 7) return you_win;
	else if (idx <= 12) return you_lose;
}

void init_ending_scene()
{
	you_lose = Scene::create("", "텍스트상자-유빈/청룡탕2.png");
	you_win = Scene::create("", "텍스트상자-유빈/청룡탕 배경이미지.jpg");
}

void ending_init()
{
	// quiet_t = Object::create("텍스트상자-유빈/professor.png", you_win, 700, 150);

	for (int i = 1; i < 13; i++)
	{
		char ending_path[50] = { 0, };
		sprintf(ending_path, "텍스트상자-유빈/ending (%d).png", i);
		//모든 텍스트 상자는 이전 텍스트상자가 클릭되어야 나타남

		ending_text_box[i] = Object::create(ending_path, ending_scene(i), 0, 0, false);
		ending_text_box[i]->setOnMouseCallback([&](ObjectPtr button, auto x, auto y, auto action)->bool
			{
				printf("%d\n", ending_idx);
				ending_text_box[ending_idx]->hide();

				if (ending_idx == 11) // 만약 실패 직전 텍스트라면
					you_lose->setImage("텍스트상자-유빈/game_final_ending.png");

				if (ending_idx == 7 || ending_idx == 12) // 만약 성공 또는 마지막 텍스트라면
					endGame();

				if (ending_idx != 12) ending_text_box[++ending_idx]->show();
				
				return 0;
			});
	}
}

// life_cut에서 체크해서 불러오기
void game_over_ending_main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	init_ending_scene();
	ending_init();
	you_lose->enter();
	ending_idx = 8;
	ending_text_box[8]->show();
}

void game_clear_ending_main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	init_ending_scene();
	ending_init();
	you_win->enter();
	ending_text_box[1]->show();
}