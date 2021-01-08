#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Light.h"
#include "Monster.h"
#include "Tree.h"
#include "surface.h"
#include "Gun.h"
#include "Skybox.h"
using namespace std;

#define SCR_WIDTH 600
#define SCR_HEIGHT 800

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void processInput1(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Light light = {
        glm::vec3(0.0f, 300.0f, 200.0f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
};

glm::vec3 cameraPos   = glm::vec3(0.0f, 15.0f, 100.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
Camera camera(cameraPos, cameraUp, -90.0f, 0.0f);
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
bool alive = true;
bool win = false;

float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间

Tree trees1[40],trees2[40],trees3[30],trees4[40];
Tree bana1[5], bana2[5], bana3[4], bana4[5];
Tree house[3],house1[2], house3[3], house4[2], house5;
Tree lamp1[5], lamp2[5], lamp3[12], lamp4[10];

Monster monster(90.0f, glm::vec3(-60.0f, 0.0f, 450.0f));
Gun gun(90.0f, glm::vec3(0.0f, 20.0f, 20.0f));
int gunflag = 0;
int dieflag = 0;
int shotflag = 0;
int lightflag = 0;
int main(int argc, char** argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glEnable(GL_DEPTH_TEST);

    Model modelTmp("../Model/long stone/file.obj");
    Model Treemodel("../Model/gass/gass.obj");
    Model bananamodel("../Model/banana/banana.obj");
    Model housemodel("../Model/modernhouse/file.obj");
    Model lampmodel("../Model/simple/file.obj");
    Model highhousemodel("../Model/end1/file.obj");
    Model gunModel("../Model/gun/file.obj");
    Model gun2Model("../Model/gun2/file.obj");
    Shader shader("../Shader/shader.vs", "../Shader/shader.fs");
    monster.giveModelShader(&modelTmp, &shader);
    for (int j = 0; j < 2; j++) {
        house[j] = Tree(270, glm::vec3(120.0f, 0.0f, -20.0-j*180.0f), glm::vec3(0.3f, 0.3f, 0.3f));
        house1[j] = Tree(90, glm::vec3(-120.0f, 0.0f, -20.0 - j*180.0f), glm::vec3(0.3f, 0.3f, 0.3f));
        house4[j] = Tree(180, glm::vec3(-180.0f * j - 150.0f, 0.0f, -340.0f), glm::vec3(0.3f, 0.3f, 0.3f));
        house[j].giveTreeShader(&housemodel, &shader);
        house1[j].giveTreeShader(&housemodel, &shader);
        house4[j].giveTreeShader(&housemodel, &shader);
    }
    house[2] = Tree(270, glm::vec3(110.0f, 0.0f, -380.0f), glm::vec3(0.3f, 0.3f, 0.3f));
    house[2].giveTreeShader(&housemodel, &shader);
    house5 = Tree(90, glm::vec3(-570.0, 0.0f, -440.0), glm::vec3(0.02f, 0.02f, 0.02f));
    house5.giveTreeShader(&highhousemodel, &shader);
    for(int j = 0; j < 3; j++)
    {
        house3[j] = Tree(0, glm::vec3(-180.0f * j, 0.0f, -550.0f), glm::vec3(0.3f, 0.3f, 0.3f));
        house3[j].giveTreeShader(&housemodel, &shader);
    }

    for (int j= 0; j < 40; j++)
    {
        trees1[j] = Tree(0, glm::vec3(50.0f, 0.0f, -j*10.0f), glm::vec3(0.3f, 0.3f, 0.3f));
        trees2[j] = Tree(0, glm::vec3(-50.0f, 0.0f, -j*10.0f), glm::vec3(0.3f, 0.3f, 0.3f));
        trees1[j].giveTreeShader(&Treemodel, &shader);
        trees2[j].giveTreeShader(&Treemodel, &shader);
    }
    for (int j = 0; j < 5; j++)
    {
        bana1[j] = Tree(0, glm::vec3(50.0f, 0.0f, -j*81.0 + 10.0f), glm::vec3(0.05f, 0.09f, 0.05f));
        bana2[j] = Tree(0, glm::vec3(-50.0f, 0.0f, -j*81.0 + 10.0f), glm::vec3(0.05f, 0.09f, 0.05f));
        lamp1[j] = Tree(0, glm::vec3(45.0f, 0.0f, -j*81.0 + 20.0f), glm::vec3(0.1f, 0.06f, 0.02f));
        lamp2[j] = Tree(180, glm::vec3(-45.0f, 0.0f, -j*81.0 + 20.0f), glm::vec3(0.1f, 0.06f, 0.02f));
        lamp1[j].giveTreeShader(&lampmodel, &shader);
        lamp2[j].giveTreeShader(&lampmodel, &shader);
        bana1[j].giveTreeShader(&bananamodel, &shader);
        bana2[j].giveTreeShader(&bananamodel, &shader);
    }
    for (int j = 0; j < 30; j++)
    {
        trees3[j] = Tree(0, glm::vec3(-j*10-50.0f, 0.0f, -400.0f), glm::vec3(0.2f, 0.2f, 0.2f));
        trees3[j].giveTreeShader(&Treemodel, &shader);
    }
    for (int j = 0; j < 40; j++)
    {
        trees4[j] = Tree(0, glm::vec3(-j * 10 + 50.0f, 0.0f, -480.0f), glm::vec3(0.2f, 0.2f, 0.2f));
        trees4[j].giveTreeShader(&Treemodel, &shader);
    }
    for (int j = 0; j < 4; j++)
    {
        bana3[j] = Tree(0, glm::vec3(-j* 81.0 - 50.0f, 0.0f, -400.0f), glm::vec3(0.05f, 0.09f, 0.05f));
        lamp3[j] = Tree(-90, glm::vec3(-j * 81.0 - 60.0f, 0.0f, -400.0f), glm::vec3(0.1f, 0.06f, 0.02f));
        bana3[j].giveTreeShader(&bananamodel, &shader);
        lamp3[j].giveTreeShader(&lampmodel, &shader);
    }
    for (int j = 0; j < 5; j++)
    {
        bana4[j] = Tree(0, glm::vec3(-j * 54.0 +30.0f, 0.0f, -480.0f), glm::vec3(0.05f, 0.09f, 0.05f));
        lamp4[j] = Tree(90, glm::vec3(-j * 54.0 + 40.0f, 0.0f, -480.0f), glm::vec3(0.1f, 0.06f, 0.02f));
        bana4[j].giveTreeShader(&bananamodel, &shader);
        lamp4[j].giveTreeShader(&lampmodel, &shader);
    }
    gun.giveModelShader(&gunModel, &shader);

    Shader shaderProgram("../Shader/shader_s.vs", "../Shader/shader_s.fs");
    surface s(&shaderProgram);

    Skybox s1(&shaderProgram, glm::vec3(-200.0f, 600.0f, -100.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f), 0);
    Skybox s2(&shaderProgram, glm::vec3(300.0f, 100.0f, -100.0f), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f), 1);
    Skybox s3(&shaderProgram, glm::vec3(-200.0f, 100.0f, 400.0f), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f), 1);
    Skybox s4(&shaderProgram, glm::vec3(-200.0f, 100.0f, -600.0f), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f), 0);
    Skybox s5(&shaderProgram, glm::vec3(-200.0f, 0.0f, -100.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f), 0);
    Skybox s6(&shaderProgram, glm::vec3(-700.0f, 100.0f, -100.0f), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f), 0);

    int i = 20, t = 80;
    while (!glfwWindowShouldClose(window) && alive && !win)
    {
        if(lightflag == 1)
        {
            light.position = glm::vec3(cos(glm::radians((float)glfwGetTime()) * 20) * 250.0f, 150.0f, sin(glm::radians((float)glfwGetTime()) * 20) * 250.0f + 250.0f);
        }
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(camera.Position.x < -440.0f)
        {
            win = true;
        }

        float a1 = sqrt(2.0) * 10 * cos(glm::radians(camera.Yaw - 45));
        float a2 = sqrt(2.0) * 10 * sin(glm::radians(camera.Yaw - 45));
        Rectangle R1 = {glm::vec3(a1 + camera.Position.x, 0.0f, a2 + camera.Position.z), glm::vec3(a2 + camera.Position.x, 0.0f, -1 * a1 + camera.Position.z), glm::vec3(-1 * a1 + camera.Position.x, 0.0f, -1 * a2 + camera.Position.z), glm::vec3(-1 * a2 + camera.Position.x, 0.0f, a1 + camera.Position.z)};
        Rectangle R3 = {glm::vec3(monster.GetPos().x - 5.0f, 0.0f, monster.GetPos().z - 5.0f), glm::vec3(monster.GetPos().x + 5.0f, 0.0f, monster.GetPos().z - 5.0f), glm::vec3(monster.GetPos().x + 5.0f, 0.0f, monster.GetPos().z + 5.0f), glm::vec3(monster.GetPos().x - 5.0f, 0.0f, monster.GetPos().z + 5.0f)};
        Rectangle R2 = {glm::vec3(monster.GetStone().x, 0.0f, monster.GetStone().z), glm::vec3(monster.GetStone().x + 5.0f, 0.0f, monster.GetStone().z), glm::vec3(monster.GetStone().x + 5.0f, 0.0f, monster.GetStone().z + 5.0f), glm::vec3(monster.GetStone().x, 0.0f, monster.GetStone().z + 5.0f)};
        if(ifCollision(R1, R2) || (monster.getLive() == 1 && ifCollision(R1, R3)))
        {
            alive = false;
        }

        glm::vec2 x1(camera.Position.x - monster.GetPos().x, camera.Position.z - monster.GetPos().z);
        glm::vec2 x2(camera.Front.x, camera.Front.z);
        x1 = glm::normalize(x1);
        x2 = glm::normalize(x2);
        if(fabsf(camera.Position.x - monster.GetPos().x) <= 100.0f && fabsf(camera.Position.z - monster.GetPos().z) <= 100.0f && shotflag == 1 && fabsf(x2.x * x1.x + x2.y * x1.y) > 0.995)
        {
            dieflag = 1;
        }

        if(gunflag == 1)
        {
            gun.giveModelShader(&gun2Model, &shader);
        }
        else
        {
            gun.giveModelShader(&gunModel, &shader);
        }
        gun.GiveAngle(&camera);
        gun.GivePos(&camera);
        gun.draw(&camera, &light);
        s1.draw(&camera, 1, "yp.bmp");
        s2.draw(&camera, 1, "zn.bmp");
        s3.draw(&camera, 1, "xp.bmp");
        s4.draw(&camera, 1, "xn.bmp");
        //s5.draw(&camera, 1, "yn.bmp");
        s6.draw(&camera, 1, "zp.bmp");

        for (int j = 0; j< 40; j++)
        {
            trees1[j].draw(&camera, &light);
            trees2[j].draw(&camera, &light);

        }
        for (int j = 0; j < 5; j++)
        {
            bana1[j].draw(&camera, &light);
            bana2[j].draw(&camera, &light);
            lamp1[j].draw(&camera, &light);
            lamp2[j].draw(&camera, &light);
        }
        for (int j = 0; j < 30; j++) {
            trees3[j].draw(&camera, &light);
        }
        for (int j = 0; j < 40; j++) {
            trees4[j].draw(&camera, &light);
        }
        for (int j = 0; j < 4; j++)
        {
            bana3[j].draw(&camera, &light);
            lamp3[j].draw(&camera, &light);
        }
        for (int j = 0; j < 5; j++) {
            bana4[j].draw(&camera, &light);
            lamp4[j].draw(&camera, &light);
        }
        for (int j = 0; j < 2; j++) {
            house[j].draw(&camera, &light);
            house1[j].draw(&camera, &light);
            house4[j].draw(&camera, &light);
        }
        house[2].draw(&camera, &light);
        for(int j = 0; j < 3; j++)
        {
            house3[j].draw(&camera, &light);
        }
        if(dieflag == 1)
        {
            monster.die(&camera, &light, 1);
        }
        else
        {
            if(i == 0)
            {
                monster.move(15);
                i = 20;
            }
            i--;
            if(t == 0 && monster.GetPos().x == 0 && camera.Position.z >= -400.0f)
            {
                monster.attack();
                t = 80;
            }
            t--;
            monster.draw(&camera, &light, 1);
        }
        if(monster.getLive() == 0)
        {
            dieflag = 0;
        }
        house5.draw(&camera, &light);
        s.draw(&camera, "../Texture/container.jpg", 1);
        shotflag = 0;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glm::vec3 camera1Pos   = glm::vec3(0.0f, 1500.0f, 0.0f);
    glm::vec3 camera1Up    = glm::vec3(0.0f, 0.0f,  -1.0f);
    Camera camera1(camera1Pos, camera1Up, -90.0f, -90.0f);
    while(!alive && !glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput1(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        s.draw(&camera1, "../Texture/lose.jpg", 1);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while(win && !glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput1(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        s.draw(&camera1, "../Texture/win.jpg", 1);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        gunflag = 1 - gunflag;
    if(glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
        shotflag = 1;
    if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        if(light.diffuse.x >= 0.3f)
        {
            light.diffuse -= glm::vec3(0.05f, 0.05f, 0.05f);
        }
        if(light.ambient.x >= 0.2f)
        {
            light.ambient -= glm::vec3(0.05f, 0.05f, 0.05f);
        }
    }
    if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        if(light.diffuse.x <= 1.0f)
        {
            light.diffuse += glm::vec3(0.05f, 0.05f, 0.05f);
        }
        if(light.ambient.x <= 1.0f)
        {
            light.ambient += glm::vec3(0.05f, 0.05f, 0.05f);
        }
    }
    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        lightflag = 1 - lightflag;

}

void processInput1(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}