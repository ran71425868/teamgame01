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
//  �v���C���[�̏I������
//--------------------------------------
void tower_deinit()
{
    //sprTower��j��
    safe_delete(sprTower);
}

//--------------------------------------
//  �v���C���[�̍X�V����
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

      

        // �ʒu�ɑ��x�𑫂�
       


        // �n�ʂƂ̂����蔻��i���j
        if (player.pos.y > GROUND_Y) {
            player.pos.y = GROUND_Y;
            player.speed.y = 0.0f;
        }

        // �v���C���[�̍��E�̃G���A�`�F�b�N
        if (player.pos.x < 0 + WALL_RIGHT) {
            player.pos.x = 0 + WALL_RIGHT;
        }
        if (player.pos.x > WALL_LEFT) {
            player.pos.x = WALL_LEFT;
        }

        break;
    }
}

void tower_render()
{
    //�v���C���[�̕`��
    sprite_render(sprTower, tower.pos.x, tower.pos.y, tower.scale.x, tower.scale.y, tower.texPos.x, tower.texPos.y, tower.texSize.x, tower.texSize.y, tower.pivot.x, tower.pivot.y, ToRadian(0), tower.color.x, tower.color.y);
}