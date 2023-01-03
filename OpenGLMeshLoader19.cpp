#include "TextureBuilder.h"
#include "Model_3DS.h"
#include "GLTexture.h"
#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <playsoundapi.h>

#include <string>


int WIDTH = 1280;
int HEIGHT = 720;


int fac = 1;
int m = 1;

int X10 = 0;
int Y10 = 0;
int Z10 = 0;

float Zb=0;

float X1 = 0;
float Y1 = 0;
float Z1 = 0;

float X2 = 0;
float Y2 = 0;
float Z2 = 0;

float X3 = 0;
float Y3 = 0;
float Z3 = 0;

float X4 = 0;
float Y4 = 0;
float Z4 = 0;

float X5 = 0;
float Y5 = 0;
float Z5 = 0;

float X6 = 0;
float Y6 = 0;
float Z6 = 0;

float X7 = 0;
float Y7 = 0;
float Z7 = 0;


float X8 = 0;
float Y8 = 0;
float Z8 = 0;



float X9 = 0;
float Y9 = 0;
float Z9 = 0;


float X0 = 0;
float Y0 = 0;
float Z0 = 0;


float factor = 1;

float Xsky = 80;
float Zsky = 0;


float Car1X = 0;

float Car1Z = 0;

float Car2X = 0;
float Car2Z = 0;

float Car3X = 0;
float Car3Z = 0;
float Car4X = 0;
float Car4Z = 0;
float Car5X = 0;
float Car5Z = 0;
float Car6X = 0;
float Car6Z = 0;

float X = 0;
float Y = 0;
float Z = 0;

float boat1z = 0;
float boat2z = 0;
float boat3z = 0;
float boat4z = 0;
float boat5z = 0;
float boat6z = 0;


int cameraX = 2;
int cameraY = 6;
int cameraZ = 27;
GLuint tex;
char title[] = "3D Model Loader Sample";

// 3D Projection Options
GLdouble fovy = 45.0;
GLdouble aspectRatio = (GLdouble)WIDTH / (GLdouble)HEIGHT;
GLdouble zNear = 0.1;
GLdouble zFar = 100;





class Vector
{
public:
	GLdouble x, y, z;
	Vector() {}
	Vector(GLdouble _x, GLdouble _y, GLdouble _z) : x(_x), y(_y), z(_z) {}
	//================================================================================================//
	// Operator Overloading;
	//  In C++ you can override the behavior of operators for you class objects. //
	// Here we are overloading the += operator to add a given value to all vector coordinates.        //
	//================================================================================================//
	void operator +=(float value)
	{
		x += value;
		y += value;
		z += value;
	}
};

class Vector3f {
public:
	float x, y, z;

	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f operator+(Vector3f& v) {
		return Vector3f(x + v.x, y + v.y, z + v.z);
	}

	Vector3f operator-(Vector3f& v) {
		return Vector3f(x - v.x, y - v.y, z - v.z);
	}

	Vector3f operator*(float n) {
		return Vector3f(x * n, y * n, z * n);
	}

	Vector3f operator/(float n) {
		return Vector3f(x / n, y / n, z / n);
	}

	Vector3f unit() {
		return *this / sqrt(x * x + y * y + z * z);
	}

