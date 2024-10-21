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
        break;
      
    }
}

void enemy_shot_render()
{
   
        //�e�̕`��
        sprite_render(enemy_shot.spr, enemy_shot.pos.x, enemy_shot.pos.y, enemy_shot.scale.x, enemy_shot.scale.y, enemy_shot.texPos.x, enemy_shot.texPos.y, enemy_shot.texSize.x, enemy_shot.texSize.y, enemy_shot.pivot.x, enemy_shot.pivot.y, ToRadian(enemy_shot.angle), enemy_shot.color.x, enemy_shot.color.y);
  
}

#if false
/// <summary>
/// ���ۂ� SearchSet �ŋ󂢂Ă�e��T��
/// ���̂��Ƃɂ��̒e�ɏ����ݒ�Ƃ��Ĉȉ��̐ݒ���s��
/// </summary>
/// <param name="v">SearchSet �ł������������e</param>
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
