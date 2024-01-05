#ifndef BILLIARDS_BILLIARDSTABLE_H
#define BILLIARDS_BILLIARDSTABLE_H

#include "ResourceManager.h"

class BilliardsTable {
private:
//    float tableModelDeltaX = -0.325f;
//    float tableModelDeltaY = -0.61f;
//    float tableModelScaleX = 2.16f;
//    float tableModelScaleY = 2.55f;
    
    float tableModelScaleX = 1.8f;
    float tableModelScaleY = 1.8f;

public:
    RectangleBoundingObject boundingRectangle;

    Model* model;

    BilliardsTable(RectangleBoundingObject boundingRectangle);

    void draw();
};

#endif //BILLIARDS_BILLIARDSTABLE_H
