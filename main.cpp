#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#include<cstdlib>
#include<GL/gl.h>
#include<cmath>
#include<mmsystem.h>

using namespace std;

/// Scenario 1's variables

/// toogling day & night
/// Scenario 1
bool dis1 = true;
bool dis2 = false;

/// Scenario 2's variable
bool dis3 = false;
bool dis4 = false;

/// Scenario 3
bool dis5 = false;
bool dis6 = false;

/// Scenario 4
bool dis7 = false;
bool dis8 = false;


///..................................................////
/// ballon
float disBallon = 2;
float speedBallon = 0.1f;

/// Normal vehicle on road 1
float nd = 15.8657;

/// bus3
float posbus3LR = 1.3f;
float speedLRbus3 = 0.2f;

/// bus4
float posbus4RL = 25.3213f;
float speedLRbus4 = 0.3f;

/// sports car 2
float posRL2 = 28.0f;
float speedRL2 = 0.3f;

/// Traffic Sound
bool ok = false;

/// traffic Light
bool Red = false;
bool Yellow = false;
bool Green = false;

int cc = 0;
float r1 = 1.0f, g1 = 0.0f, b1 = 0.0f;  /// Red
float r2 = 1.0f, g2 = 1.0f, b2 = 0.0f;  /// Yellow
float r3 = 0.0f, g3 = 1.0f, b3 = 0.0f;  /// Green

/// Ambulance

float amRed = 1.0f;
float amGreen = 0.0f;
float amBlue = 0.0f;


/// Manual Vehicle
float posRL = 30.0f;
float posLR = 0.0f;
float speedLR = 0.4f;
float speedRL = 0.4f;
float angle = 0.0f;

float posLR2=26.5431f;
float speedLR2 = 0.4f;
/// Emergency road vehicle
float eDis = 28.9638;
float eDis2 = 0;
/// Normal vehicle
float speed = 0.3f;

/// Plane
float ep = 30.0f;
float sp = 0.2f;

/// Scenario 2's variable

bool firstFire = false;
bool secondFire = false;
bool thirdFire = false;

bool waterfireX = false;
bool waterfireXY = false;

float _angle1 = 0.0f;
float angle2 = 180.0f;
float angle3 = 0.0f;


float ambulanceSpeed = 0.2f;
float fireCarSpeed = 0.0f;
float fireCarDisS2 = 1.0f;


///gasballon
float obj_gasballon = 2.0f;
///cloud
float obj_cloud = 5.0f;

/// Scenario 3's varible


/// SKY
void sky()
{
    glBegin(GL_POLYGON);
    glColor3ub(132,205,238);
    glVertex2f(0,5.2461);
    glVertex2f(30,5.2461);
    glColor3ub(51,51,201);
    glVertex2f(30,15);
    glVertex2f(0,15);
    glEnd();

}

void sky2() {
    glBegin(GL_POLYGON);
    glColor3ub(132,205,238);
    glVertex2f(0,2.9265);
    glVertex2f(30,2.9265);
    glColor3ub(51,51,201);
    glVertex2f(30,15);
    glVertex2f(0,15);
    glEnd();

}


void skyNight()
{

    glBegin(GL_POLYGON);
    glColor3ub(5,52,122);
    glVertex2f(0,0);
    glVertex2f(30,0);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,52,122);
    glVertex2f(0,9.0);
    glVertex2f(30,9.0);
    glColor3ub(0,0,0);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();
}

void skyNight2()
{
    glBegin(GL_POLYGON);
    glColor3ub(5,52,122);
    glVertex2f(0,5.2461);
    glVertex2f(30,5.2461);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,52,122);
    glVertex2f(0,2.8);
    glVertex2f(30,2.8);
    glColor3ub(0,0,0);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();
}
// Circle   Gas ballon

void ballonCircle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}
//Gas ballon

void gasballon()
{
    glPushMatrix();
    glTranslatef(obj_gasballon,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(115, 47, 8);
    glVertex2f(1.7, 10.9);
    glVertex2f(1.7, 10.5);
    glVertex2f(1.2, 10.5);
    glVertex2f(1.2, 10.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(205, 189, 189);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.7, 10.9);
    glVertex2f(1.2, 10.9);
    glEnd();

    ballonCircle(0.3407, 1.4,12.3, 204,204,0);
    ballonCircle(0.6469, 1.4,12.9, 204,204,0);
    ballonCircle(0.7357, 1.04,12.75, 11,43,46);
    ballonCircle(0.7357,1.8,12.75, 146,11,11);
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.2, 10.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.3, 10.9);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.4, 10.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.5, 10.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.6, 10.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.4, 12.1);
    glVertex2f(1.7, 10.9);
    glEnd();
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(0, 0, 0);
    glVertex2f(1.2, 10.9);
    glVertex2f(1.7, 10.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(1.43, 10.5);
    glVertex2f(1.48, 10.5);
    glVertex2f(1.48, 10.7);
    glVertex2f(1.43, 10.7);
    glEnd();

    glPopMatrix();

}



void CloudCircle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}
void cloud()
{
    glPushMatrix();
    glTranslatef(obj_cloud, 0, 0);
    //1
    CloudCircle(0.36, 12.6,13.4,221,231,238);
    CloudCircle(0.25, 12.1,13.4,221,231,238);
    CloudCircle(0.29,11.7,13.35,221,231,238);
    CloudCircle(0.31, 11.3,13.1,221,231,238);
    CloudCircle(0.35, 11.7,12.9,221,231,238);
    CloudCircle(0.40, 12.2,13,221,231,238);
    CloudCircle(0.25, 12.5,12.6,221,231,238);
    CloudCircle(0.62, 13.1,13,221,231,238);
    //2
    CloudCircle(0.33, 23.3,12.7,221,231,238);
    CloudCircle(0.25, 22.9,12.8,221,231,238);
    CloudCircle(0.29,22.5,12.7,221,231,238);
    CloudCircle(0.31, 22,12.4,221,231,238);
    CloudCircle(0.35, 22.4,12.3,221,231,238);
    CloudCircle(0.40, 23,12.3,221,231,238);
    CloudCircle(0.25, 23.4,12.2,221,231,238);
    CloudCircle(0.62, 23.9,12.3,221,231,238);

    glPopMatrix();
}


/// Road Side Space & Building Side Sapce

void roadsidespace()
{
    //1
    glBegin(GL_POLYGON);
    glColor3ub(205, 189, 189);
    glVertex2f(30, 4.95);
    glVertex2f(0, 4.95);
    glVertex2f(0, 5.246);
    glVertex2f(30, 5.246);
    glEnd();
    ///2
    glBegin(GL_POLYGON);
    glColor3ub(8,101,0);
    glVertex2f(30, 3.2673);
    glVertex2f(0, 3.2673);
    glVertex2f(0, 2.48);
    glVertex2f(30, 2.48);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(166,183,175);
    glVertex2f(30, 0.7968);
    glVertex2f(0, 0.7968);
    glVertex2f(0, 0);
    glVertex2f(30, 0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(2, 0);
    glVertex2f(2, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(4, 0);
    glVertex2f(4, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(6, 0);
    glVertex2f(6, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(8, 0);
    glVertex2f(8, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(10, 0);
    glVertex2f(10, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(12, 0);
    glVertex2f(12, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(14, 0);
    glVertex2f(14, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(16, 0);
    glVertex2f(16, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(18, 0);
    glVertex2f(18, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(20, 0);
    glVertex2f(20, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(22, 0);
    glVertex2f(22, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(24, 0);
    glVertex2f(24, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(26, 0);
    glVertex2f(26, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(28, 0);
    glVertex2f(28, 2.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(100,100,100);
    glVertex2f(2, 0);
    glVertex2f(2, 2.48);
    glEnd();

}


    // Main Road
void mainroad()
{

    ///1
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52);
    glVertex2f(30, 4.95);
    glVertex2f(0, 4.95);
    glVertex2f(0, 3.2673);
    glVertex2f(30, 3.2673);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52);
    glVertex2f(30, 2.4811);
    glVertex2f(0, 2.4811);
    glVertex2f(0, 0.7968);
    glVertex2f(30, 0.7968);
    glEnd();

    //Road divide line 1

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0, 4.1619);
    glVertex2f(0.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 4.1619);
    glVertex2f(1.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 4.1619);
    glVertex2f(2.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3, 4.1619);
    glVertex2f(3.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 4.1619);
    glVertex2f(4.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 4.1619);
    glVertex2f(5.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 4.1619);
    glVertex2f(6.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 4.1619);
    glVertex2f(7.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8, 4.1619);
    glVertex2f(8.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9, 4.1619);
    glVertex2f(9.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 4.1619);
    glVertex2f(10.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 4.1619);
    glVertex2f(11.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12, 4.1619);
    glVertex2f(12.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 4.1619);
    glVertex2f(13.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 4.1619);
    glVertex2f(14.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 4.1619);
    glVertex2f(15.5, 4.1619);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(16, 4.1619);
    glVertex2f(16.5, 4.1619);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(17, 4.1619);
    glVertex2f(17.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 4.1619);
    glVertex2f(18.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 4.1619);
    glVertex2f(19.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 4.1619);
    glVertex2f(20.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 4.1619);
    glVertex2f(21.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 4.1619);
    glVertex2f(22.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 4.1619);
    glVertex2f(23.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 4.1619);
    glVertex2f(24.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 4.1619);
    glVertex2f(25.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 4.1619);
    glVertex2f(26.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27, 4.1619);
    glVertex2f(27.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28, 4.1619);
    glVertex2f(28.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 4.1619);
    glVertex2f(29.5, 4.1619);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 4.1619);
    glVertex2f(32, 4.1619);
    glEnd();
    // Road dider line 2
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0,  1.6);
    glVertex2f(0.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 1.6);
    glVertex2f(1.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 1.6);
    glVertex2f(2.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3, 1.6);
    glVertex2f(3.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 1.6);
    glVertex2f(4.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 1.6);
    glVertex2f(5.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 1.6);
    glVertex2f(6.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 1.6);
    glVertex2f(7.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8, 1.6);
    glVertex2f(8.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9,1.6);
    glVertex2f(9.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 1.6);
    glVertex2f(10.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 1.6);
    glVertex2f(11.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12, 1.6);
    glVertex2f(12.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 1.6);
    glVertex2f(13.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 1.6);
    glVertex2f(14.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 1.6);
    glVertex2f(15.5, 1.6);
    glEnd();
///

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 1.6);
    glVertex2f(18.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 1.6);
    glVertex2f(19.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 1.6);
    glVertex2f(20.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 1.6);
    glVertex2f(21.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 1.6);
    glVertex2f(22.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 1.6);
    glVertex2f(23.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 1.6);
    glVertex2f(24.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 1.6);
    glVertex2f(25.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 1.6);
    glVertex2f(26.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27, 1.6);
    glVertex2f(27.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28,1.61);
    glVertex2f(28.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 1.6);
    glVertex2f(29.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 1.6);
    glVertex2f(32,1.6);
    glEnd();
}

/// GROUND LINE
void groundline()
{
    glBegin(GL_LINES);
    glLineWidth(4.5);
    glColor3f(0, 102, 0);
    glVertex2f(0, 5.2461);
    glVertex2f(30, 5.2461);
    glEnd();
}

    // BULIDING 1 //
void building1()
{
    glBegin(GL_POLYGON);
    glColor3ub(230, 0, 69);
    glVertex2f(1.5,6.4);
    glVertex2f(1.5,5.2);
    glColor3ub(230, 0,169);
    glVertex2f(2.3,5.2);
    glVertex2f(2.3,6.4);
    glEnd();

    //Window

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(1.67,6.1);
    glVertex2f(1.9,6.1);
    glVertex2f(1.9,6.26);
    glVertex2f(1.67,6.26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(1.67,5.75);
    glVertex2f(1.9,5.75);
    glVertex2f(1.9,5.9);
    glVertex2f(1.67,5.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(1.67,5.38);
    glVertex2f(1.9,5.38);
    glVertex2f(1.9,5.53);
    glVertex2f(1.67,5.53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(2,6.1);
    glVertex2f(2.3,6.1);
    glVertex2f(2.3,6.26);
    glVertex2f(2,6.26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(2,5.75);
    glVertex2f(2.3,5.75);
    glVertex2f(2.3,5.9);
    glVertex2f(2,5.9);
    glEnd();

}

    //  BULIDING 2 //

void building2()
{
    glBegin(GL_POLYGON);
    glColor3ub(9,146,174 );
    glVertex2f(2.3,7);
    glVertex2f(2.3,5.2);
    glVertex2f(3.4,5.2);
    glVertex2f(3.4,7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(194,233,236);
    glVertex2f(2.3,7);
    glVertex2f(2.3,5.2);
    glVertex2f(2.6,5.2);
    glVertex2f(2.6,7);
    glEnd();



    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 6.8);
    glVertex2f(3.4, 6.8);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 6.6);
    glVertex2f(3.4, 6.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 6.4);
    glVertex2f(3.4, 6.4);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 6.2);
    glVertex2f(3.4, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 6.0);
    glVertex2f(3.4, 6.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 5.8);
    glVertex2f(3.4, 5.8);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 5.6);
    glVertex2f(3.4, 5.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(194,233,236);
    glVertex2f(2.6, 5.4);
    glVertex2f(3.4, 5.4);
    glEnd();
}

    //  BULIDING 3 //

void building3()
{
    glBegin(GL_POLYGON);
    glColor3ub(178,150,168);
    glVertex2f(4.7,5.2);
    glVertex2f(6.7,5.2);
    glVertex2f(6.7,8.4);
    glVertex2f(4.7,8.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.15,7.9);
    glVertex2f(5.5,7.9);
    glVertex2f(5.5,8.2);
    glVertex2f(5.15,8.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.15,7.38);
    glVertex2f(5.5,7.38);
    glVertex2f(5.5,7.66);
    glVertex2f(5.15,7.66);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.15,6.83);
    glVertex2f(5.5,6.83);
    glVertex2f(5.5,7.1);
    glVertex2f(5.15,7.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.15,6.27);
    glVertex2f(5.5,6.27);
    glVertex2f(5.5,6.54);
    glVertex2f(5.15,6.54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.15,5.74);
    glVertex2f(5.5,5.74);
    glVertex2f(5.5,6);
    glVertex2f(5.15,6);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(6,7.38);
    glVertex2f(6.43,7.38);
    glVertex2f(6.43,7.66);
    glVertex2f(6,7.66);

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(6,7.38);
    glVertex2f(6.43,7.38);
    glVertex2f(6.43,7.66);
    glVertex2f(6,7.66);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(6,6.83);
    glVertex2f(6.43,6.83);
    glVertex2f(6.43,7.1);
    glVertex2f(6,7.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(6 ,6.27);
    glVertex2f(6.43,6.27);
    glVertex2f(6.43,6.54);
    glVertex2f(6 , 6.54);
    glEnd();
}

    //  BULIDING 4//

void building4()
{
    glBegin(GL_POLYGON);
    glColor3ub(58, 91, 137);
    glVertex2f(6.7,7.2);
    glVertex2f(6.7,5.2);
    glVertex2f(8.1,5.2);
    glVertex2f(8.1,7.2);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 7.2);
    glVertex2f(7.4, 5.2);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 7.1);
    glVertex2f(8.1, 7.1);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 6.94);
    glVertex2f(8.1, 6.94);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 6.68);
    glVertex2f(7.7, 6.68);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 6.48);
    glVertex2f(7.7, 6.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 6.28);
    glVertex2f(7.7, 6.28);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 6.08);
    glVertex2f(7.7, 6.08);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 5.88);
    glVertex2f(7.7, 5.88);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 5.68);
    glVertex2f(7.7, 5.68);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 5.48);
    glVertex2f(7.7, 5.48);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(7.4, 5.28);
    glVertex2f(7.7, 5.28);
    glEnd();
}

    // BULIDING 5 //

void building5()
{
    glBegin(GL_POLYGON);
    glColor3ub(245, 207, 145);
    glVertex2f(7.7,5.2);
    glVertex2f(9.3,5.2);
    glVertex2f(9.3,6.9);
    glVertex2f(7.7,6.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58 , 21 ,21);
    glVertex2f(8.67,5.2);
    glVertex2f(9.2,5.2);
    glVertex2f(9.2,6.75);
    glVertex2f(8.67,6.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58 , 21 ,21);
    glVertex2f(8.37,5.2);
    glVertex2f(7.9,5.2);
    glVertex2f(7.9,6.54);
    glVertex2f(8.37,6.54);
    glEnd();

}

    //  BULIDING 7 //
void building7()
{

    glBegin(GL_POLYGON);
    glColor3ub(24 , 207 ,213);
    glVertex2f(11.23,5.24);
    glVertex2f(10.72,5.24);
    glVertex2f(10.64,6.47);
    glVertex2f(10.72,6.47);
    glVertex2f(10.22,6.47);
    glColor3ub(24,213,119);
    glVertex2f(10.22,8.45);
    glVertex2f(11.67,8.45);
    glVertex2f(11.67,7.96);
    glVertex2f(11.23,7.95);
    glVertex2f(11.23,5.24);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 8.15);
    glVertex2f(11.67, 8.15);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 7.85);
    glVertex2f(11.23, 7.85);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 7.71);
    glVertex2f(11.23, 7.71);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 7.51);
    glVertex2f(11.23, 7.51);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 7.31);
    glVertex2f(11.23, 7.31);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 7.11);
    glVertex2f(11.23, 7.11);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 6.91);
    glVertex2f(11.23, 6.91);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 6.71);
    glVertex2f(11.23, 6.71);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 6.51);
    glVertex2f(11.23, 6.51);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 6.31);
    glVertex2f(11.23, 6.31);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 6.11);
    glVertex2f(11.23, 6.11);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 5.91);
    glVertex2f(11.23, 5.91);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 5.71);
    glVertex2f(11.23, 5.71);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glVertex2f(10.64, 5.51);
    glVertex2f(11.23, 5.51);
    glEnd();
}

    // BULIDING 6//

void building6()
{
    glBegin(GL_POLYGON);
    glColor3ub(122, 131, 145 );
    glVertex2f(9.3,5.24);
    glVertex2f(10.72,5.24);
    glVertex2f(10.72,6.47);
    glVertex2f(9.3,6.47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(58 , 21 ,21);
    glVertex2f(10.1,5.2);
    glVertex2f(10.44,5.2);
    glVertex2f(10.44,5.8);
    glVertex2f(10.1,5.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58 , 21 ,21);
    glVertex2f(9.7,5.2);
    glVertex2f(10.1,5.2);
    glVertex2f(10.1,5.8);
    glVertex2f(9.7,5.8);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1);
    glColor3f(0, 0, 0);
    glVertex2f(10.1, 5.2);
    glVertex2f(10.1, 5.8);
    glEnd();
}

    // BULIDING 8 //

