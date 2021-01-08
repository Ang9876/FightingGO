//
// Created by Ang Chee on 2018/01/15.
//

#ifndef CGPIPELINE_GUN_H
#define CGPIPELINE_GUN_H
#include "Model.h"
#include "Camera.h"
#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define SCR_WIDTH 600
#define SCR_HEIGHT 800
#define PI 3.14159265

class Gun
{
public:
    Gun(float angle, glm::vec3 pos);
    void giveModelShader(Model* body, Shader* shader);
    void draw(Camera* camera, Light* light);
    void hurt(float portion);
    void GivePos(Camera* camera);
    void GiveAngle(Camera* camera);
    int GetHp();

private:
    Model* gun;
    Shader* shader;
    float angle;
    glm::vec3 pos;
    int hp;
};


#endif //CGPIPELINE_GUN_H
