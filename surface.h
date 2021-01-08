//
// Created by Ang Chee on 2018/01/15.
//

#ifndef CGPIPELINE_SURFACE_H
#define CGPIPELINE_SURFACE_H
#include "Model.h"
#include "Camera.h"
#include "stb_image.h"
#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class surface
{
public:
    surface(Shader* shader);
    void draw(Camera* camera, const char* file, int choice);
private:
    float vertices[20];
    unsigned int indices[6];
    unsigned int VBO, VAO, EBO;
    Shader* shader;
};


#endif //CGPIPELINE_SURFACE_H
