#include "all.h"

int title_state;
int title_timer;

void title_init() {
	title_state = 0;
	title_timer = 0;
}
void title_deinit() {
	music::stop(2);
	
}
void title_update() {
	switch (title_state) {
	case 0:
		//////// 初期設定 ////////
		audio_init();
		title_state++;
		/*fallthrough*/

	case 1:
		//////// パラメータの設定 ////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		music::play(2);
		music::setVolume(2, 0.5f);
		title_state++;
		/*fallthrough*/

	case 2:
		//////// 通常時 ////////
		if (TRG(0) & PAD_START) {
			nextScene = SCENE_GAME;
			break;
		}

		break;
	}



	title_timer++;
}
void title_render() {
	GameLib::clear(0, 0, 0);

	GameLib::text_out(4, "Monster Smash!", 90, 80, 4, 4, 1, 1, 0);

	if (title_timer / 32 % 2 == 1) {
		text_out(4, "Push Enter Key", 350, 450, 2, 2, 1, 1, 1);
	}

}