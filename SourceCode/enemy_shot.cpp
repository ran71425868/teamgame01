#include "all.h"

int enemy_shot_state;
float enemy_shot_angle;

extern OBJ2D enemy[ENEMY_MAX];

struct ENEMY_SHOT_DATA {
    Sprite* spr;
    const wchar_t* filePath;
    VECTOR2          texPos;
    VECTOR2          texSize;
    VECTOR2          pivot;
    float            radius;
}
enemyShotdata[] = {
       {NULL,   L"./Data/Images/shot.png", { 0,0 }, { 64, 64 }, { 32, 32 }, {20}},
};
OBJ2D enemy_shot[ENEMY_SHOT_MAX];

struct ENEMY_SHOT_SET {
    int enemyshotType;
    VECTOR2 pos;
}
enemySet[] = {
    {0,{  0, 0}},
    {0,{  0, 0}},
    {-1,{  -1, -1 }},
};

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
	//enemyshotを破棄
    int dataNum = ARRAYSIZE(enemyShotdata);
    for (int i = 0; i < dataNum; i++) {
        safe_delete(enemyShotdata[i].spr);
    }
}
//--------------------------------------
//  タワーの更新処理
//--------------------------------------
void enemy_shot_update()
{
    switch (enemy_shot_state)
    {
    case 0:
    {
        //////// 初期設定 ////////

       //enemy_shotの画像を読み込み
        int dataNum = sizeof(enemyShotdata) / sizeof(ENEMY_SHOT_DATA);
        for (int i = 0; i < dataNum; i++) {
            enemyShotdata[i].spr = sprite_load(enemyShotdata[i].filePath);
        }

        ++enemy_shot_state;
        /*fallthrough*/
    }
       

    case 1:
        //////// パラメータの設定 ////////

        for (int i = 0; i < ENEMY_SHOT_MAX; i++) {
            enemy_shot[i] = {};
            enemy_shot[i].moveAlg = -1;
        }
       
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
    for (int i = 0; i < ENEMY_SHOT_MAX; ++i)
    {
        if (enemy[i].moveAlg == -1)continue;

        //弾の描画
        sprite_render(enemy_shot[i].spr, enemy_shot[i].pos.x, enemy_shot[i].pos.y, enemy_shot[i].scale.x, enemy_shot[i].scale.y, enemy_shot[i].texPos.x, enemy_shot[i].texPos.y, enemy_shot[i].texSize.x, enemy_shot[i].texSize.y, enemy_shot[i].pivot.x, enemy_shot[i].pivot.y, ToRadian(enemy_shot[i].angle), enemy_shot[i].color.x, enemy_shot[i].color.y);
    }
}

void enemy_shot_move()
{
    if (STATE(0) & PAD_TRG1)
    {
        for (int i = 0; i < ENEMY_MAX; i++) {
            if (enemy[i].type == 1) {
                enemy_shot[i].pos = enemy[i].pos;
                enemy_shot[i].angle = enemy_shot_angle;
                /*if (enemy[i].pos.x < SCREEN_W && enemy[i].pos.y <= 0)enemy_shot_angle=90.0f;
                else if (enemy[i].pos.x > 0 && enemy[i].pos.y >= 720)enemy_shot_angle=-90.0f;
                if (enemy[i].pos.y < SCREEN_H && enemy[i].pos.x >= SCREEN_W)enemy_shot_angle=180.0f;
                else if (enemy[i].pos.y > 0 && enemy[i].pos.x <= 0)enemy_shot_angle=0.0f;*/
            }
            enemy_shot[i].pos.x += cosf(ToRadian(enemy_shot[i].angle - 90)) * 10;
            enemy_shot[i].pos.y += sinf(ToRadian(enemy_shot[i].angle - 90)) * 10;

        }
    }
}
