#include "all.h"
#include	<stdlib.h>
#include	<time.h>

int rnd;
int enemy_state;
int speed[8] = { 5,5,5,10,10,10,13,13 };


struct ENEMY_DATA {
    Sprite* spr;
    const wchar_t* filePath;
    VECTOR2          texPos;
    VECTOR2          texSize;
    VECTOR2          pivot;
    float            radius;
}
enemyData[] = {
       {NULL,   L"./Data/Images/monster.png", { 0,0 }, { 160, 160 }, { 80, 80 }, {20}},
       {NULL,   L"./Data/Images/Green_monster.png", { 0,0 }, { 160, 160 }, { 80, 80 }, {20}},
       {NULL,   L"./Data/Images/Red_monster.png", { 0,0 }, { 160, 160 }, { 80, 80 }, {20}},
};
OBJ2D enemy[ENEMY_MAX];

struct ENEMY_SET {
    int enemyType;
    VECTOR2 pos;
}
enemySet[] = {
    {0,{  300, 540}},
    {0,{  500, 540}},
    {0,{  100, 540}},
    {1,{  200, 540}},
    {1,{  1000,540 }},
    {1,{  700, 540}},
    {2,{  800, 540}},
    {2,{  400, 540}},
    {-1,{  -1, -1 }},
};
//--------------------------------------
//  エネミーの初期設定
//--------------------------------------
void enemy_init()
{
    //player_stateを0
    enemy_state = 0;

    srand((unsigned)time(NULL));
    for (int i = 0; enemySet[i].enemyType >= 0; i++) {
        rnd = rand() % 1281;
        enemySet[i].pos.x = rnd;
    }

}

//--------------------------------------
//  エネミーの終了処理
//--------------------------------------
void enemy_deinit()
{
    //Enemyを破棄
    int dataNum = ARRAYSIZE(enemyData);
    for (int i = 0; i < dataNum; i++) {
        safe_delete(enemyData[i].spr);
    }
}

//--------------------------------------
//  エネミーの更新処理
//--------------------------------------
void enemy_update()
{
    switch (enemy_state)
    {
    case 0:
    {

        //////// 初期設定 ////////

        //エネミーの画像を読み込み
        int dataNum = sizeof(enemyData) / sizeof(ENEMY_DATA);
        for (int i = 0; i < dataNum; i++) {
            enemyData[i].spr = sprite_load(enemyData[i].filePath);
        }
        ++enemy_state;
        /*fallthrough*/
    }

    case 1:
        //////// パラメータの設定 ////////

        for (int i = 0; i < ENEMY_MAX; i++) {
            enemy[i] = {};
            enemy[i].moveAlg = -1;
        }
        ++enemy_state;
        /*fallthrough*/

    case 2:
        //討伐後もう一度呼び出す
        for (int i = 0; enemySet[i].enemyType >= 0; i++) {
            OBJ2D* p = searchSet0(enemy, ENEMY_MAX, enemySet[i].enemyType, enemySet[i].pos);
            if (!p) break;
        }

        enemy_moveX();

        for (int i = 0; i < ENEMY_MAX; i++) {
            if (enemy[i].moveAlg == -1)continue;

            switch (enemy[i].moveAlg) {
            case 0:
                moveEnemy0(&enemy[i]);
                break;
            case 1:
                moveEnemy1(&enemy[i]);
                break;
            case 2:
                moveEnemy2(&enemy[i]);
                break;
            }
            ++enemy[i].timer;
        }

        break;
    }
}

