//
// Created by Ang Chee on 2018/01/15.
//

#include "surface.h"
surface::surface(Shader* shader)
{
    this -> shader = shader;
    float v[20] = {
            0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
            0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f,   0.0f, 1.0f
    };
    unsigned int in[6] = {
            0, 1, 3,
            1, 2, 3
    };
    for(int i = 0; i < 20; i++)
    {
        vertices[i] = v[i];
    }
    for(int i = 0; i < 6; i++)
    {
        indices[i] = in[i];
    }


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void surface::draw(Camera* camera, const char* file, int choice)
{
    shader -> use();
    // load and create a texture
    // -------------------------
    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    shader -> use();
    shader -> setInt("texture1", 0);

    // create transformations
    if(choice == 1)
    {
        glm::mat4 projection(1.0f);
        projection = glm::perspective(glm::radians(camera -> Zoom), (float)600.0 / 800, 0.1f, 10000.0f);
        glm::mat4 view(1.0f);
        view = camera -> GetViewMatrix();
        shader -> setMat4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));
        shader -> setMat4fv("view", 1, GL_FALSE, glm::value_ptr(view));
    }
    glm::mat4 model(1.0f);
    model = glm::scale(model, glm::vec3(1200.0f, 1200.0f, 1200.0f));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader -> setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));

    // render container
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}