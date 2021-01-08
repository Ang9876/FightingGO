//
// Created by Ang Chee on 2017/12/23.
//
#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <math.h>
#include "ifCollision.h"

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW        = -90.0f;
const float PITCH      =  0.0f;
const float SPEED      =  60.0f;
const float SENSITIVITY =  0.4f;
const float ZOOM       =  45.0f;


// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // Camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // Eular Angles
    float Yaw;
    float Pitch;
    // Camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // Constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }
    // Constructor with scalar values
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(Position, glm::vec3(Position.x + Front.x,
                                               Position.y + Front.y,
                                               Position.z + Front.z), Up);
    }

    glm::vec3 GetPosition()
    {
        return Position;
    }

    // Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        glm::vec3 tmpPos = Position;
        if (direction == FORWARD)
            Position += glm::vec3(Front.x * velocity,
                                  Front.y * velocity,
                                  Front.z * velocity);


        if (direction == BACKWARD)
            Position -= glm::vec3(Front.x * velocity,
                                  Front.y * velocity,
                                  Front.z * velocity);
        if (direction == LEFT)
            Position -= glm::vec3(Right.x * velocity,
                                  Right.y * velocity,
                                  Right.z * velocity);
        if (direction == RIGHT)
            Position += glm::vec3(Right.x * velocity,
                                  Right.y * velocity,
                                  Right.z * velocity);
        float a1 = sqrt(2.0) * 10 * cos(glm::radians(Yaw - 45));
        float a2 = sqrt(2.0) * 10 * sin(glm::radians(Yaw - 45));
        Rectangle R1 = {glm::vec3(a1 + Position.x, 0.0f, a2 + Position.z), glm::vec3(a2 + Position.x, 0.0f, -1 * a1 + Position.z), glm::vec3(-1 * a1 + Position.x, 0.0f, -1 * a2 + Position.z), glm::vec3(-1 * a2 + Position.x, 0.0f, a1 + Position.z)};
        Rectangle R2 = {glm::vec3(-60.0f, 0.0f, 80.0f), glm::vec3(-480.0f, 0.0f, 80.0f), glm::vec3(-480.0f, 0.0f, -390.0f), glm::vec3(-60.0f, 0.0f, -390.0f)};
        Rectangle R3 = {glm::vec3(55.0f, 0.0f, 80.0f), glm::vec3(400.0f, 0.0f, 80.0f), glm::vec3(400.0f, 0.0f, -440.0f), glm::vec3(55.0f, 0.0f, -440.0f)};
        Rectangle R4 = {glm::vec3(55.0f, 0.0f, -500.0f), glm::vec3(55.0f, 0.0f, -700.0f), glm::vec3(-480.0f, 0.0f, -700.0f), glm::vec3(-480.0f, 0.0f, -500.0f)};
        if(ifCollision(R1, R2) || ifCollision(R1, R3) || ifCollision(R1, R4) || Position.x < -480.0f)
        {
            Position = tmpPos;
        }

        Position.y = 15.0f;
        if(Position.x < -440.0f)
        {
            Position.y = 30.0f;
        }
    }

    // Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   += xoffset;
        Pitch += yoffset;

        // Make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // Update Front, Right and Up Vectors using the updated Eular angles
        updateCameraVectors();
    }

    // Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset)
    {
        if (Zoom >= 1.0f && Zoom <= 45.0f)
            Zoom -= yoffset;
        if (Zoom <= 1.0f)
            Zoom = 1.0f;
        if (Zoom >= 45.0f)
            Zoom = 45.0f;
    }

private:
    // Calculates the front vector from the Camera's (updated) Eular Angles
    void updateCameraVectors()
    {
        // Calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // Also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = glm::normalize(glm::cross(Right, Front));
    }
};
#endif