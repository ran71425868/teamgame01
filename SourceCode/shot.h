#ifndef SHOT_H 
#define SHOT_H 

//プレイヤーの画像定義
#define SHOT_TEX_W                 32.0f
#define SHOT_TEX_H                 32.0f
#define SHOT_PIVOT_X               32.0f
#define SHOT_PIVOT_Y               32.0f


// 関数のプロトタイプ宣言 
void shot_init();
void shot_deinit();
void shot_update();
void shot_render();

void shot_move();

#endif//SCENE_TITLE_H