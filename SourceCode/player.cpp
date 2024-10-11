#include "all.h"

int player_state;

//OBJ2D�^�̕ϐ�player��錾
OBJ2D player;

Sprite* sprPlayer;

//--------------------------------------
//  �v���C���[�̏����ݒ�
//--------------------------------------
void player_init()
{
    //player_state��0
    player_state = 0;
}
//--------------------------------------
//  �v���C���[�̏I������
//--------------------------------------
void player_deinit()
{
    //sprPlayer��j��
    safe_delete(sprPlayer);
}

//--------------------------------------
//  �v���C���[�̍X�V����
//--------------------------------------
void player_update()
{
    switch (player_state)
    {
    case 0:
        //////// �����ݒ� ////////

        //�v���C���[�̉摜��ǂݍ���
        sprPlayer = sprite_load(L"./Data/Images/UFO.png");

        ++player_state;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        //player�̃p�����[�^�ݒ�
        player = {};
        player.timer = 0;
        player.pos = { SCREEN_W * 0.5f,SCREEN_H * 0.5f };
        player.scale = { 1.0f,1.0f };
        player.texPos = { 0,0 };
        player.texSize = { PLAYER_TEX_W ,PLAYER_TEX_H };
        player.pivot = { PLAYER_PIVOT_X,PLAYER_PIVOT_Y };
        player.color = { 1.0f,1.0f,1.0f,1.0f };
        player.radius = 20.0f;
        player.offset = { 0,-32 };


        ++player_state;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

        //player_moveX�EY���Ă�
        player_moveY();
        player_moveX();

        // �ʒu�ɑ��x�𑫂�
        player.pos += player.speed;


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

void player_render()
{
    //�v���C���[�̕`��
    sprite_render(sprPlayer, player.pos.x, player.pos.y, player.scale.x, player.scale.y, player.texPos.x, player.texPos.y, player.texSize.x, player.texSize.y, player.pivot.x, player.pivot.y, ToRadian(0), player.color.x, player.color.y);
}

void player_moveY()
{
    //�����A��
    if (player.pos.y == 600) {
        player.speed.x = 0.0f;
        player.speed.y = -13.0f;
        if (player.pos.y == SCREEN_H / 2) {
            player.speed.y = 0.0f;
        }
    }
}


void player_moveX()
{

    //�C�ӂ̑���ɂ��ړ�

    if (STATE(0) & PAD_DOWN && !(STATE(0) & PAD_UP)) {
        player.speed.y += PLAYER_ACCEL_Y;
        player.scale.y = 1.0f;

    }
    else {
        if (player.speed.y > 0) {
            player.speed.y -= PLAYER_DECEL_Y;
            if (player.speed.y < 0)
                player.speed.y = 0.0f;

        }

        if (player.speed.y < 0) {
            player.speed.y += PLAYER_DECEL_Y;
            if (player.speed.y > 0)
                player.speed.y = 0.0f;

        }
    }

    if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT)) {
        player.speed.x -= PLAYER_ACCEL_X;
        player.scale.x = -1.0f;
    }
    else if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT)) {
        player.speed.x += PLAYER_ACCEL_X;
        player.scale.x = 1.0f;

    }
    else {
        if (player.speed.x > 0) {
            player.speed.x -= PLAYER_DECEL_X;
            if (player.speed.x < 0) {
                player.speed.x = 0.0f;
            }
        }

        if (player.speed.x < 0) {
            player.speed.x += PLAYER_DECEL_X;
            if (player.speed.x > 0) {
                player.speed.x = 0.0f;
            }
        }

    }
    if (player.speed.x >= PLAYER_SPEED_X_MAX)
        player.speed.x = PLAYER_SPEED_X_MAX;

    if (player.speed.x <= -PLAYER_SPEED_X_MAX)
        player.speed.x = -PLAYER_SPEED_X_MAX;
}