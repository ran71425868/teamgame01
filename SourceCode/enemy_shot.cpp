#include "all.h"

int enemy_shot_state;
float enemy_shot_angle;

extern OBJ2D enemy[ENEMY_MAX];

//OBJ2D型の変数enemy_shotを宣言
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
// 　タワーの終了処理
//--------------------------------------
void enemy_shot_deinit()
{
	//sprTowerを破棄
	safe_delete(sprEnemyshot);
}
//--------------------------------------
//  タワーの更新処理
//--------------------------------------
void enemy_shot_update()
{
    switch (enemy_shot_state)
    {
    case 0:
        //////// 初期設定 ////////

        //プレイヤーの画像を読み込み
        sprEnemyshot = sprite_load(L"./Data/Images/shot.png");

        ++enemy_shot_state;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        //playerのパラメータ設定
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

        enemy_shot_render();
        enemy_shot_move();
        break;
    }
}

void enemy_shot_render()
{
    //弾の描画
    sprite_render(sprEnemyshot, enemy_shot.pos.x, enemy_shot.pos.y, enemy_shot.scale.x, enemy_shot.scale.y, enemy_shot.texPos.x, enemy_shot.texPos.y, enemy_shot.texSize.x, enemy_shot.texSize.y, enemy_shot.pivot.x, enemy_shot.pivot.y, ToRadian(enemy_shot.angle), enemy_shot.color.x, enemy_shot.color.y);
}

void enemy_shot_move()
{
    if (STATE(0) & PAD_TRG1)
    {
        for (int i = 0; i < ENEMY_MAX; i++) {
            if (enemy[i].type == 1) {
                enemy_shot.pos = enemy[i].pos;
                enemy_shot.angle = enemy_shot_angle;
                /*if (enemy[i].pos.x < SCREEN_W && enemy[i].pos.y <= 0)enemy_shot_angle=90.0f;
                else if (enemy[i].pos.x > 0 && enemy[i].pos.y >= 720)enemy_shot_angle=-90.0f;
                if (enemy[i].pos.y < SCREEN_H && enemy[i].pos.x >= SCREEN_W)enemy_shot_angle=180.0f;
                else if (enemy[i].pos.y > 0 && enemy[i].pos.x <= 0)enemy_shot_angle=0.0f;*/
            }

        }
    }
    enemy_shot.pos.x += cosf(ToRadian(enemy_shot.angle - 90)) * 10;
    enemy_shot.pos.y += sinf(ToRadian(enemy_shot.angle - 90)) * 10;
}
