//
// Created by Ang Chee on 2017/12/24.
//

#ifndef CGPIPELINE_MONSTER_H
#define CGPIPELINE_MONSTER_H
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
#define ATTACKCOUNT 40
#define FLYCOUNT 15
#define DIECOUNT 40

class Monster
{
public:
    Monster(float angle, glm::vec3 pos);
    void giveModelShader(Model* body, Shader* shader);
    void draw(Camera* camera, Light* light, int choice);
    void move(float distance);
    void turn(float theta);
    void die(Camera* camera, Light* light, int choice);
    void attack();
    int getLive();
    glm::vec3 GetPos();
    glm::vec3 GetStone();

private:
    Model* monsterBody;
    Shader* monsterShader;
    float angle;
    glm::vec3 pos;
    int hp;
    int hpFull;
    int moveStatus;
    int attackStatus;
    int flyStatus;
    int liveStatus;
    glm::vec3 targetPos;
    glm::vec3 initPos;
    glm::vec3 tmpPos;
    int flag;
    void drawStone(Camera* camera, Light* light);
};
#endif //CGPIPELINE_MONSTER_H
