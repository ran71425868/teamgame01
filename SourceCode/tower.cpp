#include "all.h"

int tower_state;
int hp;

extern OBJ2D enemy[ENEMY_MAX];


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
    hp = 10000;
}
//--------------------------------------
// 　タワーの終了処理
//--------------------------------------
void tower_deinit()
{
    //sprTowerを破棄
    safe_delete(sprTower);
}

//--------------------------------------
//  タワーの更新処理
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
        //////// 通常時 ////////



        

        break;
    }
}

void tower_render()
{
    //タワーの描画
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