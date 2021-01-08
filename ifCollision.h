//
// Created by Ang Chee on 2018/01/15.
//

#ifndef CGPIPELINE_IFCOLLISION_H
#define CGPIPELINE_IFCOLLISION_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <math.h>
using namespace std;

typedef struct Rectangle
{
    glm::vec3 pointA;
    glm::vec3 pointB;
    glm::vec3 pointC;
    glm::vec3 pointD;
} Rectangle;

bool ifCollision(Rectangle obj1, Rectangle obj2);

#endif //CGPIPELINE_IFCOLLISION_H