	Vector3f cross(Vector3f v) {
		return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
};

class Camera {
public:
	Vector3f eye, center, up;
	float eyeX = 3.5f;
	float eyeY = 6.0f;
	float eyeZ = 2.0f;
	float centerX = 0.0f;
	float centerY = 0.0f;
	float centerZ = 0.0f;
	float upX = 0.0f;
	float upY = 1.0f;
	float upZ = 0.0f;


Camera(float eyeX = 1, float eyeY = 5.5f, float eyeZ = 27, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f) {
	eye = Vector3f(eyeX, eyeY, eyeZ);
	center = Vector3f(centerX, centerY, centerZ);
	up = Vector3f(upX, upY, upZ);
}

void moveX(float d) {
	Vector3f right = up.cross(center - eye).unit();
	eye = eye + right * d;
	center = center + right * d;
}






void moveY(float d) {
	eye = eye + up.unit() * d;
	center = center + up.unit() * d;
}

void moveZ(float d) {
	Vector3f view = (center - eye).unit();
	eye = eye + view * d;
	center = center + view * d;
}
//
//void rotateX(float a) {
//	Vector3f view = (center - eye).unit();
//	Vector3f right = up.cross(view).unit();
//	view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
//	up = view.cross(right);
//	center = eye + view;
//}
//
//void rotateY(float a) {
//	Vector3f view = (center - eye).unit();
//	Vector3f right = up.cross(view).unit();
//	view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
//	right = view.cross(up);
//	center = eye + view;
//}

void up1() {

	eye.x = 0;
	eye.y = 11;
	eye.z = 2;

}

void side1() {

	eye.x = 7.5;
	eye.y = 2.5;
	eye.z = 0;
}

void front() {
	eye.x = 0;
	eye.z = 8;
	eye.y = 3.2;
}
void move() {
	
	eye.z -= 1.5 * factor;
	center.z -= 1.5 * factor;

	
	
}



void move2() {

	eye.z = 27;
	center.z = 0 ;





}

void move4() {

	eye.y = 15;
	

}

void move5() {

	eye.y = 5.5;


}
void move1() {
	eye.x = X + 1.3,eye.y =Y + 5.5, center.x = 0.0f, center.y = 0.0f,
	eye.z = Z + 27;
	/*center.z -= 1;*/



}

void moveXLeft() {

	eye.x -= 0.5;
	



}
void moveXRight() {

	eye.x += 0.5;




}
void firstPerson() {

	eye.z = Z+18 ;
	center.z = Z -10;

	center.x = X  ;
	center.y = Y+3 ;

	eye.x = X+1.5;
	eye.y = Y+3.4;

}
void lost() {

	eye.x = 100;
	eye.y = 200;
	eye.z = 200;




}


void look() {
	gluLookAt(
		eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		up.x, up.y, up.z
	);
}






};


Camera camera;


Vector Eye(2, 5, 27);
Vector At(0, 0, 0);
Vector Up(0, 1, 0);

int cameraZoom = 0;

// Model Variables
Model_3DS model_house;
Model_3DS model_tree;
Model_3DS model_robot;
//Model_3DS model_grass;
//Model_3DS model_car1;
Model_3DS model_streetLamp;

Model_3DS model_boat;

Model_3DS model_boat2;

Model_3DS model_dragon;

Model_3DS model_shoe;

Model_3DS model_glue;

Model_3DS model_car;
Model_3DS model_skull;
Model_3DS model_mount;
// Textures
GLTexture tex_ground;
GLTexture tex_street;
GLTexture tex_sea;


//=======================================================================
// Lighting Configuration Function
//=======================================================================
void InitLightSource()
{
	// Enable Lighting for this OpenGL Program
	glEnable(GL_LIGHTING);

	// Enable Light Source number 0
	// OpengL has 8 light sources
	glEnable(GL_LIGHT0);

	// Define Light source 0 ambient light
	GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	// Define Light source 0 diffuse light
	GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	// Define Light source 0 Specular light
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Finally, define light source 0 position in World Space
	GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

//=======================================================================
// Render Ground Function
//=======================================================================
void RenderGround()
{
	glDisable(GL_LIGHTING);	// Disable lighting 

	glColor3f(0.6, 0.6, 0.6);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing
	if (m == 1) {
		glBindTexture(GL_TEXTURE_2D, tex_street.texture[0]);	// Bind the ground texture
	}

	if (m == 2) {
		glBindTexture(GL_TEXTURE_2D, tex_sea.texture[0]);	// Bind the ground texture
	}

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);	// Set quad normal direction.
	glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
	glVertex3f(-20, 0, -400);
	glTexCoord2f(5, 0);
	glVertex3f(20, 0, -400);
	glTexCoord2f(5, 5);
	glVertex3f(20, 0, 20);
	glTexCoord2f(0, 5);
	glVertex3f(-20, 0, 20);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING);	// Enable lighting again for other entites coming throung the pipeline.

	glColor3f(1, 1, 1);	// Set material back to white instead of grey used for the ground texture.
}
void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.look();
}
unsigned int m_screenWidth = 800;
unsigned int m_screenHeight = 600;
float m_textColorR = 1.0f;
float m_textColorG = 1.0f;
float m_textColorB = 1.0f;
void* m_glutFont = GLUT_BITMAP_TIMES_ROMAN_24;
unsigned int m_lineHeight = 15;

void drawText(const std:: string& text, const unsigned int x, const unsigned int y, const float r, const float g, const float b)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, m_screenWidth, 0, m_screenHeight, 0, 15);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(r, g, b);
	glRasterPos2i(x, y);
	for (const char c : text)
		glutBitmapCharacter(m_glutFont, (int)c);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}




int i = 0;
int A = 1;
int B = 0;
int C = 0;

