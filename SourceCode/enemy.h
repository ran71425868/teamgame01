#ifndef ENEMY_H
#define ENEMY_H

//******************************************************************************
//
//
//      enemy.h
//
//
//******************************************************************************

#define ENEMY_MAX   (8)


//�v���C���[�̉摜��`
#define ENEMY_TEX_W                 128.0f
#define ENEMY_TEX_H                 128.0f
#define ENEMY_PIVOT_X               64.0f
#define ENEMY_PIVOT_Y               128.0f

//------< ��� >----------------------------------------------------------------


//------< �֐� >----------------------------------------------------------------
void enemy_init();
void enemy_deinit();
void enemy_update();
void enemy_render();

void enemy_moveX();
void enemy_moveY();

void moveEnemy0(OBJ2D* obj);
void moveEnemy1(OBJ2D* obj);
void moveEnemy2(OBJ2D* obj);

#endif//ENEMY_H