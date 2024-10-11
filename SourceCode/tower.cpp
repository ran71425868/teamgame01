#include "all.h"

int tower_state;

//OBJ2D型の変数playerを宣言
OBJ2D tower;

Sprite* sprTower;

//--------------------------------------
//  タワーの初期設定
//--------------------------------------
void tower_init()
{
    //tower_stateを0
    tower_state = 0;
}
//--------------------------------------
//  プレイヤーの終了処理
//--------------------------------------
void tower_deinit()
{
    //sprTowerを破棄
    safe_delete(sprTower);
}

//--------------------------------------
//  プレイヤーの更新処理
//--------------------------------------
void tower_update()
{
    switch (tower_state)
    {
    case 0:
        //////// 初期設定 ////////

        //プレイヤーの画像を読み込み
        sprTower = sprite_load(L"./Data/Images/castle_1.png");

        ++tower_state;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        //playerのパラメータ設定
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
        //////// 通常時 ////////

      

        // 位置に速度を足す
       


        // 地面とのあたり判定（仮）
        if (player.pos.y > GROUND_Y) {
            player.pos.y = GROUND_Y;
            player.speed.y = 0.0f;
        }

        // プレイヤーの左右のエリアチェック
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
    //プレイヤーの描画
    sprite_render(sprTower, tower.pos.x, tower.pos.y, tower.scale.x, tower.scale.y, tower.texPos.x, tower.texPos.y, tower.texSize.x, tower.texSize.y, tower.pivot.x, tower.pivot.y, ToRadian(0), tower.color.x, tower.color.y);
}