int E = 800;
//=======================================================================
// Display Function
//=======================================================================
void Display(void)
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	setupCamera();

	drawText("SCORE = " + std::to_string(i), 380, 560, A, B, C);

	//GLfloat lightIntensity[] = { 5.7, 5.7, 0.5, 2.0f };
	//GLfloat lightPosition[] = { 0, 0, 0, 1 };


	//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);

	
	
		drawText("GAME OVER ", E, 360, 1, 1, 1);
	

	if (m == 1) {

		GLfloat lightIntensity2[] = { 0.7, 0.7, 0.7, 1.0f };
		GLfloat lightPosition2[] = { 0, 100, 0, 0};


		GLfloat lightSpot[] = { 0, 1, -80 };
		GLfloat lightEX[] = { 128 };
		GLfloat lightCUTOFF[] = { 180 };



		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightSpot);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 120);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180);


		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity2);

	}
	else {
		GLfloat lightIntensity2[] = { 0.7, 0.7, 0.4, 1.0f };
		GLfloat lightPosition2[] = { 0, 100, -100, 0 };




		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity2);

	
	
	}


	// Draw Ground
	RenderGround();

	//draw robot
	glPushMatrix();

	glTranslatef(X, Y, Z);
	glTranslatef(0, 1, 16);
	glScalef(0.9, 0.9, 0.9);
	glRotatef(180.f, 0, 1, 0);
	model_robot.Draw();
	glPopMatrix();


	if (m == 2) {
		//boat
	glPushMatrix();
	glTranslatef(X, Y, Z);
	glTranslatef(1.3, 1, 20);

	glScalef(0.02, 0.025, 0.016);
	glRotatef(90.f, 0, 1, 0);
	model_boat.Draw();
	glPopMatrix();





	glPushMatrix();
	glTranslatef(13, 0, -7);
	glScalef(1, 17, 150);
	glRotatef(270.0f, 0, 1, 0);
	model_mount.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-13.3, 0, -7);
	glScalef(1, 12, 150);
	glRotatef(90.0f, 0, 1, 0);
	model_mount.Draw();
	glPopMatrix();
	



		//draw boatObstacle1
		glPushMatrix();
		
		glTranslatef(Car2X, 0, Car2Z);
		glTranslatef(4.5, 0, -21);
		glScalef(0.05, 0.04, 0.03);
		glRotatef(90.f, 0, 1, 0);
		model_boat.Draw();
		glPopMatrix();

		//draw boatObstacle2
		glPushMatrix();
		
		glTranslatef(Car3X, 0, Car3Z);
		glTranslatef(-1.8, 0, -41);
		glScalef(0.04, 0.04, 0.03);
		glRotatef(90.f, 0, 1, 0);
		model_boat.Draw();
		glPopMatrix();

		//draw boatObstacle3
		glPushMatrix();
		
		glTranslatef(Car4X, 0, Car4Z);
		glTranslatef(4.2, 0, -61);
		glScalef(0.04, 0.04, 0.03);
		glRotatef(90.f, 0, 1, 0);
		model_boat.Draw();
		glPopMatrix();


		//draw boatObstacle4
		glPushMatrix();
		
		glTranslatef(Car5X, 0, Car5Z);
		glTranslatef(-3.7, 0, -81);
		glScalef(0.04, 0.04, 0.03);
		glRotatef(90.f, 0, 1, 0);
		model_boat.Draw();
		glPopMatrix();


		//draw boatObstacle5
		glPushMatrix();
		
		glTranslatef(Car6X, 0, Car6Z);
		glTranslatef(1.3, 0, -91);
		glScalef(0.04, 0.04, 0.03);
		glRotatef(90.f, 0, 1, 0);
		model_boat.Draw();
		glPopMatrix();

		//draw boatObstacle6
		glPushMatrix();
		
		glTranslatef(Car1X, 0, Car1Z);
		glTranslatef(-2, 0, -1);
		glScalef(0.05, 0.04, 0.03);
		glRotatef(90.f, 0, 1, 0);
		model_boat.Draw();
		glPopMatrix();


	}


	if (m == 1) {
		glPushMatrix();
		glTranslatef(X1, Y1, Z1);
		// Draw Tree Model
		//left1
		glPushMatrix();
		glTranslatef(-10, 0, -7);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();

		//left2
		glPushMatrix();
		glTranslatef(-10, 0, -36);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//left3
		glPushMatrix();
		glTranslatef(-10, 0, -65);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//left4
		glPushMatrix();

		glTranslatef(-10, 0, -94);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//left5
		glPushMatrix();

		glTranslatef(-10, 0, -123);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//left6
		glPushMatrix();

		glTranslatef(-10, 0, -152);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();

		//right1
		glPushMatrix();
		glTranslatef(10, 0, -7);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();


		//right2
		glPushMatrix();
		glTranslatef(10, 0, -36);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//right3
		glPushMatrix();
		glTranslatef(10, 0, -65);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//right4
		glPushMatrix();

		glTranslatef(10, 0, -94);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//right5
		glPushMatrix();

		glTranslatef(10, 0, -123);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();
		//right6
		glPushMatrix();

		glTranslatef(10, 0, -152);
		glScalef(1, 1, 1);
		glRotatef(90.0f, 0, 1, 0);
		model_tree.Draw();
		glPopMatrix();







		// Draw house Model

		//left1
		glPushMatrix();
		glTranslatef(-13, 0, 2);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();
		//left2
		glPushMatrix();
		glTranslatef(-14, 0, -22);
		glScalef(2, 2, 2);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();

		//left3
		glPushMatrix();
		glTranslatef(-13, 0, -55);
		glScalef(1.4, 1.4, 1.4);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();
		//left4
		glPushMatrix();
		glTranslatef(-13, 0, -79);
		glScalef(1.7, 1.7, 1.7);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();

		//left5
		glPushMatrix();

		glTranslatef(-13, 0, -110);
		glScalef(1.8, 1.8, 1.8);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();
		//left6
		glPushMatrix();

		glTranslatef(-13, 0, -135);
		glScalef(1.6, 1.6, 1.6);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();

		//right1
		glPushMatrix();
		glTranslatef(13, 0, 2);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(90.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();
		//right2
		glPushMatrix();
		glTranslatef(13, 0, -22);
		glScalef(2, 2, 2);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(90.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();

		//right3
		glPushMatrix();
		glTranslatef(13, 0, -55);
		glScalef(1.4, 1.4, 1.4);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();
		//right4
		glPushMatrix();
		glTranslatef(13, 0, -79);
		glScalef(1.7, 1.7, 1.7);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();

		//right5
		glPushMatrix();

		glTranslatef(13, 0, -110);
		glScalef(1.8, 1.8, 1.8);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();
		//right6
		glPushMatrix();

		glTranslatef(13, 0, -135);
		glScalef(1.6, 1.6, 1.6);
		glRotatef(90.f, 1, 0, 0);
		glRotatef(270.f, 0, 0, 1);
		model_house.Draw();
		glPopMatrix();




		//draw street lamp1
		glPushMatrix();


		glTranslatef(9, -1, 12);
		glScalef(0.5, 0.6, 0.5);
		glRotatef(180.f, 0, 1, 0);
		model_streetLamp.Draw();
		glPopMatrix();

		//draw street lamp2
		glPushMatrix();


		glTranslatef(-9, -1, 12);
		glScalef(0.5, 0.6, 0.5);

		model_streetLamp.Draw();
		glPopMatrix();

		//draw street lamp3
		glPushMatrix();


		glTranslatef(-9, -1, -40);
		glScalef(0.5, 0.6, 0.5);

		model_streetLamp.Draw();
		glPopMatrix();

		//draw street lamp4
		glPushMatrix();


		glTranslatef(9, -1, -42);
		glScalef(0.5, 0.6, 0.5);
		glRotatef(180.f, 0, 1, 0);
		model_streetLamp.Draw();
		glPopMatrix();

		




		//draw street lamp5
		glPushMatrix();


		glTranslatef(-9, -1, -62);
		glScalef(0.5, 0.6, 0.5);

		model_streetLamp.Draw();
		glPopMatrix();

		//draw street lamp6
		glPushMatrix();


		glTranslatef(9, -1, -62);
		glScalef(0.5, 0.6, 0.5);
		glRotatef(180.f, 0, 1, 0);
		model_streetLamp.Draw();
		glPopMatrix();

		glPopMatrix();





		//draw car
		glPushMatrix();

		glTranslatef(Car1X, 0, Car1Z);
		glTranslatef(3, 0, 0);
		glScalef(0.9, 0.9, 0.9);
		glRotatef(180.f, 0, 1, 0);
		model_car.Draw();
		glPopMatrix();

		//draw car2
		glPushMatrix();

		glTranslatef(Car2X, 0, Car2Z);
		glTranslatef(9, 0, -20);
		glScalef(0.9, 0.9, 0.9);
		glRotatef(180.f, 0, 1, 0);
		model_car.Draw();
		glPopMatrix();

		//draw car3
		glPushMatrix();

		glTranslatef(Car3X, 0, Car3Z);
		glTranslatef(3, 0, -40);
		glScalef(0.9, 0.9, 0.9);
		glRotatef(180.f, 0, 1, 0);
		model_car.Draw();
		glPopMatrix();

		//draw car4
		glPushMatrix();

		glTranslatef(Car4X, 0, Car4Z);
		glTranslatef(9, 0, -60);
		glScalef(0.9, 0.9, 0.9);
		glRotatef(180.f, 0, 1, 0);
		model_car.Draw();
		glPopMatrix();


		//draw car5
		glPushMatrix();

		glTranslatef(Car5X, 0, Car5Z);
		glTranslatef(1, 0, -80);
		glScalef(0.9, 0.9, 0.9);
		glRotatef(180.f, 0, 1, 0);
		model_car.Draw();
		glPopMatrix();



		//draw car6
		glPushMatrix();

		glTranslatef(Car6X, 0, Car6Z);
		glTranslatef(6, 0, -90);
		glScalef(0.9, 0.9, 0.9);
		glRotatef(180.f, 0, 1, 0);
		model_car.Draw();
		glPopMatrix();

	}


	//skull1

	glPushMatrix();
	glTranslatef(X2, Y2, Z2);
	glTranslatef(2, 2.5, 0);
	glScalef(0.2, 0.2, 0.2);
	
	model_skull.Draw();
	glPopMatrix();

	//skull2

	glPushMatrix();
	glTranslatef(X3, Y3, Z3);
	glTranslatef(2, 2.5, -30);
	glScalef(0.2, 0.2, 0.2);

	model_skull.Draw();
	glPopMatrix();

	//skull3

	glPushMatrix();
	glTranslatef(X4, Y4, Z4);
	glTranslatef(2, 2.5, -60);
	glScalef(0.2, 0.2, 0.2);

	model_skull.Draw();
	glPopMatrix();



	//skull4

	glPushMatrix();
	glTranslatef(X5, Y5, Z5);
	glTranslatef(2, 2.5, -90);
	glScalef(0.2, 0.2, 0.2);

	model_skull.Draw();
	glPopMatrix();


	//skull5

	glPushMatrix();
	glTranslatef(X6, Y6, Z6);
	glTranslatef(2, 2.5, -120);
	glScalef(0.2, 0.2, 0.2);

	model_skull.Draw();
	glPopMatrix();





	//skull6

	glPushMatrix();
	glTranslatef(X7, Y7, Z7);
	glTranslatef(-0.4, 2.5, -40);
	glScalef(0.2, 0.2, 0.2);

	model_skull.Draw();
	glPopMatrix();


	//double skulls (X2 multiplier)

	glPushMatrix();
	glTranslatef(X10, Y10, Z10);
	glTranslatef(1.7, 2.5, -190);
	glScalef(0.1, 0.1, 0.1);

	model_skull.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(X10, Y10, Z10);
	glTranslatef(2.2, 2.5, -190);
	glScalef(0.1, 0.1, 0.1);

	model_skull.Draw();

	glPopMatrix();

	//shoe

	glPushMatrix();
	glTranslatef(X8, Y8, Z8);
	glTranslatef(-0.3, 2.5, -120);
	glScalef(0.07, 0.07, 0.07);

	model_shoe.Draw();
	glPopMatrix();




	//dragon

	glPushMatrix();
	glTranslatef(X9, Y9, Z9);
	glTranslatef(-1, 2.5, -190);
	glScalef(0.015, 0.015, 0.015);

	model_dragon.Draw();
	glPopMatrix();




	//glue(coin magnet)
	 
	glPushMatrix();
	glTranslatef(X0, Y0, Z0);
	glTranslatef(-0.5, -1, -55);
	glScalef(0.5, 0.7, 0.1);

	model_glue.Draw();
	glPopMatrix();





	//sky box
	glPushMatrix();

	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	glTranslatef(80, 0, Zsky);
	glScalef(1, 1, 1);
	glRotated(90, 1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, tex);
	gluQuadricTexture(qobj, true);
	gluQuadricNormals(qobj, GL_SMOOTH);
	//khalee el x wel y wel z
	gluSphere(qobj, 100, 100, 100);
	gluDeleteQuadric(qobj);


	glPopMatrix();









	glutSwapBuffers();
}



//=======================================================================
// Keyboard Function
//=======================================================================
//void myKeyboard(unsigned char button, int x, int y)
//{
//	switch (button)
//	{
//	case 'w':
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		break;
//	case 'r':
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		break;
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//
//	glutPostRedisplay();
//}


void Keyboard(unsigned char key, int x, int y) {
	float d = 0.09;

	switch (key) {

	case 'f':
		camera.firstPerson();
		break;
	case 't':
		camera.move1();
		break;
	

	case 27:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}

//Player and camera motion
void Keyboard1(int key, int x, int y) {
	float d = 0.09;

	switch (key) {
	case GLUT_KEY_LEFT:
		X += -0.5;
		camera.moveXLeft();


		if (X <= -10 && m==1) {
			Car1Z = 0;
			Car2Z = 0;
			Car3Z = 0;
			Car4Z = 0;
			Car5Z = 0;
			Car6Z = 0;

			boat1z = 0;
			boat2z = 0;
			boat3z = 0;
			boat4z = 0;
			boat5z = 0;
			boat6z = 0;
			m = 2;
			Z = 0;
			X = 0;
			camera.move1();
			Zsky = 0;
			sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);

		}

		if (X <= -10 && m == 2) {


			Z = 900;
			camera.lost();
			sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);

		}
		


		break;
	case GLUT_KEY_RIGHT:
		X += 0.5;
		camera.moveXRight();

		if (X >= 7 && m==1) {
			
			m = 2;
			Z = 0;

			X = 0;


			Car1Z = 0;
			Car2Z = 0;
			Car3Z = 0;
			Car4Z = 0;
			Car5Z = 0;
			Car6Z = 0;

			boat1z = 0;
			boat2z = 0;
			boat3z = 0;
			boat4z = 0;
			boat5z = 0;
			boat6z = 0;
			camera.move1();
			Zsky = 0;
			sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);
		}


		if (X >= 7 && m == 2) {

			Z = 900;
			camera.lost();

			sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
		}
		break;



	case 27:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}




