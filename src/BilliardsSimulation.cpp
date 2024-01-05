#include "BilliardsSimulation.h"

BilliardsSimulation::BilliardsSimulation(Window &window, Camera &camera)
        : window(window),
          camera(camera),
          table(RectangleBoundingObject(tableX, tableY, tableWidth, tableHeight)) {
    Light light = Light(Vector(0, 4, 0), Vector(0.1, 0.1, 0.1), Vector(0.3, 0.3, 0.3), Vector(0.0, 0.0, 0.0));

    ResourceManager::getShader("default")->setLightProperty(light);
    ResourceManager::getShader("default")->setMatProperty("proj_mat", camera.projectionMatrix.m);
    ResourceManager::getShader("default")->setMatProperty("view_mat", camera.viewMatrix.m);

    ResourceManager::getShader("bounding_object")->setMatProperty("proj_mat", camera.projectionMatrix.m);
    ResourceManager::getShader("bounding_object")->setMatProperty("view_mat", camera.viewMatrix.m);

    float tableTopX = tableX - (tableWidth / 2.0f);
    float tableTopY = tableY - (tableHeight / 2.0f);

    pockets.push_back(BilliardsPocket(CircleBoundingObject(tableTopX + cornerHoleDeltaX,
                                                           tableTopY + cornerHoleDeltaY,
                                                           pocketRadius)));
    pockets.push_back(BilliardsPocket(CircleBoundingObject(tableTopX + tableWidth - cornerHoleDeltaX,
                                                           tableTopY + cornerHoleDeltaY,
                                                           pocketRadius)));
    pockets.push_back(BilliardsPocket(CircleBoundingObject(tableTopX + cornerHoleDeltaX,
                                                           tableTopY + tableHeight - cornerHoleDeltaY,
                                                           pocketRadius)));
    pockets.push_back(BilliardsPocket(CircleBoundingObject(tableTopX + tableWidth - cornerHoleDeltaX,
                                                           tableTopY + tableHeight - cornerHoleDeltaY,
                                                           pocketRadius)));
    pockets.push_back(BilliardsPocket(CircleBoundingObject(tableTopX + middleHoleDeltaX,
                                                           tableTopY + (tableHeight / 2.0f),
                                                           pocketRadius*1.05f)));
    pockets.push_back(BilliardsPocket(CircleBoundingObject(tableTopX + tableWidth - middleHoleDeltaX,
                                                           tableTopY + (tableHeight / 2.0f),
                                                           pocketRadius*1.05f)));

//    balls.push_back(BilliardsBall(Vector(0.4f, -0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 0));
//    balls.push_back(BilliardsBall(Vector(0.0f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 1));
//    balls.push_back(BilliardsBall(Vector(0.1f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 2));
//    balls.push_back(BilliardsBall(Vector(0.2f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 3));
//    balls.push_back(BilliardsBall(Vector(0.3f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 4));
//    balls.push_back(BilliardsBall(Vector(0.4f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 5));
//    balls.push_back(BilliardsBall(Vector(-0.1f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 6));
//    balls.push_back(BilliardsBall(Vector(-0.2f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 7));
//    balls.push_back(BilliardsBall(Vector(-0.3f, 0.0f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 8));
//    balls.push_back(BilliardsBall(Vector(0.1f, -0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 9));
//    balls.push_back(BilliardsBall(Vector(0.2f, -0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 10));
//    balls.push_back(BilliardsBall(Vector(0.0f, 0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 11));
//    balls.push_back(BilliardsBall(Vector(0.1f, 0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 12));
//    balls.push_back(BilliardsBall(Vector(0.2f, 0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 13));
//    balls.push_back(BilliardsBall(Vector(0.3f, 0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 14));
//    balls.push_back(BilliardsBall(Vector(0.4f, 0.1f, 0.0f), Vector(0.8f, 0.8f, 0.0f), 15));
      balls.push_back(BilliardsBall(Vector(0.0f, -0.4f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 0));
      balls.push_back(BilliardsBall(Vector(0.0f, 0.4f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 1));
      balls.push_back(BilliardsBall(Vector(0.03f, 0.46f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 2));
      balls.push_back(BilliardsBall(Vector(-0.03f, 0.46f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 3));
      balls.push_back(BilliardsBall(Vector(0.06f, 0.52f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 4));
      balls.push_back(BilliardsBall(Vector(0.0f, 0.52f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 5));
      balls.push_back(BilliardsBall(Vector(-0.06f, 0.52f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 6));
      balls.push_back(BilliardsBall(Vector(-0.09f, 0.58f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 7));
      balls.push_back(BilliardsBall(Vector(-0.03f, 0.58f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 8));
      balls.push_back(BilliardsBall(Vector(0.03f, 0.58f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 9));
      balls.push_back(BilliardsBall(Vector(0.09f, 0.58f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10));
      balls.push_back(BilliardsBall(Vector(-0.13f, 0.64f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 11));
      balls.push_back(BilliardsBall(Vector(-0.06f, 0.64f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 12));
      balls.push_back(BilliardsBall(Vector(0.0f, 0.64f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 13));
      balls.push_back(BilliardsBall(Vector(0.06f, 0.64f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 14));
      balls.push_back(BilliardsBall(Vector(0.13f, 0.64f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 15));
      lastRoundBalls=balls;
              
    srand (static_cast <unsigned> (time(0))); //seed random
}

bool BilliardsSimulation::noBallsMoving() {
    for (int i = 0; i < balls.size(); i++) {
        double speed = balls[i].velocity.length();
        if (speed > BilliardsBall::smallestSpeed) {
            return false;
        }
    }
    return true;
}

bool BilliardsSimulation::noBallsColliding() {
    for (int i = 0; i < balls.size(); i++) {
        for (int j = i + 1; j < balls.size(); j++) {
            BilliardsBall &ball1 = balls[i];
            BilliardsBall &ball2 = balls[j];

            double x1 = ball1.position.x;
            double x2 = ball2.position.x;
            double y1 = ball1.position.y;
            double y2 = ball2.position.y;

            double radius = ball1.radius;

            double distanceSquared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            if (distanceSquared < 4 * radius * radius) {
                return false;
            }
        }
    }
    return true;
}

bool BilliardsSimulation::ballEnterPockets(){
//    if(!balls.size()){
//        gameOver=gameRound%2;
//    }
    bool marker=false;
    for (int i = 0; i < balls.size(); i++) {
        BilliardsBall &ball1 = balls[i];
        
        for (BilliardsPocket &pocket : pockets) {
            
            double x1 = ball1.position.x;
            double x2 = pocket.boundingCircle.x;
            double y1 = ball1.position.y;
            double y2 = pocket.boundingCircle.y;
            
            double radius1 = ball1.radius;
            double radius2 = pocket.boundingCircle.radius;
            double distanceSquared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            //if (distanceSquared < pow((radius1+radius2),2)) {
            if (distanceSquared < pow((radius2),2)) {
                Util::log(Severity::INFO, "Ball Detected Entered Pockets, Ball Number: #"+std::to_string(ball1.ballNumber));
                balls.erase(balls.begin()+i);
                
                i--;
                //ball1.position.z=-1;
                marker=true;
                
                Util::log(INFO, "ballsize== "+std::to_string(int(balls.size())));
                continue;
            }
            
        }
    }
    return marker;
}

void BilliardsSimulation::manageCollisions() {
    for (int i = 0; i < balls.size(); i++) {
        BilliardsBall &ball = balls[i];
        // Check for collision with table
        float tableRightBorder = table.boundingRectangle.x + (table.boundingRectangle.width / 2.0f);
        float tableLeftBorder = table.boundingRectangle.x - (table.boundingRectangle.width / 2.0f);
        float tableTopBorder = table.boundingRectangle.y + (table.boundingRectangle.height / 2.0f);
        float tableBottomBorder = table.boundingRectangle.y - (table.boundingRectangle.height / 2.0f);
        float radius = ball.boundingCircle.radius;
        if (ball.boundingCircle.x + radius > tableRightBorder) {
            ball.velocity.x *= -1;
            ball.position.x = ball.boundingCircle.x = tableRightBorder - radius - (float) Util::EPSILON;
        }
        if (ball.boundingCircle.x - radius < tableLeftBorder) {
            ball.velocity.x *= -1;
            ball.position.x = ball.boundingCircle.x = tableLeftBorder + radius + (float) Util::EPSILON;
        }
        if (ball.boundingCircle.y + radius > tableTopBorder) {
            ball.velocity.y *= -1;
            ball.position.y = ball.boundingCircle.y = tableTopBorder - radius - (float) Util::EPSILON;
        }
        if (ball.boundingCircle.y - radius < tableBottomBorder) {
            ball.velocity.y *= -1;
            ball.position.y = ball.boundingCircle.y = tableBottomBorder + radius + (float) Util::EPSILON;
        }

        // Check for collision with other balls
        for (int j = i + 1; j < balls.size(); j++) {
            BilliardsBall &otherBall = balls[j];

            Vector p1 = ball.position;
            Vector p2 = otherBall.position;

            double distanceSquared = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
            if (distanceSquared < 4 * radius * radius) {
                // Found a collision
                Vector v1 = ball.velocity;
                Vector v2 = otherBall.velocity;

                ball.velocity = v1 - (((v1 - v2) * (p1 - p2)) / ((p1 - p2) * (p1 - p2))) * (p1 - p2);
                otherBall.velocity = v2 - (((v2 - v1) * (p2 - p1)) / ((p2 - p1) * (p2 - p1))) * (p2 - p1);

                v1 = ball.velocity;
                v2 = otherBall.velocity;

                // Make sure they are no longer colliding
                double a = (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
                double b = 2 * (p1.x - p2.x) * (v1.x - v2.x) + 2 * (p1.y - p2.y) * (v1.y - v2.y);
                double c = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) - 4 * radius * radius;

                double t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                double t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

                double t;

                if (t1 >= 0) {
                    t = t1 + Util::EPSILON;
                } else {
                    t = t2 + Util::EPSILON;
                }

                ball.position = p1 + t * v1;
                otherBall.position = p2 + t * v2;
            }
        }
    }
}

void BilliardsSimulation::enterCameraTransitionState(Vector cameraTransitionEndPosition, 
        Vector cameraTransitionEndCenter, 
        Vector cameraTransitionEndUp, 
        BilliardsSimState stateAfterCameraTransition) {
    timesCameraMovedInTransition = 0;

    cameraTransitionPositionDelta = (1.0f/25.0f) * (cameraTransitionEndPosition - camera.position);
    cameraTransitionCenterDelta = (1.0f/25.0f) * (cameraTransitionEndCenter - camera.center);
    cameraTransitionUpDelta = (1.0f/25.0f) * (cameraTransitionEndUp - camera.up);

    this->stateAfterCameraTransition = stateAfterCameraTransition;
    currentState = BilliardsSimState::TRANSITIONING_CAMERA;
}

void BilliardsSimulation::CameraTransition(Vector cameraTransitionEndPosition,
        Vector cameraTransitionEndCenter,
        Vector cameraTransitionEndUp
        ) {
    timesCameraMovedInTransition = 0;

    cameraTransitionPositionDelta = (1.0f/25.0f) * (cameraTransitionEndPosition - camera.position);
    cameraTransitionCenterDelta = (1.0f/25.0f) * (cameraTransitionEndCenter - camera.center);
    cameraTransitionUpDelta = (1.0f/25.0f) * (cameraTransitionEndUp - camera.up);

    
    currentState = BilliardsSimState::TRANSITIONING_CAMERA;
}

void BilliardsSimulation::drawBoundingObjects() {
    for (BilliardsPocket &pocket : pockets) {
        pocket.boundingCircle.draw();
    }
    for (BilliardsBall &ball : balls) {
        ball.boundingCircle.draw();
    }
    table.boundingRectangle.draw();
}

float randij(int i, int j){
    float r = i + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(j-i)));
    return r;
}

double BilliardsSimulation::AIeval(int pocketBall){
    double score=1000;
    double balldist=100,
    pocketedball=2500;
    
    for(int i=0;i<balls.size();i++){
        for(int j=i+1;j<balls.size();j++){
            BilliardsBall &ball1 = balls[i];
            BilliardsBall &ball2 = balls[j];
            Vector bij=ball1.position-ball2.position;
            if(!std::isnan(bij.length()))
               score+=bij.length()*balldist;
        }
    }

    score+=pocketedball*(pocketBall);
//    Util::log(INFO, "score== "+std::to_string(score));
    cout<<"AIevalscore= "+std::to_string(score)<<endl;
    return score;
}

double BilliardsSimulation::AIevalRule(vector<BilliardsBall> ballscopy){
    double score=1000;
    double balldist=150,foul=50000,pocketedball=500;
    vector<int> removedBallNum;
    for(auto bc:ballscopy){
        removedBallNum.emplace_back(bc.ballNumber);
    }
    for(auto b:balls){
        auto it=find(removedBallNum.begin(),removedBallNum.end(),b.ballNumber);
        removedBallNum.erase(it);
    }
    for(int bn:removedBallNum){
        if(bn==0)return -foul;
        else{
            score+=pocketedball*bn;
        }
    }
    
    for(int i=0;i<balls.size();i++){
        for(int j=i+1;j<balls.size();j++){
            BilliardsBall &ball1 = balls[i];
            BilliardsBall &ball2 = balls[j];
            Vector bij=ball1.position-ball2.position;
            if(!std::isnan(bij.length()))
               score+=bij.length()*balldist;
        }
    }
    
//    Util::log(INFO, "rule score== "+std::to_string(score));
    cout<<"AIevalscore= "+std::to_string(score)<<endl;
    return score;
}

double BilliardsSimulation::AIsimulate(Vector Params){
    vector<BilliardsBall> ballscopy=balls;
    
    stick.angle=Params.x;
    stick.hitPower=Params.y;
    stick.beforeAnimiationHitPower = stick.hitPower;
    balls[0].velocity = Vector(3.5f * stick.beforeAnimiationHitPower, 0.0f, 0.0f).rotate(Vector::zAxis, stick.angle);
    balls[0].velocity.y *= -1;
    while(!noBallsMoving()){
        for (int i = 0; i < balls.size(); i++) {
            BilliardsBall &ball = balls[i];
            ball.update(0.02f);
        }
        manageCollisions();
        ballEnterPockets();
    }
//    Util::log(INFO, "Enter AI eval");
    double ans=0;
    if(gameMode==1){
        ans=AIeval(ballscopy.size()-balls.size());
    }
    else{
        ans=AIevalRule(ballscopy);
    }
    balls=ballscopy;
    return ans;

//    if (stick.hitPower > 0.0f) {
//        stick.hitPower -= 0.1 * stick.beforeAnimiationHitPower;
//    }
//    else {
//        balls[0].velocity = Vector(3.5f * stick.beforeAnimiationHitPower, 0.0f, 0.0f).rotate(Vector::zAxis, stick.angle);
//        balls[0].velocity.y *= -1;
//        for (int i = 0; i < balls.size(); i++) {
//            BilliardsBall &ball = balls[i];
//            ball.update(Params.z);
//        }
//        
//        manageCollisions();
//        
//        ballEnterPockets();
//        
//        if (noBallsMoving()) {
//            ans=AIeval();
//            Util::log(INFO, "Enter AI eval");
//        }
//    }
//    balls=ballscopy;
//    return ans;
    
    
}

Vector BilliardsSimulation::AItrain(){
    const double maxforce=1.3f;
    const double minforce=0.01f;
    const int maxiter=250;
    const int diversei=5;
    double maxScore=0;
    double forceMut=0.005f;
    double angleMut=0.001f;
    double PI=3.1416;
    Vector bestParams = Vector();
    
    for(int i=0;i<maxiter;i++){
        double angle=0.2f,force=0.2f;
        if(i%diversei==0){
            angle=(randij(0,2)*PI);
            force=(randij(0,1)*maxforce);
        }
        else{
            angle=bestParams.x;
            angle+=angleMut*(randij(-1,1)*PI);
            
            force=bestParams.y;
            force+=forceMut*(randij(-1,1));
        }
        force=force<minforce?minforce:force;
        force=force>maxforce?maxforce:force;
        Vector Params=Vector(angle,force,0);
        double evalScore=AIsimulate(Params);
//        Util::log(INFO, "Enter AI simulate");
        if(bestParams.length()<1e-6||evalScore>maxScore){
            bestParams=Params;
            maxScore=evalScore;
        }
    }
    gameScore+=maxScore;
    return bestParams;
}

void BilliardsSimulation::update(double timeDelta) {
//    Util::log(INFO, "currentState== "+std::to_string(int(currentState)));
    //int cameraState = 1;
    
//    Util::log(INFO, "ballsize== "+std::to_string(int(balls.size())));
//    for(int i=0;i<balls.size();i++){
//        Util::log(INFO, std::to_string(i)+"balli== ");
//        std::cout<<balls[i].position<<std::endl;
//    }
//    if(glfwGetKey(window.glfwWindow, GLFW_KEY_G)){
//        gameMode=(gameMode+1)%2;
//        cout<<"GameMode: "<<gameMode<<endl;
//    }
    if(cameraState==2){
        if(glfwGetKey(window.glfwWindow, GLFW_KEY_A)){
            camera.position.x-=0.01f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_D)){
            camera.position.x+=0.01f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_W)){
            camera.position.y+=0.01f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_S)){
            camera.position.y-=0.01f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_Q)){
            camera.position.z-=0.018f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_E)){
            camera.position.z+=0.018f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_Z)){
            camera.position.x/=1.03f;
            camera.position.y/=1.03f;camera.position.z/=1.03f;
        }
        else if(glfwGetKey(window.glfwWindow, GLFW_KEY_X)){
            camera.position.x*=1.03f;camera.position.y*=1.03f;camera.position.z*=1.03f;
        }
        camera.updateViewMatrix();
    }
    
    if(glfwGetKey(window.glfwWindow, GLFW_KEY_1)){
        cameraState=1; //overview
        Vector endPosition = Vector(0.0f, 2.4f, 0.0f);
        Vector endCenter = Vector(0.0f, 0.0f, 0.0f);
        Vector endUp = Vector(1.0f, 0.0f, 0.0f);

        enterCameraTransitionState(endPosition, endCenter, endUp, BilliardsSimState::POSITIONING_CUE_STICK);
    }
    else if(glfwGetKey(window.glfwWindow, GLFW_KEY_2)){
        cameraState=2; //follow ball not stick
        Vector endPosition = Vector(balls[0].position.x, 0.4f, balls[0].position.y) +
        Vector(-1.0f, 0.0f, 0.0f).rotate(Vector::yAxis, stick.angle);
        Vector endCenter = Vector(balls[0].position.x, 0.0f, balls[0].position.y);
        Vector endUp = Vector(0.0f, 1.0f, 0.0f);
        
        enterCameraTransitionState(endPosition, endCenter, endUp, BilliardsSimState::POSITIONING_CUE_STICK);
    }
    else if(glfwGetKey(window.glfwWindow, GLFW_KEY_3)){
        if(cameraState!=3){
            cameraState=3; //follow stick
            Vector endPosition = Vector(balls[0].position.x, 0.4f, balls[0].position.y) +
            Vector(-1.0f, 0.0f, 0.0f).rotate(Vector::yAxis, stick.angle);
            Vector endCenter = Vector(balls[0].position.x, 0.0f, balls[0].position.y);
            Vector endUp = Vector(0.0f, 1.0f, 0.0f);
            
            enterCameraTransitionState(endPosition, endCenter, endUp, BilliardsSimState::POSITIONING_CUE_STICK);
        }
    }
//    currentState=BilliardsSimState::BALL_ENTER_POCKET;
    if (currentState == BilliardsSimState::POSITIONING_CUE_STICK) {
        if(gameRound%2==1){
            bool changedCueStick = false;
            
            if (glfwGetKey(window.glfwWindow, GLFW_KEY_LEFT)) {
                stick.increaseAngle();
                changedCueStick = true;
            }
            if (glfwGetKey(window.glfwWindow, GLFW_KEY_RIGHT)) {
                stick.decreaseAngle();
                changedCueStick = true;
            }
            if (glfwGetKey(window.glfwWindow, GLFW_KEY_UP)) {
                stick.increaseHitPower();
                changedCueStick = true;
            }
            if (glfwGetKey(window.glfwWindow, GLFW_KEY_DOWN)) {
                stick.decreaseHitPower();
                changedCueStick = true;
            }
            if (glfwGetKey(window.glfwWindow, GLFW_KEY_SPACE)) {
                stick.beforeAnimiationHitPower = stick.hitPower;
                
                //            Vector endPosition = Vector(0.0f, 2.4f, 0.0f);
                //            Vector endCenter = Vector(0.0f, 0.0f, 0.0f);
                //            Vector endUp = Vector(1.0f, 0.0f, 0.0f);
                //
                //            enterCameraTransitionState(endPosition, endCenter, endUp, BilliardsSimState::ANIMATING_CUE_STICK);
                currentState=BilliardsSimState::ANIMATING_CUE_STICK;
            }
            
//            if (cameraState==3&&changedCueStick) {
//                camera.position = Vector(balls[0].position.x, 0.4f, balls[0].position.y) +
//                Vector(-1.0f, 0.0f, 0.0f).rotate(Vector::yAxis, stick.angle);
//                camera.up = Vector(0.0f, 1.0f, 0.0f);
//                camera.center = Vector(balls[0].position.x, 0.0f, balls[0].position.y);
//                camera.updateViewMatrix();
//            }
        }else{
            cout<<"Entering AI train..."<<endl;
            Vector AIresult=AItrain();
//            Util::log(INFO, "End AI train angle= "+std::to_string(AIresult.x)+" ,force= "+std::to_string(AIresult.y));
            cout<<"End AI train \nangle= "+std::to_string(AIresult.x)+" ,force= "+std::to_string(AIresult.y)<<endl;
            stick.angle=AIresult.x;
            stick.hitPower=AIresult.y;
            
            stick.beforeAnimiationHitPower = stick.hitPower;
            currentState=BilliardsSimState::ANIMATING_CUE_STICK;
//            const int maxforce=80;
//            const int minforce=1;
//            const int maxiter=100;
//            const int diversei=10;
//            double maxScore=0;
//            double forceMut=0.005f;
//            double angleMut=0.001f;
//            double PI=3.1416;
//            Vector bestParams = Vector();
//            
//            for(int i=0;i<maxiter;i++){
//                int angle=0,force=20;
//                if(i%diversei==0){
//                    angle=(randij(0,2)*PI);
//                    force=(randij(0,1)*maxforce);
//                }
//                else{
//                    angle=bestParams.x;
//                    angle+=angleMut*(randij(-1,1)*PI);
//                    
//                    force=bestParams.y;
//                    force+=forceMut*(randij(-1,1));
//                }
//                force=force<minforce?minforce:force;
//                force=force>maxforce?maxforce:force;
//                double evalScore=AIsimulate();
//                if(bestParams.length()<1||evalScore>maxScore){
//                    bestParams=Vector(angle,force,0);
//                    maxScore=evalScore;
//                }
//            }
//            
//            stick.angle=bestParams.x;
//            stick.hitPower=bestParams.y;
//            stick.beforeAnimiationHitPower = stick.hitPower;
//            currentState=BilliardsSimState::ANIMATING_CUE_STICK;
        }
        if (cameraState==3) {
            camera.position = Vector(balls[0].position.x, 0.4f, balls[0].position.y) +
            Vector(-1.0f, 0.0f, 0.0f).rotate(Vector::yAxis, stick.angle);
            camera.up = Vector(0.0f, 1.0f, 0.0f);
            camera.center = Vector(balls[0].position.x, 0.0f, balls[0].position.y);
            camera.updateViewMatrix();
        }
        
    }
    else if (currentState == BilliardsSimState::ANIMATING_CUE_STICK) {
        if (stick.hitPower > 0.0f) {
            stick.hitPower -= 0.1 * stick.beforeAnimiationHitPower;
        } 
        else {
            balls[0].velocity = Vector(3.5f * stick.beforeAnimiationHitPower, 0.0f, 0.0f).rotate(Vector::zAxis, stick.angle);
            balls[0].velocity.y *= -1;
            currentState = BilliardsSimState::SIMULATING_BALLS_MOVING;
        }
    } 
    else if (currentState == BilliardsSimState::SIMULATING_BALLS_MOVING) {
        for (int i = 0; i < balls.size(); i++) {
            BilliardsBall &ball = balls[i];
            ball.update(timeDelta);
        }
        
        manageCollisions();
        
        //        if(ballEnterPockets()){
        //            currentState = BilliardsSimState::BALL_ENTER_POCKET;
        //            Util::log(Severity::INFO, "Ball Detected Entered Pockets");
        //        }
        ballEnterPockets();
        
        if (noBallsMoving()) {
//            Vector endPosition = Vector(balls[0].position.x, 0.4f, balls[0].position.y) +
//            Vector(-1.0f, 0.0f, 0.0f).rotate(Vector::yAxis, stick.angle);
//            Vector endCenter = Vector(balls[0].position.x, 0.0f, balls[0].position.y);
//            Vector endUp = Vector(0.0f, 1.0f, 0.0f);
//            
//            enterCameraTransitionState(endPosition, endCenter, endUp, BilliardsSimState::POSITIONING_CUE_STICK);
            
            if(gameRound%2){
                if(gameMode==1){
                    gameScore-=AIeval(lastRoundBalls.size()-balls.size());
                }
                else{
                    gameScore-=AIevalRule(lastRoundBalls);
                }
            }
            lastRoundBalls=balls;
            
//            Util::log(INFO, "-----gameRound== "+std::to_string(int(gameRound))+"  Game Score= "+std::to_string(gameScore));
            cout<<"Round:"+std::to_string(int(gameRound))+" Score:"+std::to_string(gameScore)<<endl;
            if(gameMode==2&& balls.size()==1&&balls[0].ballNumber==0){
                
                currentState=BilliardsSimState::BALL_ENTER_POCKET;
            }
            else if(gameMode==1&&balls.size()==0){
                currentState=BilliardsSimState::BALL_ENTER_POCKET;
            }
            else{
                currentState=BilliardsSimState::POSITIONING_CUE_STICK;
            }
            gameRound++;
            
            
        }
        
    }
    else if (currentState == BilliardsSimState::TRANSITIONING_CAMERA) {
        if (timesCameraMovedInTransition >= 25) {
            currentState = stateAfterCameraTransition;
            stateAfterCameraTransition = BilliardsSimState::TRANSITIONING_CAMERA;
        }
        else {
            camera.position = camera.position + cameraTransitionPositionDelta;                
            camera.center = camera.center + cameraTransitionCenterDelta;                
            camera.up = camera.up + cameraTransitionUpDelta;                
            camera.updateViewMatrix();

            timesCameraMovedInTransition++;
        }
    }
    else if (currentState == BilliardsSimState::BALL_ENTER_POCKET){
//        Util::log(Severity::INFO, "Ball Detected Entered Pockets");
        Model* m;
        
        Matrix translation = Matrix(Vector(0,0.3,0));
        Matrix rotation = Matrix(Vector(0.0, 1.0, 0.0), (float) (M_PI / 2.0));
        Matrix scale = Matrix::scaleMatrix(Vector(1,1,0.5));
        Matrix modelMat = rotation * translation * scale;
        if(gameScore>20000){
            m=ResourceManager::getModel("lose");
        }
        else{
            m=ResourceManager::getModel("win");
        }
        m->draw(ResourceManager::getShader("default"), modelMat);
    }

    ResourceManager::getShader("default")->setMatProperty("view_mat", camera.viewMatrix.m);
    ResourceManager::getShader("default")->setMatProperty("proj_mat", camera.projectionMatrix.m);

    ResourceManager::getShader("bounding_object")->setMatProperty("view_mat", camera.viewMatrix.m);
    ResourceManager::getShader("bounding_object")->setMatProperty("proj_mat", camera.projectionMatrix.m);

    glViewport(0, 0, camera.width, camera.height);
}

void BilliardsSimulation::draw() {
    drawBoundingObjects();
    for (BilliardsBall &ball : balls) {
        ball.draw();
    }
    table.draw();
    if (currentState == BilliardsSimState::POSITIONING_CUE_STICK
            || currentState == BilliardsSimState::ANIMATING_CUE_STICK
            || stateAfterCameraTransition == BilliardsSimState::ANIMATING_CUE_STICK || currentState == BilliardsSimState::TRANSITIONING_CAMERA) {
        stick.draw(balls[0].position);
    }
    AnimCharacter anim=AnimCharacter();
    anim.draw();
    Model* m;
    if(gameMode==1){
        m=ResourceManager::getModel("1");
        
    }
    else{
        m=ResourceManager::getModel("2");
    }
    Matrix translation = Matrix(Vector(0,-0.6,-1.8));
    Matrix rotation = Matrix(Vector(0.0, 1.0, 0.0), (float) (-M_PI / 2.0));
    Matrix scale = Matrix::scaleMatrix(Vector(1,1,1));
    Matrix modelMat = rotation * translation * scale;

    m->draw(ResourceManager::getShader("default"), modelMat);
//    m=ResourceManager::getModel("win");
//    m->draw(ResourceManager::getShader("default"), modelMat);
}
