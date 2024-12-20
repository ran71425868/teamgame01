#include "all.h"

int enemy_shot_state;

extern OBJ2D enemy[ENEMY_MAX];
extern OBJ2D tower;

OBJ2D enemy_shot;
Sprite* sprEnemyshot;


//--------------------------------------
//  enemy_shotの初期設定
//--------------------------------------
void enemy_shot_init()
{
	//enemy_shot_stateを0
	enemy_shot_state = 0;
}
//--------------------------------------
// 　enemy_shotの終了処理
//--------------------------------------
void enemy_shot_deinit()
{
	//enemyshotを破棄
    safe_delete(sprEnemyshot);
}
//--------------------------------------
//  enemy_shotの更新処理
//--------------------------------------
void enemy_shot_update()
{
    switch (enemy_shot_state)
    {
    case 0:
    {
        //////// 初期設定 ////////

       //enemy_shotの画像を読み込み
        sprEnemyshot = sprite_load(L"./Data/Images/shot.png");

        ++enemy_shot_state;
        /*fallthrough*/
    }


    case 1:
        //////// パラメータの設定 ////////

        enemy_shot = {};
        enemy_shot.timer = 0;
        enemy_shot.pos = { 0,0 };
        enemy_shot.scale = { 0.5f,0.5f };
        enemy_shot.texPos = { 0,0 };
        enemy_shot.texSize = { ENEMY_SHOT_TEX_W ,ENEMY_SHOT_TEX_H };
        enemy_shot.pivot = { ENEMY_SHOT_PIVOT_X,ENEMY_SHOT_PIVOT_Y };
        enemy_shot.color = { 1.0f,1.0f,1.0f,1.0f };
        enemy_shot.radius = 20.0f;
        enemy_shot.offset = { 0,0 };

        ++enemy_shot_state;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////


        break;
      
    }
}

void enemy_shot_render()
{
   
        //弾の描画
        sprite_render(enemy_shot.spr, enemy_shot.pos.x, enemy_shot.pos.y, enemy_shot.scale.x, enemy_shot.scale.y, enemy_shot.texPos.x, enemy_shot.texPos.y, enemy_shot.texSize.x, enemy_shot.texSize.y, enemy_shot.pivot.x, enemy_shot.pivot.y, ToRadian(enemy_shot.angle), enemy_shot.color.x, enemy_shot.color.y);
  
}

#if false
/// <summary>
/// 実際は SearchSet で空いてる弾を探す
/// そのあとにその弾に初期設定として以下の設定を行う
/// </summary>
/// <param name="v">SearchSet でさがしだした弾</param>
void enemy_launch_shot(OBJ2D* v)
{
    VECTOR2 vec;
    vec.x = tower.pos.x - enemy[i].pos.x;
    vec.y = tower.pos.y - enemy[i].pos.y;

    float diagonal = sqrtf(vec.x * vec.x + vec.y * vec.y);

    vec.x = vec.x / diagonal;
    vec.y = vec.y / diagonal;

    float speed = 10.0f;
    v->pos.x = vec.x * speed;
    v->pos.y = vec.y * speed;
}
#endif
