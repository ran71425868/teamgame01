#include "all.h"

OBJ2D* searchSet0(OBJ2D arr[], int dataNum, int moveAlg, VECTOR2 pos)
{
    //searchSet関数の作成
    for (int i = 0; i < dataNum; i++) {
        if (arr[i].moveAlg != -1)continue;
        //arr[i] = {};
        arr[i].moveAlg = moveAlg;
        arr[i].pos = pos;
        return &arr[i];
    }



    return NULL;                        // 生成できなかった
}