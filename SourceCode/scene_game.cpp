#include "all.h"
#include <sstream>

int game_state;
int game_timer;
int score;
int count;

extern int player_state;
extern int enemy_state;
extern OBJ2D enemy[ENEMY_MAX];


Sprite* sprBack;

std::ostringstream oss;                                 // •¶Žš—ñƒXƒgƒŠ[ƒ€
POINT point;

void game_init() {
	game_state = 0;
	game_timer = 0;
	score = 0;
	
}
void game_deinit() {
	music::stop(0);
	player_deinit();
	enemy_deinit();
	tower_deinit();
	shot_deinit();
}
void game_update() {
	switch (game_state) {
	case 0:
		sprBack = sprite_load(L"./Data/Images/map_1.png");

		audio_init();
		player_init();
		enemy_init();
		tower_init();
		shot_init();

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
		if (game_timer > 3000) {
			nextScene = SCENE_RESULT;
			break;
		}

		player_update();
		enemy_update();
		tower_update();
	 shot_update();

		judge();
		break;
	}

	game_timer++;
}
void game_render() {
	GameLib::clear(0, 0, 1);
	sprite_render(sprBack, 0, 0);


	text_out(0, "timer", 0, 0, 2, 2);
	text_out(0, std::to_string(game_timer), 0, 30, 2, 2);
	text_out(0, "score", 0, 70, 2, 2);
	text_out(0, std::to_string(score), 0, 100, 2, 2);
	text_out(4, "Down:S Right: D Left: A", 0, 150, 1, 1);
	

	player_render();
	enemy_render();
	tower_render();
	shot_render();
}
void game_score() {
	for (int i = 0; i < 3; i++) {
		if (enemy[i].moveAlg == -1)
			score += 10;
	}
	for (int i = 3; i < 6; i++) {
		if (enemy[i].moveAlg == -1)
			score += 20;
	}
	for (int i = 6; i < 8; i++) {
		if (enemy[i].moveAlg == -1)
			score += 30;
	}
}
