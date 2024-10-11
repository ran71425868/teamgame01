#ifndef PLAYER_H
#define PLAYER_H

//******************************************************************************
//
//
//      player.h
//
//
//******************************************************************************



//プレイヤーの画像定義
#define PLAYER_TEX_W                 128.0f
#define PLAYER_TEX_H                 128.0f
#define PLAYER_PIVOT_X               64.0f
#define PLAYER_PIVOT_Y               128.0f




#define GRAVITY                     1.0f

//プレイヤーの加減速の定数
#define PLAYER_ACCEL_X      0.3f
#define PLAYER_ACCEL_Y      0.3f
#define PLAYER_DECEL_X      0.4f
#define PLAYER_DECEL_Y      0.4f
#define PLAYER_SPEED_X_MAX      8.0f

//壁の判定
#define WALL_LEFT          SCREEN_W - PLAYER_TEX_W * 0.5f
#define WALL_RIGHT          PLAYER_TEX_W * 0.5f


//地面の高さ
#define GROUND_Y                    600.0f

//------< 変数 >----------------------------------------------------------------

extern OBJ2D player;

//------< 関数 >----------------------------------------------------------------
void player_init();
void player_deinit();
void player_update();
void player_render();

void player_moveX();
void player_moveY();

#endif//PLAYER_H