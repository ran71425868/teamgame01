#ifndef PLAYER_SHOT_H 
#define PLAYER_SHOT_H 

//player_shotの画像定義
#define PLAYER_SHOT_TEX_W                 64.0f
#define PLAYER_SHOT_TEX_H                 64.0f
#define PLAYER_SHOT_PIVOT_X               32.0f
#define PLAYER_SHOT_PIVOT_Y               32.0f


// 関数のプロトタイプ宣言 
void player_shot_init();
void player_shot_deinit();
void player_shot_update();
void player_shot_render();

void player_shot_move();

#endif//PLAYER_SHOT_H