void building8()
{


    glBegin(GL_POLYGON);
    glColor3ub(54,15,159);
    glVertex2f(11.23,5.2);
    glVertex2f(12.8,5.2);
    glColor3ub(200,0,230);
    glVertex2f(12.8,7.9);
    glVertex2f(11.23,7.9);
    glEnd();


    // window
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(12.2,5.7);
    glVertex2f(12.5,5.7);
    glVertex2f(12.5,5.9);
    glVertex2f(12.2,5.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(12.2,6.25);
    glVertex2f(12.5,6.25);
    glVertex2f(12.5,6.5);
    glVertex2f(12.2,6.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(12.2,6.78);
    glVertex2f(12.5,6.78);
    glVertex2f(12.5,7);
    glVertex2f(12.2,7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(12.2,7.34);
    glVertex2f(12.5,7.34);
    glVertex2f(12.5,7.62);
    glVertex2f(12.2,7.62);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(11.5,5.7);
    glVertex2f(11.9,5.7);
    glVertex2f(11.9,5.9);
    glVertex2f(11.5,5.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(11.5,6.25);
    glVertex2f(11.9,6.25);
    glVertex2f(11.9,6.52);
    glVertex2f(11.5,6.52);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(11.5,6.78);
    glVertex2f(11.9,6.78);
    glVertex2f(11.9,7);
    glVertex2f(11.5,7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(11.5,7.34);
    glVertex2f(11.9,7.34);
    glVertex2f(11.9,7.62);
    glVertex2f(11.5,7.62);
    glEnd();

}

void building9()
{
    //  BULIDING 9 //
    glBegin(GL_POLYGON);
    glColor3ub(199,79,27 );
    glVertex2f(12.8,5.2);
    glVertex2f(14.18,5.2);
    glVertex2f(14.18,6.4);
    glVertex2f(12.8,6.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(13,6.2);
    glVertex2f(14,6.2);
    glVertex2f(14,6);
    glVertex2f(13,6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(13.6,5.53);
    glVertex2f(14,5.53);
    glVertex2f(14,5.8);
    glVertex2f(13.6,5.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(175,204,223);
    glVertex2f(13,5.53);
    glVertex2f(13.37,5.53);
    glVertex2f(13.37,5.8);
    glVertex2f(13,5.8);
    glEnd();

}

   //   BULIDING 10 //

void building10()
{
    glBegin(GL_POLYGON);
    glColor3ub(153 , 68, 250);
    glVertex2f(18.4,8.3);
    glVertex2f(18.4,5.2);
    glColor3ub(74 , 68, 250);
    glVertex2f(20.9,5.2);
    glVertex2f(20.9,8.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(141,217,229  );
    glVertex2f(18.9,7.6);
    glVertex2f(19.3,7.6);
    glVertex2f(19.3,7.9);
    glVertex2f(18.9,7.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(141,217,229 );
    glVertex2f(18.9,7.1);
    glVertex2f(19.3,7.1);
    glVertex2f(19.3,7.4);
    glVertex2f(18.9,7.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(141,217,229 );
    glVertex2f(20.2,7.1);
    glVertex2f(20.5,7.1);
    glVertex2f(20.5,7.4);
    glVertex2f(20.2,7.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(141,217,229 );
    glVertex2f(20.2,6.5);
    glVertex2f(20.5,6.5);
    glVertex2f(20.5,6.8);
    glVertex2f(20.2,6.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(141,217,229 );
    glVertex2f(20.2,6.2);
    glVertex2f(20.5,6.2);
    glVertex2f(20.5,5.9);
    glVertex2f(20.2,5.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(141,217,229 );
    glVertex2f(20.2,7.6);
    glVertex2f(20.5,7.6);
    glVertex2f(20.5,7.9);
    glVertex2f(20.2,7.9);
    glEnd();
}


    //   Hospital //

void hospital()
{

    glBegin(GL_POLYGON);
    glColor3ub(0, 192, 217);
    glVertex2f(15.6,5.2);
    glVertex2f(19.6,5.2);
    glVertex2f(19.6,7);
    glVertex2f(15.6,7);
    glEnd();
    //window row1

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(15.8,6.5);
    glVertex2f(19.5,6.5);
    glVertex2f(19.5,6.9);
    glVertex2f(15.8,6.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub( 192,203,205);
    glVertex2f(15.8,5.9);
    glVertex2f(19.5,5.9);
    glVertex2f(19.5,6.3);
    glVertex2f(15.8,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub( 192,203,205);
    glVertex2f(15.8,5.3);
    glVertex2f(19.5,5.3);
    glVertex2f(19.5,5.7);
    glVertex2f(15.8,5.7);
    glEnd();
    glLineWidth(2.0);

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.2, 6.9);
    glVertex2f(16.2, 6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.2, 6.3);
    glVertex2f(16.2, 5.9);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.2, 5.7);
    glVertex2f(16.2, 5.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.6, 6.9);
    glVertex2f(16.6, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.6, 6.3);
    glVertex2f(16.6, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.6, 5.7);
    glVertex2f(16.6, 5.3);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17, 6.9);
    glVertex2f(17, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17, 6.3);
    glVertex2f(17, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17, 5.7);
    glVertex2f(17, 5.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17.4, 6.9);
    glVertex2f(17.4, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17.4, 6.3);
    glVertex2f(17.4, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17.4, 5.7);
    glVertex2f(17.4, 5.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17.8, 6.9);
    glVertex2f(17.8, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17.8, 6.3);
    glVertex2f(17.8, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(17.8, 5.7);
    glVertex2f(17.8, 5.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(18.2, 6.9);
    glVertex2f(18.2, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(18.2, 6.3);
    glVertex2f(18.2, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(18.2, 5.7);
    glVertex2f(18.2, 5.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(18.6, 6.9);
    glVertex2f(18.6, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(18.6, 6.3);
    glVertex2f(18.6, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(18.6, 5.7);
    glVertex2f(18.6, 5.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(19, 6.9);
    glVertex2f(19, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(19, 6.3);
    glVertex2f(19, 5.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(19, 5.7);
    glVertex2f(19, 5.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(40,152,175);
    glVertex2f(16.6,7);
    glVertex2f(18.6,7);
    glVertex2f(18.6,7.5);
    glVertex2f(16.6,7.5);
    glEnd();

    //



    /// Hospital symbol
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.5210 , 7.1045);
    glVertex2f(17.5210 , 7.4804);
    glVertex2f(17.6178 , 7.4804);
    glVertex2f(17.6178 , 7.1045);
    glVertex2f(17.5210 , 7.1045);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.6178 , 7.2564);
    glVertex2f(17.6178 , 7.1045);
    glVertex2f(17.5210 , 7.1045);
    glVertex2f(17.5210 , 7.2564);
    glVertex2f(17.3660 , 7.2564);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.3660 , 7.3347);
    glVertex2f(17.5210 , 7.3347);
    glVertex2f(17.5210 , 7.3347);
    glVertex2f(17.5210 , 7.3347);
    glEnd();

    //
     glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.3660 , 7.3347);
    glVertex2f(17.5210 , 7.3347);
    glVertex2f(17.5210 , 7.2564);
    glVertex2f(17.3660 , 7.2564);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.6178 , 7.3347);
    glVertex2f(17.7733 , 7.3347);
    glVertex2f(17.7733 , 7.2564);
    glVertex2f(17.6178 , 7.2564);
    glEnd();


}


/// road border

void zebraCrossing()
{
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3f(1,1,1);
    glVertex2f(16.0729,0.7968);
    glVertex2f(16.0729,2.4811);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3f(1,1,1);
    glVertex2f(17.4613,0.7968);
    glVertex2f(17.4613,2.4811);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(16.1962,2.3437);
    glVertex2f(17.3680,2.3437);
    glVertex2f(17.3680,2.1159);
    glVertex2f(16.1962,2.1159);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(16.1962,1.9517);
    glVertex2f(17.3680,1.9517);
    glVertex2f(17.3680,1.7239);
    glVertex2f(16.1962,1.7239);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(16.1962,1.5332);
    glVertex2f(17.3680,1.5332);
    glVertex2f(17.3680,1.3054);
    glVertex2f(16.1962,1.3054);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(16.1962,1.1571);
    glVertex2f(17.3680,1.1571);
    glVertex2f(17.3680,0.9293);
    glVertex2f(16.1962,0.9293);
    glEnd();
    // glVertex2f(16.0729,1.6913

}


    // BULIDING 11 //

 void building11()
{

     glBegin(GL_POLYGON);
     glColor3ub(16,90,175);
     glVertex2f(20.4,6.4);
     glVertex2f(20.4,5.2);
     glVertex2f(22.9,5.2);
     glVertex2f(22.9,6.4);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3ub(185,212,243 );
     glVertex2f(20.7,6.1);
     glVertex2f(21.1,6.1);
     glVertex2f(21.1,5.3);
     glVertex2f(20.7,5.3);
     glEnd();
     glBegin(GL_POLYGON);
     glColor3ub(185,212,243);
     glVertex2f(21.5,6.1);
     glVertex2f(21.9,6.1);
     glVertex2f(21.9,5.3);
     glVertex2f(21.5,5.3);
     glEnd();
     glBegin(GL_POLYGON);
     glColor3ub(185,212,243);
     glVertex2f(22.3,6.1);
     glVertex2f(22.6,6.1);
     glVertex2f(22.6,5.3);
     glVertex2f(22.3,5.3);
     glEnd();

     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(20.7, 5.9);
     glVertex2f(21.1, 5.9);
     glEnd();
     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(20.7, 5.7);
     glVertex2f(21.1, 5.7);
     glEnd();
     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(20.7, 5.5);
     glVertex2f(21.1, 5.5);
     glEnd();

     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(21.5, 5.9);
     glVertex2f(21.9, 5.9);
     glEnd();
     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(21.5, 5.7);
     glVertex2f(21.9, 5.7);
     glEnd();
     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(21.5, 5.5);
     glVertex2f(21.9, 5.5);
     glEnd();

     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(22.3, 5.9);
     glVertex2f(22.7, 5.9);
     glEnd();
     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(22.3, 5.7);
     glVertex2f(22.7, 5.7);
     glEnd();
     glBegin(GL_LINES);
     glColor3ub(16,90,175);
     glLineWidth(1.0);
     glVertex2f(22.3, 5.5);
     glVertex2f(22.7, 5.5);
     glEnd();

 }

   ///     (SCHOOL)

void school()
{
    glBegin(GL_POLYGON);
    glColor3ub(178, 127, 8);
    glVertex2f(23.7,7.5);
    glVertex2f(23.7,5.2);
    glColor3ub(142, 83, 13 );
    glVertex2f(29.4,5.2);
    glVertex2f(29.4,7.5);
    glEnd();
    //School window row1

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(24,6.6);
    glVertex2f(24.3,6.6);
    glVertex2f(24.3,6.9);
    glVertex2f(24,6.9);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(24.8,6.6);
    glVertex2f(25.1,6.6);
    glVertex2f(25.1,6.9);
    glVertex2f(24.8,6.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(25.6,6.6);
    glVertex2f(25.9,6.6);
    glVertex2f(25.9,6.9);
    glVertex2f(25.6,6.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(26.4,6.6);
    glVertex2f(26.7,6.6);
    glVertex2f(26.7,6.9);
    glVertex2f(26.4,6.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(27.2,6.6);
    glVertex2f(27.5,6.6);
    glVertex2f(27.5,6.9);
    glVertex2f(27.2,6.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(28,6.6);
    glVertex2f(28.3,6.6);
    glVertex2f(28.3,6.9);
    glVertex2f(28,6.9);
    glEnd();
    glBegin(GL_POLYGON);

    glColor3ub(181,255,246 );
    glVertex2f(28.8,6.6);
    glVertex2f(29.1,6.6);
    glVertex2f(29.1,6.9);
    glVertex2f(28.8,6.9);
    glEnd();

    //School Row Window2
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(24,6);
    glVertex2f(24.3,6);
    glVertex2f(24.3,6.3);
    glVertex2f(24,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(24.8,6);
    glVertex2f(25.1,6);
    glVertex2f(25.1,6.3);
    glVertex2f(24.8,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(25.6,6);
    glVertex2f(25.9,6);
    glVertex2f(25.9,6.3);
    glVertex2f(25.6,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(26.4,6);
    glVertex2f(26.7,6);
    glVertex2f(26.7,6.3);
    glVertex2f(26.4,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(27.2,6);
    glVertex2f(27.5,6);
    glVertex2f(27.5,6.3);
    glVertex2f(27.2,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(28,6);
    glVertex2f(28.3,6);
    glVertex2f(28.3,6.3);
    glVertex2f(28,6.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(28.8,6);
    glVertex2f(29.1,6);
    glVertex2f(29.1,6.3);
    glVertex2f(28.8,6.3);
    glEnd();


    //School Row Window3
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(24,5.8);
    glVertex2f(24.3,5.8);
    glVertex2f(24.3,5.4);
    glVertex2f(24,5.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(24.8,5.8);
    glVertex2f(25.1,5.8);
    glVertex2f(25.1,5.4);
    glVertex2f(24.8,5.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(28,5.8);
    glVertex2f(28.3,5.8);
    glVertex2f(28.3,5.4);
    glVertex2f(28,5.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(28.8,5.8);
    glVertex2f(29.1,5.8);
    glVertex2f(29.1,5.4);
    glVertex2f(28.8,5.4);
    glEnd();
    //School Door
    glBegin(GL_POLYGON);
    glColor3ub(86,52,0);
    glVertex2f(25.6,5.9);
    glVertex2f(25.6,5.2);
    glVertex2f(26.5,5.2);
    glVertex2f(26.5,5.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86,52,0);
    glVertex2f(26.5,5.9);
    glVertex2f(26.5,5.2);
    glVertex2f(27.5,5.2);
    glVertex2f(27.5,5.9);
    glEnd();
    //Door Line
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(26.5,5.9);
    glVertex2f(26.5,5.2);
    glEnd();
    //Roof
    glBegin(GL_POLYGON);
    glColor3ub(21,110,88);
    glVertex2f(25.2,7.9);
    glVertex2f(28.1,7.9);
    glVertex2f(28.1,7.2);
    glVertex2f(25.2,7.2);
    glEnd();
}

 // circle For tree
void circle(float radius, float cX, float cY)
{
   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(7,86,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}
void circleLight(float radius, float cX, float cY,float r, float y, float g)
{
   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(r,y,g);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}

//FOR TREE.....
void tree()
{
    //1
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(4,2.7);
    glVertex2f(4.2,2.7);
    glVertex2f(4.2,3.8);
    glVertex2f(4,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.4701,3.97,4.24);
    circle(0.3395,4.35,4.07);
    circle(0.3113,3.94,3.89);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(8.8,2.7);
    glVertex2f(9,2.7);
    glVertex2f(9,3.8);
    glVertex2f(8.8,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,8.77,3.89);
    circle(0.3395,9.18,4.07);
    circle(0.4701,8.79,4.23);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(14,2.7);
    glVertex2f(14.2,2.7);
    glVertex2f(14.2,3.8);
    glVertex2f(14,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,13.94,3.89);
    circle(0.3395,14.35,4.07);
    circle(0.4701,13.97,4.23);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(18.9,2.7);
    glVertex2f(19.1,2.7);
    glVertex2f(19.1,3.8);
    glVertex2f(18.9,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,18.8,3.89);
    circle(0.3395,19.2,4.07);
    circle(0.4701,18.8,4.23);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(24.2,2.7);
    glVertex2f(24.4,2.7);
    glVertex2f(24.4,3.8);
    glVertex2f(24.2,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,24.1,3.89);
    circle(0.3395,24.5,4.07);
    circle(0.4701,24.1,4.23);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(28.99,2.7);
    glVertex2f(29.17,2.7);
    glVertex2f(29.17,3.8);
    glVertex2f(28.99,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,28.87,3.89);
    circle(0.3395,29.28,4.07);
    circle(0.4701,28.87,4.23);
    glEnd();


}

void extraPortionOfTunnel()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(24,14,16);
    glVertex2f(1.1712,4.9517);
    glVertex2f(1.7967,4.9517);
    glColor3ub(129,51,6);
    glVertex2f(1.7967,5.3869);
    glEnd();
}

void tunnel()
{
    glBegin(GL_POLYGON);
    glColor3ub(122, 119, 119 );
    glVertex2f(0,3.2673);
    glVertex2f(0.85,3.2673);
    glVertex2f(0.85,4.7);
    glVertex2f(0,4.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(24, 14, 16);
    glVertex2f(0,4.7);
    glVertex2f(.85,4.7);
    glVertex2f(1.85,5.4);
    glVertex2f(0,5.4);
    glEnd();
}


void sun()
{

    ///glBegin(GL_POLYGON);

    glBegin(GL_POLYGON);
    float rd = 0.8f;
    for (int i = 0; i < 200; i++) {
        glColor3f(1, 1, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = rd * cos(A);
        float y = rd * sin(A);

        glVertex2f(x + 15.0725, y + 9.8979);

    }

    glEnd();



}


/// 22-46130-1
void drawCircle(float r, float g, float b,float cX,float cY) {
    glBegin(GL_POLYGON);
    float rd = 0.1233f;
    for (int i = 0; i < 200; i++) {
        glColor3f(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = rd * cos(A);
        float y = rd * sin(A);
        glVertex2f(x + cX, y + cY);
    }
    glEnd();
}

void trafficLight(float x,float y)
{
    // stand
     glBegin(GL_QUADS);
     glColor3f(0,0,0);
     glVertex2f(15.5232+x ,0.7968+y);
     glVertex2f(15.3258+x ,0.7968+y);
     glVertex2f(15.3258+x ,2.6584+y);
     glVertex2f(15.5232+x ,2.6584+y);
     glEnd();

    // upper box
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
     glVertex2f(15.0961+x,2.6584+y);
     glVertex2f(15.7510+x,2.6584+y);
     glVertex2f(15.7510+x,3.8762+y);
     glVertex2f(15.0961+x,3.8762+y);
     glEnd();


     switch(cc) {

 case 0:
     /// Red
    drawCircle(r1,g1,b1,15.4256+x,3.6312+y);
    break;
 case 1:
     /// yellow
    drawCircle(r2,g2,b2,15.4293+x,3.2705+y);
    break;
 case 2:
     /// Green
    drawCircle(r3,g3,b3,15.4352+x,2.8879+y);
    break;

    }

}


void trafficSound()
{
  sndPlaySound("trafficSound.wav", SND_ASYNC);
}

void wheelsCircle(float r,float x, float y) {

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++) {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }
        glEnd();
}


void Wheel(float x, float y){
glPushMatrix();
glTranslatef(x,y,0.0f);
float rd = 0.1649;
wheelsCircle(rd,x,y);
glEnd();
glColor3f(0,0,0);
glPopMatrix();
}

/// Car
void car1_4()
{
    /// Cabin
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(17.875,1.3052);
    glVertex2f(19.966,1.3052);
    glVertex2f(19.8064,1.6346);
    glVertex2f(17.8455,1.6346);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(18.3318,1.6346);
    glVertex2f(18.5744,1.8667);
    glVertex2f(19.2476,1.8667);
    glVertex2f(19.4592,1.6346);
    glEnd();

    /// Window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(18.5845,1.8410);
    glVertex2f(19.2214,1.8410);
    glColor3ub(47,255,200);
    glVertex2f(19.3766,1.6678);
    glVertex2f(18.4031,1.6678);
    glEnd();

    /// Line
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3f(0,0,0);
    glVertex2f(18.9211,1.8410);
    glVertex2f(18.9211,1.6678);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex2f(17.8572,1.4443);
    glVertex2f(17.8572,1.5062);
    glVertex2f(17.9516,1.5062);
    glVertex2f(17.9516,1.4443);
    glEnd();

    /// Emergency light
      float nx = 2.0053;
      float ny = 3.12;
      glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(16.7067+nx,5.0205-ny);
        glVertex2f(16.8685+nx,5.0205-ny);
        glVertex2f(16.8685+nx,5.1451-ny);
        glVertex2f(16.7067+nx,5.1451-ny);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0,0,1);
        glVertex2f(16.8685+nx,5.0205-ny);
        glVertex2f(17.0347+nx,5.0205-ny);
        glVertex2f(17.0347+nx,5.1451-ny);
        glVertex2f(16.8685+nx,5.1451-ny);
        glEnd();

    /// wheels
    Wheel(18.2052,1.3052);
    Wheel(19.4866,1.3052);

}

void car1() {

    glPushMatrix();
    glTranslatef(posRL,0.0f,0.0f);

    /// Cabin
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(17.875,1.3052);
    glVertex2f(19.966,1.3052);
    glVertex2f(19.8064,1.6346);
    glVertex2f(17.8455,1.6346);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(18.3318,1.6346);
    glVertex2f(18.5744,1.8667);
    glVertex2f(19.2476,1.8667);
    glVertex2f(19.4592,1.6346);
    glEnd();

    /// Window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(18.5845,1.8410);
    glVertex2f(19.2214,1.8410);
    glColor3ub(47,255,200);
    glVertex2f(19.3766,1.6678);
    glVertex2f(18.4031,1.6678);
    glEnd();

    /// Line
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3f(0,0,0);
    glVertex2f(18.9211,1.8410);
    glVertex2f(18.9211,1.6678);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex2f(17.8572,1.4443);
    glVertex2f(17.8572,1.5062);
    glVertex2f(17.9516,1.5062);
    glVertex2f(17.9516,1.4443);
    glEnd();

    /// Emergency light
      float nx = 2.0053;
      float ny = 3.12;
      glBegin(GL_QUADS);
        glColor3f(amRed,amGreen,amBlue);
        glVertex2f(16.7067+nx,5.0205-ny);
        glVertex2f(16.8685+nx,5.0205-ny);
        glVertex2f(16.8685+nx,5.1451-ny);
        glVertex2f(16.7067+nx,5.1451-ny);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(amBlue,0,amRed);
        glVertex2f(16.8685+nx,5.0205-ny);
        glVertex2f(17.0347+nx,5.0205-ny);
        glVertex2f(17.0347+nx,5.1451-ny);
        glVertex2f(16.8685+nx,5.1451-ny);
        glEnd();


    /// wheels
    Wheel(18.2052,1.3052);
    Wheel(19.4866,1.3052);

    glPopMatrix();

}

void carY(float x,float y) {
    glPushMatrix();
    glTranslatef(posLR, 0.0f, 0.0f);


    /// Cabin
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(11.0691, 2.3614+y);
    glVertex2f(13.0299, 2.3614+y);
    glVertex2f(13, 2.0320+y);
    glVertex2f(10.9093, 2.0320+y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(11.6279, 2.5934+y);
    glVertex2f(12.3011, 2.5934+y);
    glVertex2f(12.5437, 2.3614+y);
    glVertex2f(11.4162, 2.3614+y);
    glEnd();

    /// Window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(11.6541, 2.5677+y);
    glVertex2f(12.2910, 2.5677+y);
    glVertex2f(12.4724, 2.3946+y);
    glVertex2f(11.4989, 2.3946+y);
    glEnd();

    /// Line
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3f(0, 0, 0);
    glVertex2f(11.9544, 2.5677+y);
    glVertex2f(11.9544, 2.3946+y);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(13.0183, 2.2330+y);
    glVertex2f(12.9239, 2.2330+y);
    glVertex2f(12.9239, 2.1711+y);
    glVertex2f(13.0183, 2.1711+y);
    glEnd();

    /// wheels
    Wheel(11.3889, 2.0320+y);
    Wheel(12.6703, 2.0320+y);

    glPopMatrix();

}

/// Sports Car
void SportsCar(float x) {
    float nx = 3.6264f;
    glPushMatrix();
    glTranslatef(x,0,0);
    /// cabin
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex2f(4.9786+nx,2.4395);
    glVertex2f(6.6818+nx,2.4395);
    glVertex2f(6.9094+nx,2.1102);
    glVertex2f(5.1335+nx,2.1102);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex2f(4.9786+nx,2.4395);
    glVertex2f(5.0569+nx,2.4395);
    glVertex2f(5.0569+nx,2.6166);
    glVertex2f(4.9786+nx,2.6166);
    glEnd();

    /// ceil
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex2f(5.5374+nx,2.6716);
    glVertex2f(6.2106+nx,2.6716);
    glVertex2f(6.4531+nx,2.4395);
    glVertex2f(5.3257+nx,2.4395);
    glEnd();

    /// windows
    glBegin(GL_QUADS);
    glColor3ub(1,130,242);
    glVertex2f(5.5636+nx,2.6479);
    glVertex2f(6.2005+nx,2.6479);
    glColor3ub(47,255,200);
    glVertex2f(6.3819+nx,2.4328);
    glVertex2f(5.4084+nx,2.4328);
    glEnd();

    /// wheel
    Wheel(6.5797+nx,2.1102);
    Wheel(5.2984+nx,2.1102);

    glPopMatrix();
}


void bus3(float x,float y)
{
    float nx = 17.8064;
    float ny= 1.3;
    glPushMatrix();
    glTranslatef(posbus3LR,0,0);

    /// cabin
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(20.6654-nx+x,4.0529-ny+y);
    glVertex2f(23.0108-nx+x,4.0529-ny+y);
    glVertex2f(23.0108-nx+x,3.7235-ny+y);
    glVertex2f(20.6654-nx+x,3.7235-ny+y);
    glEnd();

    /// ceil
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(20.7487-nx+x,4.2849-ny+y);
    glVertex2f(22.8862-nx+x,4.2849-ny+y);
    glVertex2f(22.8862-nx+x,4.0529-ny+y);
    glVertex2f(20.7487-nx+x,4.0529-ny+y);
    glEnd();

    /// window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(20.7785-nx+x,4.2510-ny+y);
    glVertex2f(22.8509-nx+x,4.2510-ny+y);
    glVertex2f(22.8509-nx+x,4.0854-ny+y);
    glVertex2f(20.7785-nx+x,4.0854-ny+y);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(23.0108-nx+x,3.8661-ny+y);
    glVertex2f(22.9194-nx+x,3.8661-ny+y);
    glVertex2f(22.9194-nx+x,3.8157-ny+y);
    glVertex2f(23.0108-nx+x,3.8157-ny+y);
    glEnd();


    Wheel(21.0850-nx+x,3.7236-ny+y);
    Wheel(22.5312-nx+x,3.7236-ny+y);

    glPopMatrix();
}

void policeCar()
{
    float nx = 2.1325;
    float ny = 2.9719;
    glPushMatrix();
    glTranslatef(eDis2,0.0f,0.0f);

    /// Cabin
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(17.875+nx,1.3052+ny);
    glVertex2f(19.966+nx,1.3052+ny);
    glVertex2f(19.8064+nx,1.6346+ny);
    glVertex2f(17.8455+nx,1.6346+ny);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(18.3318+nx,1.6346+ny);
    glVertex2f(18.5744+nx,1.8667+ny);
    glVertex2f(19.2476+nx,1.8667+ny);
    glVertex2f(19.4592+nx,1.6346+ny);
    glEnd();

    /// Window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(18.5845+nx,1.8410+ny);
    glVertex2f(19.2214+nx,1.8410+ny);
    glVertex2f(19.3766+nx,1.6678+ny);
    glVertex2f(18.4031+nx,1.6678+ny);
    glEnd();

    /// Line
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3f(0,0,0);
    glVertex2f(18.9211+nx,1.8410+ny);
    glVertex2f(18.9211+nx,1.6678+ny);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex2f(17.8572+nx,1.4443+ny);
    glVertex2f(17.8572+nx,1.5062+ny);
    glVertex2f(17.9516+nx,1.5062+ny);
    glVertex2f(17.9516+nx,1.4443+ny);
    glEnd();

    /// Light

    glBegin(GL_QUADS);
    glColor3f(amRed,amGreen,amBlue);
    glVertex2f(20.8894,4.9637);
    glVertex2f(21.0512,4.9637);
    glVertex2f(21.0512,4.8391);
    glVertex2f(20.8894,4.8391);
    glEnd();

        glBegin(GL_QUADS);
        glColor3f(amBlue,0,amRed);
        glVertex2f(21.0512,4.9637);
        glVertex2f(21.2175,4.9637);
        glVertex2f(21.2175,4.8391);
        glVertex2f(21.0512,4.8391);
        glEnd();

    /// wheels
    Wheel(18.2052+nx,1.3052+ny);
    Wheel(19.4866+nx,1.3052+ny);

   glPopMatrix();
}


void car3() {

    float nx = 13.5432;
    float ny = 0.4;
    glPushMatrix();
    glTranslatef(posLR2, 0.0f, 0.0f);


    /// Cabin
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(11.0691+nx, 2.3614+ny);
    glVertex2f(13.0299+nx, 2.3614+ny);
    glVertex2f(13+nx, 2.0320+ny);
    glVertex2f(10.9093+nx, 2.0320+ny);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(11.6279+nx, 2.5934+ny);
    glVertex2f(12.3011+nx, 2.5934+ny);
    glVertex2f(12.5437+nx, 2.3614+ny);
    glVertex2f(11.4162+nx, 2.3614+ny);
    glEnd();

    /// Window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(11.6541+nx, 2.5677+ny);
    glVertex2f(12.2910+nx, 2.5677+ny);
    glVertex2f(12.4724+nx, 2.3946+ny);
    glVertex2f(11.4989+nx, 2.3946+ny);
    glEnd();

    /// Line
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3f(0, 0, 0);
    glVertex2f(11.9544+nx, 2.5677+ny);
    glVertex2f(11.9544+nx, 2.3946+ny);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(13.0183+nx, 2.2330+ny);
    glVertex2f(12.9239+nx, 2.2330+ny);
    glVertex2f(12.9239+nx, 2.1711+ny);
    glVertex2f(13.0183+nx, 2.1711+ny);
    glEnd();

    /// wheels
    Wheel(11.3889+nx, 2.0320+ny);
    Wheel(12.6703+nx, 2.0320+ny);

    glPopMatrix();


}
/// Ambulance
void Ambulance(float x,float y) {

    glPushMatrix();
    glTranslatef(eDis2,0,0);

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(16.0162+x,4.3296+y);
    glVertex2f(16.0162+x,4.6590+y);
    glVertex2f(16.4481+x,5.0205+y);
    glVertex2f(17.9836+x,5.0205+y);
    glVertex2f(18.3616+x,4.6590+y);
    glVertex2f(18.3616+x,4.3296+y);
    glEnd();

    /// window
    glBegin(GL_POLYGON);
    glColor3ub(0, 192, 217);
    glVertex2f(16.3060+x,4.8236+y);
    glVertex2f(16.8112+x,4.8236+y);
    glVertex2f(16.8112+x,4.9693+y);
    glVertex2f(16.4463+x,4.9693+y);
    glEnd();

    /// symbol

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(17.2053+x,4.7813+y);
    glVertex2f(17.1114+x,4.7813+y);
    glVertex2f(17.1114+x,4.8287+y);
    glVertex2f(17.2053+x,4.8287+y);
    glEnd();
///

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(17.2053+x,4.7813+y);
    glVertex2f(17.1114+x,4.7813+y);
    glVertex2f(17.1114+x,4.8287+y);
    glVertex2f(17.2053+x,4.8287+y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(255,0,0);
    glVertex2f(17.2053+x,4.9170+y);
    glVertex2f(17.2053+x,4.6892+y);
    glVertex2f(17.2640+x,4.6892+y);
    glVertex2f(17.2640+x,4.9170+y);
    glEnd();

///
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(17.2640+x,4.7813+y);
    glVertex2f(17.3582+x,4.7813+y);
    glVertex2f(17.3582+x,4.8287+y);
    glVertex2f(17.2640+x,4.8287+y);
    glEnd();


    /// Emergency Light

        glBegin(GL_QUADS);
        glColor3f(amRed,amGreen,amBlue);
        glVertex2f(16.7067+x,5.0205+y);
        glVertex2f(16.8685+x,5.0205+y);
        glVertex2f(16.8685+x,5.1451+y);
        glVertex2f(16.7067+x,5.1451+y);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(amBlue,0,amRed);
        glVertex2f(16.8685+x,5.0205+y);
        glVertex2f(17.0347+x,5.0205+y);
        glVertex2f(17.0347+x,5.1451+y);
        glVertex2f(16.8685+x,5.1451+y);
        glEnd();


    glBegin(GL_LINE);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(16.0162+x,4.6590+y);
    glVertex2f(18.3616+x,4.6590+y);
    glEnd();


    Wheel(16.4958+x,4.3296+y);
    Wheel(17.9420+x,4.3296+y);

    glPopMatrix();
}

/// Plane
void Plane()
{
    glPushMatrix();
    glTranslatef(ep,0,0);
    /// body
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(25.4365,11.7203);
    glVertex2f(27.4579,11.7203);
    glColor3ub(39,89,145);
    glVertex2f(27.7729,12.0278);
    glVertex2f(25.7688,12.0278);
    glEnd();

    /// rightWings
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(26.4177,11.8562);
    glVertex2f(26.7851,11.8562);
    glColor3ub(39,54,145);
    glVertex2f(27.3625,11.3366);
    glVertex2f(27.3625,11.3366);
    glEnd();
    /// Left wings
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(26.4177,12.0278);
    glVertex2f(27.1144,12.4426);
    glColor3ub(39,54,145);
    glVertex2f(27.2957,12.4426);
    glVertex2f(26.7851,12.0278);
    glEnd();
    /// tails
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(27.7729,12.3234);
    glColor3ub(236,34,216);
    glVertex2f(27.7729,12.0278);
    glVertex2f(27.3959,12.0278);
    glEnd();
    /// windows
    glBegin(GL_POLYGON);
    glColor3ub(0, 192, 217);
    glVertex2f(25.6627,11.9297);
    glVertex2f(25.9539,11.9297);
    glColor3ub(47,255,200);
    glVertex2f(25.9539,12.0278);
    glVertex2f(25.7688,12.0278);
    glEnd();

    glPopMatrix();
}

/// circle for fire car

void circleFireCar(float r,float cX, float cY, float redC,float greenC,float blueC)
{
glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(redC, greenC, blueC);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + cX, y + cY);
    }
    glEnd();
}


/// Fire brigade vehicle
void FireCar(float x,float t,float y) {

    glPushMatrix();
    glTranslatef(t,0,0);

    /// cabin
    glBegin(GL_POLYGON);
    glColor3ub(213,24,24);
    glVertex2f(5.8938+x,4.6561+y);
    glVertex2f(8.2392+x,4.6561+y);
    glColor3ub(232,6,134);
    glVertex2f(8.2392+x,4.3267+y);
    glVertex2f(5.8938+x,4.3267+y);
    glEnd();


    /// up cabin
    glBegin(GL_POLYGON);
    glColor3ub(232,6,134);
    glVertex2f(6.1861+x,4.8882+y);
    glVertex2f(6.1861+x,4.6561+y);
    glColor3ub(157,6,232);
    glVertex2f(8.0144+x,4.6561+y);
    glVertex2f(8.0144+x,4.8882+y);
    glEnd();

    /// water flusher
    glBegin(GL_POLYGON);
    glColor3ub(232,6,157);
    glVertex2f(5.5305+x,5.0733+y);
    glVertex2f(7.7613+x,5.0753+y);
    glColor3ub(0,0,0);
    glVertex2f(7.7613+x,5.2003+y);
    glVertex2f(5.5305+x,5.2003+y);
    glEnd();

    /// pump

    circleFireCar(0.1798+0.1,7.9412+1.2,5.0680-0.1,0,0,0); /// max circle
    circleFireCar(0.0966+0.1,7.9412+1.2,5.0680-0.1,204,0,102) ;/// min circle
    /// wheel
    Wheel(6.3734+x,4.3267+y);
    Wheel(7.8196+x,4.3269+y);

    glPopMatrix();
}


void FireCar2(float x,float t,float y) {

    glPushMatrix();
    glTranslatef(t,0,0);

    /// cabin
    glBegin(GL_POLYGON);
    glColor3ub(213,24,24);
    glVertex2f(5.8938+x,4.6561+y);
    glVertex2f(8.2392+x,4.6561+y);
    glColor3ub(232,6,134);
    glVertex2f(8.2392+x,4.3267+y);
    glVertex2f(5.8938+x,4.3267+y);
    glEnd();


    /// up cabin
    glBegin(GL_POLYGON);
    glColor3ub(232,6,134);
    glVertex2f(6.1861+x,4.8882+y);
    glVertex2f(6.1861+x,4.6561+y);
    glColor3ub(157,6,232);
    glVertex2f(8.0144+x,4.6561+y);
    glVertex2f(8.0144+x,4.8882+y);
    glEnd();

 /// water flusher
    glBegin(GL_POLYGON);
    glColor3ub(232,6,157);
    glVertex2f(5.5305+3,5.0733+y);
    glVertex2f(7.7613+3,5.0753+y);
    glColor3ub(0,0,0);
    glVertex2f(7.7613+3,5.2003+y);
    glVertex2f(5.5305+3,5.2003+y);
    glEnd();

    /// pump

    circleFireCar(0.1798+0.1,7.9412+0.35,5.0680-0.8,0,0,0); /// max circle
    circleFireCar(0.0966+0.1,7.9412+0.35,5.0680-0.8,204,0,102) ;/// min circle
    /// wheel
    Wheel(6.3734+x,4.3267+y);
    Wheel(7.8196+x,4.3269+y);

    glPopMatrix();
}

/// School bus
void schoolBus() {
    glPushMatrix();
    glTranslatef(eDis,0,0);

    /// cabin
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(20.6654,4.0529);
    glVertex2f(23.0108,4.0529);
    glVertex2f(23.0108,3.7235);
    glVertex2f(20.6654,3.7235);
    glEnd();

    /// ceil
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(20.7487,4.2849);
    glVertex2f(22.8862,4.2849);
    glVertex2f(22.8862,4.0529);
    glVertex2f(20.7487,4.0529);
    glEnd();

    /// window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(20.7785,4.2510);
    glVertex2f(22.8509,4.2510);
    glVertex2f(22.8509,4.0854);
    glVertex2f(20.7785,4.0854);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(23.0108,3.8661);
    glVertex2f(22.9194,3.8661);
    glVertex2f(22.9194,3.8157);
    glVertex2f(23.0108,3.8157);
    glEnd();
    ///
    Wheel(21.0850,3.7236);
    Wheel(22.5312,3.7236);

   glPopMatrix();
}


void schoolBus2() {

    glPushMatrix();
    glTranslatef(eDis2,0,0);

    /// cabin
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(25.3275,4.7739);
    glVertex2f(27.6729,4.7739);
    glVertex2f(27.6729,4.4445);
    glVertex2f(25.3275,4.4445);
    glEnd();

    /// ceil
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(25.4521,5.0060);
    glVertex2f(27.5897,5.0060);
    glVertex2f(27.5897,4.7739);
    glVertex2f(25.4521,4.7739);
    glEnd();

    /// window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(25.4875,4.9720);
    glVertex2f(27.5598,4.9720);
    glVertex2f(27.5598,4.8064);
    glVertex2f(25.4875,4.8064);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(25.3275,4.5871);
    glVertex2f(25.4189,4.5871);
    glVertex2f(25.4189,4.5368);
    glVertex2f(25.3275,4.5368);
    glEnd();


    /// Line border
    ///1
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.5630,4.8064);
    glVertex2f(25.5630,4.9720);
    glEnd();
///2
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.7215 ,4.9720);
    glVertex2f(25.7215,4.8064);
    glEnd();
///3
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.8483,4.8064);
    glVertex2f(25.8483,4.9720);
    glEnd();
    ///4


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.9751,4.9720);
    glVertex2f(25.9751,4.8064);
    glEnd();
    ///
    ///5


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.1189,4.8064);
    glVertex2f(26.1189,4.9720);
    glEnd();

    /// 6


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.2713 ,4.9720);
    glVertex2f(26.2713 ,4.8064);
    glEnd();
    ///7


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.4280,4.8064);
    glVertex2f(26.4280,4.9720);
    glEnd();
    ///8


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.5762,4.9720);
    glVertex2f(26.5762,4.8064);
    glEnd();
    ///9


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.7136,4.8064);
    glVertex2f(26.7136,4.9720);
    glEnd();
    ///10


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.8446 ,4.9720);
    glVertex2f(26.8446 ,4.8064);
    glEnd();

    ///11


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.9712,4.8064);
    glVertex2f(26.9712,4.9720);
    glEnd();
    ///12


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.0979,4.9720);
    glVertex2f(27.0979,4.8064);
    glEnd();

    ///13


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.2088,4.8064);
    glVertex2f(27.2088,4.9720);
    glEnd();

    ///14


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.3398,4.9720);
    glVertex2f(27.3398,4.8064);
    glEnd();

    ///15


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.4665,4.8064);
    glVertex2f(27.4665,4.9720);
    glEnd();


    Wheel(25.8071,4.4447);
    Wheel(27.2533,4.4447);
    glPopMatrix();

}



void bus4(float x,float y) {
    float ny = 3.4152;

    glPushMatrix();
    glTranslatef(posbus4RL,0,0);

    /// cabin
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(25.3275+x,4.7739-ny+y);
    glVertex2f(27.6729+x,4.7739-ny+y);
    glVertex2f(27.6729+x,4.4445-ny+y);
    glVertex2f(25.3275+x,4.4445-ny+y);
    glEnd();

    /// ceil
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(25.4521+x,5.0060-ny+y);
    glVertex2f(27.5897+x,5.0060-ny+y);
    glVertex2f(27.5897+x,4.7739-ny+y);
    glVertex2f(25.4521+x,4.7739-ny+y);
    glEnd();

    /// window
    glBegin(GL_QUADS);
    glColor3ub(0, 192, 217);
    glVertex2f(25.4875+x,4.9720-ny+y);
    glVertex2f(27.5598+x,4.9720-ny+y);
    glVertex2f(27.5598+x,4.8064-ny+y);
    glVertex2f(25.4875+x,4.8064-ny+y);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(25.3275+x,4.5871-ny+y);
    glVertex2f(25.4189+x,4.5871-ny+y);
    glVertex2f(25.4189+x,4.5368-ny+y);
    glVertex2f(25.3275+x,4.5368-ny+y);
    glEnd();


    /// Line border
    ///1
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.5630+x,4.8064-ny+y);
    glVertex2f(25.5630+x,4.9720-ny+y);
    glEnd();
///2
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.7215+x,4.9720-ny+y);
    glVertex2f(25.7215+x,4.8064-ny+y);
    glEnd();
///3
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.8483+x,4.8064-ny+y);
    glVertex2f(25.8483+x,4.9720-ny+y);
    glEnd();
    ///4

    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(25.9751+x,4.9720-ny+y);
    glVertex2f(25.9751+x,4.8064-ny+y);
    glEnd();
    ///
    ///5

    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.1189+x,4.8064-ny+y);
    glVertex2f(26.1189+x,4.9720-ny+y);
    glEnd();

    /// 6


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.2713 +x,4.9720-ny+y);
    glVertex2f(26.2713 +x,4.8064-ny+y);
    glEnd();
    ///7

    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.4280+x,4.8064-ny+y);
    glVertex2f(26.4280+x,4.9720-ny+y);
    glEnd();
    ///8


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.5762+x,4.9720-ny+y);
    glVertex2f(26.5762+x,4.8064-ny+y);
    glEnd();
    ///9


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.7136+x,4.8064-ny+y);
    glVertex2f(26.7136+x,4.9720-ny+y);
    glEnd();
    ///10


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.8446+x ,4.9720-ny+y);
    glVertex2f(26.8446 +x,4.8064-ny+y);
    glEnd();

    ///11


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(26.9712+x,4.8064-ny+y);
    glVertex2f(26.9712+x,4.9720-ny+y);
    glEnd();
    ///12


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.0979+x,4.9720-ny+y);
    glVertex2f(27.0979+x,4.8064-ny+y);
    glEnd();

    ///13


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.2088+x,4.8064-ny+y);
    glVertex2f(27.2088+x,4.9720-ny+y);
    glEnd();

    ///14


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.3398+x,4.9720-ny+y);
    glVertex2f(27.3398+x,4.8064-ny+y);
    glEnd();

    ///15


    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(27.4665+x,4.8064-ny+y);
    glVertex2f(27.4665+x,4.9720-ny+y);
    glEnd();


    Wheel(25.8071+x,4.4447-ny+y);
    Wheel(27.2533+x,4.4447-ny+y);
    glPopMatrix();

}

void Ambulance2(float x,float y)
{
     glPushMatrix();
    glTranslatef(eDis,0,0);

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(25.4857+x,3.8124+y);
    glVertex2f(25.9056+x,4.2138+y);
    glVertex2f(27.3515+x,4.2138+y);
    glVertex2f(27.8311+x,3.8124+y);
    glVertex2f(27.8311+x,3.4830+y);
    glVertex2f(25.4857+x,3.4830+y);
    glEnd();

    /// window
    glBegin(GL_POLYGON);
    glColor3ub(0, 192, 217);
    glVertex2f(26.9698+x,4.1559+y);
    glVertex2f(27.3347+x,4.1559+y);
    glVertex2f(27.4749+x,4.0102+y);
    glVertex2f(26.9638+x,4.0102+y);
    glEnd();

    /// symbol
    float nx = 9.3387;
    float ny = 0.7583;
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(17.2053+nx+x,4.7813-ny+y);
    glVertex2f(17.1114+nx+x,4.7813-ny+y);
    glVertex2f(17.1114+nx+x,4.8287-ny+y);
    glVertex2f(17.2053+nx+x,4.8287-ny+y);
    glEnd();
///

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(17.2053+nx+x,4.7813-ny+y);
    glVertex2f(17.1114+nx+x,4.7813-ny+y);
    glVertex2f(17.1114+nx+x,4.8287-ny+y);
    glVertex2f(17.2053+nx+x,4.8287-ny+y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(255,0,0);
    glVertex2f(17.2053+nx+x,4.9170-ny+y);
    glVertex2f(17.2053+nx+x,4.6892-ny+y);
    glVertex2f(17.2640+nx+x,4.6892-ny+y);
    glVertex2f(17.2640+nx+x,4.9170-ny+y);
    glEnd();

///
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(17.2640+nx+x,4.7813-ny+y);
    glVertex2f(17.3582+nx+x,4.7813-ny+y);
    glVertex2f(17.3582+nx+x,4.8287-ny+y);
    glVertex2f(17.2640+nx+x,4.8287-ny+y);
    glEnd();

    float nx2 = 9.8;
    float ny2 = -0.7825;

    /// Emergency Light

        glBegin(GL_QUADS);
        glColor3f(amRed,amGreen,amBlue);
        glVertex2f(16.7067+nx2+x,5.0205+ny2+y);
        glVertex2f(16.8685+nx2+x,5.0205+ny2+y);
        glVertex2f(16.8685+nx2+x,5.1451+ny2+y);
        glVertex2f(16.7067+nx2+x,5.1451+ny2+y);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(amBlue,0,amRed);
        glVertex2f(16.8685+nx2+x,5.0205+ny2+y);
        glVertex2f(17.0347+nx2+x,5.0205+ny2+y);
        glVertex2f(17.0347+nx2+x,5.1451+ny2+y);
        glVertex2f(16.8685+nx2+x,5.1451+ny2+y);
        glEnd();


    glBegin(GL_LINE);
    glLineWidth(4);
    glColor3ub(0,0,0);
    glVertex2f(16.0162+nx2+x,4.6590+ny2+y);
    glVertex2f(18.3616+nx2+x,4.6590+ny2+y);
    glEnd();


    Wheel(27.3515+x,3.4831+y);
    Wheel(25.9053+x,3.4831+y);

    glPopMatrix();

}


void sportsCar2()
{
    glPushMatrix();
    glTranslatef(posRL2,0,0);

    glBegin(GL_POLYGON);
    glColor3ub(225,2,100);
    glVertex2f(21.2095,1.4270);
    glVertex2f(22.9854,1.4270);
    glColor3ub(220,10,99);
    glVertex2f(23.1403,1.7564);
    glVertex2f(21.4371,1.7564);
    glEnd();

    /// cain

    glBegin(GL_POLYGON);
    glColor3ub(225,2,100);
    glVertex2f(21.6658,1.7564);
    glVertex2f(22.7932,1.7564);
    glColor3ub(220,10,99);
    glVertex2f(22.5815,1.9885);
    glVertex2f(21.9083,1.9885);
    glEnd();

    /// window
    glBegin(GL_POLYGON);
    glColor3ub(23,21,4);
    glVertex2f(21.7370,1.7896);
    glVertex2f(22.7105,1.7896);
    glColor3ub(220,10,99);
    glVertex2f(22.5553,1.9628);
    glVertex2f(21.9184,1.9628);
    glEnd();

    /// Light
    glBegin(GL_POLYGON);
    glColor3ub(254,254,254);
    glVertex2f(21.2900,1.5691);
    glVertex2f(21.3843,1.5691);
    glColor3ub(225,255,255);
    glVertex2f(21.3843,1.6310);
    glVertex2f(21.2900,1.6310);
    glEnd();

    /// wings
    glBegin(GL_POLYGON);
    glColor3ub(254,254,254);
    glVertex2f(23.0620,1.9335);
    glVertex2f(23.0620,1.7564);
    glColor3ub(225,255,255);
    glVertex2f(23.1403,1.7564);
    glVertex2f(23.1403,1.9335);
    glEnd();

    /// wheel

    Wheel(21.5392,1.4270);
    Wheel(22.8205,1.4270);

    glPopMatrix();
}

///star

void skyStar()
{
    srand(0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glLineWidth(3);
    for (int i = 0; i < 500; ++i) {
        float x = rand()%31;
        float y = (11.0 + (rand() % 31));
        glVertex2f(x, y);
    }
    glEnd();
}
/// Moon

void Moon(float cx, float cy) {

    float rxy = 0.5;
    float rxy2 =  0.6;

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++) {
            glColor3ub(255,255,255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float x = rxy2 * cos(A);
            float y = rxy2 * sin(A);
            glVertex2f(x+15.1490+cx,y+8.0+cy);
        }
        glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++) {
            glColor3ub(5,52,122);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float x = rxy * cos(A);
            float y = rxy * sin(A);
            glVertex2f(x+15.5067+cx,y+7.97+cy);
        }
        glEnd();


}


/// scenario2_22-46130-1


void FireCarS2()
{
        glPushMatrix();
        glTranslatef(fireCarDisS2,0,0);
        glBegin(GL_POLYGON);
        glColor3ub(204,0,102);
        glVertex2f(2.3152,2.4300);
        glVertex2f(2.3152,1.6893);
        glColor3ub(102,0,102);
        glVertex2f(7.5896,1.6893);
        glVertex2f(7.5896,2.4300);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,0,0);
        glVertex2f(2.8207,2.4300);
        glVertex2f(6.9324,2.4300);
        glColor3ub(64,64,64);
        glVertex2f(6.9324,2.9519);
        glVertex2f(2.8207,2.9519);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,0,0);
        glVertex2f(2.8207,3.3728);
        glVertex2f(4.8091,3.3728);
        glColor3ub(0,0,0);
        glVertex2f(4.8091,2.9519);
        glVertex2f(2.8207,2.9519);
        glEnd();

        /// pipe
        glBegin(GL_POLYGON);
        glColor3ub(255,0,0);
        glVertex2f(3.7853,3.3728);
        glVertex2f(3.3899,3.3728);
        glColor3ub(64,64,64);
        glVertex2f(4.8331,5.2491);
        glVertex2f(5.0447,4.8856);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,0,0);
        glVertex2f(5.0447,4.8856);
        glVertex2f(7.0080,4.8856);
        glColor3ub(64,64,64);
        glVertex2f(7.0080,5.2497);
        glVertex2f(4.8331,5.2497);
        glEnd();


        /// pump
        circleFireCar(0.4044,2.8207,3.3728,0,0,0);
        circleFireCar(0.2496,2.8207,3.3728,255,0,0);

    /// water -> X axis

    if(waterfireX == true) {
        waterfireXY = false;
        glBegin(GL_POLYGON);
        glColor3ub(12,88,240);
        glVertex2f(7.0080,5.2497);
        glVertex2f(10.0,6.5);
        glColor3ub(255,255,255);
        glVertex2f(10.0,3.5);
        glVertex2f(7.0080,4.8856);
        glEnd();
    }

    if(waterfireXY == true) {
        waterfireX= false;
        glBegin(GL_POLYGON);
        glColor3ub(12,88,240);
        glVertex2f(7.0080,5.2497);
        glVertex2f(8.5554,7.4880);
        glColor3ub(255,255,255);
        glVertex2f(9.8023,5.1629);
        glVertex2f(7.0080,4.8856);
        glEnd();
    }

    circleFireCar(0.3707,3.2588,1.6896,0,0,0);
    circleFireCar(0.3707, 6.5111,1.6896,0,0,0);

    /// emergency light
        glBegin(GL_QUADS);
        glColor3f(amRed,amGreen,amBlue);
        glVertex2f(5.6757,3.2078);
        glVertex2f(5.9601,3.2078);
        glVertex2f(5.9601,2.9519);
        glVertex2f(5.6757,2.9519);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(amBlue,0,amRed);
        glVertex2f(5.9601,3.2078);
        glVertex2f(5.9601,2.9519);
        glVertex2f(6.2909,2.9519);
        glVertex2f(6.2909,3.2078);
        glEnd();

    /// Window
    glBegin(GL_QUADS);
        glColor3ub(0,204,204);
        glVertex2f(6.2104,2.5343);
        glVertex2f(6.8416,2.5343);
        glColor3ub(102,255,255);
        glVertex2f(6.8416,2.8268);
        glVertex2f(6.2104,2.8268);
        glEnd();

    /// Light
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(7.4067,1.9347);
    glVertex2f(7.5639,1.9347);
    glColor3ub(255,255,102);
    glVertex2f(7.5639,2.0252);
    glVertex2f(7.4067,2.0252);
    glEnd();

    glPopMatrix();
}

   // Road Side Space & Building Side Sapce
void roadsidespace2()
{
    //1
    glBegin(GL_POLYGON);
    glColor3ub(205, 189, 189);
    glVertex2f(0, 2.61);
    glVertex2f(30, 2.61);
    glVertex2f(30, 2.9265);
    glVertex2f(0, 2.9265);
    glEnd();


}
    /// Scenario 2
    /// Main Road 2
void mainroad2()
{
    ///1 road
    glBegin(GL_POLYGON);
    glColor3ub(64,64,64);
    glVertex2f(0,2.6);
    glVertex2f(30,2.6);
    glColor3ub(0,0,0);
    glVertex2f(30,0);
    glVertex2f(0,0);
    glEnd();

    // Road dider line 1
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0,  1.16);
    glVertex2f(0.5, 1.16);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 1.16);
    glVertex2f(1.5, 1.16);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 1.16);
    glVertex2f(2.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3, 1.16);
    glVertex2f(3.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 1.16);
    glVertex2f(4.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 1.16);
    glVertex2f(5.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 1.16);
    glVertex2f(6.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 1.16);
    glVertex2f(7.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8, 1.16);
    glVertex2f(8.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9,1.16);
    glVertex2f(9.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 1.16);
    glVertex2f(10.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 1.16);
    glVertex2f(11.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12, 1.16);
    glVertex2f(12.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 1.16);
    glVertex2f(13.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 1.16);
    glVertex2f(14.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 1.16);
    glVertex2f(15.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(16, 1.16);
    glVertex2f(16.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(17, 1.16);
    glVertex2f(17.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 1.16);
    glVertex2f(18.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 1.16);
    glVertex2f(19.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 1.16);
    glVertex2f(20.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 1.16);
    glVertex2f(21.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 1.16);
    glVertex2f(22.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 1.16);
    glVertex2f(23.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 1.16);
    glVertex2f(24.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 1.16);
    glVertex2f(25.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 1.16);
    glVertex2f(26.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27, 1.16);
    glVertex2f(27.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28,1.16);
    glVertex2f(28.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 1.16);
    glVertex2f(29.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 1.16);
    glVertex2f(30,1.16);
    glEnd();
}

    // GROUND LINE 2
void groundline2()
{
    glBegin(GL_LINES);
    glLineWidth(2.5);// Each set of 4 vertices form a quad
    glColor3f(0, 102, 0); // Red
    glVertex2f(0, 2.9);    // x, y
    glVertex2f(30, 2.9);    // x, y
    glEnd();
}

void Building1()
{
    glBegin(GL_POLYGON);
    glColor3ub(51,0,25);
    glVertex2f(5.4,2.9);
    glVertex2f(10.4,2.9);
    glColor3ub(102,0,102);
    glVertex2f(10.4,10.97);
    glVertex2f(5.4,10.97);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(6.5,9.2);
    glVertex2f(7.4,9.2);
    glVertex2f(7.4,9.8);
    glVertex2f(6.5,9.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(6.5,7.8);
    glVertex2f(7.4,7.8);
    glVertex2f(7.4,8.5);
    glVertex2f(6.5,8.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(6.5,6.4);
    glVertex2f(7.4,6.4);
    glVertex2f(7.4,7.1);
    glVertex2f(6.5,7.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246);
    glVertex2f(6.5,5);
    glVertex2f(7.4,5);
    glVertex2f(7.4,5.7);
    glVertex2f(6.5,5.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
    glVertex2f(8.8,9.2);
    glVertex2f(9.7,9.2);
    glVertex2f(9.7,9.8);
    glVertex2f(8.8,9.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(8.8,7.8);
        glVertex2f(9.7,7.8);
        glVertex2f(9.7,8.5);
        glVertex2f(8.8,8.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(8.8,6.4);
        glVertex2f(9.7,6.4);
        glVertex2f(9.7,7.1);
        glVertex2f(8.8,7.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(8.8,5);
        glVertex2f(9.7,5);
        glVertex2f(9.7,5.6);
        glVertex2f(8.8,5.6);
    glEnd();

    //Door
    glBegin(GL_POLYGON);
    glColor3ub(51,25,0 );
        glVertex2f(8.8,2.9);
        glVertex2f(9.7,2.9);
        glVertex2f(9.7,4.4);
        glVertex2f(8.8,4.4);
    glEnd();


}


void Building2()
{
glBegin(GL_POLYGON);
 glColor3ub(102,51,0);

    glVertex2f(12.7,2.9);
    glVertex2f(12.7,10);
    glVertex2f(13.7,10);

    glVertex2f(13.7,10.7);
glColor3ub(255,128,0);
    glVertex2f(10.4,10.7);
    glVertex2f(10.4,2.9);
glEnd();


    //window
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(10.7,9.2);
        glVertex2f(11.5,9.2);
        glVertex2f(11.5,9.8);
        glVertex2f(10.7,9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(10.7,7.9);
        glVertex2f(11.5,7.9);
        glVertex2f(11.5,8.5);
        glVertex2f(10.7,8.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(10.7,6.7);
        glVertex2f(11.5,6.7);
        glVertex2f(11.5,7.3);
        glVertex2f(10.7,7.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(10.7,5.4);
        glVertex2f(11.5,5.4);
        glVertex2f(11.5,6);
        glVertex2f(10.7,6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(10.7,4.1);
        glVertex2f(11.5,4.1);
        glVertex2f(11.5,4.7);
        glVertex2f(10.7,4.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(12.7,9.8);
        glVertex2f(12.5,9.8);
        glVertex2f(12.5,9.2);
        glVertex2f(12.7,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(12.7,8.5);
        glVertex2f(12.5,8.5);
        glVertex2f(12.5,7.9);
        glVertex2f(12.7,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(12.7,7.3);
        glVertex2f(12.5,7.3);
        glVertex2f(12.5,6.7);
        glVertex2f(12.7,6.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(12.7,6);
        glVertex2f(12.5,6);
        glVertex2f(12.5,5.4);
        glVertex2f(12.7,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(12.7,4.8);
        glVertex2f(12.5,4.8);
        glVertex2f(12.5,4.1);
        glVertex2f(12.7,4.1);
    glEnd();
}

   ///     Building 3

void Building3()
{
    glBegin(GL_POLYGON);

        glColor3ub(143,26,220);

        glVertex2f(12.7,10);

        glVertex2f(12.7,2.9);
        glColor3ub(51,0,102);
        glVertex2f(25.6,2.9);
        glVertex2f(25.6,10);
    glEnd();

    //window

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(13.4,8.6);
        glVertex2f(14.2,8.6);
        glVertex2f(14.2,9.2);
        glVertex2f(13.4,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(15.1,8.6);
        glVertex2f(15.9,8.6);
        glVertex2f(15.9,9.2);
        glVertex2f(15.1,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(17,8.6);
        glVertex2f(17.8,8.6);
        glVertex2f(17.8,9.2);
        glVertex2f(17,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(18.8,8.6);
        glVertex2f(19.6,8.6);
        glVertex2f(19.6,9.2);
        glVertex2f(18.8,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(20.6,8.6);
        glVertex2f(21.4,8.6);
        glVertex2f(21.4,9.2);
        glVertex2f(20.6,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(22.4,8.6);
        glVertex2f(23.2,8.6);
        glVertex2f(23.2,9.2);
        glVertex2f(22.4,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(24.2,8.6);
        glVertex2f(25,8.6);
        glVertex2f(25,9.2);
        glVertex2f(24.2,9.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(13.4,7.3);
        glVertex2f(14.2,7.3);
        glVertex2f(14.2,7.9);
        glVertex2f(13.4,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(15.2,7.3);
        glVertex2f(16,7.3);
        glVertex2f(16,7.9);
        glVertex2f(15.2,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(17,7.3);
        glVertex2f(17.8,7.3);
        glVertex2f(17.8,7.9);
        glVertex2f(17,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(18.8,7.3);
        glVertex2f(19.6,7.3);
        glVertex2f(19.6,7.9);
        glVertex2f(18.8,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(20.6,7.3);
        glVertex2f(21.4,7.3);
        glVertex2f(21.4,7.9);
        glVertex2f(20.6,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(22.4,7.3);
        glVertex2f(23.2,7.3);
        glVertex2f(23.2,7.9);
        glVertex2f(22.4,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(24.2,7.3);
        glVertex2f(25.1,7.3);
        glVertex2f(25.1,7.9);
        glVertex2f(24.2,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(13.4,6);
        glVertex2f(14.2,6);
        glVertex2f(14.2,6.7);
        glVertex2f(13.4,6.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(15.2,6);
        glVertex2f(16,6);
        glVertex2f(16,6.7);
        glVertex2f(15.2,6.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(17,6);
        glVertex2f(17.8,6);
        glVertex2f(17.8,6.7);
        glVertex2f(17,6.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(18.8,6);
        glVertex2f(19.6,6);
        glVertex2f(19.6,6.7);
        glVertex2f(18.8,6.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(20.6,6);
        glVertex2f(21.4,6);
        glVertex2f(21.4,6.7);
        glVertex2f(20.6,6.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(22.4,6);
        glVertex2f(23.2,6);
        glVertex2f(23.2,6.7);
        glVertex2f(22.4,6.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(24.2,6);
        glVertex2f(25,6);
        glVertex2f(25,6.7);
        glVertex2f(24.2,6.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(13.4,4.8);
        glVertex2f(14.2,4.8);
        glVertex2f(14.2,5.4);
        glVertex2f(13.4,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(15.2,4.8);
        glVertex2f(16,4.8);
        glVertex2f(16,5.4);
        glVertex2f(15.2,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(17,4.8);
        glVertex2f(17.8,4.8);
        glVertex2f(17.8,5.4);
        glVertex2f(17,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(18.8,4.8);
        glVertex2f(19.6,4.8);
        glVertex2f(19.6,5.4);
        glVertex2f(18.8,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(20.6,4.8);
        glVertex2f(21.4,4.8);
        glVertex2f(21.4,5.4);
        glVertex2f(20.6,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(22.4,4.8);
        glVertex2f(23.2,4.8);
        glVertex2f(23.2,5.4);
        glVertex2f(22.4,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(24.2,4.8);
        glVertex2f(25,4.8);
        glVertex2f(25,5.4);
        glVertex2f(24.2,5.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(13.4,4.3);
        glVertex2f(14.2,4.3);
        glVertex2f(14.2,3.3);
        glVertex2f(13.4,3.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(15.2,4.3);
        glVertex2f(16,4.3);
        glVertex2f(16,3.3);
        glVertex2f(15.2,3.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(22.4,4.3);
        glVertex2f(23.2,4.3);
        glVertex2f(23.2,3.3);
        glVertex2f(22.4,3.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(24.2,4.3);
        glVertex2f(25,4.3);
        glVertex2f(25,3.3);
        glVertex2f(24.2,3.3);
    glEnd();

    //Door
    glBegin(GL_POLYGON);
    glColor3ub(51,25,0 );
        glVertex2f(17,4.5);
        glVertex2f(21.4,4.5);
        glVertex2f(21.4,2.9);
        glVertex2f(17,2.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3f(0, 0, 0);
    glVertex2f(19.2,  4.5);
    glVertex2f(19.2, 2.9);
    glEnd();


}
//Building 4
void Building4()
{
    glBegin(GL_POLYGON);
        glColor3ub(178,150,168);
        glVertex2f(28.5,2.9);
        glVertex2f(28.5,11.2);
        glColor3ub(255,153,255);
        glVertex2f(24.2,11.2);
        glVertex2f(24.2,2.9);
    glEnd();


    //window
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(26,10);
        glVertex2f(26,10.7);
        glVertex2f(25.2,10.7);
        glVertex2f(25.2,10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(25.6,8.7);
        glVertex2f(26,8.7);
        glVertex2f(26,9.3);
        glVertex2f(25.6,9.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(25.6,7.5);
        glVertex2f(26,7.5);
        glVertex2f(26,8.1);
        glVertex2f(25.6,8.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(25.6,6.3);
        glVertex2f(26,6.3);
        glVertex2f(26,6.9);
        glVertex2f(25.6,6.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(25.6,4.97);
        glVertex2f(26,4.97);
        glVertex2f(26,5.6);
        glVertex2f(25.6,5.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(27,10);
        glVertex2f(27.8,10);
        glVertex2f(27.8,10.7);
        glVertex2f(27,10.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(27,8.7);
        glVertex2f(27.8,8.7);
        glVertex2f(27.8,9.3);
        glVertex2f(27,9.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(27,7.5);
        glVertex2f(27.8,7.5);
        glVertex2f(27.8,8.1);
        glVertex2f(27,8.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(27,6.3);
        glVertex2f(27.8,6.3);
        glVertex2f(27.8,6.9);
        glVertex2f(27,6.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(181,255,246 );
        glVertex2f(27,5);
        glVertex2f(27.8,5);
        glVertex2f(27.8,5.6);
        glVertex2f(27,5.6);
    glEnd();
    //door

    glBegin(GL_POLYGON);
    glColor3ub(51,25,0 );
        glVertex2f(27.8,2.9);
        glVertex2f(27,2.9);
        glVertex2f(27,4.4);
        glVertex2f(27.8,4.4);
    glEnd();

}

void tunnel2()
{

    glBegin(GL_POLYGON);
        glColor3ub(122, 119, 119);
        glVertex2f(0,5.6);
        glVertex2f(2.5872,5.6);
        glVertex2f(1.2487,4.1);
        glVertex2f(0,4.1);
    glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(122, 119, 119 );
        glVertex2f(1.25,0);
        glVertex2f(1.25,4.1);
        glVertex2f(0,4.1);
        glVertex2f(0,0);
    glEnd();

}


void extraGrid()
{
    glBegin(GL_POLYGON);
    glColor3ub(24, 14, 16);
    glVertex2f(1.2487,4.1001);
    glVertex2f(1.2487,2.6108);
    glVertex2f(2.5872,2.6108);
    glVertex2f(2.5790,4.1001);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(24, 14, 16);
    glVertex2f(1.2487,4.1001);
    glVertex2f(2.5790,5.6293);
    glVertex2f(2.5771,4.1001);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.5);
    glColor3f(0 , 0 , 0);
    glVertex2f(0,4.1);
    glVertex2f(1.25,4.1);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(5.5);
    glColor3f(0 , 0 , 0);
    glVertex2f(2.6,5.6);
    glVertex2f(2.6,2.6);
    glEnd();

}


float a1 = 0.0f;
float a2 = 45.0f;
float a3 = -45.0f;

void FireAnimation(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    /// Outer shape (orange)
    glColor3ub(233,154,17);
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i < 50; i++) {
        float angle = i * 36.0 + a1;
        float len = 0.15 + 0.1 * rand() / 10100;
        float x1 = len * cos(angle);
        float y1 = len * sin(angle);
        glVertex2f(x1-0.4, y1-0.4);
        glVertex2f(0.0, 0.0);
    }
    for (int i = 0; i < 50; i++) {
        float angle = i * 36.0 + a1;
        float len = 0.15 - 0.1 * rand() / 1010;
        float x1 = len * cos(angle);
        float y1 = len * sin(angle);
        glVertex2f(x1 - 0.8, y1 + 2);
        glVertex2f(0.0, 0.0);
    }
    glEnd();
    glPopMatrix();

    /// Middle shape (yellow)
    glPushMatrix();
    glTranslatef(x, y, 0);
    glBegin(GL_TRIANGLES);
    glColor3ub(243,243,5);
    for (int i = 0; i < 10; i++) {
        float angle = i * 36.0 + a2;
        float len = 0.15 - 0.1 * rand() / 2000;
        float x1 = len * cos(angle);
        float y1 = len * sin(angle);
        glVertex2f(x1 - 0.6, y1 + 1);
        glVertex2f(0.0, 0.0);
    }
    glEnd();
    glPopMatrix();

    /// Inner part (red)
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243,53,5);
    for (int i = 0; i < 10; i++) {
        float angle = i * 36.0 + a3;
        float len = 0.15 + 0.1 * rand() / 100000;
        float x1 = len * cos(angle);
        float y1 = len * sin(angle);
        glVertex2f(x1, y1 + 0.3);
        glVertex2f(0.0, 0.0);
    }
    glEnd();
    glPopMatrix();

    a1+= 0.02f;
    a2+= 0.03f;
    a3-= 0.02f;
}




void isSound() {
    if(ok==true) {
        trafficSound();
    }
}


/// scenario 3

   ///SKY3
void sky3()
{
    glBegin(GL_POLYGON);
    glColor3ub(132,205,238);
    glVertex2f(0,6);
    glVertex2f(30,6);
    glColor3ub(51,51,201);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();


}

void night3()
{
    glBegin(GL_POLYGON);
    glColor3ub(5,52,122);
    glVertex2f(0,5.2461);
    glVertex2f(30,5.2461);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,52,122);
    glVertex2f(0,9.0);
    glVertex2f(30,9.0);
    glColor3ub(0,0,0);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();
}


void CloudCircle3(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}
void cloud3()
{
    //1
    CloudCircle3(0.36, 12.6,13.4,221,231,238);
    CloudCircle3(0.25, 12.1,13.4,221,231,238);
    CloudCircle3(0.29,11.7,13.35,221,231,238);
    CloudCircle3(0.31, 11.3,13.1,221,231,238);
    CloudCircle3(0.35, 11.7,12.9,221,231,238);
    CloudCircle3(0.40, 12.2,13,221,231,238);
    CloudCircle3(0.25, 12.5,12.6,221,231,238);
    CloudCircle3(0.62, 13.1,13,221,231,238);
    //2
    CloudCircle3(0.33, 23.3,12.7,221,231,238);
    CloudCircle3(0.25, 22.9,12.8,221,231,238);
    CloudCircle3(0.29,22.5,12.7,221,231,238);
    CloudCircle3(0.31, 22,12.4,221,231,238);
    CloudCircle3(0.35, 22.4,12.3,221,231,238);
    CloudCircle3(0.40, 23,12.3,221,231,238);
    CloudCircle3(0.25, 23.4,12.2,221,231,238);
    CloudCircle3(0.62, 23.9,12.3,221,231,238);
}


   // Road Side Space & Building Side Sapce
void roadsidespace3()
{
    //1
    glBegin(GL_POLYGON);
    glColor3ub(110,127,128);
    glVertex2f(0, 6);
    glVertex2f(30, 6);
    glVertex2f(30, 5.8);
    glVertex2f(0, 5.8);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3ub(110,127,128);
    glVertex2f(0, 3.2);
    glVertex2f(30, 3.2);
    glVertex2f(30, 2.4);
    glVertex2f(0, 2.4);
    glEnd();

}


    // Main Road
void mainroad3()
{

    ///1 road
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52);
    glVertex2f(0, 5.8);
    glVertex2f(30, 5.8);
    glVertex2f(30, 3.2);
    glVertex2f(0, 3.2);
    glEnd();

    //road2
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52);
    glVertex2f(0, 2.4);
    glVertex2f(30, 2.4);
    glVertex2f(30, 0);
    glVertex2f(0, 0);
    glEnd();



    // Road divider line 1
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0,  4.5);
    glVertex2f(0.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 4.5);
    glVertex2f(1.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 4.5);
    glVertex2f(2.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3, 4.5);
    glVertex2f(3.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 4.5);
    glVertex2f(4.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 4.5);
    glVertex2f(5.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 4.5);
    glVertex2f(6.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 4.5);
    glVertex2f(7.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8,4.5);
    glVertex2f(8.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9,4.5);
    glVertex2f(9.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 4.5);
    glVertex2f(10.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 4.5);
    glVertex2f(11.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12, 4.5);
    glVertex2f(12.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 4.5);
    glVertex2f(13.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 4.5);
    glVertex2f(14.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 4.5);
    glVertex2f(15.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(16, 4.5);
    glVertex2f(16.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(17, 4.5);
    glVertex2f(17.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 4.5);
    glVertex2f(18.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 4.5);
    glVertex2f(19.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 4.5);
    glVertex2f(20.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 4.5);
    glVertex2f(21.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 4.5);
    glVertex2f(22.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 4.5);
    glVertex2f(23.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 4.5);
    glVertex2f(24.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 4.5);
    glVertex2f(25.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 4.5);
    glVertex2f(26.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27,4.5);
    glVertex2f(27.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28,4.5);
    glVertex2f(28.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 4.5);
    glVertex2f(29.5,4.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 4.5);
    glVertex2f(30,4.5);
    glEnd();


    //road divider 2
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0,  1.16);
    glVertex2f(0.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 1.16);
    glVertex2f(1.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 1.16);
    glVertex2f(2.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3, 1.16);
    glVertex2f(3.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 1.16);
    glVertex2f(4.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 1.16);
    glVertex2f(5.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 1.16);
    glVertex2f(6.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 1.16);
    glVertex2f(7.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8, 1.16);
    glVertex2f(8.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9,1.16);
    glVertex2f(9.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 1.16);
    glVertex2f(10.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 1.16);
    glVertex2f(11.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12, 1.16);
    glVertex2f(12.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 1.16);
    glVertex2f(13.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 1.16);
    glVertex2f(14.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 1.16);
    glVertex2f(15.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(16, 1.16);
    glVertex2f(16.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(17, 1.16);
    glVertex2f(17.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 1.16);
    glVertex2f(18.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 1.16);
    glVertex2f(19.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 1.16);
    glVertex2f(20.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 1.16);
    glVertex2f(21.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 1.16);
    glVertex2f(22.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 1.16);
    glVertex2f(23.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 1.16);
    glVertex2f(24.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 1.16);
    glVertex2f(25.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 1.16);
    glVertex2f(26.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27, 1.16);
    glVertex2f(27.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28,1.16);
    glVertex2f(28.5,1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 1.16);
    glVertex2f(29.5, 1.16);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 1.16);
    glVertex2f(30,1.16);
    glEnd();

}

//TREE

void circle3(float radius, float cX, float cY)
{
   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(7,86,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}
void tree3()
{
    //1
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(4,2.7);
    glVertex2f(4.2,2.7);
    glVertex2f(4.2,3.8);
    glVertex2f(4,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.4701,3.97,4.24);
    circle(0.3395,4.35,4.07);
    circle(0.3113,3.94,3.89);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(8.8,2.7);
    glVertex2f(9,2.7);
    glVertex2f(9,3.8);
    glVertex2f(8.8,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,8.77,3.89);
    circle(0.3395,9.18,4.07);
    circle(0.4701,8.79,4.23);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(14,2.7);
    glVertex2f(14.2,2.7);
    glVertex2f(14.2,3.8);
    glVertex2f(14,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,13.94,3.89);
    circle(0.3395,14.35,4.07);
    circle(0.4701,13.97,4.23);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(18.9,2.7);
    glVertex2f(19.1,2.7);
    glVertex2f(19.1,3.8);
    glVertex2f(18.9,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,18.8,3.89);
    circle(0.3395,19.2,4.07);
    circle(0.4701,18.8,4.23);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(24.2,2.7);
    glVertex2f(24.4,2.7);
    glVertex2f(24.4,3.8);
    glVertex2f(24.2,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,24.1,3.89);
    circle(0.3395,24.5,4.07);
    circle(0.4701,24.1,4.23);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3ub(150, 104, 17 );
    glVertex2f(28.99,2.7);
    glVertex2f(29.17,2.7);
    glVertex2f(29.17,3.8);
    glVertex2f(28.99,3.8);
    glEnd();
    glLineWidth(2.0);
    circle(0.3113,28.87,3.89);
    circle(0.3395,29.28,4.07);
    circle(0.4701,28.87,4.23);
    glEnd();


}
void building1_3()
{
    glBegin(GL_POLYGON);
    glColor3ub(182,82,54);
    glVertex2f(3.4,6);
    glVertex2f(1,6);
    glColor3ub(255,178,102);
    glVertex2f(1,8.2);
    glVertex2f(3.4,8.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(1.57,7.6);
    glVertex2f(2,7.6);
    glVertex2f(2,7.9);
    glVertex2f(1.57,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(1.57,7);
    glVertex2f(2,7);
    glVertex2f(2,7.3);
    glVertex2f(1.57,7.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(1.57,6.4);
    glVertex2f(2,6.4);
    glVertex2f(2,6.7);
    glVertex2f(1.57,6.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(2.5,7.6);
    glVertex2f(2.9,7.6);
    glVertex2f(2.9,7.9);
    glVertex2f(2.5,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(2.5,7);
    glVertex2f(2.9,7);
    glVertex2f(2.9,7.3);
    glVertex2f(2.5,7.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(104, 205, 230 );
    glVertex2f(2.5,6.4);
    glVertex2f(2.9,6.4);
    glVertex2f(2.9,6.7);
    glVertex2f(2.5,6.7);
    glEnd();

}
void building2_3()
{
    glBegin(GL_POLYGON);
    glColor3ub(150,4,0);
    glVertex2f(8.6,6);
    glVertex2f(4.75,6);
    glColor3ub(213,83,78);
    glVertex2f(4.75,12.5);
    glVertex2f(8.6,12.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.5,11.2);
    glVertex2f(6.3,11.2);
    glVertex2f(6.3,11.9);
    glVertex2f(5.5,11.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.5,9.9);
    glVertex2f(6.3,9.9);
    glVertex2f(6.3,10.5);
    glVertex2f(5.5,10.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.5,8.7);
    glVertex2f(6.3,8.7);
    glVertex2f(6.3,9.3);
    glVertex2f(5.5,9.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(5.5,7.4);
    glVertex2f(6.3,7.4);
    glVertex2f(6.3,8);
    glVertex2f(5.5,8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(7.2,11.2);
    glVertex2f(8,11.2);
    glVertex2f(8,11.9);
    glVertex2f(7.2,11.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(7.2,9.9);
    glVertex2f(8,9.9);
    glVertex2f(8,10.5);
    glVertex2f(7.2,10.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(7.2,8.7);
    glVertex2f(8,8.7);
    glVertex2f(8,9.3);
    glVertex2f(7.2,9.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(7.2,7.4);
    glVertex2f(8,7.4);
    glVertex2f(8,8);
    glVertex2f(7.2,8);
    glEnd();

}

void hospital3()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 192, 217);
    glVertex2f(9.5,6);
    glVertex2f(17.3,6);
    glColor3ub(93, 208, 226);
    glVertex2f(17.3,9.6);
    glVertex2f(9.5,9.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(201,222,251);
    glVertex2f(11.5,9.4);
    glVertex2f(15.4,9.4);
    glVertex2f(15.4,10.5);
    glVertex2f(11.5,10.5);
    glEnd();
    //window row 1

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(9.8,8.5);
    glVertex2f(17,8.5);
    glVertex2f(17,9.3);
    glVertex2f(9.8,9.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(10.4, 9.3);
    glVertex2f(10.4, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(11, 9.3);
    glVertex2f(11, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(11.6, 9.3);
    glVertex2f(11.6, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(12.2, 9.3);
    glVertex2f(12.2, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(12.8, 9.3);
    glVertex2f(12.8, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(13.4, 9.3);
    glVertex2f(13.4, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(14, 9.3);
    glVertex2f(14, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(14.6, 9.3);
    glVertex2f(14.6, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(15.2, 9.3);
    glVertex2f(15.2, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(15.8, 9.3);
    glVertex2f(15.8, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.4, 9.3);
    glVertex2f(16.4, 8.5);
    glEnd();
    //window row 2


    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(9.8,7.4);
    glVertex2f(17,7.4);
    glVertex2f(17,8.2);
    glVertex2f(9.8,8.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(10.4, 8.2);
    glVertex2f(10.4, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(11, 8.2);
    glVertex2f(11, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(11.6, 8.2);
    glVertex2f(11.6, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(12.2, 8.2);
    glVertex2f(12.2, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(12.8, 8.2);
    glVertex2f(12.8, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(13.4, 8.2);
    glVertex2f(13.4, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(14, 8.2);
    glVertex2f(14, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(14.6, 8.2);
    glVertex2f(14.6, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(15.2, 8.2);
    glVertex2f(15.2, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(15.8, 8.2);
    glVertex2f(15.8, 7.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.4, 8.2);
    glVertex2f(16.4, 7.4);
    glEnd();

        //window row3

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(9.8,6.2);
    glVertex2f(17,6.2);
    glVertex2f(17,7);
    glVertex2f(9.8,7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(10.4, 7);
    glVertex2f(10.4, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(11, 7);
    glVertex2f(11, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(11.6, 7);
    glVertex2f(11.6, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(12.2, 7);
    glVertex2f(12.2, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(12.8, 7);
    glVertex2f(12.8, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(13.4, 7);
    glVertex2f(13.4, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(14, 7);
    glVertex2f(14, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(14.6, 7);
    glVertex2f(14.6, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(15.2, 7);
    glVertex2f(15.2, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(15.8, 7);
    glVertex2f(15.8, 6.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 192, 217);
    glLineWidth(1.0);
    glVertex2f(16.4, 7);
    glVertex2f(16.4, 6.2);
    glEnd();

    /// Sign
    float nx = 4.1;
      float ny = 2.75;

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.5210-nx , 7.1045+ny);
    glVertex2f(17.5210-nx , 7.4804+ny);
    glVertex2f(17.6178-nx , 7.4804+ny);
    glVertex2f(17.6178-nx , 7.1045+ny);
    glVertex2f(17.5210-nx , 7.1045+ny);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.6178-nx , 7.2564+ny);
    glVertex2f(17.6178-nx , 7.1045+ny);
    glVertex2f(17.5210-nx , 7.1045+ny);
    glVertex2f(17.5210-nx , 7.2564+ny);
    glVertex2f(17.3660-nx , 7.2564+ny);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.3660-nx , 7.3347+ny);
    glVertex2f(17.5210-nx , 7.3347+ny);
    glVertex2f(17.5210-nx , 7.3347+ny);
    glVertex2f(17.5210 -nx, 7.3347+ny);
    glEnd();

     //
     glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.3660-nx , 7.3347+ny);
    glVertex2f(17.5210-nx , 7.3347+ny);
    glVertex2f(17.5210-nx , 7.2564+ny);
    glVertex2f(17.3660-nx , 7.2564+ny);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(17.6178-nx , 7.3347+ny);
    glVertex2f(17.7733-nx , 7.3347+ny);
    glVertex2f(17.7733-nx , 7.2564+ny);
    glVertex2f(17.6178-nx , 7.2564+ny);
    glEnd();
}

void building3_3() {
    glBegin(GL_POLYGON);
    glColor3ub(14,35,58);
    glVertex2f(17.9,6);
    glVertex2f(19.5,6);
    glColor3ub(53,125,208);
    glVertex2f(19.5,8.1);
    glVertex2f(17.9,8.1);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.5);
    glColor3f(10, 102, 100);
    glVertex2f(17.9,7.6);
    glVertex2f(19.5,7.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86,52,0);
    glVertex2f(18.3,6);
    glVertex2f(19.1,6);
    glVertex2f(19.1,7.4);
    glVertex2f(18.3,7.4);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1.5);
    glColor3f(0, 0, 0);
    glVertex2f(18.3,7.1);
    glVertex2f(19.1,7.1);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glColor3f(0, 0, 0);
    glVertex2f(18.3,6.8);
    glVertex2f(19.1,6.8);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glColor3f(0, 0, 0);
    glVertex2f(18.3,6.5);
    glVertex2f(19.1,6.5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glColor3f(0, 0, 0);
    glVertex2f(18.3,6.2);
    glVertex2f(19.1,6.2);
    glEnd();

}

void building4_3() {
    glBegin(GL_POLYGON);
    glColor3ub(42,111,199);
    glVertex2f(20.6,6);
    glVertex2f(20.6,10.5);
    glVertex2f(25.5,10.5);
    glVertex2f(25.5,6);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(21.3,8.5);
    glVertex2f(22,8.5);
    glVertex2f(22,9);
    glVertex2f(21.3,9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(22.8,8.5);
    glVertex2f(23.5,8.5);
    glVertex2f(23.5,9);
    glVertex2f(22.8,9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(24.3,8.5);
    glVertex2f(25,8.5);
    glVertex2f(25,9);
    glVertex2f(24.3,9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(21.3,7.4);
    glVertex2f(22,7.4);
    glVertex2f(22,7.9);
    glVertex2f(21.3,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(22.8,7.4);
    glVertex2f(23.5,7.4);
    glVertex2f(23.5,7.9);
    glVertex2f(22.8,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(24.3,7.4);
    glVertex2f(25,7.4);
    glVertex2f(25,7.9);
    glVertex2f(24.3,7.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glColor3f(100, 100, 100);
    glVertex2f(20.6,9.4);
    glVertex2f(25.5,9.4);
    glEnd();

    //door
    glBegin(GL_POLYGON);
    glColor3ub(86,52,0);
    glVertex2f(22.8,6);
    glVertex2f(23.5,6);
    glVertex2f(23.5,6.9);
    glVertex2f(22.8,6.9);
    glEnd();
}
void building5_3()
{

    glBegin(GL_POLYGON);
    glColor3ub(224,164,0);
    glVertex2f(28.9,6);
    glVertex2f(28.9,12.6);
    glVertex2f(24,12.6);
    glVertex2f(24,6);
    glEnd();


    //window

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(24.5,11.4);
    glVertex2f(25.2,11.4);
    glVertex2f(25.2,11.9);
    glVertex2f(24.5,11.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(25.2,10.5);
    glVertex2f(25.2,10.8);
    glVertex2f(24.5,10.8);
    glVertex2f(24.5,10.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(26.1,11.4);
    glVertex2f(26.8,11.4);
    glVertex2f(26.8,11.9);
    glVertex2f(26.1,11.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(26.1,10.3);
    glVertex2f(26.8,10.3);
    glVertex2f(26.8,10.8);
    glVertex2f(26.1,10.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(26.1,9.1);
    glVertex2f(26.8,9.1);
    glVertex2f(26.8,9.7);
    glVertex2f(26.1,9.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(26.1,8);
    glVertex2f(26.8,8);
    glVertex2f(26.8,8.6);
    glVertex2f(26.1,8.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(27.7,11.4);
    glVertex2f(28.4,11.4);
    glVertex2f(28.4,11.9);
    glVertex2f(27.7,11.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(27.7,10.3);
    glVertex2f(28.4,10.3);
    glVertex2f(28.4,10.8);
    glVertex2f(27.7,10.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(27.7,9.1);
    glVertex2f(28.4,9.1);
    glVertex2f(28.4,9.7);
    glVertex2f(27.7,9.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(155,209,225);
    glVertex2f(27.7,8);
    glVertex2f(28.4,8);
    glVertex2f(28.4,8.6);
    glVertex2f(27.7,8.6);
    glEnd();
    //Door
    glBegin(GL_POLYGON);
    glColor3ub(86,52,0);
    glVertex2f(26.8,6);
    glVertex2f(26,6);
    glVertex2f(26,7);
    glVertex2f(26.8,7);
    glEnd();


}

///


    //SKY 4
void sky4()
{
    glBegin(GL_POLYGON);
    glColor3ub(132,205,238);
    glVertex2f(0,6);
    glVertex2f(30,6);
    glColor3ub(51,51,201);
    glVertex2f(30,15);
    glVertex2f(0,15);

    glEnd();


}

void cloud4()
{
    //1
    CloudCircle(0.36, 12.6,13.4,221,231,238);
    CloudCircle(0.25, 12.1,13.4,221,231,238);
    CloudCircle(0.29,11.7,13.35,221,231,238);
    CloudCircle(0.31, 11.3,13.1,221,231,238);
    CloudCircle(0.35, 11.7,12.9,221,231,238);
    CloudCircle(0.40, 12.2,13,221,231,238);
    CloudCircle(0.25, 12.5,12.6,221,231,238);
    CloudCircle(0.62, 13.1,13,221,231,238);
    //2
    CloudCircle(0.33, 23.3,12.7,221,231,238);
    CloudCircle(0.25, 22.9,12.8,221,231,238);
    CloudCircle(0.29,22.5,12.7,221,231,238);
    CloudCircle(0.31, 22,12.4,221,231,238);
    CloudCircle(0.35, 22.4,12.3,221,231,238);
    CloudCircle(0.40, 23,12.3,221,231,238);
    CloudCircle(0.25, 23.4,12.2,221,231,238);
    CloudCircle(0.62, 23.9,12.3,221,231,238);
}



   // Road Side Space & Building Side Sapce
void Roadsidespace4()
{
    //1
    glBegin(GL_POLYGON);
    glColor3ub(110,127,128);
    glVertex2f(0, 6.78);
    glVertex2f(30, 6.78);
    glVertex2f(30, 6.2);
    glVertex2f(0, 6.2);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3ub(110,127,128);
    glVertex2f(0, 3.58);
    glVertex2f(30, 3.58);
    glVertex2f(30, 3.0);
    glVertex2f(0, 3.0);
    glEnd();

}


    // Main Road 4
void mainroad4()
{

    ///1 road
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52);
    glVertex2f(0, 6.2);
    glVertex2f(0, 3.4);
    glVertex2f(30, 3.4);
    glVertex2f(30, 6.2);
    glEnd();

    //road2
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52);
    glVertex2f(0, 3.0);
    glVertex2f(0, 0);
    glVertex2f(30, 0);
    glVertex2f(30, 3.0);
    glEnd();



    //road divider 2
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0,  1.6);
    glVertex2f(0.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 1.6);
    glVertex2f(1.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 1.6);
    glVertex2f(2.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3, 1.6);
    glVertex2f(3.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 1.6);
    glVertex2f(4.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 1.6);
    glVertex2f(5.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 1.6);
    glVertex2f(6.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 1.6);
    glVertex2f(7.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8, 1.6);
    glVertex2f(8.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9,1.6);
    glVertex2f(9.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 1.6);
    glVertex2f(10.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 1.6);
    glVertex2f(11.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12, 1.6);
    glVertex2f(12.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 1.6);
    glVertex2f(13.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 1.6);
    glVertex2f(14.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 1.6);
    glVertex2f(15.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(16, 1.6);
    glVertex2f(16.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(17, 1.6);
    glVertex2f(17.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 1.6);
    glVertex2f(18.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 1.6);
    glVertex2f(19.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 1.6);
    glVertex2f(20.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 1.6);
    glVertex2f(21.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 1.6);
    glVertex2f(22.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 1.6);
    glVertex2f(23.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 1.6);
    glVertex2f(24.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 1.6);
    glVertex2f(25.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 1.6);
    glVertex2f(26.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27, 1.6);
    glVertex2f(27.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28,1.6);
    glVertex2f(28.5,1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 1.6);
    glVertex2f(29.5, 1.6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 1.6);
    glVertex2f(30,1.6);
    glEnd();
    //uper road 2
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(0,  4.9);
    glVertex2f(0.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(1.0, 4.9);
    glVertex2f(1.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(2, 4.9);
    glVertex2f(2.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(3,4.9);
    glVertex2f(3.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(4, 4.9);
    glVertex2f(4.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(5, 4.9);
    glVertex2f(5.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(6, 4.9);
    glVertex2f(6.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(7, 4.9);
    glVertex2f(7.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(8, 4.9);
    glVertex2f(8.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(9,4.9);
    glVertex2f(9.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(10, 4.9);
    glVertex2f(10.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(11, 4.9);
    glVertex2f(11.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(12,4.9);
    glVertex2f(12.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(13, 4.9);
    glVertex2f(13.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(14, 4.9);
    glVertex2f(14.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(15, 4.9);
    glVertex2f(15.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(16, 4.9);
    glVertex2f(16.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(17, 4.9);
    glVertex2f(17.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(18, 4.9);
    glVertex2f(18.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(19, 4.9);
    glVertex2f(19.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(20, 4.9);
    glVertex2f(20.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(21, 4.9);
    glVertex2f(21.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(22, 4.9);
    glVertex2f(22.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(23, 4.9);
    glVertex2f(23.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(24, 4.9);
    glVertex2f(24.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(25, 4.9);
    glVertex2f(25.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(26, 4.9);
    glVertex2f(26.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(27, 4.9);
    glVertex2f(27.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(28,4.9);
    glVertex2f(28.5,4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29, 4.9);
    glVertex2f(29.5, 4.9);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(1.0);
    glColor3f(229, 221, 104);
    glVertex2f(29.9, 4.9);
    glVertex2f(30,4.9);
    glEnd();


}
void building1_4()
{
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(3.1331, 10.5145);
    glVertex2f(4.1499, 10.5145);
    glVertex2f(4.1499, 10.7134);
    glVertex2f(3.1329, 10.7134);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(3.1331, 10.5145);
    glVertex2f(4.1499, 10.5145);
    glVertex2f(4.1499, 10.5145);
    glVertex2f(4.1499, 10.7134);
    glVertex2f(4.1499, 10.7134);
    glVertex2f(3.1329, 10.7134);
    glVertex2f(3.1329, 10.7134);
    glVertex2f(3.1331, 10.5145);
    glEnd();

    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(255,153,51);
    glVertex2f(2.8108, 10.5145);
    glVertex2f(4.4225, 10.5145);
    glVertex2f(4.4225 , 8.6004);
    glVertex2f(2.8108, 8.6004);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(2.8108, 10.5145);
    glVertex2f(4.4225, 10.5145);
    glVertex2f(4.4225, 10.5145);
    glVertex2f(4.4225 , 8.6004);
    glVertex2f(4.4225 , 8.6004);
    glVertex2f(2.8108, 8.6004);
    glVertex2f(2.8108, 8.6004);
    glVertex2f(2.8108, 10.5145);
    glEnd();

    ///Windows
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.1331, 10.3285);
    glVertex2f(3.4905, 10.3285);
    glVertex2f(3.4905, 10.0565 );
    glVertex2f(3.1331, 10.0565);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.7898, 10.0565);
    glVertex2f(4.1471, 10.0565);
    glVertex2f(4.1471, 10.3285);
    glVertex2f(3.7898, 10.3285);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.1331, 9.6546);
    glVertex2f(3.4905, 9.6546);
    glVertex2f(3.4905, 9.9266);
    glVertex2f(3.1331, 9.9266 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.7898, 9.9266);
    glVertex2f(4.1471, 9.9266);
    glVertex2f(4.1471, 9.6546);
    glVertex2f(3.7898, 9.6546);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.1331, 9.5060);
    glVertex2f(3.4905, 9.5060);
    glVertex2f(3.4905, 9.2340);
    glVertex2f(3.1331, 9.2340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.7898, 9.5060);
    glVertex2f(4.1471, 9.5060);
    glVertex2f(4.1471, 9.2340);
    glVertex2f(3.7898, 9.2340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.1331, 9.0947);
    glVertex2f(3.4905, 9.0947);
    glVertex2f(3.4905, 8.8227);
    glVertex2f(3.1331, 8.8227);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(3.7898, 9.0947);
    glVertex2f(4.1471, 9.0947);
    glVertex2f(4.1471, 8.8227);
    glVertex2f(3.7898, 8.8227);
    glEnd();
}

void building2_4()
{
    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(255,178,0);
    glVertex2f(2.1603, 8.6004);
    glVertex2f(4.7179, 8.6004);
    glVertex2f(4.7213, 6.7870);
    glVertex2f(2.1630, 6.7870);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(2.1603, 8.6004);
    glVertex2f(4.7179, 8.6004);
    glVertex2f(4.7179, 8.6004);
    glVertex2f(4.7213, 6.7870);
    glVertex2f(4.7213, 6.7870);
    glVertex2f(2.1630, 6.7870);
    glVertex2f(2.1630, 6.7870);
    glVertex2f(2.1603, 8.6004);
    glEnd();

    ///Glass
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(207,255,249);
    glVertex2f(2.2313, 8.0650);
    glVertex2f(4.7213, 8.0650);
    glVertex2f(4.7213, 8.4812);
    glVertex2f(2.2313, 8.4812);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(4.7213, 8.4812);
    glVertex2f(2.2313, 8.4812);
    glVertex2f(2.2313, 8.4812);
    glVertex2f(2.2313, 8.0650);
    glVertex2f(2.2313, 8.0650);
    glVertex2f(4.7213, 8.0650);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(207,255,249);
    glVertex2f(2.2313, 7.4630);
    glVertex2f(4.7213, 7.4630);
    glVertex2f(4.7213, 7.8792);
    glVertex2f(2.2313, 7.8792);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(4.7213, 7.8792);
    glVertex2f(2.2313, 7.8792);
    glVertex2f(2.2313, 7.8792);
    glVertex2f(2.2313, 7.4630);
    glVertex2f(2.2313, 7.4630);
    glVertex2f(2.2313, 7.8792);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(207,255,249);
    glVertex2f(2.2313, 6.8778);
    glVertex2f(4.7213, 6.8778);
    glVertex2f(4.7213, 7.2940);
    glVertex2f(2.2313, 7.2940);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(4.7213, 7.2940);
    glVertex2f(2.2313, 7.2940);
    glVertex2f(2.2313, 7.2940);
    glVertex2f(2.2313, 6.8778);
    glVertex2f(2.2313, 6.8778);
    glVertex2f(4.7213, 6.8778);
    glEnd();

    ///Mid lines
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(2.1613, 7.9702);
    glVertex2f(4.7191, 7.9702);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(205,194,245);
    glVertex2f(2.1613, 7.3815);
    glVertex2f(4.7191, 7.3815);
    glEnd();


}

void building3_4()
{
    ///top
    glBegin(GL_POLYGON);
    glColor3ub(204,204,0);
    glVertex2f(6.9220, 10.6817);
    glVertex2f(7.6293, 10.6817);
    glVertex2f(7.6293, 10.4952);
    glVertex2f(6.9220, 10.4952);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(232,203,224);
    glVertex2f(6.9220, 10.6817);
    glVertex2f(7.6293, 10.6817);
    glVertex2f(7.6293, 10.6817);
    glVertex2f(7.6293, 10.4952);
    glVertex2f(7.6293, 10.4952);
    glVertex2f(6.9220, 10.4952);
    glEnd();

    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(204,204,0);
    glVertex2f(6.9220, 10.4952);
    glVertex2f(9.5307, 10.4949);
    glVertex2f(9.5307, 6.7870);
    glVertex2f(6.9220, 6.7870);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(232,203,224);
    glVertex2f(6.9220, 10.4952);
    glVertex2f(9.5307, 10.4949);
    glVertex2f(9.5307, 10.4949);
    glVertex2f(9.5307, 6.7870);
    glVertex2f(9.5307, 6.7870);
    glVertex2f(6.9220, 6.7870);
    glEnd();

    ///windows
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.9422, 9.8125);
    glVertex2f(7.2995, 9.8125);
    glVertex2f(7.2995, 10.0845);
    glVertex2f(6.9422, 10.0845);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(7.6293, 9.8125);
    glVertex2f(7.9866, 9.8125);
    glVertex2f(7.9866, 10.0845);
    glVertex2f(7.6293, 10.0845);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(8.2859, 9.8125);
    glVertex2f(8.6432, 9.8125);
    glVertex2f(8.6432, 10.0845);
    glVertex2f(8.2859, 10.0845);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.9422, 9.2520);
    glVertex2f(7.2995, 9.2520);
    glVertex2f(7.2995, 9.5240);
    glVertex2f(6.9422, 9.5240);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(7.6293, 9.2520);
    glVertex2f(7.9866, 9.2520);
    glVertex2f(7.9866, 9.5240);
    glVertex2f(7.6293, 9.5240);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(8.2859, 9.2520);
    glVertex2f(8.6432, 9.2520);
    glVertex2f(8.6432, 9.5240);
    glVertex2f(8.2859, 9.5240);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.9422, 8.7152);
    glVertex2f(7.2995, 8.7152);
    glVertex2f(7.2995, 8.9872);
    glVertex2f(6.9422, 8.9872);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(7.6293, 8.7152);
    glVertex2f(7.9866, 8.7152);
    glVertex2f(7.9866, 8.9872);
    glVertex2f(7.6293, 8.9872);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(8.2859, 8.7152);
    glVertex2f(8.6432, 8.7152);
    glVertex2f(8.6432, 8.9872);
    glVertex2f(8.2859, 8.9872);
    glEnd();

    ///4
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.9422, 8.1780);
    glVertex2f(7.2995, 8.1780);
    glVertex2f(7.2995, 8.4500);
    glVertex2f(6.9422, 8.4500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(7.6293, 8.1780);
    glVertex2f(7.9866, 8.1780);
    glVertex2f(7.9866, 8.4500);
    glVertex2f(7.6293, 8.4500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(8.2859, 8.1780);
    glVertex2f(8.6432, 8.1780);
    glVertex2f(8.6432, 8.4500);
    glVertex2f(8.2859, 8.4500);
    glEnd();

    ///door
    glBegin(GL_POLYGON);
    glColor3ub(112,75,91);
    glVertex2f(6.9220, 6.7870);
    glVertex2f(8.1917, 6.7870);
    glVertex2f(8.1917, 7.9141);
    glVertex2f(6.9220, 7.9141);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(232,203,224);
    glVertex2f(6.9220, 6.7870);
    glVertex2f(8.1917, 6.7870);
    glVertex2f(8.1917, 6.7870);
    glVertex2f(8.1917, 7.9141);
    glVertex2f(8.1917, 7.9141);
    glVertex2f(6.9220, 7.9141);
    glVertex2f(6.9220, 7.9141);
    glVertex2f(6.9220, 6.7870);
    glEnd();

    ///Side glass
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(8.9462, 10.4949);
    glVertex2f(8.9462, 6.7870);
    glVertex2f(9.5307, 6.7870);
    glVertex2f(9.5307, 10.4949);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(15);
    glColor3ub(88,60,84);
    glVertex2f(8.9462, 10.4949);
    glVertex2f(8.9462, 6.7870);
    glVertex2f(8.9462, 6.7870);
    glVertex2f(9.5307, 6.7870);
    glVertex2f(9.5307, 6.7870);
    glVertex2f(9.5307, 10.4949);
    glEnd();

    ///mid line
    glBegin(GL_LINES);
    glLineWidth(15);
    glColor3ub(88,60,84);
    glVertex2f(9.2496, 6.7870);
    glVertex2f(9.2496, 10.4949);
    glEnd();

}

void building4_4()
{
    ///top
    glBegin(GL_POLYGON);
    glColor3ub(255,102,102);
    glVertex2f(5.1595, 12.3990);
    glVertex2f(6.4223, 12.3990);
    glVertex2f(6.4223, 12.2124);
    glVertex2f(5.1595, 12.2124);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(190,246,221);
    glVertex2f(5.1595, 12.3990);
    glVertex2f(6.4223, 12.3990);
    glVertex2f(6.4223, 12.3990);
    glVertex2f(6.4223, 12.2124);
    glVertex2f(6.4223, 12.2124);
    glVertex2f(5.1595, 12.2124);
    glVertex2f(5.1595, 12.2124);
    glVertex2f(5.1595, 12.3990);
    glEnd();

    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(255,102,102);
    glVertex2f(4.7213, 12.2124);
    glVertex2f(6.9220, 12.2124);
    glVertex2f(6.9220, 6.7870);
    glVertex2f(4.7213, 6.7870);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(190,246,221);
    glVertex2f(4.7213, 12.2124);
    glVertex2f(6.9220, 12.2124);
    glVertex2f(6.9220, 12.2124);
    glVertex2f(6.9220, 6.7870);
    glVertex2f(6.9220, 6.7870);
    glVertex2f(4.7213, 6.7870);
    glVertex2f(4.7213, 6.7870);
    glVertex2f(4.7213, 12.2124);
    glEnd();

    ///windows
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 11.6773);
    glVertex2f(5.5147, 11.6773);
    glVertex2f(5.5147, 11.9493);
    glVertex2f(5.1574, 11.9493);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 11.6773);
    glVertex2f(6.4336, 11.6773);
    glVertex2f(6.4336, 11.9493);
    glVertex2f(6.0762, 11.9493);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 11.1381);
    glVertex2f(5.5147, 11.1381);
    glVertex2f(5.5147, 11.4101);
    glVertex2f(5.1574, 11.4101);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 11.1381);
    glVertex2f(6.4336, 11.1381);
    glVertex2f(6.4336, 11.4101);
    glVertex2f(6.0762, 11.4101);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 10.5706);
    glVertex2f(5.5147, 10.5706);
    glVertex2f(5.5147, 10.8426);
    glVertex2f(5.1574, 10.8426);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 10.5706);
    glVertex2f(6.4336, 10.5706);
    glVertex2f(6.4336, 10.8426);
    glVertex2f(6.0762, 10.8426);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 10.0314);
    glVertex2f(5.5147, 10.0314);
    glVertex2f(5.5147, 10.3034);
    glVertex2f(5.1574, 10.3034);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 10.0314);
    glVertex2f(6.4336, 10.0314);
    glVertex2f(6.4336, 10.3034);
    glVertex2f(6.0762, 10.3034);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 9.4697);
    glVertex2f(5.5147, 9.4697);
    glVertex2f(5.5147, 9.7417);
    glVertex2f(5.1574, 9.7417);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 9.4697);
    glVertex2f(6.4336, 9.4697);
    glVertex2f(6.4336, 9.7417);
    glVertex2f(6.0762, 9.7417);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 8.9304);
    glVertex2f(5.5147, 8.9304);
    glVertex2f(5.5147, 9.2024);
    glVertex2f(5.1574, 9.2024);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 8.9304);
    glVertex2f(6.4336, 8.9304);
    glVertex2f(6.4336, 9.2024);
    glVertex2f(6.0762, 9.2024);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 8.3779);
    glVertex2f(5.5147, 8.3779);
    glVertex2f(5.5147, 8.6499);
    glVertex2f(5.1574, 8.6499);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 8.3779);
    glVertex2f(6.4336, 8.3779);
    glVertex2f(6.4336, 8.6499);
    glVertex2f(6.0762, 8.6499);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 7.8169);
    glVertex2f(5.5147, 7.8169);
    glVertex2f(5.5147, 8.0889);
    glVertex2f(5.1574, 8.0889);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(6.0762, 7.8169);
    glVertex2f(6.4336, 7.8169);
    glVertex2f(6.4336, 8.0889);
    glVertex2f(6.0762, 8.0889);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(5.1574, 7.2814);
    glVertex2f(5.5147, 7.2814);
    glVertex2f(5.5147, 7.5534);
    glVertex2f(5.1574, 7.5534);
    glEnd();

    ///door
    glBegin(GL_POLYGON);
    glColor3ub(190,246,221);
    glVertex2f(6.0762, 6.7870);
    glVertex2f(6.4336, 6.7870);
    glVertex2f(6.4336, 7.3828);
    glVertex2f(6.0762, 7.3828);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(190,246,221);
    glVertex2f(6.0762, 6.7870);
    glVertex2f(6.4336, 6.7870);
    glVertex2f(6.4336, 6.7870);
    glVertex2f(6.4336, 7.3828);
    glVertex2f(6.4336, 7.3828);
    glVertex2f(6.0762, 7.3828);
    glVertex2f(6.0762, 7.3828);
    glVertex2f(6.0762, 6.7870);
    glEnd();
}

void building5_4()
{
    ///glass
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(12.1179, 9.3513);
    glVertex2f(12.1179, 6.7870);
    glVertex2f(12.7612, 6.7870);
    glVertex2f(12.7612, 7.9445);
    glVertex2f(12.8868, 7.9445);
    glVertex2f(12.8868, 8.0617);
    glVertex2f(13.1002, 8.0616);
    glVertex2f(13.1002, 9.3513);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(128,0,128);
    glVertex2f(12.7612, 6.7870);
    glVertex2f(12.7612, 7.9445);
    glVertex2f(12.7612, 7.9445);
    glVertex2f(12.8868, 7.9445);
    glVertex2f(12.8868, 7.9445);
    glVertex2f(12.8868, 8.0617);
    glVertex2f(12.8868, 8.0617);
    glVertex2f(13.1002, 8.0616);
    glVertex2f(13.1002, 8.0616);
    glVertex2f(13.1002, 9.3513);
    glVertex2f(13.1002, 9.3513);
    glVertex2f(12.1179, 9.3513);
    glEnd();

    ///Lines
    ///1
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 9.1037);
    glVertex2f(13.1002, 9.1037);
    glEnd();

    ///2
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 8.8634);
    glVertex2f(13.1002, 8.8634);
    glEnd();

    ///3
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 8.6372);
    glVertex2f(13.1002, 8.6372);
    glEnd();

    ///4
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 8.4303);
    glVertex2f(13.1002, 8.4303);
    glEnd();

    ///5
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 8.2234);
    glVertex2f(13.1002, 8.2234);
    glEnd();

    ///6
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 8.0240);
    glVertex2f(12.8868, 8.0240);
    glEnd();

    ///7
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 7.8321);
    glVertex2f(12.7612, 7.8321);
    glEnd();

    ///8
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 7.6290);
    glVertex2f(12.7612, 7.6290);
    glEnd();

    ///9
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 7.4218);
    glVertex2f(12.7612, 7.4218);
    glEnd();

    ///10
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 7.2007);
    glVertex2f(12.7612, 7.2007);
    glEnd();

    ///11
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(131,80,113);
    glVertex2f(12.1194, 6.9938);
    glVertex2f(12.7612, 6.9938);
    glEnd();
}

void building6_4()
{
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(222,16,16);
    glVertex2f(12.8868, 7.9445);
    glVertex2f(13.4970, 7.9445);
    glVertex2f(13.4968, 8.0615);
    glVertex2f(12.8868, 8.0617);
    glEnd();



    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(222,16,16);
    glVertex2f(12.7612, 7.9445);
    glVertex2f(12.7612, 6.7870);
    glVertex2f(13.6020, 6.7870);
    glVertex2f(13.6020, 7.9445);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(255,179,138);
    glVertex2f(12.7612, 7.9445);
    glVertex2f(12.7612, 6.7870);
    glVertex2f(12.7612, 6.7870);
    glVertex2f(13.6020, 6.7870);
    glVertex2f(13.6020, 6.7870);
    glVertex2f(13.6020, 7.9445);
    glVertex2f(13.6020, 7.9445);
    glVertex2f(12.7612, 7.9445);
    glEnd();

    ///windows
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(12.8902, 7.6524);
    glVertex2f(13.1165, 7.6524);
    glVertex2f(13.1165, 7.8044);
    glVertex2f(12.8902, 7.8044);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(13.2869, 7.6524);
    glVertex2f(13.5132, 7.6524);
    glVertex2f(13.5132, 7.8044);
    glVertex2f(13.2869, 7.8044);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(12.8902, 7.2977);
    glVertex2f(13.1165, 7.2977);
    glVertex2f(13.1165, 7.4497);
    glVertex2f(12.8902, 7.4497);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(13.2869, 7.2977);
    glVertex2f(13.5132, 7.2977);
    glVertex2f(13.5132, 7.4497);
    glVertex2f(13.2869, 7.4497);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(12.8902, 6.9278);
    glVertex2f(13.1165, 6.9278);
    glVertex2f(13.1165, 7.0798);
    glVertex2f(12.8902, 7.0798);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(13.2869, 6.9278);
    glVertex2f(13.5132, 6.9278);
    glVertex2f(13.5132, 7.0798);
    glVertex2f(13.2869, 7.0798);
    glEnd();
}

void building7_4()
{
    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(26,140,184);
    glVertex2f(14.2700, 11.3812);
    glVertex2f(14.2700, 6.7870);
    glVertex2f(15.7277, 6.7870);
    glVertex2f(15.7277, 10.8066);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(24,154,211);
    glVertex2f(14.2700, 11.3812);
    glVertex2f(14.2700, 6.7870);
    glVertex2f(14.2700, 6.7870);
    glVertex2f(15.7277, 6.7870);
    glVertex2f(15.7277, 6.7870);
    glVertex2f(15.7277, 10.8066);
    glVertex2f(15.7277, 10.8066);
    glVertex2f(14.2700, 11.3812);
    glEnd();

    ///glass
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(14.6921, 10.8066);
    glVertex2f(14.6907, 6.7870);
    glVertex2f(15.7277, 6.7870);
    glVertex2f(15.7277, 10.8066);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(24,154,211);
    glVertex2f(14.6907, 6.7870);
    glVertex2f(15.7277, 6.7870);
    glVertex2f(15.7277, 6.7870);
    glVertex2f(15.7277, 10.8066);
    glVertex2f(15.7277, 10.8066);
    glVertex2f(14.6921, 10.8066);
    glEnd();

    ///Lines
    ///1
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 10.5656);
    glVertex2f(15.7277, 10.5656);
    glEnd();

    ///2
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 10.3592);
    glVertex2f(15.7277, 10.3592);
    glEnd();

    ///3
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 10.1238);
    glVertex2f(15.7277, 10.1238);
    glEnd();

    ///4
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 9.9057);
    glVertex2f(15.7277, 9.9057);
    glEnd();

    ///5
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 9.6913);
    glVertex2f(15.7277, 9.6913);
    glEnd();

    ///6
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 9.4538);
    glVertex2f(15.7277, 9.4538);
    glEnd();

    ///7
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 9.2170);
    glVertex2f(15.7277, 9.2170);
    glEnd();

    ///8
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 9.0019);
    glVertex2f(15.7277, 9.0019);
    glEnd();

    ///9
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 8.7926);
    glVertex2f(15.7277, 8.7926);
    glEnd();

    ///10
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 8.6011);
    glVertex2f(15.7277, 8.6011);
    glEnd();

    ///11
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 8.4109);
    glVertex2f(15.7277, 8.4109);
    glEnd();

    ///12
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 8.2109);
    glVertex2f(15.7277, 8.2109);
    glEnd();

    ///13
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 8.0183);
    glVertex2f(15.7277, 8.0183);
    glEnd();

    ///14
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 7.8052);
    glVertex2f(15.7277, 7.8052);
    glEnd();

    ///15
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 7.6065);
    glVertex2f(15.7277, 7.6065);
    glEnd();

    ///16
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 7.3808);
    glVertex2f(15.7277, 7.3808);
    glEnd();

    ///17
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 7.1732);
    glVertex2f(15.7277, 7.1732);
    glEnd();

    ///18
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(26,140,184);
    glVertex2f(14.6921, 6.9588);
    glVertex2f(15.7277, 6.9588);
    glEnd();
}

void building8_4()
{
    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(124,104,123);
    glVertex2f(13.6018, 8.8974);
    glVertex2f(13.6020, 6.7870);
    glVertex2f(14.6921, 6.7870);
    glVertex2f(14.6921, 8.6119);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(102,41,70);
    glVertex2f(13.6018, 8.8974);
    glVertex2f(13.6020, 6.7870);
    glVertex2f(13.6020, 6.7870);
    glVertex2f(14.6921, 6.7870);
    glVertex2f(14.6921, 6.7870);
    glVertex2f(14.6921, 8.6119);
    glVertex2f(14.6921, 8.6119);
    glVertex2f(13.6018, 8.8974);
    glEnd();

    ///glass
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(13.8773, 8.6119);
    glVertex2f(13.8773, 6.7870);
    glVertex2f(14.6921, 6.7870);
    glVertex2f(14.6921, 8.6119);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(102,41,70);
    glVertex2f(13.8773, 6.7870);
    glVertex2f(14.6921, 6.7870);
    glVertex2f(14.6921, 6.7870);
    glVertex2f(14.6921, 8.6119);
    glVertex2f(14.6921, 8.6119);
    glVertex2f(13.8773, 8.6119);
    glEnd();

    ///lines
    ///1
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 8.4220);
    glVertex2f(14.6907, 8.4220);
    glEnd();

    ///2
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 8.2226);
    glVertex2f(14.6907, 8.2226);
    glEnd();

    ///3
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 8.0307);
    glVertex2f(14.6907, 8.0307);
    glEnd();

    ///4
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 7.8276);
    glVertex2f(14.6907, 7.8276);
    glEnd();

    ///5
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 7.6204);
    glVertex2f(14.6907, 7.6204);
    glEnd();

    ///6
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 7.3993);
    glVertex2f(14.6907, 7.3993);
    glEnd();

    ///7
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 7.1924);
    glVertex2f(14.6907, 7.1924);
    glEnd();

    ///8
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(124,104,123);
    glVertex2f(13.8773, 6.9856);
    glVertex2f(14.6907, 6.9856);
    glEnd();
}

void building9_4()
{
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(55,101,208);
    glVertex2f(15.5935, 9.6839);
    glVertex2f(16.6238, 9.6839);
    glVertex2f(16.6237, 9.4973);
    glVertex2f(15.5935, 9.4973);
    glEnd();



    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(55,101,208);
    glVertex2f(15.2860, 9.4973);
    glVertex2f(16.8977, 9.4973);
    glVertex2f(16.8977, 6.7870);
    glVertex2f(15.2860, 6.7870);
    glEnd();


    ///windows
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(15.6083, 8.8890);
    glVertex2f(15.9657, 8.8890);
    glVertex2f(15.9657, 9.1610);
    glVertex2f(15.6083, 9.1610);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(16.2649, 8.8890);
    glVertex2f(16.6223, 8.8890);
    glVertex2f(16.6223, 9.1610);
    glVertex2f(16.2649, 9.1610);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(15.6083, 8.3284);
    glVertex2f(15.9657, 8.3284);
    glVertex2f(15.9657, 8.6004);
    glVertex2f(15.6083, 8.6004);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(16.2649, 8.3284);
    glVertex2f(16.6223, 8.3284);
    glVertex2f(16.6223, 8.6004);
    glVertex2f(16.2649, 8.6004);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(15.6083, 7.7917);
    glVertex2f(15.9657, 7.7917);
    glVertex2f(15.9657, 8.0637);
    glVertex2f(15.6083, 8.0637);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(16.2649, 7.7917);
    glVertex2f(16.6223, 7.7917);
    glVertex2f(16.6223, 8.0637);
    glVertex2f(16.2649, 8.0637);
    glEnd();

    ///4
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(15.6083, 7.2669);
    glVertex2f(15.9657, 7.2669);
    glVertex2f(15.9657, 7.5389);
    glVertex2f(15.6083, 7.5389);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(16.2649, 7.2669);
    glVertex2f(16.6223, 7.2669);
    glVertex2f(16.6223, 7.5389);
    glVertex2f(16.2649, 7.5389);
    glEnd();
}

void building10_4()
{
    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(122,71,79);
    glVertex2f(16.8977, 8.0183);
    glVertex2f(18.2348, 8.0183);
    glVertex2f(18.2348, 6.7870);
    glVertex2f(16.8977, 6.7870);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(103,47,10);
    glVertex2f(16.8977, 8.0183);
    glVertex2f(18.2348, 8.0183);
    glVertex2f(18.2348, 8.0183);
    glVertex2f(18.2348, 6.7870);
    glVertex2f(18.2348, 6.7870);
    glVertex2f(16.8977, 6.7870);
    glVertex2f(16.8977, 6.7870);
    glVertex2f(16.8977, 8.0183);
    glEnd();

    ///Windows
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(17.0617, 7.5924);
    glVertex2f(17.4190, 7.5924);
    glVertex2f(17.4190, 7.8644);
    glVertex2f(17.0617, 7.8644);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(17.7079, 7.5924);
    glVertex2f(18.0652, 7.5924);
    glVertex2f(18.0652, 7.8644);
    glVertex2f(17.7079, 7.8644);
    glEnd();

    ///door
    glBegin(GL_POLYGON);
    glColor3ub(73,44,0);
    glVertex2f(17.3671, 7.2742);
    glVertex2f(17.8115, 7.2742);
    glVertex2f(17.8114, 6.7870);
    glVertex2f(17.3675, 6.7870);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(73,44,0);
    glVertex2f(17.3671, 7.2742);
    glVertex2f(17.8115, 7.2742);
    glVertex2f(17.8115, 7.2742);
    glVertex2f(17.8114, 6.7870);
    glVertex2f(17.8114, 6.7870);
    glVertex2f(17.3675, 6.7870);
    glVertex2f(17.3675, 6.7870);
    glVertex2f(17.3671, 7.2742);
    glEnd();
}

void building11_4()
{
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(181,222,16);
    glVertex2f(21.2438, 10.6817);
    glVertex2f(21.9511, 10.6817);
    glVertex2f(21.9511, 10.4951);
    glVertex2f(21.2438, 10.4952);
    glEnd();



    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(181,222,16);
    glVertex2f(20.1060, 6.7870);
    glVertex2f(21.9511, 6.7870);
    glVertex2f(21.9511, 10.4949);
    glVertex2f(20.1060, 10.4952);
    glEnd();



    ///glass
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(20.1060, 10.4952);
    glVertex2f(20.1060, 6.7870);
    glVertex2f(20.6495, 6.7870);
    glVertex2f(20.6495, 10.4952);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(15);
    glColor3ub(151,113,115);
    glVertex2f(20.1060, 10.4952);
    glVertex2f(20.1060, 6.7870);
    glVertex2f(20.1060, 6.7870);
    glVertex2f(20.6495, 6.7870);
    glVertex2f(20.6495, 6.7870);
    glVertex2f(20.6495, 10.4952);
    glEnd();

    ///mid line
    glBegin(GL_LINES);
    glLineWidth(15);
    glColor3ub(151,113,115);
    glVertex2f(20.3760, 6.7870);
    glVertex2f(20.3760, 10.4949);
    glEnd();

    ///windows
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(20.9371, 9.9014);
    glVertex2f(21.2945, 9.9014);
    glVertex2f(21.2945, 10.1734);
    glVertex2f(20.9371, 10.1734);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(21.5937, 9.9014);
    glVertex2f(21.9511, 9.9014);
    glVertex2f(21.9511, 10.1734);
    glVertex2f(21.5937, 10.1734);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(20.9371, 9.3408);
    glVertex2f(21.2945, 9.3408);
    glVertex2f(21.2945, 9.6128);
    glVertex2f(20.9371, 9.6128);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(21.5937, 9.3408);
    glVertex2f(21.9511, 9.3408);
    glVertex2f(21.9511, 9.6128);
    glVertex2f(21.5937, 9.6128);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(20.9371, 8.8041);
    glVertex2f(21.2945, 8.8041);
    glVertex2f(21.2945, 9.0761);
    glVertex2f(20.9371, 9.0761);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(21.5937, 8.8041);
    glVertex2f(21.9511, 8.8041);
    glVertex2f(21.9511, 9.0761);
    glVertex2f(21.5937, 9.0761);
    glEnd();

    ///4
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(20.9371, 8.2793);
    glVertex2f(21.2945, 8.2793);
    glVertex2f(21.2945, 8.5513);
    glVertex2f(20.9371, 8.5513);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(21.5937, 8.2793);
    glVertex2f(21.9511, 8.2793);
    glVertex2f(21.9511, 8.5513);
    glVertex2f(21.5937, 8.5513);
    glEnd();

    ///door
    glBegin(GL_POLYGON);
    glColor3ub(73,44,0);
    glVertex2f(21.3113, 6.7870);
    glVertex2f(21.9511, 6.7870);
    glVertex2f(21.9511, 7.9141);
    glVertex2f(21.3135, 7.9141);
    glEnd();


}

void building12_4()
{


    ///Structure
    glBegin(GL_POLYGON);
    glColor3ub(255,154,0);
    glVertex2f(21.9511, 6.7870);
    glVertex2f(23.9523, 6.7870);
    glVertex2f(23.9523, 11.7904);
    glVertex2f(21.9511, 11.7904);
    glEnd();



    ///windows
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 11.1381);
    glVertex2f(22.6877, 11.1381);
    glVertex2f(22.6877, 11.4101);
    glVertex2f(22.3303, 11.4101);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 11.1381);
    glVertex2f(23.6065, 11.1381);
    glVertex2f(23.6065, 11.4101);
    glVertex2f(23.2492, 11.4101);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 10.5706);
    glVertex2f(22.6877, 10.5706);
    glVertex2f(22.6877, 10.8426);
    glVertex2f(22.3303, 10.8426);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 10.5706);
    glVertex2f(23.6065, 10.5706);
    glVertex2f(23.6065, 10.8426);
    glVertex2f(23.2492, 10.8426);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 10.0314);
    glVertex2f(22.6877, 10.0314);
    glVertex2f(22.6877, 10.3034);
    glVertex2f(22.3303, 10.3034);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 10.0314);
    glVertex2f(23.6065, 10.0314);
    glVertex2f(23.6065, 10.3034);
    glVertex2f(23.2492, 10.3034);
    glEnd();

    ///4
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 9.4697);
    glVertex2f(22.6877, 9.4697);
    glVertex2f(22.6877, 9.7417);
    glVertex2f(22.3303, 9.7417);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 9.4697);
    glVertex2f(23.6065, 9.4697);
    glVertex2f(23.6065, 9.7417);
    glVertex2f(23.2492, 9.7417);
    glEnd();

    ///5
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 8.9304);
    glVertex2f(22.6877, 8.9304);
    glVertex2f(22.6877, 9.2024);
    glVertex2f(22.3303, 9.2024);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 8.9304);
    glVertex2f(23.6065, 8.9304);
    glVertex2f(23.6065, 9.2024);
    glVertex2f(23.2492, 9.2024);
    glEnd();

    ///6
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 8.3779);
    glVertex2f(22.6877, 8.3779);
    glVertex2f(22.6877, 8.6499);
    glVertex2f(22.3303, 8.6499);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 8.3779);
    glVertex2f(23.6065, 8.3779);
    glVertex2f(23.6065, 8.6499);
    glVertex2f(23.2492, 8.6499);
    glEnd();

    ///7
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 7.8169);
    glVertex2f(22.6877, 7.8169);
    glVertex2f(22.6877, 8.0889);
    glVertex2f(22.3303, 8.0889);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(23.2492, 7.8169);
    glVertex2f(23.6065, 7.8169);
    glVertex2f(23.6065, 8.0889);
    glVertex2f(23.2492, 8.0889);
    glEnd();

    ///8
    glBegin(GL_POLYGON);
    glColor3ub(196, 245, 238);
    glVertex2f(22.3303, 7.2814);
    glVertex2f(22.6877, 7.2814);
    glVertex2f(22.6877, 7.5534);
    glVertex2f(22.3303, 7.5534);
    glEnd();

    ///door
    glBegin(GL_POLYGON);
    glColor3ub(73,44,0);
    glVertex2f(23.2571, 6.7870);
    glVertex2f(23.6144, 6.7870);
    glVertex2f(23.6144, 7.3828);
    glVertex2f(23.2571, 7.3828);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(187,204,221);
    glVertex2f(23.2571, 6.7870);
    glVertex2f(23.6144, 6.7870);
    glVertex2f(23.6144, 6.7870);
    glVertex2f(23.6144, 7.3828);
    glVertex2f(23.6144, 7.3828);
    glVertex2f(23.2571, 7.3828);
    glVertex2f(23.2571, 7.3828);
    glVertex2f(23.2571, 6.7870);
    glEnd();
}

void roadsidespace4()
{
    ///1
    glBegin(GL_POLYGON);
    glColor3ub(132, 149, 141);
    glVertex2f(0, 6.7870);
    glVertex2f(0, 6.4468);
    glVertex2f(30, 6.4468);
    glVertex2f(30, 6.7870);
    glEnd();

    ///2
    glBegin(GL_POLYGON);
    glColor3ub(132, 149, 141);
    glVertex2f(0, 5.3310);
    glVertex2f(0, 4.8904);
    glVertex2f(30, 4.8904);
    glVertex2f(30, 5.3310);
    glEnd();

    ///3
    glBegin(GL_POLYGON);
    glColor3ub(132, 149, 141);
    glVertex2f(0, 2.7833);
    glVertex2f(0, 2.2101);
    glVertex2f(30, 2.2101);
    glVertex2f(30, 2.7833);
    glEnd();

    ///4
    glBegin(GL_POLYGON);
    glColor3ub(132, 149, 141);
    glVertex2f(0.0000, 0.9617);
    glVertex2f(0.0000, 0.6012);
    glVertex2f(30.0000, 0.6012);
    glVertex2f(30.0000, 0.9617);
    glEnd();
}



/// Scenario display functions

void MorningDisplay1()
{
    sky();
    sun();
    gasballon();
    cloud();
    roadsidespace();
    mainroad();
    groundline();
    building1();
    building2();
    building3();
    building4();
    building5();
    building7();
    building6();
    building8();
    building9();
    building10();
    hospital();
    building11();
    school();
    extraPortionOfTunnel();
    schoolBus2();
    FireCar(1.2,eDis2,0);
    Ambulance(0,0);
    Ambulance2(0,0);
    FireCar2(2.2,eDis,-0.8);
    policeCar();
    schoolBus();
    tree();
    tunnel();
    zebraCrossing();
    car3();
    bus3(0.5,0);
    SportsCar(posLR);
    carY(1,0);
    sportsCar2();
    car1();
    bus4(1.0,0);
    trafficLight(0,0);
    Plane();

}

void NightDisplay1()
{
    skyNight();
    cloud();
    Moon(0,0);
    gasballon();
    roadsidespace();
    mainroad();
    groundline();
    building1();
    building2();
    building3();
    building4();
    building5();
    building7();
    building6();
    building8();
    building9();
    building10();
    hospital();
    building11();
    school();
    school();
    extraPortionOfTunnel();
    schoolBus2();
    FireCar(1.2,eDis2,0);
    Ambulance(0,0);
    Ambulance2(0,0);
    FireCar2(2.2,eDis,-0.8);
    policeCar();
    schoolBus();
    tree();
    tunnel();
    zebraCrossing();
    car3();
    bus3(0.5,0);
    SportsCar(posLR);
    carY(1,0);
    sportsCar2();
    car1();
    bus4(1.0,0);
    trafficLight(0,0);
    skyStar();
    Plane();  skyNight();
    cloud();
    Moon(0,0);
    gasballon();
    roadsidespace();
    mainroad();
    groundline();
    building1();
    building2();
    building3();
    building4();
    building5();
    building7();
    building6();
    building8();
    building9();
    building10();
    hospital();
    building11();
    school();
    school();
    extraPortionOfTunnel();
    schoolBus2();
    FireCar(1.2,eDis2,0);
    Ambulance(0,0);
    Ambulance2(0,0);
    FireCar2(2.2,eDis,-0.8);
    policeCar();
    schoolBus();
    tree();
    tunnel();
    zebraCrossing();
    car3();
    bus3(0.5,0);
    SportsCar(posLR);
    carY(1,0);
    sportsCar2();
    car1();
    bus4(1.0,0);
    trafficLight(0,0);
    skyStar();
    Plane();
}


/// 2nd scenario

void MorningDisplay2()
{
    sky2();
    sun();
    cloud();
    roadsidespace2();
    mainroad2();
    groundline2();
    extraGrid();
    Building2();
    Building1();
    Building4();
    Building3();

    if(firstFire == true) {
    FireAnimation(9.2105,5.2621);
    }
    if(secondFire == true) {
//    fireSound();
    FireAnimation(17.4140,5.0702);
    }
    if(thirdFire == true) {
//        fireSound();
    FireAnimation(22.8495,6.4066);
    }

    Ambulance(0,-2.1);
    FireCarS2();
    Ambulance2(0,-3);
    tunnel2();
}

void NightDisplay2()
{
    skyNight();
    skyStar();
    cloud();
    Moon(-12,-1);
    roadsidespace2();
    mainroad2();
    groundline2();
    extraGrid();
    Building2();
    Building1();
    Building4();
    Building3();

    if(firstFire == true) {
//    fireSound();
    FireAnimation(9.2105,5.2621);
    }
    if(secondFire == true) {
    FireAnimation(17.4140,5.0702);
    }
    if(thirdFire == true) {
    FireAnimation(22.8495,6.4066);
    }

    Ambulance(0,-2.1);
    FireCarS2();
    Ambulance2(0,-3);
    tunnel2();
}

/// 3rd scenario

void MorningDisplay3() {
    sky3();
    cloud();
    roadsidespace3();
    mainroad3();
    building1_3();
    building2_3();
    building3_3();
    hospital3();
    building5_3();
    building4_3();
    bus3(.5,-2);
    car1();
    bus4(3,-2);
    Ambulance(1,0.5);
    Ambulance(4,0.7);
    Ambulance(7,0.3);

    Ambulance2(1,0);
    Ambulance2(4,0.2);
    Ambulance2(8,0);
    tree3();
}

void NightDisplay3() {
    night3();
    skyStar();
    cloud();

    roadsidespace3();
    mainroad3();
    building1_3();
    building2_3();
    building3_3();
    hospital3();
    building5_3();
    building4_3();
    bus3(1,-2);
    car1();
    bus4(3,-2);
    Ambulance(1,0.5);
    Ambulance(4,0.7);
    Ambulance(7,0.3);

    Ambulance2(1,0);
    Ambulance2(4,0.2);
    Ambulance2(8,0);
    tree3();

}
///
void MorningDisplay4() {
    sky4();
    Plane();
    cloud();
    gasballon();
    Roadsidespace4();
    mainroad4();
    building1_4();
    building2_4();
    building3_4();
    building4_4();
    building5_4();
    building6_4();
    building7_4();
    building8_4();
    building9_4();
    building10_4();
    building11_4();
    building12_4();

    Ambulance2(0,2);
    FireCar(1.2,eDis2,0);
    Ambulance(0,0);

    carY(1,0);
    car1();
    bus3(2,0);
    policeCar();
    car1_4();
    bus4(0.5,0);

    trafficLight(2,2.3);

}

void NightDisplay4() {
    night3();
    skyStar();
    Plane();
    cloud();
    gasballon();
    Roadsidespace4();
    mainroad4();
    building1_4();
    building2_4();
    building3_4();
    building4_4();
    building5_4();
    building6_4();
    building7_4();
    building8_4();
    building9_4();
    building10_4();
    building11_4();
    building12_4();

    Ambulance2(0,2);
    FireCar(1.2,eDis2,0);
    Ambulance(0,0);

    carY(1,0);
    car1();
    bus3(2,0);
    policeCar();
    car1_4();
    bus4(0.5,0);

    trafficLight(2,2.3);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    /// day
    if(dis1) {
        MorningDisplay1();
    }

    /// Night
    else if(dis2){
        NightDisplay1();
    }

    else if(dis3){
        MorningDisplay2();
    }

    else if(dis4) {
        NightDisplay2();
    }
    else if(dis5) {
        MorningDisplay3();
    }
    else if(dis6) {
        NightDisplay3();

    } else if(dis7) {
        MorningDisplay4();
    }
    else if(dis8) {
        NightDisplay4();
    }
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {

    switch(key) {
    /// keys for manual
    case 'A':
    case 'a':
        speedRL += 0.2f;
        break;

    case 'D':
    case 'd':
        speedRL -= 0.2f;
        break;

    case 'R':
    case 'r':
        cc=0;
        break;
    case 'Y':
    case 'y':
        cc=1;
        break;
    case 'G':
    case 'g':
        cc=2;
        break;

        /// blue car L->r
    case 'L':
    case 'l':
        speedLR += 0.2;
        break;

    case 'J':
    case 'j':
        speedLR -= 0.2;
        break;

    case 'S':
    case 's':
        ok = true;
       isSound();
        break;

    case '1':
        dis1 = true;
        dis2 = false;
        dis3 = false;
        dis4 = false;
        dis5 = false;
        dis6 = false;
        dis7 = false;
        dis8 = false;
        break;
    case '2':
        dis1 = false;
        dis2 = true;
        dis3 = false;
        dis4 = false;
        dis5 = false;
        dis6 = false;
        dis7 = false;
        dis8 = false;
        break;
    case '3':
        dis1 = false;
        dis2 = false;
        dis3 = true;
        dis4 = false;
        dis5 = false;
        dis6 = false;
        dis7 = false;
        dis8 = false;
        break;
    case '4':
        dis1 = false;
        dis2 = false;
        dis3 = false;
        dis4 = true;
        dis5 = false;
        dis6 = false;
        dis7 = false;
        dis8 = false;
        break;

    case '5':
        dis1 = false;
        dis2 = false;
        dis3 = false;
        dis4 = false;
        dis5 = true;
        dis6 = false;
        dis7 = false;
        dis8 = false;
        break;

    case '6':
        dis1 = false;
        dis2 = false;
        dis3 = false;
        dis4 = false;
        dis5 = false;
        dis6 = true;
        dis7 = false;
        dis8 = false;
        break;
    case '7':
        dis1 = false;
        dis2 = false;
        dis3 = false;
        dis4 = false;
        dis5 = false;
        dis6 = false;
        dis7 = true;
        dis8 = false;
        break;

    case '8':
        dis1 = false;
        dis2 = false;
        dis3 = false;
        dis4 = false;
        dis5 = false;
        dis6 = false;
        dis7 = false;
        dis8 = true;
        break;


    case 'Q':
    case 'q':

        firstFire = true;
        secondFire = false;
        thirdFire = false;
        break;

    case 'W':
    case 'w':

        firstFire = false;
        secondFire = true;
        thirdFire = false;
        break;

    case 'E':
    case 'e':

        firstFire = false;
        secondFire = false;
        thirdFire = true;
        break;

    case 'F':
    case 'f':

        firstFire = true;
        secondFire = true;
        thirdFire = true;
        break;

    case 'T':
    case 't':
        firstFire = false;
        secondFire = false;
        thirdFire = false;
        break;


    case 'P':
    case 'p':
        fireCarSpeed+= 0.1;
        break;
    case 'O':
    case 'o':
        fireCarSpeed -= 0.1;
        break;

    case 'I':
    case 'i':
        waterfireX = false;
        waterfireXY = false;
        break;

    }
glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
    waterfireX = true;
    waterfireXY = false;
    }
    if(button == GLUT_RIGHT_BUTTON) {
    waterfireX = false;
    waterfireXY = true;
    }
    glutPostRedisplay();
    }


void updateTrafficLight(int val) {

    /// Traffic light
    cc = (cc+1)%3;

    if(cc == 0) {
        Red = true;
        Yellow = false;
        Green = false;
    } else if(cc==1) {
    Red = true;
        Yellow = true;
        Green = false;
    } else {
    Red = false;
        Yellow = false;
        Green = true;

    }
    glutPostRedisplay();
    glutTimerFunc(1200,updateTrafficLight,0);

}

void update(int val) {

    /// R -> L
    posRL += speedRL * -1;
    if(posRL < -30) {
        posRL = 30.0f;
    }

    /// L -> R
     posLR -= speedLR * -1;
    if (posLR > 30) {
        posLR = -30.0f;
    }
    if(posLR < 5.0f && posLR > 2.0f) {
        if((Red || Yellow)) {
        speedLR = 0;
    } else {
        speedLR = 0.5f;
    }
    }
    /// emergency
    ///1
    eDis -= speed * -1;
    if(eDis >= 28.9638) {
        eDis = -28.9638f;
    }

    ///2
    eDis2 += speed * -1;
    if(eDis2 < - 28.9638) {
        eDis2 = 28.9638;
    }


    /// plane

    ep += sp * -1;
    if(ep < -30) {
        ep = 30.0f;
    }

    /// bus3
    posbus3LR -= speedLRbus3 * -1;
    if (posbus3LR > 30) {
        posbus3LR = -30.0f;
    }
    if(posbus3LR < 11.0f && posbus3LR > 10.0f) {
        if((Red || Yellow)) {
        speedLRbus3 = 0;
    } else {
        speedLRbus3 = 0.3f;
    }
    }

    ///bus4
    posbus4RL += speedLRbus4 * -1;
    if(posbus4RL < -30) {
        posbus4RL = 30.0f;
    }
    if(posbus4RL < -7.0f && posbus4RL > -8.0f) {
        if((Red || Yellow)) {
        speedLRbus4 = 0;
    } else {
        speedLRbus4 = 0.3f;
    }
    }
    /// sports car 2

    posRL2 += speedRL2 * -1;
    if(posRL2 < -28) {
        posRL2 = 28.0f;
    }
    if(posRL2 < -3.0f && posRL2 > -4.0f) {
        if((Red || Yellow)) {
        speedRL2 = 0;
    } else {
        speedRL2= 0.3f;
    }
    }
    glutPostRedisplay();
    glutTimerFunc(100,update,0);

}

void updateFire(int val)
{
    _angle1+=1.0f;
    if(_angle1 > 360.0)
    {
        _angle1-=360;
    }
    glutPostRedisplay();
    glutTimerFunc(10000, updateFire, 0);
}

void updateFireCarScenario(int val) {
      /// scenario 2
    /// firecar
    fireCarDisS2 -= fireCarSpeed * -1;
    if (fireCarDisS2 > 30) {
        fireCarDisS2 = -30.0f;
    }
    if(fireCarDisS2 > 1.5 && (waterfireX == true || waterfireXY == true)) {
        firstFire = false;
    }
    if(fireCarDisS2 > 8.0 && (waterfireX == true || waterfireXY == true)) {
        secondFire = false;
    }
    if(fireCarDisS2 > 14.5 && waterfireXY == true) {
        thirdFire = false;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateFireCarScenario, 0);
}

void updateEmergencyLight(int val) {
    amRed = 1.0f - amRed;
    amBlue = 1.0f - amBlue;
    glutPostRedisplay();
    glutTimerFunc(110, updateEmergencyLight, 0);
}


void movegasballon(int value)
{
    obj_gasballon += 0.004;
    if(obj_cloud > 30)
    {
        obj_cloud = 2;
    }
    glutPostRedisplay();
    glutTimerFunc(10, movegasballon, 0);
}

void moveCloud(int value)
{
    obj_cloud-= 0.004;
    if(obj_cloud<-14)
    {
        obj_cloud = 19;
    }
    glutPostRedisplay();
    glutTimerFunc(10, moveCloud, 0);
}

void commands()
{
    cout << "Instruction:\nThis is our Graphics Project : SafetyFirst Road System\n";
    cout << "This project was created by :";

    cout << "\n\nMOHAMMED ISTISHAD ALAM TISHAD (22-46130-1)";
    cout << "\nRUBAYIT ALAM                    (22-46893-1)";
    cout << "\nLAMIA HAQUE CHANDNI             (22-46747-1)";
    cout << "\nNUZHAT TABASSUM                 (21-45909-3)";
    cout << "\n\nPlease continue to enjoy the project by Pressing :\n";
    cout << "..................................................";
    cout << "\n(A/a) for Increasing velocity of Red police Car\n";
    cout << "(D/d) for Decreasing velocity of Red police Car \n";
    cout << "\n..............................................";
    cout << "\n(R/r) for turn on (RED) light of Traffic light  ";
    cout << "\n(Y/y) for turn on (YELLOW) light of Traffic light";
    cout << "\n(G/g) for turn on (GREEN) light of Traffic  \n";
    cout << "\n..............................................";
    cout << "\n(L/l) for increasing velocity of racing BLUE Car & pink car  ";
    cout << "\n(J/j) for decreasing velocity of racing BLUE Car & pink car \n";
    cout << "\n..............................................";
    cout << "\n(S/s) for traffic road sound                ";
    cout << "\n..............................................";
    cout << "\n(1) for 1st scenario Morning              ";
    cout << "\n(2) for 1st scenario Night                ";
    cout << "\n(3) for 2nd scenario Morning              ";
    cout << "\n(4) for 2nd scenario Night                ";
    cout << "\n(5) for 3rd scenario Morning              ";
    cout << "\n(6) for 3rd scenario Night                ";
    cout << "\n(7) for 4th scenario Morning              ";
    cout << "\n(8) for 4th scenario Night                ";
    cout << "\n..............................................";
    cout << "\n(Q/q) for First Fire ";
    cout << "\n(W/w) for Second Fire ";
    cout << "\n(E/e) for third Fire ";
    cout << "\n(T/t) for turn on All Fire ";
    cout << "\n(F/f) for turn off all Fire ";
    cout << "\n(O/o) for increase velocity of Fire Car";
    cout << "\n(P/p) for decrease velocity of Fire Car";
    cout << "\n..............................................";
    cout << "\n RIGHT CLICK for Spray water X direction    ";
    cout << "\n LEFT CLICK for Spray water XY direction    ";
    cout << "\n(I/i) stop Spraying water ";
    cout << "\n..............................................";


}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,30,0,15);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main (int argc, char** argv) {
commands();
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutCreateWindow("Safety First Road System");
glutInitWindowSize(1200, 900);
glutInitWindowPosition(50, 50);
glutTimerFunc(100,update,0);
glutTimerFunc(0,updateEmergencyLight,0);
glutTimerFunc(100,updateTrafficLight,0);
glutTimerFunc(1000,updateFire,0);
glutTimerFunc(1000,updateFireCarScenario,0);
glutTimerFunc(100, moveCloud, 0);
glutTimerFunc(100, movegasballon, 0);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMouseFunc(handleMouse);
glutDisplayFunc(display);
glutMainLoop();

return 0;
}


