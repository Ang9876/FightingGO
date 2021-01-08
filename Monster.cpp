//
// Created by Ang Chee on 2017/12/24.
//

#include "Monster.h"
// ------------------------ public ----------------------------

// position and direction of the monster
// angle is from positive z axis to positive x axis
// angle is the direction of the left of the monster
Monster::Monster(float angle, glm::vec3 pos)
{
    this -> angle = angle;
    this -> pos = pos;
    monsterBody = nullptr;
    monsterShader = nullptr;
    hp = 100;
    hpFull = 100;
    moveStatus = 0;
    attackStatus = 0;
    flyStatus = 0;
    liveStatus = 0;
    targetPos = glm::vec3(0.0f);
    initPos = glm::vec3(0.0f);
    tmpPos = glm::vec3(500.0f, 0.0f, 0.0f);
    flag = 1;
}

void Monster::giveModelShader(Model* body, Shader* shader)
{
    monsterBody = body;
    monsterShader = shader;
}

void Monster::draw(Camera* camera, Light* light, int choice)
{
    if(flag == 1 && pos.x == 0)
    {
        turn(-90.0f);
        flag = 0;
    }
    if(pos.z >= 0)
    {
        pos = glm::vec3(-60.0f, 0.0f, -450.0f);
        angle = 90.0f;
        flag = 1;
    }
    monsterShader -> use();
    if(choice == 1)
    {
        glm::mat4 projection(1.0f);
        projection = glm::perspective(glm::radians(camera -> Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 10000.0f);
        glm::mat4 view(1.0f);
        view = camera -> GetViewMatrix();
        monsterShader -> setMat4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));
        monsterShader -> setMat4fv("view", 1, GL_FALSE, glm::value_ptr(view));
    }
    float relative_pos[24] = {  0.0, 42.0,  0.0, // body
                                3.0,  0.0,  0.0, // leg1
                               -5.0,  0.0,  0.0, // leg2
                               12.0, 27.0,  0.0, // upper arm1
                              -12.0, 27.0,  0.0, // upper arm2
                               12.0, 27.0,  0.0, // lower arm1
                              -12.0, 27.0,  0.0, // lower arm2
                                0.0, 50.0,  0.0};// head
    float transition_scale[24] = { 0.6, 0.2, 0.2,
                                   0.2, 0.38, 0.2,
                                   0.2, 0.38, 0.2,
                                   0.2, 0.15, 0.2,
                                   0.2, 0.15, 0.2,
                                   0.2, 0.15, 0.2,
                                   0.2, 0.15, 0.2,
                                   0.2,  0.1, 0.2};

    for(int i = 0; i < 8; i++)
    {
        glm::mat4 model(1.0f);
        model = glm::translate(model, pos);
        if(attackStatus == ATTACKCOUNT)
        {
            targetPos = camera -> Position;
            initPos = pos;
        }
        if(attackStatus != 0)
        {
            model = glm::rotate(model, atan((targetPos.x - pos.x) / (targetPos.z - pos.z)), glm::vec3(0.0f, 1.0f, 0.0f));
        }
        model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
        model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::translate(model, glm::vec3(relative_pos[3 * i], relative_pos[3 * i + 1], relative_pos[3 * i + 2]));
        if((i == 1 && moveStatus == 1) || (i == 2 && moveStatus == 3))
        {
            model = glm::translate(model, glm::vec3(0.0f, 37.0f, 0.0f));
            model = glm::rotate(model, glm::radians(-15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::translate(model, glm::vec3(0.0f, -37.0f, 0.0f));
        }
        if(i == 7 && moveStatus % 2 == 1)
        {
            model = glm::rotate(model, glm::radians(-15.0f * (moveStatus - 2)), glm::vec3(0.0f, 1.0f, 0.0f));
        }
        if(i >= 3 && i != 7 && attackStatus != 0)
        {
            float angleArm;
            if(attackStatus < ATTACKCOUNT / 3)
            {
                angleArm = 0.0f - (3.0 * attackStatus / ATTACKCOUNT) * 215.0f;
            }
            else
            {
                angleArm = -215.0f + (3.0 * (attackStatus - ATTACKCOUNT / 3) / (ATTACKCOUNT * 2)) * 215.0f;
            }
            model = glm::translate(model, glm::vec3(0.0f, 12.0f, 0.0f));
            model = glm::rotate(model, glm::radians(angleArm), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::translate(model, glm::vec3(0.0f, -12.0f, 0.0f));

        }
        if(i == 0 || i >= 5)
        {
            model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        }
        model = glm::scale(model, glm::vec3(transition_scale[3 * i], transition_scale[3 * i + 1], transition_scale[3 * i + 2]));
        monsterShader -> setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
        monsterBody -> Draw(*monsterShader, camera -> GetPosition(), *light);
    }
    drawStone(camera, light);
    if(attackStatus != 0)
    {
        attackStatus--;
    }
    if(attackStatus != 0 && ATTACKCOUNT - attackStatus >= 11.0 * ATTACKCOUNT / 15)
    {
        flyStatus = FLYCOUNT;
        attackStatus = 0;
    }
    if(flyStatus != 0)
    {
        flyStatus--;
    }
}

// monster move for the input distance in its now direction
void Monster::move(float distance)
{
    pos.x += sin(PI * angle / 180) * distance;
    pos.z += cos(PI * angle / 180) * distance;
    moveStatus = (moveStatus + 1) % 4;
}

// monster turn a direction. The positive direction is from z to x.
void Monster::turn(float theta)
{
    angle += theta;
    if(angle >= 360)
    {
        angle -= 360;
    }
}

void Monster::die(Camera* camera, Light* light, int choice)
{
    if(liveStatus == 0)
    {
        liveStatus = DIECOUNT;
    }
    moveStatus = 0;
    attackStatus = 0;
    flyStatus = 0;
    if(liveStatus >= 35)
    {
        monsterShader->use();
        if (choice == 1)
        {
            glm::mat4 projection(1.0f);
            projection = glm::perspective(glm::radians(camera->Zoom), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f,
                                          10000.0f);
            glm::mat4 view(1.0f);
            view = camera->GetViewMatrix();
            monsterShader->setMat4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));
            monsterShader->setMat4fv("view", 1, GL_FALSE, glm::value_ptr(view));
        }
        float relative_pos[24] = {0.0, 42.0, 0.0, // body
                                  3.0, 0.0, 0.0, // leg1
                                  -5.0, 0.0, 0.0, // leg2
                                  12.0, 27.0, 0.0, // upper arm1
                                  -12.0, 27.0, 0.0, // upper arm2
                                  12.0, 27.0, 0.0, // lower arm1
                                  -12.0, 27.0, 0.0, // lower arm2
                                  0.0, 50.0, 0.0};// head
        float transition_scale[24] = {0.6, 0.2, 0.2,
                                      0.2, 0.38, 0.2,
                                      0.2, 0.38, 0.2,
                                      0.2, 0.15, 0.2,
                                      0.2, 0.15, 0.2,
                                      0.2, 0.15, 0.2,
                                      0.2, 0.15, 0.2,
                                      0.2, 0.1, 0.2};

        for (int i = 0; i < 8; i++)
        {
            glm::mat4 model(1.0f);
            model = glm::translate(model, pos);
            model = glm::rotate(model, glm::radians(-1.0f * 90.0f * (DIECOUNT - liveStatus) / 5), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(model, glm::vec3(relative_pos[3 * i], relative_pos[3 * i + 1], relative_pos[3 * i + 2]));
            if ((i == 1 && moveStatus == 1) || (i == 2 && moveStatus == 3))
            {
                model = glm::translate(model, glm::vec3(0.0f, 37.0f, 0.0f));
                model = glm::rotate(model, glm::radians(-15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                model = glm::translate(model, glm::vec3(0.0f, -37.0f, 0.0f));
            }
            if (i == 7 && moveStatus % 2 == 1)
            {
                model = glm::rotate(model, glm::radians(-15.0f * (moveStatus - 2)), glm::vec3(0.0f, 1.0f, 0.0f));
            }
            if (i == 0 || i >= 5)
            {
                model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            }
            model = glm::scale(model, glm::vec3(transition_scale[3 * i], transition_scale[3 * i + 1],
                                                transition_scale[3 * i + 2]));
            monsterShader->setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
            monsterBody->Draw(*monsterShader, camera->GetPosition(), *light);
        }
    }
    if(liveStatus != 0)
        liveStatus--;
    if(liveStatus == 1)
    {
        pos = glm::vec3(-60.0f, 0.0f, -450.0f);
        angle = 90.0f;
        flag = 1;
    }
}


void Monster::attack()
{
    if(attackStatus == 0)
        attackStatus = ATTACKCOUNT;
}

int Monster::getLive()
{
    return liveStatus;
}

glm::vec3 Monster::GetStone()
{
    return tmpPos;
}

glm::vec3 Monster::GetPos()
{
    return pos;
}

// ------------------------ private ----------------------------
void Monster::drawStone(Camera* camera, Light* light)
{
    if(ATTACKCOUNT - attackStatus > 2.0 * ATTACKCOUNT / 15 && ATTACKCOUNT - attackStatus < 11.0 * ATTACKCOUNT / 15)
    {
        glm::mat4 model(1.0f);
        model = glm::translate(model, pos);
        if(attackStatus != 0)
        {
            model = glm::rotate(model, atan((targetPos.x - pos.x) / (targetPos.z - pos.z)), glm::vec3(0.0f, 1.0f, 0.0f));
        }
        model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::translate(model, glm::vec3(0.0, 10.0,  0.0));
        float angleArm;
        if(attackStatus < ATTACKCOUNT / 3)
        {
            angleArm = 0.0f - (3.0 * attackStatus / ATTACKCOUNT) * 215.0f;
        }
        else
        {
            angleArm = -215.0f + (3.0 * (attackStatus - ATTACKCOUNT / 3) / (ATTACKCOUNT * 2)) * 215.0f;
        }
        model = glm::translate(model, glm::vec3(0.0f, 11.0f, 0.0f));
        model = glm::rotate(model, glm::radians(angleArm), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::translate(model, glm::vec3(0.0f, -11.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.3, 0.07, 0.1));
        monsterShader -> setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
        monsterBody -> Draw(*monsterShader, camera -> GetPosition(), *light);
    }
    if(flyStatus != 0)
    {
        glm::mat4 model(1.0f);
        tmpPos.x = initPos.x + (FLYCOUNT - flyStatus) * (targetPos.x - initPos.x) / FLYCOUNT;
        tmpPos.y = 34 - 34 * (FLYCOUNT - flyStatus) * (FLYCOUNT - flyStatus) / (FLYCOUNT * FLYCOUNT);
        tmpPos.z = initPos.z + (FLYCOUNT - flyStatus) * (targetPos.z - initPos.z) / FLYCOUNT;
        model = glm::translate(model, tmpPos);
        model = glm::rotate(model, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        //model = glm::translate(model, glm::vec3(0.0, 10.0,  0.0));
        model = glm::scale(model, glm::vec3(0.3, 0.07, 0.1));
        monsterShader -> setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
        monsterBody -> Draw(*monsterShader, camera -> GetPosition(), *light);
    }
    if(flyStatus == 0)
    {
        tmpPos = glm::vec3(500.0f, 0.0f, 0.0f);
    }
}