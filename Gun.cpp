//
// Created by Ang Chee on 2018/01/15.
//

#include "Gun.h"
Gun::Gun(float angle, glm::vec3 pos)
{
    this -> angle = angle;
    this -> pos = pos;
    this -> gun = nullptr;
    this -> shader = nullptr;
    this -> hp = 3;
}

void Gun::giveModelShader(Model* body, Shader* shader)
{
    this -> gun = body;
    this -> shader = shader;
}

void Gun::draw(Camera* camera, Light* light)
{
    shader -> use();
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(camera -> Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
    glm::mat4 view(1.0f);
    view = camera -> GetViewMatrix();
    shader -> setMat4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));
    shader -> setMat4fv("view", 1, GL_FALSE, glm::value_ptr(view));
    glm::mat4 model(1.0f);
    model = glm::translate(model, pos);
    model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(camera -> Pitch), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians((float)90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::translate(model, glm::vec3(7.0f, 0.0f, 2.0f));
    model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
    shader -> setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
    gun -> Draw(*shader, camera -> GetPosition(), *light);
}

void Gun::GivePos(Camera* camera)
{
    pos = glm::vec3(camera -> Position.x, camera -> Position.y - 5.0f, camera -> Position.z);
}

void Gun::GiveAngle(Camera *camera)
{
    angle = 270.0f - camera -> Yaw;
}

int Gun::GetHp()
{
    return hp;
}