//=======================================================================
//// Motion Function
////=======================================================================
//void myMotion(int x, int y)
//{
//	y = HEIGHT - y;
//
//	if (cameraZoom - y > 0)
//	{
//		Eye.x += -0.1;
//		Eye.z += -0.1;
//	}
//	else
//	{
//		Eye.x += 0.1;
//		Eye.z += 0.1;
//	}
//
//	cameraZoom = y;
//
//	glLoadIdentity();	//Clear Model_View Matrix
//
//	gluLookAt(Eye.x, Eye.y, Eye.z, At.x, At.y, At.z, Up.x, Up.y, Up.z);	//Setup Camera with modified paramters
//
//	GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	glutPostRedisplay();	//Re-draw scene 
//}

//=======================================================================
// Mouse Function
//=======================================================================
//void myMouse(int button, int state, int x, int y)
//{
//	y = HEIGHT - y;
//
//	if (state == GLUT_DOWN)
//	{
//		cameraZoom = y;
//	}
//}

//=======================================================================
// Reshape Function
//=======================================================================
void myReshape(int w, int h)
{
	if (h == 0) {
		h = 1;
	}

	WIDTH = w;
	HEIGHT = h;

	// set the drawable region of the window
	glViewport(0, 0, w, h);

	// set up the projection matrix 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, (GLdouble)WIDTH / (GLdouble)HEIGHT, zNear, zFar);

	// go back to modelview matrix so we can move the objects about
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Eye.x, Eye.y, Eye.z, At.x, At.y, At.z, Up.x, Up.y, Up.z);
}

