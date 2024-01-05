#include "AnimCharacter.h"

AnimCharacter::AnimCharacter()
        : model(ResourceManager::getModel("data")),model2(ResourceManager::getModel("floor")) { }

void AnimCharacter::draw() {
//    Matrix translation = Matrix(Vector(tableModelDeltaX, tableModelDeltaY, 0.0));
    Matrix translation = Matrix(Vector(1.3,-0.6,-0.3));
    Matrix rotation = Matrix(Vector(0.0, 1.0, 0.0), 0);
    Matrix scale = Matrix::scaleMatrix(Vector(tableModelScaleX,
                                              (tableModelScaleX + tableModelScaleY) / 2.0f,
                                              tableModelScaleY));
    Matrix modelMat = rotation * translation * scale;

    model->draw(ResourceManager::getShader("default"), modelMat);
    Matrix translation2 = Matrix(Vector(0,-0.6,0));
    Matrix rotation2 = Matrix(Vector(0.0, 1.0, 0.0), (float) (M_PI / 2.0));
    Matrix scale2 = Matrix::scaleMatrix(Vector(2,2,2));
    Matrix modelMat2 = rotation2 * translation2 * scale2;
    model2->draw(ResourceManager::getShader("default"), modelMat2);
//    Matrix translation3 = Matrix(Vector(0,0,0));
//    Matrix rotation3 = Matrix(Vector(0.0, 1.0, 0.0), (float) (M_PI / 2.0));
//    Matrix scale3 = Matrix::scaleMatrix(Vector(0.1,0.1,0.1));
//    Matrix modelMat3 = rotation3 * translation3 * scale3;
//    model3->draw(ResourceManager::getShader("default"), modelMat3);
}
