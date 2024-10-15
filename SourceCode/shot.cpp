#include "all.h"

int shot_state;

extern OBJ2D player;

//OBJ2D型の変数playerを宣言
OBJ2D shot;

Sprite* sprShot;

//--------------------------------------
//  タワーの初期設定
//--------------------------------------
void shot_init()
{
    //tower_stateを0
    shot_state = 0;
    
}
//--------------------------------------
// 　タワーの終了処理
//--------------------------------------
void shot_deinit()
{
    //sprTowerを破棄
    safe_delete(sprShot);
}

//--------------------------------------
//  タワーの更新処理
//--------------------------------------
void shot_update()
{
    switch (shot_state)
    {
    case 0:
        //////// 初期設定 ////////

        //プレイヤーの画像を読み込み
        sprShot = sprite_load(L"./Data/Images/shot.png");

        ++shot_state;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        //playerのパラメータ設定
        shot = {};
        shot.timer = 0;
        shot.pos = { SCREEN_W * 0.5f,SCREEN_H * 0.5f };
        shot.scale = { 1.0f,1.0f };
        shot.texPos = { 0,0 };
        shot.texSize = { SHOT_TEX_W ,SHOT_TEX_H };
        shot.pivot = { SHOT_PIVOT_X,SHOT_PIVOT_Y };
        shot.color = { 1.0f,1.0f,1.0f,1.0f };
        shot.radius = 20.0f;
        shot.offset = { 0,0 };


        ++shot_state;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////





        break;
    }
}

void shot_render()
{
    //タワーの描画
    sprite_render(sprShot, shot.pos.x, shot.pos.y, shot.scale.x, shot.scale.y, shot.texPos.x, shot.texPos.y, shot.texSize.x, shot.texSize.y, shot.pivot.x, shot.pivot.y, ToRadian(0), shot.color.x, shot.color.y);
    

    //text_out(0, std::to_string(hp), 0, 200, 2, 2);
}