//
// Created by Ang Chee on 2018/01/15.
//

#ifndef CGPIPELINE_TREE_H
#define CGPIPELINE_TREE_H
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

class Tree
{
public:
    Tree();
    Tree(float angle, glm::vec3 pos,glm::vec3 scal);
    void giveTreeShader(Model* body, Shader* shader);
    void draw(Camera* camera, Light* light);
    glm::vec3 GetPos();
    float GetAngle();

private:
    Model* treeBody;
    Shader* treeShader;
    float angle;
    glm::vec3 pos;
    glm::vec3 scal;
};


#endif //CGPIPELINE_TREE_H
