//
// Created by Ang Chee on 2017/12/21.
//

#ifndef CGPIPELINE_SHADER_H
#define CGPIPELINE_SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec4f(const std::string &name, float v1, float v2, float v3, float v4) const;
    void setVec3f(const std::string &name, glm::vec3 v) const;
    void setMat4fv(const std::string &name, int num, int transpose, const GLfloat* trans) const;
};


#endif //CGPIPELINE_SHADER_H
