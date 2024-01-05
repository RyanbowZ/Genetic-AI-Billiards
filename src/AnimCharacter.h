//
//  AnimCharacter.h
//  FINAL
//
//  Created by ryan zhou on 12/1/23.
//

#ifndef AnimCharacter_h
#define AnimCharacter_h
#include "ResourceManager.h"
class AnimCharacter {
private:
    
    float tableModelScaleX = 1;
    float tableModelScaleY = 1;
    
//    float tableModelDeltaX = -0.1f;
//    float tableModelDeltaY = -0.4f;
//    float tableModelScaleX = 0.01f;
//    float tableModelScaleY = 0.01f;

public:
    

    Model* model;
    Model* model2;
    Model* model3;

    AnimCharacter();

    void draw();
};


#endif /* AnimCharacter_h */
