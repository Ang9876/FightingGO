//
// Created by Ang Chee on 2017/12/24.
//

#ifndef CGPIPELINE_LIGHT_H
#define CGPIPELINE_LIGHT_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Light
{
    glm::vec3 position;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

#endif //CGPIPELINE_LIGHT_H