void Timer2(int value) {



	Zb -= 1.5 * 0.67;

	boat1z += 0.099;
	boat2z += 0.099;
	boat3z += 0.148;
	boat4z -= 0.003;
	boat5z -= 0.03;
	boat6z += 0.099;

	Z -= 1.5 *factor;
	camera.move();
	Zsky -= 1.5 * factor;
	Z1 -= 0.5;
	Car1Z -= 0.7;
	Car2Z -= 0.6;
	Car3Z -= 0.55;
	Car4Z -= 0.4;
	Car5Z -= 0.5;
	Car6Z -= 0.6;

	


	if (Z <= -260) {
	
		Z = 0;

		Zsky = 0;
		Z1 = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;
	
		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;



		camera.move2();
	
	}









	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(100, Timer2, 0);
}
void Timer3(int value) {
 
	if (   Z + 14.8 <= Car1Z && Z +14.8 >= Car1Z-10  && X+3 <= Car1X +2 && X+3 >= Car1X -2  && Y != 10 && m==2  ) {
		Z = 900;
		camera.lost();
		sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
		E = 380;
		B = 1;
		C = 1;

	
	}

	if (Z + 14.8 <= Car1Z && Z + 14.8 >= Car1Z - 10 && X + 3 <= Car1X + 2 && X + 3 >= Car1X - 2 && Y != 10 && m == 1) {
		m = 2;
		Z = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;

		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;
		camera.move1();
		Zsky = 0;
		sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);
	}


	if (Z + 34 <= Car2Z && Z + 34 >= Car2Z - 10 && X -3 <= Car2X + 2 && X -3 >= Car2X - 2 && Y != 10 && m == 2) {
		Z = 900;
		camera.lost();
		sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
		E = 380;
		B = 1;
		C = 1;
	}

	if (Z + 34 <= Car2Z && Z + 34 >= Car2Z - 10 && X - 3 <= Car2X + 2 && X - 3 >= Car2X - 2 && Y != 10 && m == 1) {
		m = 2;
		Z = 0;
		Zsky = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;

		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;
		camera.move1();
		sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);
	}


	if (Z + 54 <= Car3Z && Z + 54 >= Car3Z - 10 && X + 3 <= Car3X + 2 && X + 3 >= Car3X - 2 && Y != 10 && m == 2) {
		Z = 900;
		camera.lost();
		sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
		E = 380;
		B = 1;
		C = 1;

	}
	if (Z + 54 <= Car3Z && Z + 54 >= Car3Z - 10 && X + 3 <= Car3X + 2 && X + 3 >= Car3X - 2 && Y != 10 && m == 1) {
		m = 2;
		Z = 0;
		Zsky = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;

		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;
		camera.move1();
		sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);

	}

	if (Z + 74 <= Car4Z && Z + 74 >= Car4Z - 10 && X - 3 <= Car4X + 2 && X - 3 >= Car4X - 2 && Y != 10 && m == 2) {
		Z = 900;
		camera.lost();
		E = 380;
		B = 1;
		C = 1;
		sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
	}
	if (Z + 74 <= Car4Z && Z + 74 >= Car4Z - 10 && X - 3 <= Car4X + 2 && X - 3 >= Car4X - 2 && Y != 10 && m == 1) {
		m = 2;
		Z = 0;
		Zsky = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;

		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;
		camera.move1();
		sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);
	}


	if (Z + 94 <= Car5Z && Z + 94 >= Car5Z - 10 && X + 5 <= Car5X + 2 && X + 5 >= Car5X - 2 && Y != 10 && m == 2) {
		Z = 900;
		camera.lost();
		E = 380;
		B = 1;
		C = 1;
		sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
	}
	if (Z + 94 <= Car5Z && Z + 94 >= Car5Z - 10 && X + 5 <= Car5X + 2 && X + 5 >= Car5X - 2 && Y != 10 && m == 1) {
		m = 2;
		Z = 0;
		Zsky = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;

		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;
		camera.move1();
		sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);
	}


	if (Z + 104 <= Car6Z && Z + 104 >= Car6Z - 10 && X <= Car6X + 2 && X >= Car6X - 2 && Y != 10 && m == 2) {
		Z = 900;
		camera.lost();
		sndPlaySound(TEXT("mixkit-sad-game-over-trombone-471.wav"), SND_ASYNC);
		E = 380;
		B = 1;
		C = 1;
	}

	if (Z + 104 <= Car6Z && Z + 104 >= Car6Z - 10 && X <= Car6X + 2 && X >= Car6X - 2 && Y != 10 && m == 1) {
		m = 2;
		Z = 0;
		Zsky = 0;
		Car1Z = 0;
		Car2Z = 0;
		Car3Z = 0;
		Car4Z = 0;
		Car5Z = 0;
		Car6Z = 0;

		boat1z = 0;
		boat2z = 0;
		boat3z = 0;
		boat4z = 0;
		boat5z = 0;
		boat6z = 0;

		camera.move1();
			sndPlaySound(TEXT("mixkit - sea - wave - noise - 1202"), SND_ASYNC);

	}




	


	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(100, Timer3, 0);
}



