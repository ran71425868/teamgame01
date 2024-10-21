#include "all.h"

int enemy_shot_state;
extern int game_timer;
float diagonal;
int enemy_shot_flug;

extern OBJ2D enemy[ENEMY_MAX];
extern OBJ2D tower;

OBJ2D enemy_shot;
OBJ2D vec;
OBJ2D v;
Sprite* sprEnemyshot;


//--------------------------------------
//  enemy_shot�̏����ݒ�
//--------------------------------------
void enemy_shot_init()
{
	//enemy_shot_state��0
	enemy_shot_state = 0;
    diagonal = 0;
    enemy_shot_flug = 1;
}
//--------------------------------------
// �@enemy_shot�̏I������
//--------------------------------------
void enemy_shot_deinit()
{
	//enemyshot��j��
    safe_delete(sprEnemyshot);
}
//--------------------------------------
//  enemy_shot�̍X�V����
//--------------------------------------
void enemy_shot_update()
{
    switch (enemy_shot_state)
    {
    case 0:
    {
        //////// �����ݒ� ////////

       //enemy_shot�̉摜��ǂݍ���
        sprEnemyshot = sprite_load(L"./Data/Images/shot.png");

        ++enemy_shot_state;
        /*fallthrough*/
    }


    case 1:
        //////// �p�����[�^�̐ݒ� ////////

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
        //////// �ʏ펞 ////////

        enemy_shot_flug++;
        enemy_shot_move();
        break;
      
    }
}

void enemy_shot_render()
{
   
        //�e�̕`��
        sprite_render(enemy_shot.spr, enemy_shot.pos.x, enemy_shot.pos.y, enemy_shot.scale.x, enemy_shot.scale.y, enemy_shot.texPos.x, enemy_shot.texPos.y, enemy_shot.texSize.x, enemy_shot.texSize.y, enemy_shot.pivot.x, enemy_shot.pivot.y, ToRadian(enemy_shot.angle), enemy_shot.color.x, enemy_shot.color.y);
  
}

void enemy_shot_move()
{
    if (game_timer>0)
    {
        for (int i = 0; i < ENEMY_MAX; i++) {
            if (enemy[i].type == 1&&enemy_shot_flug==1) {
                vec.pos.x = tower.pos.x - enemy->pos.x;
                vec.pos.x = tower.pos.x - enemy->pos.x;

                diagonal = sqrtf(vec.pos.x * vec.pos.x + vec.pos.y * vec.pos.y);

                v.pos.x = vec.pos.x / diagonal;
                v.pos.y = vec.pos.y / diagonal;
                enemy_shot_flug--;
               /* enemy_shot.pos = enemy[i].pos;
                enemy_shot.angle = enemy_shot_angle;
                if (enemy[i].pos.x < SCREEN_W && enemy[i].pos.y <= 0)enemy_shot_angle=90.0f;
                else if (enemy[i].pos.x > 0 && enemy[i].pos.y >= 720)enemy_shot_angle=-90.0f;
                if (enemy[i].pos.y < SCREEN_H && enemy[i].pos.x >= SCREEN_W)enemy_shot_angle=180.0f;
                else if (enemy[i].pos.y > 0 && enemy[i].pos.x <= 0)enemy_shot_angle=0.0f;*/
            }
           

        }
       
        enemy_shot.pos.x += cosf(ToRadian(enemy_shot.angle - 90)) * 10;
        enemy_shot.pos.y += sinf(ToRadian(enemy_shot.angle - 90)) * 10;
    }
}
