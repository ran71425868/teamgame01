#ifndef TOWER_H 
#define TOWER_H 

//tower�̉摜��`
#define TOWER_TEX_W                 128.0f
#define TOWER_TEX_H                 128.0f
#define TOWER_PIVOT_X               64.0f
#define TOWER_PIVOT_Y               64.0f

// �֐��̃v���g�^�C�v�錾 
void tower_init();
void tower_deinit();
void tower_update();
void tower_render();

void tower_hp();

#endif//SCENE_TITLE_H