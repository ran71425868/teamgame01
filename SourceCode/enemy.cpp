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
    {0,{  300, 0}},
    {0,{  500, 0}},
    {0,{  100, 0}},
    {1,{  200, 0}},
    {1,{  1000,720 }},
    {1,{  700, 720}},
    {2,{  800, 720}},
    {2,{  400, 720}},
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
        for (int i = 0; enemySet[i].enemyType >= 0; i++) {
            rnd = rand() % 1281;
            enemySet[i].pos.x = rnd;
        }
        for (int i = 0; enemySet[i].enemyType >= 0; i++) {
            enemySet[0].pos.y = 0;
            enemySet[1].pos.y = 0;
            enemySet[2].pos.y = 0;
            enemySet[3].pos.y = 0;

            enemySet[4].pos.y = 720;
            enemySet[5].pos.y = 720;
            enemySet[6].pos.y = 720;
            enemySet[7].pos.y = 720;



        }



        enemy_moveX();
        enemy_moveY();

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

    if (enemy[0].pos.x > SCREEN_W / 2) enemy[0].pos.x -= speed[0];
    else enemy[0].pos.x += speed[0];

    if (enemy[1].pos.x > SCREEN_W / 2) enemy[1].pos.x -= speed[1];
    else enemy[1].pos.x += speed[1];

    if (enemy[2].pos.x > SCREEN_W / 2) enemy[2].pos.x -= speed[2];
    else enemy[2].pos.x += speed[2];

    if (enemy[3].pos.x > SCREEN_W / 2) enemy[3].pos.x -= speed[3];
    else enemy[3].pos.x += speed[3];

    if (enemy[4].pos.x > SCREEN_W / 2) enemy[4].pos.x -= speed[4];
    else enemy[4].pos.x += speed[4];

    if (enemy[5].pos.x > SCREEN_W / 2) enemy[5].pos.x -= speed[5];
    else enemy[5].pos.x += speed[5];
    
    if (enemy[6].pos.x > SCREEN_W / 2) enemy[6].pos.x -= speed[6];
    else enemy[6].pos.x += speed[6];

    if (enemy[7].pos.x > SCREEN_W / 2) enemy[7].pos.x -= speed[7];
    else enemy[7].pos.x += speed[7];
}
void enemy_moveY()
{
   /* if (enemy[0].pos.y > SCREEN_H / 2)  enemy[0].pos.y -= speed[0];
    else enemy[0].pos.y += speed[0];


    if (enemy[1].pos.y > SCREEN_H / 2)  enemy[1].pos.y -= speed[1];
    else enemy[1].pos.y += speed[1];

    if (enemy[2].pos.y > SCREEN_H / 2)  enemy[2].pos.y -= speed[2];
    else enemy[2].pos.y += speed[2];

    if (enemy[3].pos.y > SCREEN_H / 2)  enemy[3].pos.y -= speed[3];
    else enemy[3].pos.y += speed[3];

    if (enemy[4].pos.y > SCREEN_H / 2)  enemy[4].pos.y -= speed[4];
    else enemy[4].pos.y += speed[4];

    if (enemy[5].pos.y > SCREEN_H / 2)  enemy[5].pos.y -= speed[5];
    else enemy[5].pos.y += speed[5];

    if (enemy[6].pos.y > SCREEN_H / 2)  enemy[6].pos.y -= speed[6];
    else enemy[6].pos.y += speed[6];

    if (enemy[7].pos.y > SCREEN_H / 2)  enemy[7].pos.y -= speed[7];
    else enemy[7].pos.y += speed[7];*/
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