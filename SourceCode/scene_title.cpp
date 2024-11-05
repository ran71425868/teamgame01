#include "all.h"

//test

int title_state;
int title_timer;

Sprite* sprTitle;

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
		//////// �����ݒ� ////////

		audio_init();
		sprTitle = sprite_load(L"./Data/Images/title.png");
		title_state++;
		/*fallthrough*/

	case 1:
		//////// �p�����[�^�̐ݒ� ////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		music::play(2);
		music::setVolume(2, 0.5f);
		title_state++;
		/*fallthrough*/

	case 2:
		//////// �ʏ펞 ////////
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
	sprite_render(sprTitle, 0, 0);

	GameLib::text_out(3, "repel it", 225, 80, 5, 5, 1, 1, 0);
	GameLib::text_out(3, "the aliens", 404, 180, 5, 5, 1, 1, 0);

	if (title_timer / 32 % 2 == 1) {
		text_out(4, "Push Enter Key", 350, 450, 2, 2, 1, 1, 1);
	}

}