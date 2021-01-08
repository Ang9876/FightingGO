//
// Created by Ang Chee on 2018/01/15.
//

#include "ifCollision.h"

bool ifCollision(Rectangle obj1, Rectangle obj2)
{
    //centers of two objects
    glm::vec2 obj1_center = glm::vec2((obj1.pointA.x + obj1.pointC.x) / 2,
                                      (obj1.pointA.z + obj1.pointC.z) / 2);
    glm::vec2 obj2_center = glm::vec2((obj2.pointA.x + obj2.pointC.x) / 2,
                                      (obj2.pointA.z + obj2.pointC.z) / 2);
    //unit vector of local x/y-axis of two objects
    glm::vec2 obj1X, obj1Y, obj2X, obj2Y;
    //half of width/height of obj1/2
    GLfloat WObj1, HObj1, WObj2, HObj2;
    //center displace of two objects
    glm::vec2 distCenter = glm::vec2(obj2_center.x - obj1_center.x, obj2_center.y - obj1_center.y);

    //calc
    WObj1 = sqrtf((obj1.pointA.x - obj1.pointB.x) * (obj1.pointA.x - obj1.pointB.x) +
                  (obj1.pointA.z - obj1.pointB.z) * (obj1.pointA.z - obj1.pointB.z)) / 2;
    WObj2 = sqrtf((obj2.pointA.x - obj2.pointB.x) * (obj2.pointA.x - obj2.pointB.x) +
                  (obj2.pointA.z - obj2.pointB.z) * (obj2.pointA.z - obj2.pointB.z)) / 2;
    HObj1 = sqrtf((obj1.pointA.x - obj1.pointD.x) * (obj1.pointA.x - obj1.pointD.x) +
                  (obj1.pointA.z - obj1.pointD.z) * (obj1.pointA.z - obj1.pointD.z)) / 2;
    HObj2 = sqrtf((obj2.pointA.x - obj2.pointD.x) * (obj2.pointA.x - obj2.pointD.x) +
                  (obj2.pointA.z - obj2.pointD.z) * (obj2.pointA.z - obj2.pointD.z)) / 2;

    obj1X = glm::vec2((obj1.pointA.x - obj1.pointB.x) / 2 / WObj1, (obj1.pointA.z - obj1.pointB.z) / 2 / WObj1);
    obj1Y = glm::vec2((obj1.pointA.x - obj1.pointD.x) / 2 / HObj1, (obj1.pointA.z - obj1.pointD.z) / 2 / HObj1);
    obj2X = glm::vec2((obj2.pointA.x - obj2.pointB.x) / 2 / WObj2, (obj2.pointA.z - obj2.pointB.z) / 2 / WObj2);
    obj2Y = glm::vec2((obj2.pointA.x - obj2.pointD.x) / 2 / HObj2, (obj2.pointA.z - obj2.pointD.z) / 2 / HObj2);

    // if(fabsf(centerDist * point1.x) > )
    //calculate project length on obj1X, obj1Y, obj2X, obj2Y
    GLfloat distObj1X = fabsf(distCenter.x * obj1X.x + distCenter.y * obj1X.y);
    GLfloat distObj1Y = fabsf(distCenter.x * obj1Y.x + distCenter.y * obj1Y.y);
    GLfloat distObj2X = fabsf(distCenter.x * obj2X.x + distCenter.y * obj2X.y);
    GLfloat distObj2Y = fabsf(distCenter.x * obj2Y.x + distCenter.y * obj2Y.y);

    //judge if collision
    if((distObj1X - WObj1) > fabsf(WObj2 * (obj1X.x * obj2X.x + obj1X.y * obj2X.y)) + fabsf(HObj2 * (obj1X.x * obj2Y.x + obj1X.y * obj2Y.y)))
    {
        return false;
    }
    else if((distObj1Y - HObj1) > fabsf(WObj2 * (obj2X.x * obj1Y.x + obj2X.y * obj1Y.y)) + fabsf(HObj2 * (obj2Y.x * obj1Y.x + obj2Y.y * obj1Y.y)))
    {
        return false;
    }
    else if((distObj2X - WObj2) > fabsf(WObj1 * (obj1X.x * obj2X.x + obj1X.y * obj2X.y)) + fabsf(HObj1 * (obj1Y.x * obj2X.x + obj1Y.y * obj2X.y)))
    {
        return false;
    }
    else if((distObj2Y - HObj2) > fabsf(WObj1 * (obj1X.x * obj2Y.x + obj1X.y * obj2Y.y)) + fabsf(HObj1 * (obj1Y.x * obj2Y.x + obj1Y.y * obj2Y.y)))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void print(Rectangle obj1, Rectangle obj2)
{
    cout << "obj1: " << obj1.pointA.x << " " << obj1.pointA.z << " " << obj1.pointB.x << " " << obj1.pointB.z << " " << obj1.pointC.x << " " << obj1.pointC.z << " " << obj1.pointD.x << " " << obj1.pointD.z << endl;
    cout << "obj2: " << obj2.pointA.x << " " << obj2.pointA.z << " " << obj2.pointB.x << " " << obj2.pointB.z << " " << obj2.pointC.x << " " << obj2.pointC.z << " " << obj2.pointD.x << " " << obj2.pointD.z << endl;
}