void Timer4(int value) {

	if (Z + 19 <= 0 && Z + 19 >= 0 - 2 && X +0.8  <= 2.5  && X +1.5 >= 2.5 -1.5 && Y != 10 && Y2 != 100) {
	
		Y2 = 100;
		i = i + fac;
		sndPlaySound(TEXT("mixkit-arcade-game-jump-coin-216.wav"), SND_ASYNC);
	}

	if (Z + 49 <= 0 && Z + 49 >= 0 - 2 && X + 0.8 <= 2.5  && X + 1.5 >= 2.5 - 1.5 && Y != 10 && Y3 != 100) {
		
		Y3 = 100;
		
		i = i + fac;
		sndPlaySound(TEXT("mixkit-arcade-game-jump-coin-216.wav"), SND_ASYNC);
	}
	
	if (Z + 79 <= 0 && Z + 79 >= 0 - 2 && X + 0.8 <= 2.5  && X + 1.5 >= 2.5 - 1.5 && Y != 10 && Y4 != 100) {
		
		Y4 = 100;
		i = i + fac;
		sndPlaySound(TEXT("mixkit-arcade-game-jump-coin-216.wav"), SND_ASYNC);
	}

	if (Z + 109 <= 0 && Z + 109 >= 0 - 2 && X + 0.8 <= 2.5  && X + 1.5 >= 2.5 - 1.5 && Y != 10 && Y5 != 100) {

		Y5 = 100;
		i = i + fac;
		sndPlaySound(TEXT("mixkit-arcade-game-jump-coin-216.wav"), SND_ASYNC);
	}

	if (Z + 139 <= 0 && Z + 139 >= 0 - 2 && X + 0.8 <= 2.5  && X + 1.5 >= 2.5 - 1.5 && Y != 10 && Y6 != 100) {

		Y6 = 100;
		i = i + fac;

		sndPlaySound(TEXT("mixkit-arcade-game-jump-coin-216.wav"), SND_ASYNC);
	}


	if (Z + 59 <= 0 && Z + 59 >= 0 - 2 && X + 5 <= 2.5 +1.5  && X + 5.5  >= 1 && Y != 10 && Y7 != 100) {
		
		Y7 = 100;
	
		i = i + fac;
		sndPlaySound(TEXT("mixkit-arcade-game-jump-coin-216.wav"), SND_ASYNC);
	}


	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(100, Timer4, 0);
}



