#ifndef SHOT_H 
#define SHOT_H 

//�v���C���[�̉摜��`
#define SHOT_TEX_W                 64.0f
#define SHOT_TEX_H                 64.0f
#define SHOT_PIVOT_X               32.0f
#define SHOT_PIVOT_Y               32.0f


// �֐��̃v���g�^�C�v�錾 
void shot_init();
void shot_deinit();
void shot_update();
void shot_render();

void shot_move();
void shot_radian();



#endif//SCENE_TITLE_H