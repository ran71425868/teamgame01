#ifndef ENEMY_SHOT_H 
#define ENEMY_SHOT_H 

#define ENEMY_SHOT_MAX   (2)

//enemy_shot�̉摜��`
#define ENEMY_SHOT_TEX_W                 64.0f
#define ENEMY_SHOT_TEX_H                 64.0f
#define ENEMY_SHOT_PIVOT_X               32.0f
#define ENEMY_SHOT_PIVOT_Y               32.0f


// �֐��̃v���g�^�C�v�錾 
void enemy_shot_init();
void enemy_shot_deinit();
void enemy_shot_update();
void enemy_shot_render();

void enemy_shot_move();
void moveEnemyshot0(OBJ2D* obj);

#endif//ENEMY_SHOT_H
