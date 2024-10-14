#include "all.h"

int tower_state;

//OBJ2D�^�̕ϐ�player��錾
OBJ2D tower;

Sprite* sprTower;

//--------------------------------------
//  �^���[�̏����ݒ�
//--------------------------------------
void tower_init()
{
    //tower_state��0
    tower_state = 0;
}
//--------------------------------------
// �@�^���[�̏I������
//--------------------------------------
void tower_deinit()
{
    //sprTower��j��
    safe_delete(sprTower);
}

//--------------------------------------
//  �^���[�̍X�V����
//--------------------------------------
void tower_update()
{
    switch (tower_state)
    {
    case 0:
        //////// �����ݒ� ////////

        //�v���C���[�̉摜��ǂݍ���
        sprTower = sprite_load(L"./Data/Images/castle_1.png");

        ++tower_state;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        //player�̃p�����[�^�ݒ�
       tower = {};
       tower.timer = 0;
       tower.pos = { SCREEN_W * 0.5f,SCREEN_H * 0.5f };
       tower.scale = { 1.0f,1.0f };
       tower.texPos = { 0,0 };
       tower.texSize = { PLAYER_TEX_W ,PLAYER_TEX_H };
       tower.pivot = { PLAYER_PIVOT_X,PLAYER_PIVOT_Y };
       tower.color = { 1.0f,1.0f,1.0f,1.0f };
       tower.radius = 20.0f;
       tower.offset = { 0,-32 };


        ++tower_state;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////



        

        break;
    }
}

void tower_render()
{
    //�^���[�̕`��
    sprite_render(sprTower, tower.pos.x, tower.pos.y, tower.scale.x, tower.scale.y, tower.texPos.x, tower.texPos.y, tower.texSize.x, tower.texSize.y, tower.pivot.x, tower.pivot.y, ToRadian(0), tower.color.x, tower.color.y);
   /* primitive::rect(600, 235, 80, 10, 0, 0, ToRadian(0), 1, 0, 0.1);*/
    primitive::circle(tower.pos.x, tower.pos.y, 40, 1, 1, ToRadian(0), 0.9f, 0.8f, 0.3f);
}