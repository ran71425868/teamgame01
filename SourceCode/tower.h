#ifndef TOWER_H 
#define TOWER_H 

//プレイヤーの画像定義
#define TOWER_TEX_W                 128.0f
#define TOWER_TEX_H                 128.0f
#define TOWER_PIVOT_X               64.0f
#define TOWER_PIVOT_Y               64.0f




#define GRAVITY                     1.0f


//壁の判定
#define WALL_LEFT          SCREEN_W - PLAYER_TEX_W * 0.5f
#define WALL_RIGHT          PLAYER_TEX_W * 0.5f
#define WALL_DOWN          SCREEN_H - PLAYER_TEX_H * 0.5f
#define WALL_UP             PLAYER_TEX_H * 0.5f


// 関数のプロトタイプ宣言 
void tower_init();
void tower_deinit();
void tower_update();
void tower_render();

void tower_hp();

#endif//SCENE_TITLE_H