int w = 0;
void Timer5(int value) {

	w++;
	if (w == 11) {

		if (Y2 == 100) {

			Y2 = 0;
		}

		if (Y3 == 100) {

			Y3 = 0;
		}
		if (Y4 == 100) {

			Y4 = 0;
		}

		if (Y5 == 100) {

			Y5 = 0;
		}

		if (Y6 == 100) {

			Y6 = 0;
		}
		if (Y7 == 100) {

			Y7 = 0;
		}
		w = 0;
		
	}
// ask OpenGL to recall the display function to reflect the changes on the window
glutPostRedisplay();

// recall the Timer function after 20 seconds (20,000 milliseconds)
glutTimerFunc(2000, Timer5, 0);
}

//powerups

void Timer6(int value) {

	
	
	//super sneakers

	if (Z + 139 <= 0 && Z + 139 >= 0 - 1 && X + 4.5 <= 2.5 + 1.5 && X + 5.5 >= 1 && Y != 10) {

		
		factor = 0.8;
		Y8 = 200;
		camera.move();

		Y2 = 200;
		Y3 = 200;
		Y4 = 200;
		Y5 = 200;
		Y6 = 200;
		Y7 = 200;


		sndPlaySound(TEXT("mixkit-fairy-arcade-sparkle-866.wav"), SND_ASYNC);



	}




	//jetpack(dragon)


	if (Z + 209 <= 0 && Z + 209 >= 0 - 1 && X + 4.5 <= 2.5 + 1.5 && X + 4.5 >= 1 && Y != 10) {

		Y = 10;
		
		Y9 = 200;
		camera.move4();

		
		/*sndPlaySound(TEXT("mixkit-fast-sweeping-transition-164.wav"), SND_ASYNC);*/

		sndPlaySound(TEXT("mixkit-medium-size-bird-flutter-63.wav"), SND_ASYNC);




	}



	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(100, Timer6, 0);
}



