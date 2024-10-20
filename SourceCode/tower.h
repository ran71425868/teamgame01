#ifndef TOWER_H 
#define TOWER_H 

//towerの画像定義
#define TOWER_TEX_W                 128.0f
#define TOWER_TEX_H                 128.0f
#define TOWER_PIVOT_X               64.0f
#define TOWER_PIVOT_Y               64.0f

// 関数のプロトタイプ宣言 
void tower_init();
void tower_deinit();
void tower_update();
void tower_render();

void tower_hp();

#endif//SCENE_TITLE_H