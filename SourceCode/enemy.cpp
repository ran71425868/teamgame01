#include "all.h"
#include	<stdlib.h>
#include	<time.h>

int rndX,rndY;
int enemy_state;
int speed[8] = { 1.5,2,2.5,3,3.5,5,5.5,7};

extern float angle;


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
    int moveType;
}
enemySet[] = {
    {0,{  300, 0}, 0},
    {0,{  500, 0}, 0},
    {0,{  100, 0}, 0},
    {1,{  200, 0}, 0},
    {1,{  1000,720 },0},
    {1,{  700, 720}, 0},
    {2,{  800, 720}, 0},
    {2,{  400, 720}, 0},
    {-1,{  -1, -1 }, -1},
};
//--------------------------------------
//  �G�l�~�[�̏����ݒ�
//--------------------------------------
void enemy_init()
{
    //player_state��0
    enemy_state = 0;

    srand((unsigned)time(NULL));
    for (int i = 0; enemySet[i].enemyType >= 0; i++) {
        rndX = rand() % 1281;
        enemySet[i].pos.x = rndX;
    }

    for (int i = 0; enemySet[i].enemyType >= 0; i++) {
       rndY = rand() % 2;
        if (rndY == 1) {
            rndY = rndY * 720;
        }
        enemySet[i].pos.y = rndY;
    }
}

//--------------------------------------
//  �G�l�~�[�̏I������
//--------------------------------------
void enemy_deinit()
{
    //Enemy��j��
    int dataNum = ARRAYSIZE(enemyData);
    for (int i = 0; i < dataNum; i++) {
        safe_delete(enemyData[i].spr);
    }
}

//--------------------------------------
//  �G�l�~�[�̍X�V����
//--------------------------------------
void enemy_update()
{
    switch (enemy_state)
    {
    case 0:
    {

        //////// �����ݒ� ////////

        //�G�l�~�[�̉摜��ǂݍ���
        int dataNum = sizeof(enemyData) / sizeof(ENEMY_DATA);
        for (int i = 0; i < dataNum; i++) {
            enemyData[i].spr = sprite_load(enemyData[i].filePath);
        }
        ++enemy_state;
        /*fallthrough*/
    }

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        for (int i = 0; i < ENEMY_MAX; i++) {
            enemy[i] = {};
            enemy[i].moveAlg = -1;
        }
        ++enemy_state;
        /*fallthrough*/

    case 2:
        //�����������x�Ăяo��
        for (int i = 0; enemySet[i].enemyType >= 0; i++) {
            OBJ2D* p = searchSet0(enemy, ENEMY_MAX, enemySet[i].enemyType, enemySet[i].pos);

            enemy[i].type = enemySet[i].moveType;

            if (!p) break;
        }

        for (int i = 0; enemySet[i].enemyType >= 0; i++) {
            rndX = rand() % 1281;
            enemySet[i].pos.x = rndX;
        }

        for (int i = 0; enemySet[i].enemyType >= 0; i++) {
            rndY = rand() % 2;
            if (rndY == 1) {
                rndY = rndY * 720;
            }
            enemySet[i].pos.y = rndY;
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

        // �G�l�~�[�̕`��
        sprite_render(enemy[i].spr, enemy[i].pos.x, enemy[i].pos.y, enemy[i].scale.x, enemy[i].scale.y, enemy[i].texPos.x, enemy[i].texPos.y, enemy[i].texSize.x, enemy[i].texSize.y, enemy[i].pivot.x, enemy[i].pivot.y, ToRadian(0), enemy[i].color.x, enemy[i].color.y, enemy[i].color.z, enemy[i].color.w);

    }
}
void enemy_moveX() {

    
    for (int i= 0; i < ENEMY_MAX; i++) {

        if (enemy[i].type == 0)
        {
            if (enemy[i].pos.x > SCREEN_W / 2) enemy[i].pos.x -= speed[0];
            else enemy[i].pos.x += speed[0];
        }
        
    }
}
void enemy_moveY(){
    for (int i = 0; i < ENEMY_MAX; i++) {

        if (enemy[i].type == 0)
        {
            if (enemy[i].pos.y < SCREEN_H / 2)  enemy[i].pos.y += speed[0];
            else enemy[i].pos.y -= speed[0];
        }
       
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
        ////////�ʏ펞////////
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
        ////////�ʏ펞////////
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
        ////////�ʏ펞////////
        break;
    }
}