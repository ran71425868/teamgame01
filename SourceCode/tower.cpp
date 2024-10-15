#include "all.h"

int tower_state;
int hp;

extern OBJ2D enemy[ENEMY_MAX];


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
    hp = 10000;
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
       tower.pos = { SCREEN_W*0.5f,SCREEN_H*0.5f };
       tower.scale = { 1.0f,1.0f };
       tower.texPos = { 0,0 };
       tower.texSize = { TOWER_TEX_W ,TOWER_TEX_H };
       tower.pivot = { TOWER_PIVOT_X,TOWER_PIVOT_Y };
       tower.color = { 1.0f,1.0f,1.0f,1.0f };
       tower.radius = 20.0f;
       tower.offset = { 0,0 };


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
    primitive::rect(600, 280, 80, 10, 0, 0, ToRadian(0), 1, 0, 0.1);
    /*primitive::circle(640, 360,40,1,1, ToRadian(0), 1, 0, 0.1);*/
  

    text_out(0, std::to_string(hp), 0, 200, 2, 2);
}

void tower_hp() {
    for (int i = 0; i < 3; i++) {
        if (enemy[i].moveAlg == -1)
            hp -= 10;
    }
    for (int i = 3; i < 6; i++) {
        if (enemy[i].moveAlg == -1)
            hp -= 20;
    }
    for (int i = 6; i < 8; i++) {
        if (enemy[i].moveAlg == -1)
            hp -= 30;
    }

    if (hp < 0) {
        nextScene = SCENE_RESULT;
    }

}