void Timer7(int value) {
	
	factor = 1;


	if (Y2 == 200) {

		Y2 = 0;
	}

	if (Y3 == 200) {

		Y3 = 0;
	}
	if (Y4 == 200) {

		Y4 = 0;
	}

	if (Y5 == 200) {

		Y5 = 0;
	}

	if (Y6 == 200) {

		Y6 = 0;
	}
	if (Y7 == 200) {

		Y7 = 0;
	}

	if (Y8 == 200) {

		Y8 = 0;
	}

	

	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(20000, Timer7, 0);
}







void Timer8(int value) {

	if (Y == 10 && Z <=-100 && Z >= -110) {

		Y = 0;
		Y9 = 0;
		camera.move5();
	}


	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(900, Timer8, 0);
}



//Coin magnet (gluestick)



int k = 0;
void Timer10(int value) {

	if (Y0 == 100 && k ==6) {

		Y0 = 0;
		k = 0;
	}
	k++;
	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(5000, Timer10, 0);
}
void Timer9(int value) {

	if (Z + 74 <= 0 && Z + 74 >= 0 - 1 && X + 5 <= 2.5 + 1.5 && X + 5.5 >= 1 && Y != 10 && Y0 !=100) {
		
		Y0 = 100;
		sndPlaySound(TEXT("mixkit-game-success-alert-2039.wav"), SND_ASYNC);
		
		if (Y2 != 100) {
			Y2 = 100;
			i = i + fac;
		}
		


		
		if (Y3 != 100) {
			Y3 = 100;
			i = i + fac;
		}
		

		if (Y4 != 100) {

			Y4 = 100;
			i = i + fac;

		}

		if (Y5 != 100) {

			Y5 = 100;
			i = i + fac;
		
		}

		if (Y6 != 100) {

			Y6 = 100;
			i = i + fac;
			
		}

		if (Y7 != 100) {

			Y7 = 100;
			i = i + fac;

		}




		glutTimerFunc(0, Timer10, 0);



	}


	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(100, Timer9, 0);
}






//X2 multiplier

int p = 0;


void Timer12(int value) {

	p++;
	if (p == 20 && Y10 == 100) {
		

		fac = 1;

		Y10 = 0;


		p = 0;


	}








	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(1000, Timer12, 0);
}
void Timer11(int value) {

	
	if (Z + 209 <= 0 && Z + 209 >= 0 - 1 && X + 0.8 <= 2.5 && X + 1.5 >= 2.5 - 1.5 && Y != 10 && Y10 != 100 ) {

		Y10 = 100;
		
		fac = 2;

		


		i = i + fac;
		sndPlaySound(TEXT("mixkit-arcade-score-interface-217.wav"), SND_ASYNC);


		glutTimerFunc(0, Timer12, 0);
	}


	



	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(100, Timer11, 0);
}







//=======================================================================
// Assets Loading Function
//=======================================================================
void LoadAssets()
{
	// Loading Model files


	/*if (m == 1) {*/
		model_house.Load("Models/house/house.3DS");
		model_tree.Load("Models/tree/Tree1.3ds");

		model_streetLamp.Load("Models/Street Lamp/StreetLamp.3ds");

		model_car.Load("Models/jeep/jeep.3ds");
		tex_street.Load("Textures/street.bmp");


	/*if (m == 2) {*/

		model_boat.Load("Models/Boat/3DS/Boat.3DS");
		
		tex_sea.Load("Textures/sea_pic.bmp");


	model_robot.Load("Models/robot/robot.3ds");

	model_mount.Load("Models/mountain/mount.blend1.3ds");

	model_skull.Load("Models/skull/skull.3ds");


	model_shoe.Load("Models/Black shoe/Black shoe.3ds");

	model_dragon.Load("Models/3ds/Dragon 2.5_3ds.3ds");
	

	model_glue.Load("Models/gluestick/gluestick.3ds");



	/*model_grass.Load("Models/grass1/grass02.3ds");*/

	// Loading texture files
	/*tex_ground.Load("Textures/ground.bmp");*/
	

	loadBMP(&tex, "Textures/blu-sky-3.bmp", true);
}

//=======================================================================
// Main Function
//=======================================================================
void main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(WIDTH, HEIGHT);

	glutInitWindowPosition(100, 150);


	InitLightSource();

	glutCreateWindow(title);

	glutDisplayFunc(Display);

	/*glutKeyboardFunc(myKeyboard);*/

	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(Keyboard1);

	/*glutMotionFunc(myMotion);

	glutMouseFunc(myMouse);*/

	/*glutReshapeFunc(myReshape);*/

	glutTimerFunc(0, Timer2, 0);
	glutTimerFunc(0, Timer3, 0);
	glutTimerFunc(0, Timer4, 0);
	glutTimerFunc(0, Timer5, 0);
	glutTimerFunc(0, Timer6, 0);
	glutTimerFunc(0, Timer7, 0);
	glutTimerFunc(0, Timer8, 0);
	glutTimerFunc(0, Timer9, 0);
	glutTimerFunc(0, Timer11, 0);
	
	/*myInit();*/

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}