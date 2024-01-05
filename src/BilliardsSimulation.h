#ifndef BILLIARDS_BILLIARDSSIMULATION_H
#define BILLIARDS_BILLIARDSSIMULATION_H

#include <vector>
#include "BilliardsBall.h"
#include "BilliardsStick.h"
#include "BilliardsPocket.h"
#include "BilliardsTable.h"
#include "AnimCharacter.h"
#include "Window.h"
#include "BoundingObject.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "Model.h"

enum class BilliardsSimState {
    POSITIONING_CUE_STICK, ANIMATING_CUE_STICK, SIMULATING_BALLS_MOVING, TRANSITIONING_CAMERA, BALL_ENTER_POCKET
};

class BilliardsSimulation {
private:
    float pocketRadius = 0.056f;
    float tableX = 0.0f;
    float tableY = 0.0f;
    float tableWidth = 1.09f;
    float tableHeight = 2.1f;
    float cornerHoleDeltaX = 0;
    float cornerHoleDeltaY = 0;
    float middleHoleDeltaX = 0;
    int cameraState = 1;
    int gameRound = 0;
    int gameOver = -1;
    int gameMode = 2;
    double gameScore = 0; //AI - human
    
    

    Window &window;
    Camera &camera;
    BilliardsTable table;
    BilliardsStick stick;
    vector<BilliardsBall> balls;
    vector<BilliardsBall> lastRoundBalls;
    vector<BilliardsPocket> pockets;

    int timesCameraMovedInTransition;
    BilliardsSimState stateAfterCameraTransition;
    Vector cameraTransitionPositionDelta;
    Vector cameraTransitionCenterDelta;
    Vector cameraTransitionUpDelta;

    void drawBoundingObjects();

    bool noBallsColliding();

    bool noBallsMoving();

    void manageCollisions();
    
    bool ballEnterPockets();
    
    Vector AItrain();
    
    double AIsimulate(Vector Params);
    
    double AIeval(int pocketedBall);
    
    double AIevalRule(vector<BilliardsBall> ballscopy);
    

    void enterCameraTransitionState(Vector cameraTransitionEndPosition, 
            Vector cameraTransitionEndCenter, 
            Vector cameraTransitionEndUp, 
            BilliardsSimState stateAfterCameraTransition);
    void CameraTransition(Vector cameraTransitionEndPosition,
            Vector cameraTransitionEndCenter,
            Vector cameraTransitionEndUp
                          );

    BilliardsSimState currentState = BilliardsSimState::SIMULATING_BALLS_MOVING;
public:
    BilliardsSimulation(Window &window, Camera &camera);

    void update(double timeDelta);

    void draw();
};

#endif //BILLIARDS_BILLIARDSSIMULATION_H
