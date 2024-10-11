#include "all.h"

extern OBJ2D player;
extern OBJ2D enemy[ENEMY_MAX];

//�����蔻��
bool hitCheckCircle(VECTOR2 pos1, float r1, VECTOR2 pos2, float r2) {
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float r = r1 + r2;

    if (dx * dx + dy * dy <= r * r)
        return true;

    return false;
}

bool hitCheck(OBJ2D* obj1, OBJ2D* obj2) {
    return hitCheckCircle(
        obj1->pos + obj1->offset, obj1->radius,
        obj2->pos + obj2->offset, obj2->radius
    );
}

void judge()
{

    //����
    for (int i = 0; i < ENEMY_MAX; i++) {
        if (enemy[i].moveAlg == -1)continue;

        if (hitCheck(&player, &enemy[i])) {
            enemy[i].moveAlg = -1;

            sound::play(XWB_SYSTEM, XWB_SYSTEM_SHOT);

           /* player.speed.x = 0.0f;
            player.speed.y = -13.0f;*/
            if (player.pos.y == SCREEN_H / 2) {
                player.speed.y = 0.0f;
            }
            game_score();
        }
    }
}
