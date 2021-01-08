//
// Created by Ang Chee on 2018/01/16.
//

#ifndef CGPIPELINE_SKYBOX_H
#define CGPIPELINE_SKYBOX_H
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

class Skybox
{
public:
    Skybox(Shader* shader, glm::vec3 pos, float ro, glm::vec3 axis, int x);
    void draw(Camera* camera, int choice, const char* file);
    void giveShader(Shader* shader);
private:
    glm::vec3 pos;
    float ro;
    glm::vec3 axis;
    float vertices[20];
    unsigned int indices[6];
    unsigned int VBO, VAO, EBO;
    Shader* shader;
};


#endif //CGPIPELINE_SKYBOX_H
