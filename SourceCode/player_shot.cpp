#include "all.h"

int player_shot_state;

extern float angle;

extern OBJ2D player;

//OBJ2D型の変数playerを宣言
OBJ2D player_shot;

Sprite* sprShot;

//--------------------------------------
//  タワーの初期設定
//--------------------------------------
void player_shot_init()
{
    //player_shot_stateを0
    player_shot_state = 0;
}
//--------------------------------------
// 　タワーの終了処理
//--------------------------------------
void player_shot_deinit()
{
    //sprTowerを破棄
    safe_delete(sprShot);
}

//--------------------------------------
//  タワーの更新処理
//--------------------------------------
void player_shot_update()
{
    switch (player_shot_state)
    {
    case 0:
        //////// 初期設定 ////////

        //プレイヤーの画像を読み込み
        sprShot = sprite_load(L"./Data/Images/shot.png");

        ++player_shot_state;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        //playerのパラメータ設定
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
     


        ++player_shot_state;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

       player_shot_render();
        player_shot_move();
        break;
    }
}

void player_shot_render()
{
    //弾の描画
    sprite_render(sprShot, player_shot.pos.x, player_shot.pos.y, player_shot.scale.x, player_shot.scale.y, player_shot.texPos.x, player_shot.texPos.y, player_shot.texSize.x, player_shot.texSize.y, player_shot.pivot.x, player_shot.pivot.y, ToRadian(player_shot.angle), player_shot.color.x, player_shot.color.y);
}

void player_shot_move()
{
    if (STATE(0) & PAD_TRG1)
    {
        player_shot.angle = angle;

        player_shot.pos = player.pos;
    }
    player_shot.pos.x += cosf(ToRadian(player_shot.angle - 90)) * 10;
    player_shot.pos.y += sinf(ToRadian(player_shot.angle - 90)) * 10;

}

