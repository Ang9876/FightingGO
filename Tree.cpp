//
// Created by Ang Chee on 2018/01/15.
//

#include "Tree.h"
// ------------------------ public ----------------------------

// position and direction of the tree
//scal is to scale it down
// angle is from positive z axis to positive x axis
// angle is the direction of the left of the monster
Tree::Tree() {

}
Tree::Tree(float angle, glm::vec3 pos,glm::vec3 scal)
{
    this->angle = angle;
    this->pos = pos;
    this->scal = scal;
    treeBody = nullptr;
    treeShader = nullptr;
}

void Tree::giveTreeShader(Model* body, Shader* shader)
{
    treeBody = body;
    treeShader = shader;
}

void Tree::draw(Camera* camera, Light* light)
{
    treeShader->use();
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 10000.0f);
    glm::mat4 view(1.0f);
    view = camera->GetViewMatrix();
    treeShader->setMat4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));
    treeShader->setMat4fv("view", 1, GL_FALSE, glm::value_ptr(view));
    glm::mat4 model(1.0f);
    model = glm::translate(model, pos); // translate it down so it's at the center of the scene
    model = glm::scale(model, scal);	// it's a bit too big for our scene, so scale it down
    model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    treeShader->setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
    treeBody->Draw(*treeShader, camera->GetPosition(), *light);
}

// monster move for the input distance in its now direction


float Tree::GetAngle()
{
    return angle;
}

glm::vec3 Tree::GetPos()
{
    return pos;
}
