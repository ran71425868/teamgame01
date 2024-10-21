#include "all.h"

int player_shot_state;

extern float angle;

extern OBJ2D player;

int shot_frug;
int shot_frug2;

int timer;

//OBJ2D型の変数player_shotを宣言
OBJ2D player_shot;
OBJ2D player_shot2;
Sprite* sprShot;

//--------------------------------------
//  player_shotの初期設定
//--------------------------------------
void player_shot_init()
{
    //player_shot_stateを0
    player_shot_state = 0;
    int shot_frug=1;
    int shot_frug2=1;
    timer = 0;
}
//--------------------------------------
// 　player_shotの終了処理
//--------------------------------------
void player_shot_deinit()
{
    //sprShotを破棄
    safe_delete(sprShot);
}

//--------------------------------------
//  player_shotの更新処理
//--------------------------------------
void player_shot_update()
{
    switch (player_shot_state)
    {
    case 0:
        //////// 初期設定 ////////

        //player_shotの画像を読み込み
        sprShot = sprite_load(L"./Data/Images/shot.png");

        ++player_shot_state;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        //player_shotのパラメータ設定
        player_shot = {};
        player_shot.timer = 0;
        player_shot.pos ={ 0,0 };
        player_shot.scale = { 0.5f,0.5f };
        player_shot.texPos = { 0,0 };
        player_shot.texSize = { PLAYER_SHOT_TEX_W ,PLAYER_SHOT_TEX_H };
        player_shot.pivot = { PLAYER_SHOT_PIVOT_X,PLAYER_SHOT_PIVOT_Y };
        player_shot.color = { 1.0f,1.0f,1.0f,1.0f };
        player_shot.radius = 20.0f;
        player_shot.offset = { 0,0 };
     
        player_shot2 = {};
        player_shot2.timer = 0;
        player_shot2.pos = { 0,0 };
        player_shot2.scale = { 0.5f,0.5f };
        player_shot2.texPos = { 0,0 };
        player_shot2.texSize = { PLAYER_SHOT_TEX_W ,PLAYER_SHOT_TEX_H };
        player_shot2.pivot = { PLAYER_SHOT_PIVOT_X,PLAYER_SHOT_PIVOT_Y };
        player_shot2.color = { 1.0f,1.0f,1.0f,1.0f };
        player_shot2.radius = 20.0f;
        player_shot2.offset = { 0,0 };

        ++player_shot_state;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        player_shot_move();
        timer++;
        break;
    }
}

void player_shot_render()
{
    //弾の描画
    sprite_render(sprShot, player_shot2.pos.x, player_shot2.pos.y, player_shot2.scale.x, player_shot2.scale.y, player_shot2.texPos.x, player_shot2.texPos.y, player_shot2.texSize.x, player_shot2.texSize.y, player_shot2.pivot.x, player_shot2.pivot.y, ToRadian(player_shot2.angle), player_shot2.color.x, player_shot2.color.y);

    sprite_render(sprShot, player_shot.pos.x, player_shot.pos.y, player_shot.scale.x, player_shot.scale.y, player_shot.texPos.x, player_shot.texPos.y, player_shot.texSize.x, player_shot.texSize.y, player_shot.pivot.x, player_shot.pivot.y, ToRadian(player_shot.angle), player_shot.color.x, player_shot.color.y);
}

void player_shot_move()
{
    if (STATE(0) & PAD_TRG1&& shot_frug==1&&timer>50)
    {
        player_shot.angle = angle;

        player_shot.pos = player.pos;
        shot_frug = 0;
        timer = 0;
    }
    player_shot.pos.x += cosf(ToRadian(player_shot.angle - 90)) * 10;
    player_shot.pos.y += sinf(ToRadian(player_shot.angle - 90)) * 10;
    if (player_shot.pos.x<0 || player_shot.pos.x>SCREEN_W || player_shot.pos.y<0 || player_shot.pos.y>SCREEN_H)
        shot_frug = 1;



    if (STATE(0) & PAD_TRG1 && shot_frug2 == 1&&shot_frug==0)
    {
        if(timer>25)
        {
            player_shot2.angle = angle;

            player_shot2.pos = player.pos;
            shot_frug2 = 0;
        }
    }
    player_shot2.pos.x += cosf(ToRadian(player_shot2.angle - 90)) * 10;
    player_shot2.pos.y += sinf(ToRadian(player_shot2.angle - 90)) * 10;
    if (player_shot2.pos.x<0 || player_shot2.pos.x>SCREEN_W || player_shot2.pos.y<0 || player_shot2.pos.y>SCREEN_H)
        shot_frug2 = 1;
}