void enemy_render()
{

    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        if (enemy[i].moveAlg == -1)continue;

        // エネミーの描画
        sprite_render(enemy[i].spr, enemy[i].pos.x, enemy[i].pos.y, enemy[i].scale.x, enemy[i].scale.y, enemy[i].texPos.x, enemy[i].texPos.y, enemy[i].texSize.x, enemy[i].texSize.y, enemy[i].pivot.x, enemy[i].pivot.y, ToRadian(0), enemy[i].color.x, enemy[i].color.y, enemy[i].color.z, enemy[i].color.w);

    }
}
void enemy_moveX() {


    enemy[0].pos.x += speed[0];
    enemy[1].pos.x += speed[1];
    enemy[2].pos.x += speed[2];
    if (enemy[0].pos.x > 1280) {
        enemy[0].pos.x = 1280;
        speed[0] *= -1;
    }
    if (enemy[1].pos.x > 1280) {
        enemy[1].pos.x = 1280;
        speed[1] *= -1;
    }
    if (enemy[2].pos.x > 1280) {
        enemy[2].pos.x = 1280;
        speed[2] *= -1;
    }
    if (enemy[0].pos.x < 0) {
        enemy[0].pos.x = 0;
        speed[0] *= -1;
    }
    if (enemy[1].pos.x < 0) {
        enemy[1].pos.x = 0;
        speed[1] *= -1;
    }
    if (enemy[2].pos.x < 0) {
        enemy[2].pos.x = 0;
        speed[2] *= -1;
    }

    enemy[3].pos.x += speed[3];
    enemy[4].pos.x += speed[4];
    enemy[5].pos.x += speed[5];
    if (enemy[3].pos.x > 1280) {
        enemy[3].pos.x = 1280;
        speed[3] *= -1;
    }
    if (enemy[4].pos.x > 1280) {
        enemy[4].pos.x = 1280;
        speed[4] *= -1;
    }
    if (enemy[5].pos.x > 1280) {
        enemy[5].pos.x = 1280;
        speed[5] *= -1;
    }
    if (enemy[3].pos.x < 0) {
        enemy[3].pos.x = 0;
        speed[3] *= -1;
    }
    if (enemy[4].pos.x < 0) {
        enemy[4].pos.x = 0;
        speed[4] *= -1;
    }
    if (enemy[5].pos.x < 0) {
        enemy[5].pos.x = 0;
        speed[5] *= -1;
    }

    enemy[6].pos.x += speed[6];
    enemy[7].pos.x += speed[7];
    if (enemy[6].pos.x > 1280) {
        enemy[6].pos.x = 1280;
        speed[6] *= -1;
    }
    if (enemy[7].pos.x > 1280) {
        enemy[7].pos.x = 1280;
        speed[7] *= -1;
    }
    if (enemy[6].pos.x < 0) {
        enemy[6].pos.x = 0;
        speed[6] *= -1;
    }
    if (enemy[7].pos.x < 0) {
        enemy[7].pos.x = 0;
        speed[7] *= -1;
    }
}

void moveEnemy0(OBJ2D* obj)
{

    switch (obj->state) {
    case 0:

        obj->scale = { 1.0f, 1.0f };
        obj->color = { 1, 1, 1, 1 };
        obj->spr = enemyData[0].spr;
        obj->texPos = enemyData[0].texPos;
        obj->texSize = enemyData[0].texSize;
        obj->pivot = enemyData[0].pivot;
        obj->radius = enemyData[0].radius;

        ++obj->state;
        /*fallthrough*/

    case 1:
        ////////通常時////////
        break;
    }
}
void moveEnemy1(OBJ2D* obj)
{

    switch (obj->state) {
    case 0:

        obj->scale = { 1.0f, 1.0f };
        obj->color = { 1, 1, 1, 1 };
        obj->spr = enemyData[1].spr;
        obj->texPos = enemyData[1].texPos;
        obj->texSize = enemyData[1].texSize;
        obj->pivot = enemyData[1].pivot;
        obj->radius = enemyData[1].radius;

        ++obj->state;
        /*fallthrough*/

    case 1:
        ////////通常時////////
        break;
    }
}
void moveEnemy2(OBJ2D* obj)
{

    switch (obj->state) {
    case 0:

        obj->scale = { 1.0f, 1.0f };
        obj->color = { 1, 1, 1, 1 };
        obj->spr = enemyData[2].spr;
        obj->texPos = enemyData[2].texPos;
        obj->texSize = enemyData[2].texSize;
        obj->pivot = enemyData[2].pivot;
        obj->radius = enemyData[2].radius;

        ++obj->state;
        /*fallthrough*/

    case 1:
        ////////通常時////////
        break;
    }
}