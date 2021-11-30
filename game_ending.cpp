/* 
#include <iostream>
#include <bangtal>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace bangtal;

ScenePtr you_win, you_lose;

ObjectPtr ending_text_box[35];
int ending_idx = 1;

ScenePtr ending_scene(int idx)
{
	if (idx < 6) return you_lose;
	else if (idx < 15) return you_win;
}

void init_ending_scene()
{
	you_lose = Scene::create("", "텍스트상자-유빈/청룡탕2.jpg");
	you_win = Scene::create("", "텍스트상자-유빈/청룡탕 배경이미지.png");
}

void ending_init()
{
	for (int i = 1; i < 15; i++)
	{
		char ending_path[15] = { 0, };
		sprintf(ending_path, "텍스트상자/ending (%d).png", i);
		//모든 텍스트 상자는 이전 텍스트상자가 클릭되어야 나타ㅏ남

		ending_text_box[i] = Object::create(ending_path, ending_scene(i), 0, 0, false);
		ending_text_box[i]->setOnMouseCallback([&](ObjectPtr button, auto x, auto y, auto action)->bool
			{
				ending_text_box[ending_idx]->hide();
				if (is_scene_the_end(ending_idx)) //만약 마지막 텍스트라면
					ending_scene(ending_idx + 1)->enter();
				ending_text_box[++ending_idx]->show();

				return 0;
			});
	}
}

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	init_ending_scene();
	startGame(you_lose);
}

*/