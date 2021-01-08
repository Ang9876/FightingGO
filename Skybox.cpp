#include "Skybox.h"

unsigned char* LoadFileContent(const char* path, int & filesize) {
    unsigned char* fileContent = nullptr;
    filesize = 0;
    FILE* file = fopen(path, "rb");
    if (file) {
        fseek(file, 0, SEEK_END);
        int nLen = ftell(file);
        if (nLen > 0) {
            rewind(file);
            fileContent = new unsigned char[nLen + 1];
            fread(fileContent, sizeof(unsigned char), nLen, file);
            fileContent[nLen] = '\0';
            filesize = nLen;
        }
        fclose(file);
    }
    return fileContent;
}

unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height) {
    if (0x4D42 == *((unsigned short*)bmpFileData)) {
        int pixelDataOffset = *((int *)(bmpFileData + 10));
        width = *((int *)(bmpFileData + 18));
        height = *((int *)(bmpFileData + 22));
        unsigned char* pixelData = bmpFileData + pixelDataOffset;
        //BGR ==> RGB
        for (int i = 0; i < width*height * 3; i += 3) {
            unsigned char temp = pixelData[i];
            pixelData[i] = pixelData[i + 2];
            pixelData[i + 2] = temp;
        }
        return pixelData;
    }
    return nullptr;
}

GLuint CreateTexture2D(unsigned char* pixelData, int width, int height, GLenum type) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);   //
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixelData);
    glBindTexture(GL_TEXTURE_2D, 0);
    return texture;
}

GLuint CreateTexture2DFromBMP(const char* bmpPath) {
    int nFileSize = 0;
    unsigned char* bmpFileContent = LoadFileContent(bmpPath, nFileSize);
    //printf("%d\n", nFileSize);
    if (bmpPath == nullptr) {
        return 0;
    }
    int bmpWidth = 0, bmpHeight = 0;
    unsigned char* pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
    if (bmpWidth == 0) {
        delete bmpFileContent;
        return 0;
    }
    GLuint texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
    delete bmpFileContent;
    return texture;

}

GLuint CreateDisplayList(function<void()>foo) {
    GLuint displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);
    foo();
    glEndList();
    return displayList;
}

Skybox::Skybox(Shader* shader, glm::vec3 pos, float ro, glm::vec3 axis, int x)
{
    this -> shader = shader;
    this -> pos = pos;
    this -> ro = ro;
    this -> axis = axis;
    float v[20] = {
            0.5f,  0.5f, 0.0f,   x + (-2 * x + 1) * 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f,   x + (-2 * x + 1) * 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,   x + (-2 * x + 1) * 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f,   x + (-2 * x + 1) * 0.0f, 1.0f
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

void Skybox::giveShader(Shader* shader)
{
    this -> shader = shader;
}

void Skybox::draw(Camera* camera, int choice, const char* file)
{
    shader -> use();
    // load and create a texture
    // -------------------------
    unsigned int texture1;
    char temp[256];
    memset(temp, 0, sizeof(temp) - 1);
    const char* dir = "../Texture/Skybox/";
    strcpy(temp, dir);
    strcat(temp, file);
    texture1 = CreateTexture2DFromBMP(temp);
    glBindTexture(GL_TEXTURE_2D, texture1);
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
    model = glm::translate(model, pos);
    model = glm::scale(model, glm::vec3(1000.0f, 1000.0f, 1000.0f));
    model = glm::rotate(model, glm::radians(ro), axis);
    shader -> setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));

    // render container
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}