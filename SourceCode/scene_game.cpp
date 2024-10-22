#include "all.h"
#include <sstream>

int game_state;
int game_timer;

int score;
int kill;
float comboscore;
int combo;

extern int player_state;
extern int enemy_state;
extern OBJ2D enemy[ENEMY_MAX];

Sprite* sprBack;

std::ostringstream oss;                                 // ������X�g���[��
POINT point;

void game_init() {
	game_state = 0;
	game_timer = 0;
	score = 0;
	kill = 0;
	combo = 0;
	comboscore = 1.0f;
}
void game_deinit() {
	music::stop(0);
	player_deinit();
	enemy_deinit();
	tower_deinit();
	player_shot_deinit();
	enemy_shot_deinit();
}
void game_update() {
	switch (game_state) {
	case 0:
		sprBack = sprite_load(L"./Data/Images/map_1.png");

		audio_init();
		player_init();
		enemy_init();
		tower_init();
		player_shot_init();
		enemy_shot_init();

		game_state++;
		/*fallthrough*/

	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);

		music::play(0);
		music::setVolume(0, 0.3f);

		game_state++;
		/*fallthrough*/

	case 2:
		if (TRG(0) & PAD_SELECT) {
			nextScene = SCENE_TITLE;
			break;
		}

		player_update();
		enemy_update();
		tower_update();
		player_shot_update();
		enemy_shot_update();

		judge();
		break;
	}

	game_timer++;
}
void game_render() {
	GameLib::clear(0, 0, 1);
	sprite_render(sprBack, 0, 0);


	text_out(4, "Up:W Down:S Right: D Left: A", 0, 0, 1, 1);
	text_out(4, "angle++:Up Key angle--:Down Key", 0, 30, 1, 1);
	text_out(0, "score", 1100, 0, 2, 2);
	text_out(0, std::to_string(score), 1100, 50, 2, 2);
	text_out(0, "kill", 0, 80, 2, 2);
	text_out(0, std::to_string(kill), 0, 110, 2, 2);
	text_out(0, "combo", 0, 150, 2, 2);
	text_out(0, std::to_string(combo), 0, 200, 2, 2);
	

	player_render();
	enemy_render();
	tower_render();
	player_shot_render();
	enemy_shot_render();
}
void game_score() {
	if (combo >= 30)
		comboscore = 2.5f;
	else if (combo >= 20)
		comboscore = 2.0f;
	else if (combo >= 10)
		comboscore = 1.5f;
	else
		comboscore = 1.0f;


	for (int i = 0; i < 3; i++) {
		if (enemy[i].moveAlg == -1 )
			score += 100*comboscore;
		
	}
	for (int i = 3; i < 6; i++) {
		if (enemy[i].moveAlg == -1)
			score += 200*comboscore;
	}
	for (int i = 6; i < 8; i++) {
		if (enemy[i].moveAlg == -1)
			score += 150*comboscore;
	}
	kill ++;
	combo++;
}
