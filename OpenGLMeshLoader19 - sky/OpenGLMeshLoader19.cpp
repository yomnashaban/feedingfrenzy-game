#include "TextureBuilder.h"
#include "Model_3DS.h"
#include "GLTexture.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <glut.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <glut.h>
#include <iostream>

#include "OpenGLMeshLoader19.h"

using namespace std;
int WIDTH = 1536;
int HEIGHT = 845;

bool once = true;
int WIDTH2 = 1280;
int HEIGHT2 = 720;

//translating bird
float xmove2 = 0;
float ymove2 = -20;
float zmove2 = -400;
std::string a;
std::string b;

int counter2 = 84;
int Score = 0;

float xbar = 150;
int  life = 1;
bool hit2 = false;

float EotL2 = 0;

float rottest = 0;



bool no = false;
bool no2 = false;
float rotc = 90;
int c = 0;
bool move = false;
bool detect = false;

bool gameover = false;

bool first = false;

int inc = 50;
int counter3 = 4;
int po;


GLuint tex;
GLuint greenbar;
GLuint yes;
GLuint tex2;
GLuint texg;
GLuint heart;
char title2[] = "BIRD";

// 3D Projection Options
GLdouble fovy2 = 45.0;
GLdouble aspectRatio2 = (GLdouble)WIDTH2 / (GLdouble)HEIGHT2;
GLdouble znear2 = 0.1;
GLdouble zfar2 = 300000;


float EotL1 = 0;
void Timer(int value);
//void drawHealth(int health);
int health = 4;
bool camera = true;
bool rlb = false;

bool switching = false;
float xintensity = 0.8;
float yintensity = 0.8;
float zintensity = 0.8;
bool s88 = true;


//translating nemo

float xmove = 10;
float ymove = 0;
float zmove = 0;
float moveshark = 0.5;
bool forwardshark = true;
float movefish = 2;
bool forwardfish = true;

float movefish2x = 2;
float movefish2y = 2;

int counter = 0;
bool healthdec = false;
bool lost = false;
bool won = false;

int hit = 0;
int score = 0;
int xhealth = 160;
int m = 5;
int n = 5;
int v = 5;

//float xhealth = 10;
//float yhealth = 3;
//float zhealth = 0;



char title[] = "NEMO";

// 3D Projection Options
GLdouble fovy = 50;
GLdouble aspectRatio = (GLdouble)WIDTH / (GLdouble)HEIGHT;
GLdouble zNear = 0.1;
GLdouble zFar = 1000;



















bool level1 = true;





class Vector
{
public:
	GLdouble x, y, z;
	Vector() {}
	Vector(GLdouble _x, GLdouble _y, GLdouble _z) : x(_x), y(_y), z(_z) {}
	//================================================================================================//
	// Operator Overloading; In C++ you can override the behavior of operators for you class objects. //
	// Here we are overloading the += operator to add a given value to all vector coordinates.        //
	//================================================================================================//
	void operator +=(float value)
	{
		x += value;
		y += value;
		z += value;
	}
};




// define default capacity of the stack
#define SIZE 50000000

// Class for stack
class stack
{
	Vector* arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE); 	// constructor
	~stack();   				// destructor

	void push(Vector);
	Vector pop();
	Vector peek();

	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize stack
stack::stack(int size)
{
	arr = new Vector[size];
	capacity = size;
	top = -1;
}

// Destructor to free memory allocated to the stack
stack::~stack()
{
	delete arr;
}
// Utility function to return the size of the stack
int stack::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}

// Utility function to add an element x in the stack
void stack::push(Vector x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}


	arr[++top] = x;
}

// Utility function to pop top element from the stack
Vector stack::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}



	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

// Utility function to return top element in a stack
Vector stack::peek()
{
	if (!isEmpty()) {
		return arr[top];
	}
	//else {
		//cout << "FUCKKKK "  << endl;
		//exit(EXIT_FAILURE);

	//}
}
















Vector Eye2(0, 30, -500);
Vector At2(0, -800, 6000);
Vector Up2(0, 1, 0);




stack s(100000);
stack s2(100000);
stack st1(100000);
stack st2(100000);

stack diss(100000);
stack diss2(100000);



//int cameraZoom = 0;


// Model Variables

bool fff = false;




Vector Eye(8, 5, 20);
Vector At(5, 0, 0);
Vector Up(0, 1, 0);

int cameraZoom = 0;

// Model Variables


Model_3DS model_myfish;
Model_3DS model_myfish2;
Model_3DS model_choral;
Model_3DS model_shark;
Model_3DS model_shell;


Model_3DS model_rock;
Model_3DS model_bird;
Model_3DS model_bird2;
Model_3DS model_b1;
Model_3DS model_c;























//=======================================================================
// Lighting Configuration Function
//=======================================================================
void InitLightSource2()
{
	// Enable Lighting for this OpenGL Program
	glEnable(GL_LIGHTING);

	// Enable Light Source number 0
	// OpengL has 8 light sources
	glEnable(GL_LIGHT0);

	// Define Light source 0 ambient light
	GLfloat ambient[] = { 0.23125, 0.2315, 0.2315, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	// Define Light source 0 diffuse light
	GLfloat diffuse[] = { 0.2775, 0.2775, 0.2775, 0.2775 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	// Define Light source 0 Specular light
	GLfloat specular[] = { 0.773911,  0.773911,  0.773911, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Finally, define light source 0 position in World Space
	GLfloat light_position[] = { xmove2, EotL2 -200.0f, zmove2, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

//=======================================================================
// Material Configuration Function
//======================================================================
void InitMaterial2()
{
	// Enable Material Tracking
	glEnable(GL_COLOR_MATERIAL);

	// Sich will be assigneet Material Properties whd by glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Set Material's Specular Color
	// Will be applied to all objects
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

	// Set Material's Shine value (0->128)
	GLfloat shininess[] = { 96.0f };
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

//=======================================================================
// OpengGL Configuration Function
//=======================================================================
void myInit2(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(fovy2, aspectRatio2, znear2, zfar2);
	//***********//
	// fovy2:			Angle between the bottom and top of the projectors, in degrees.			 //
	// aspectRatio2:		Ratio of WIDTH2 to HEIGHT2 of the clipping plane.							 //
	// znear2 and zfar2:	Specify the front and back clipping planes distances from camera.		 //
	//***********//

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(Eye2.x, Eye2.y, Eye2.z, At2.x, At2.y, At2.z, Up2.x, Up2.y, Up2.z);
	//***********//
	// Eye2 (ex, ey, ez): defines the location of the camera.									 //
	// At2 (ax, ay, az):	 denotes the direction where the camera is aiming At2.					 //
	// Up2 (ux, uy, uz):  denotes the upward orientation of the camera.							 //
	//***********//

	InitLightSource2();

	InitMaterial2();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_NORMALIZE);
}



void InitLightSource()
{
	// Enable Lighting for this OpenGL Program
	glEnable(GL_LIGHTING);

	// Enable Light Source number 0
	// OpengL has 8 light sources
	glEnable(GL_LIGHT0);

	// Define Light source 0 ambient light
	GLfloat ambient[] = { 0.23125, 0.2315, 0.2315, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	// Define Light source 0 diffuse light
	GLfloat diffuse[] = { 0.2775, 0.2775, 0.2775, 0.2775 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	// Define Light source 0 Specular light
	GLfloat specular[] = { 0.773911,  0.773911,  0.773911, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Finally, define light source 0 position in World Space
	GLfloat light_position[] = { xmove, EotL1 - 200.0f, zmove, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void setupLights() {
	GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	GLfloat l0Diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };//color of light rays
	GLfloat l0Spec[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat l0Ambient[] = { 0.1f, 0.0f, 0.0f, 1.0f };//color affects ba2y 7agat fel scene
	GLfloat l0Position[] = { 10.0f, 0.0f, 0.0f, s88 };//position of light src law ana posotional
	GLfloat l0Direction[] = { -1.0, 0.0, 0.0 };//vector of light src law ana directional
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0Diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0Ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, l0Position);
	//spotlight 3obara 3an shaakl cone, cutoff is the angle of the cone itself,exponent how it is distributed fel circl at the end of the cone el btb2a khabta fl akher
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 90.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, l0Direction);




}

//=======================================================================
// Material Configuration Function
//======================================================================
void InitMaterial()
{
	// Enable Material Tracking
	glEnable(GL_COLOR_MATERIAL);

	// Sich will be assigneet Material Properties whd by glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Set Material's Specular Color
	// Will be applied to all objects
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

	// Set Material's Shine value (0->128)
	GLfloat shininess[] = { 96.0f };
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

//=======================================================================
// OpengGL Configuration Function
//=======================================================================
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(fovy, aspectRatio, zNear, zFar);
	//*//
	// fovy:			Angle between the bottom and top of the projectors, in degrees.			 //
	// aspectRatio:		Ratio of width to height of the clipping plane.							 //
	// zNear and zFar:	Specify the front and back clipping planes distances from camera.		 //
	//*//

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(Eye.x, Eye.y, Eye.z, At.x, At.y, At.z, Up.x, Up.y, Up.z);
	//*//
	// EYE (ex, ey, ez): defines the location of the camera.									 //
	// AT (ax, ay, az):	 denotes the direction where the camera is aiming at.					 //
	// UP (ux, uy, uz):  denotes the upward orientation of the camera.							 //
	//*//

	InitLightSource();

	InitMaterial();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_NORMALIZE);
}




























void print(float x, float y, float z, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	//glColor3f(0,0,1);
	glRasterPos3f(x, y, z);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void print2(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void print1(int x, int y, const char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);


	//loop to display character by character
	for (i = 0; i < len; i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}


void build() {

	int z = 0;
	inc = 50;
	for (z = 0; z <= counter3; z++) {
		// yemen saf tany
		glPushMatrix();
		glTranslatef(0, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 350 + inc;

			Vector b1(0, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(-50, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();


		if (fff == false) {
			int b = 350 + inc;

			Vector b1(-50, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(-100, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 350 + inc;

			Vector b1(-100, -50, b);
			s.push(b1);
		}



		glPushMatrix();
		glTranslatef(-150, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 350 + inc;

			Vector b1(-150, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(-200, -50, (350 + inc));
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();



		glPushMatrix();
		glTranslatef(-250, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			int b = 350 + inc;

			Vector b1(-250, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(-300, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			int b = 350 + inc;

			Vector b1(-300, -50, b);
			s.push(b1);
		}



		// shemal saf tany

		glPushMatrix();
		glTranslatef(50, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 350 + inc;

			Vector b1(50, -50, b);
			s.push(b1);
		}



		glPushMatrix();
		glTranslatef(100, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 350 + inc;

			Vector b1(100, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(150, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();


		if (fff == false)
		{
			int b = 350 + inc;

			Vector b1(150, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(200, -50, (350 + inc));
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();




		glPushMatrix();
		glTranslatef(250, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			int b = 350 + inc;

			Vector b1(250, -50, b);
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(300, -50, (350 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 350 + inc;

			Vector b1(300, -50, b);
			s.push(b1);
		}


		// saf el awel shemal



		glPushMatrix();
		glTranslatef(-50, -50, inc);
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			Vector b1(-50, -50, (inc));
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(-125, -50, inc);
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();





		glPushMatrix();
		glTranslatef(-200, -50, inc);
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();


		if (fff == false) {
			Vector b1(-200, -50, (inc));
			s.push(b1);
		}


		glPushMatrix();
		glTranslatef(-250, -50, inc);
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();




		glPushMatrix();
		glTranslatef(-300, -50, inc);
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			Vector b1(-300, -50, (inc));
			s.push(b1);
		}


		// saf el awel shemal

		glPushMatrix();
		glTranslatef(50, -50, inc);
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			Vector b1(50, -50, (inc));
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(125, -50, inc);
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(200, -50, inc);
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			Vector b1(200, -50, (inc));
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(250, -50, inc);
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();




		glPushMatrix();
		glTranslatef(300, -50, inc);
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			Vector b1(300, -50, (inc));
			s.push(b1);
		}


		//saf talat yemen 

		glPushMatrix();
		glTranslatef(0, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			int b = 650 + inc;

			Vector b1(0, -50, b);
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(-50, -50, (650 + inc));
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-100, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();


		if (fff == false) {
			int b = 650 + inc;
			Vector b1(-100, -50, b);
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(-150, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 650 + inc;
			Vector b1(-150, -50, b);
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(-225, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			int b = 650 + inc;
			Vector b1(-225, -50, b);
			s.push(b1);
		}



		glPushMatrix();
		glTranslatef(-300, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 650 + inc;
			Vector b1(-300, -50, b);
			s.push(b1);
		}

		//saf talat shemal


		glPushMatrix();
		glTranslatef(50, -50, (650 + inc));
		glScalef(0.05, 0.03, 0.05);
		model_b1.Draw();
		glPopMatrix();




		glPushMatrix();
		glTranslatef(100, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 650 + inc;
			Vector b1(100, -50, b);
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(150, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 650 + inc;
			Vector b1(150, -50, b);
			s.push(b1);
		}

		glPushMatrix();
		glTranslatef(225, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();
		if (fff == false) {
			int b = 650 + inc;
			Vector b1(225, -50, b);
			s.push(b1);
		}



		glPushMatrix();
		glTranslatef(300, -50, (650 + inc));
		glScalef(0.05, 0.3, 0.05);
		model_b1.Draw();
		glPopMatrix();

		if (fff == false) {
			int b = 650 + inc;
			Vector b1(300, -50, b);
			s.push(b1);
		}

		inc = inc + 950;


	}




	fff = true;


}

void coin() {
	if (first == false) {

		for (int i = 0; i <= counter2; i++) {

			glPushMatrix();
			glTranslatef(0, -20, (0 + inc));
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();


			Vector b1(0, -20, inc);
			s2.push(b1);


			glPushMatrix();
			glTranslatef(20, -20, 50);
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();

			Vector b2(20, -20, (50 + inc));
			s2.push(b2);




			glPushMatrix();
			glTranslatef(-100, -20, (0 + inc));
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();


			Vector b3(-100, -20, inc);
			s2.push(b3);


			glPushMatrix();
			glTranslatef(-120, -20, 50);
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();

			Vector b4(-120, -20, (50 + inc));
			s2.push(b4);



			glPushMatrix();
			glTranslatef(100, -20, (0 + inc));
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();


			Vector b5(100, -20, inc);
			s2.push(b5);


			glPushMatrix();
			glTranslatef(120, -20, 50);
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();

			Vector b6(120, -20, (50 + inc));
			s2.push(b6);


			glPushMatrix();
			glTranslatef(-250, -20, (0 + inc));
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();


			Vector b7(-250, -20, inc);
			s2.push(b7);


			glPushMatrix();
			glTranslatef(-270, -20, 50);
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();

			Vector b8(-270, -20, (50 + inc));
			s2.push(b8);



			glPushMatrix();
			glTranslatef(250, -20, (0 + inc));
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();


			Vector b9(250, -20, inc);
			s2.push(b9);


			glPushMatrix();
			glTranslatef(270, -20, 50);
			glRotated(rotc, 1, 0, 1);
			glScalef(15, 0.8, 0.8);
			model_c.Draw();
			glPopMatrix();

			Vector b10(270, -20, (50 + inc));
			s2.push(b10);
















			inc = inc + 150;











		}

	}

	if (first == true) {

		while (!s2.isEmpty()) {

			Vector u = s2.peek();
			int u1 = u.x;
			int u2 = u.y;
			int u3 = u.z;


			glPushMatrix();
			glTranslatef(u1, u2, u3);
			glRotated(rotc, 1, 0, 1);
			glScalef(0.6, 0.6, 0.6);
			model_c.Draw();
			glPopMatrix();


			st2.push(s2.peek());
			s2.pop();


		}


	}


	while (!st2.isEmpty()) {

		s2.push(st2.peek());
		st2.pop();
	}
	first = true;




}



void drawHealth() {

	healthdec = false;
	health = 4;
	health = health - hit;
	xhealth = 160;



	if (health == 4) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0, 1.0, 1.0);

		print2(15, 650, "Your Health: 4 ");

		glPopMatrix();
		//glMatrixMode(GL_PROJECTION);
		//glPopMatrix();


	}
	else if (health == 3) {

		xhealth = xhealth - 40;

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0, 1.0, 1.0);
		print2(15, 650, "Your Health: 3 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (health == 2) {

		xhealth = xhealth - 80;

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0, 1.0, 1.0);

		print2(15, 650, "Your Health: 2 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (health == 1) {
		xhealth = xhealth - 120;

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0, 1.0, 1.0);

		print2(15, 650, "Your Health: 1 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/

	}

	//glPushMatrix();
	//glTranslated(2, 2, -35);


	if (health == 1 || health == 2) {
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		//glBindTexture(GL_TEXTURE_2D, greenbar);	// Bind the ground texture



		glBegin(GL_QUADS);
		//glNormal3f(0, 0, 1);	// Set quad normal direction.

		glColor3f(1, 0, 0);
			// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
		glVertex2f(30, 610);
		
		glVertex2f(xhealth, 610);
		
		glVertex2f(xhealth, 630);
		
		glVertex2f(30, 630);







		glEnd();
		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (health == 3 || health == 4) {


		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		//glBindTexture(GL_TEXTURE_2D, greenbar);	// Bind the ground texture



		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);	// Set quad normal direction.

		glColor3f(0, 1, 0);
			// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
		glVertex2f(30, 610);
		
		glVertex2f(xhealth, 610);
		
		glVertex2f(xhealth, 630);
		
		glVertex2f(30, 630);








		glEnd();
		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/

		//glScaled(1, 2 * (health), 1);
		//glutSolidCube(1.0);
		//glPopMatrix();
	}
	else if (health == 0) {
		lost = true;
		//cout << lost;
	}




	glColor3d(1, 1, 1);




}




void printscore() {



	


	if (score == 0) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print(15, 700, 0, "Your Score: 0 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();
*/

	}


	else if (score == 10) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 10 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 20) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 20 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 30) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 30 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 40) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 40 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 50) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 50 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 60) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 60 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 70) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 70 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 80) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 80 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}

	else if (score == 90) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 90 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 100) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 100 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 110) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 110 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 120) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 120 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 130) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 130 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}

	else if (score == 140) {

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 140 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
	else if (score == 150) {
		won = true;

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1.0, 1.0, 1.0);


		print2(15, 700, "Your Score: 150 ");

		glPopMatrix();
		/*glMatrixMode(GL_PROJECTION);
		glPopMatrix();*/
	}
}








void myDisplay(void)
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	if (level1 == true) {
		sndPlaySound(TEXT("back"), SND_NOSTOP | SND_ASYNC);
		myInit();
		if (lost == false && won == false) {

			glPushMatrix();
			printscore();
			glPopMatrix();

			glPushMatrix();
			drawHealth();
			glPopMatrix();

			myInit();

			GLfloat lightIntensity[] = { 0.7, 0.7, 0.7, 1.0f };
			//GLfloat lightPosition[] = { EotL + xmove, 100.0f, zmove, 0.0f };

			glPushMatrix();
			glRotated(EotL1, 1, 1, 1);

			//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
			InitLightSource();
			glPopMatrix();

			glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);


			/*float c = 0;
			if (c < 10) {

				c += 0.0000000000000000000000000001;*/

			if (rlb)
			{
				setupLights();

			}
			/*
			}
			rlb = false;*/


			if (camera == false) {
				if (forwardshark) {
					glPushMatrix();
					glRotated(90, 0, 1, 0);
					glTranslatef(moveshark, 3, 35);
					glScalef(-20, 25, 20);
					model_shark.Draw();
					glPopMatrix();
				}
				else {
					glPushMatrix();
					glRotated(90, 0, 1, 0);
					glTranslatef(moveshark, 3, 35);
					glScalef(20, 25, 20);
					model_shark.Draw();
					glPopMatrix();
				}

			}

			// draw  shark
			else {
				if (forwardshark) {
					glPushMatrix();
					glRotated(90, 0, 1, 0);
					glTranslatef(moveshark, 3, 1);
					glScalef(-20, 25, 20);
					model_shark.Draw();
					glPopMatrix();
				}
				else {
					glPushMatrix();
					glRotated(90, 0, 1, 0);
					glTranslatef(moveshark, 3, 1);
					glScalef(20, 25, 20);
					model_shark.Draw();
					glPopMatrix();
				}
			}




			if (forwardfish) {
				//darw another fish
				glPushMatrix();
				glTranslatef(movefish, 6, 0);
				glScalef(-9, 9, 9);
				model_myfish2.Draw();
				glPopMatrix();
			}
			else {
				glPushMatrix();
				glTranslatef(movefish, 6, 0);
				glScalef(9, 9, 9);
				model_myfish2.Draw();
				glPopMatrix();
			}






			glPushMatrix();
			glTranslatef(movefish2x, movefish2y, 0);
			glScalef(-8, 8, 8);
			model_myfish2.Draw();
			glPopMatrix();




			//draw choral
			glPushMatrix();
			glTranslatef(10, -7, 0);
			glScalef(3, 3, 3);
			model_choral.Draw();
			glPopMatrix();
			//draw choral2
			glPushMatrix();
			glTranslatef(-7, -9.5, 0);
			glScalef(3, 3, 3);
			model_choral.Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(3, -10, 0);
			glScalef(2, 2, 1);
			model_shell.Draw();
			glPopMatrix();




			//draw rock
			glPushMatrix();
			glTranslatef(10, 0, 0);
			glScalef(10, 10, 10);
			model_rock.Draw();
			glPopMatrix();

			//draw rock2
			glPushMatrix();
			glTranslatef(9, -9, 0);
			glScalef(3, 3, 3);
			model_rock.Draw();
			glPopMatrix();




			//draw fish
			glPushMatrix();
			glTranslatef(xmove, ymove, zmove);
			glRotatef(rottest, 0, 1, 0);
			glScalef(m, n, v);
			model_myfish.Draw();

			glPopMatrix();

			//sky box
			glPushMatrix();

			GLUquadricObj* qobj;
			qobj = gluNewQuadric();
			glTranslated(50, 0, 0);
			glRotated(90, 1, 0, 1);
			glBindTexture(GL_TEXTURE_2D, tex);
			gluQuadricTexture(qobj, true);
			gluQuadricNormals(qobj, GL_SMOOTH);
			gluSphere(qobj, 100, 100, 100);
			gluDeleteQuadric(qobj);

			glPopMatrix();

			//glEnable(GL_TEXTURE_GEN_S);
			//glEnable(GL_TEXTURE_GEN_T);
			//glBindTexture(GL_TEXTURE_2D, tex);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

			//glPushMatrix();
			//glRotated(90, 1, 0, 0);
			//glTranslatef(10, 0, -1000);
			//glutSolidCube(30);
			//glPopMatrix();
			//glDisable(GL_TEXTURE_GEN_S);
			//glDisable(GL_TEXTURE_GEN_T);

			glPushMatrix();
			glTranslatef(17, 5, 0);
			glRotatef(4, 0, 0, 1);





			glPopMatrix();
			if (camera == false) {
				if (counter == 0) {
					Eye.x = 70;
					xmove = 71;
				}

				Eye.y = ymove;
				Eye.z = zmove;

				counter++;

			}
		}

		else if (lost == true) {


			GLfloat lightIntensity[] = { 0.7, 0.7, 0.7, 1.0f };
			GLfloat lightPosition[] = { 0.0f, 100.0f, 0.0f, 0.0f };
			glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
			glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);


			glPushMatrix();


			GLUquadricObj* qobj;
			qobj = gluNewQuadric();
			glTranslated(50, 0, 0);
			glRotated(90, 1, 0, 1);
			glBindTexture(GL_TEXTURE_2D, tex);
			gluQuadricTexture(qobj, true);
			gluQuadricNormals(qobj, GL_SMOOTH);
			gluSphere(qobj, 100, 100, 100);
			gluDeleteQuadric(qobj);
			glPopMatrix();

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();

			glPushMatrix();
			//glScaled(3, 3, 1);


		

				std::stringstream sstm;
				sstm << score;
				a = sstm.str();

				print2(680, 450, "Your Score:");

				print1(800, 450, a.data());

			



			print2(600, 500, "Game Over, you lost all your lives");
			glPopMatrix();
			glColor3d(1, 1, 1);

			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();


		}
		else if (won == true) {

			GLfloat lightIntensity[] = { 0.7, 0.7, 0.7, 1.0f };
			GLfloat lightPosition[] = { 0.0f, 100.0f, 0.0f, 0.0f };
			glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
			glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);

			glPushMatrix();


			GLUquadricObj* qobj;
			qobj = gluNewQuadric();
			glTranslated(50, 0, 0);
			glRotated(90, 1, 0, 1);
			glBindTexture(GL_TEXTURE_2D, tex);
			gluQuadricTexture(qobj, true);
			gluQuadricNormals(qobj, GL_SMOOTH);
			gluSphere(qobj, 100, 100, 100);
			gluDeleteQuadric(qobj);
			glPopMatrix();

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();



			glPushMatrix();
			//glScaled(5,1, 1);



			std::stringstream sstm;
			sstm << score;
			b= sstm.str();

			print2(680, 450, "Your Score:");

			print1(800, 450, b.data());

			print2(600, 500, "You won, ready for level 2 ??");
			glPopMatrix();
			glColor3d(1, 1, 1);

			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();




			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();

			glBindTexture(GL_TEXTURE_2D, yes);	// Bind the ground texture
			glBegin(GL_QUADS);
			//glColor3f(0.5, 1, 0.5);

				// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glTexCoord2f(1, 1);
			glVertex2f(900, 350);
			glTexCoord2f(0, 1);

			glVertex2f(600, 350);
			glTexCoord2f(0, 0);
			glVertex2f(600, 300);
			glTexCoord2f(1, 0);
			glVertex2f(900, 300);




			glEnd();




			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();

























		}

	}

	else {



	

		if (gameover == true) {

			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//myInit2();

			

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH2, 0.0, HEIGHT2);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
			glColor3f(0.0, 1.0, 0.0);
			//glScalef(2, 2, 2);

		//	glPushMatrix();
			

			char* scores[20];
			sprintf((char*)scores, "GAME OVER ! Your Score is= %d", Score);
			print2(535, 350, (char*)scores);

			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			//glutPostRedisplay();


			//glutSwapBuffers();

		}
		else {




			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			myInit2();

			GLfloat lightIntensity[] = { 0.5, 0.5,0.5, 1.0f };
			//GLfloat lightPosition[] = { EotL2 + xmove2, 100.0f, zmove2, 0.0f };

			glPushMatrix();
			glRotated(EotL2, 1, 1, 1);

			//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
			InitLightSource2();
			glPopMatrix();

			glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);


			//glPopMatrix();

			//draw bird
			glPushMatrix();
			glTranslatef(xmove2, ymove2, zmove2);
			glScalef(1, 1, 1);
			model_bird.Draw();
			glPopMatrix();


			// coin
			coin();




			// draw HOUSES

			build();






			//taht
			glBindTexture(GL_TEXTURE_2D, texg);	// Bind the ground texture

			glPushMatrix();
			//glRotated(90, 0, 1, 0);
			glBegin(GL_QUADS);
			glNormal3f(0, 1, 0);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex3f(-500, -50, -500);
			glTexCoord2f(1, 0);
			glVertex3f(500, -50, -500);
			glTexCoord2f(1, 1);
			glVertex3f(500, -50, 4200);
			glTexCoord2f(0, 1);
			glVertex3f(-500, -50, 4200);
			glEnd();
			glPopMatrix();

			// side shemal

			glBindTexture(GL_TEXTURE_2D, tex2);	// Bind the ground texture

			glPushMatrix();

			glBegin(GL_QUADS);
			glNormal3f(1, 0, 0);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex3f(340, -50, -500);
			glTexCoord2f(1, 0);
			glVertex3f(340, -50, 4200);
			glTexCoord2f(1, 1);
			glVertex3f(340, 100, 4200);
			glTexCoord2f(0, 1);
			glVertex3f(340, 100, -500);
			glEnd();
			glPopMatrix();

			//side yemen
			glBindTexture(GL_TEXTURE_2D, tex2);	// Bind the ground texture

			glPushMatrix();
			//glRotated(90, 1, 0, 0);
			glBegin(GL_QUADS);
			glNormal3f(1, 0, 0);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex3f(-340, -50, -500);
			glTexCoord2f(1, 0);
			glVertex3f(-340, -50, 4200);
			glTexCoord2f(1, 1);
			glVertex3f(-340, 100, 4200);
			glTexCoord2f(0, 1);
			glVertex3f(-340, 100, -500);
			glEnd();
			glPopMatrix();



			//fo2

			glBindTexture(GL_TEXTURE_2D, tex2);	// Bind the ground texture

			glPushMatrix();
			//glRotated(90, 0, 1, 0);
			glBegin(GL_QUADS);
			glNormal3f(0, 1, 0);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex3f(-500, 100, -500);
			glTexCoord2f(1, 0);
			glVertex3f(500, 100, -500);
			glTexCoord2f(1, 1);
			glVertex3f(500, 100, 4200);
			glTexCoord2f(0, 1);
			glVertex3f(-500, 100, 4200);
			glEnd();
			glPopMatrix();




			//front 

			glBindTexture(GL_TEXTURE_2D, tex2);	// Bind the ground texture

			glPushMatrix();
			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex3f(-500, -50, 4200);
			glTexCoord2f(1, 0);
			glVertex3f(500, -50, 4200);
			glTexCoord2f(1, 1);
			glVertex3f(500, 100, 4200);
			glTexCoord2f(0, 1);
			glVertex3f(-500, 100, 4200);
			glEnd();
			glPopMatrix();




			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH2, 0.0, HEIGHT2);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
			//glColor3f(1.0, 1.0, 1.0);

			char* scores[20];
			sprintf((char*)scores, "Score = %d", Score);
			print2(15, 650, (char*)scores);

			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();





			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH2, 0.0, HEIGHT2);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();

			glBindTexture(GL_TEXTURE_2D, greenbar);	// Bind the ground texture



			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex2f(30, 610);
			glTexCoord2f(1, 0);
			glVertex2f(xbar, 610);
			glTexCoord2f(1, 1);

			glVertex2f(xbar, 630);
			glTexCoord2f(0, 1);
			glVertex2f(30, 630);







			glEnd();
			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();










			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, WIDTH2, 0.0, HEIGHT2);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();

			glBindTexture(GL_TEXTURE_2D, heart);	// Bind the ground texture


			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);	// Set quad normal direction.
			glTexCoord2f(0, 0);		// Set tex2 coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
			glVertex2f(30, 630);
			glTexCoord2f(1, 0);
			glVertex2f(5, 630);
			glTexCoord2f(1, 1);
			glVertex2f(5, 610);
			glTexCoord2f(0, 1);
			glVertex2f(30, 610);




			glEnd();
			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();









		}


		
	}

	glutPostRedisplay();
	glutSwapBuffers();

}





























































































//=======================================================================
// Keyboard Function
//=======================================================================









































void KeyboardSpecial(int key, int x, int y) {

	if (level1 == true) {

		if (camera) {

			//if (key == GLUT_KEY_RIGHT) {
			//	rottest = rottest + 10;
			////	n = n+1;
			////	m = m + 1;
			////	v = v + 1;


			//}

			//if (key == GLUT_KEY_LEFT) {
			////	n = n - 1;
			////	m = m - 1;
			////	v = v - 1;
			//	rottest = rottest -10;

			//}




			if (key == GLUT_KEY_UP) {

				if (Eye.z <= 47) { //maximum z to go to is 47
					zmove += 1;
					//zhealth += 1;
					Eye.z += 1;
				}

			}
			if (key == GLUT_KEY_DOWN) {

				if (Eye.z >= 12) {
					zmove -= 1;
					//zhealth -= 1;
					Eye.z += -1;
				}
			}
		}
		else {
			if (key == GLUT_KEY_UP && xmove > 22) {

				xmove -= 1;
				Eye.x += -1;

				/*cout << xmove;
				cout << "\n";*/
				//cout << Eye.x;
				//cout << "\n";


			}
			if (key == GLUT_KEY_DOWN && xmove < 64) {
				xmove += 1;
				Eye.x += 1;


			}
			if (key == GLUT_KEY_RIGHT && zmove > -19) {

				zmove -= 1;


			}
			if (key == GLUT_KEY_LEFT && zmove < 40) {
				zmove += 1;



			}

		}


		if (key == GLUT_KEY_END) {




			camera = false;


		}
		if (key == GLUT_KEY_HOME) {
			Eye.x = 8;
			Eye.y = 5;
			Eye.z = 20;
			xmove = 10;
			ymove = 0;
			zmove = 0;

			camera = true;
			counter = 0;
		}
	}
	else {

		if (key == GLUT_KEY_LEFT) {
			if (gameover == false) {

				if (!(xmove2 > 320)) {
					xmove2 += 2;
					//zmove2+= 0.5;
					//Eye2.z+= 0.5;
					Eye2.x += 2;
					At2.x += 2;
				}
			}

		}
		if (key == GLUT_KEY_RIGHT) {
			if (gameover == false) {
				if (!(xmove2 < -320)) {
					xmove2 -= 2;
					//zmove2+= 1;
					//Eye2.z+= 1;
					Eye2.x -= 2;
					At2.x -= 2;
				}
			}
		}

		if (key == GLUT_KEY_UP) {
			if (no == false) {
				zmove2 += 1.2;
				Eye2.z += 1.2;
			}

		}







	}

	glutPostRedisplay();
}

//=======================================================================
// Motion Function
//=======================================================================
void myMotion(int x, int y)
{
	y = HEIGHT - y;

	if (cameraZoom - y > 0)
	{
		Eye.x += -0.1;
		Eye.z += -0.1;
	}
	else
	{
		Eye.x += 0.1;
		Eye.z += 0.1;
	}

	cameraZoom = y;

	glLoadIdentity();	//Clear Model_View Matrix

	gluLookAt(Eye.x, Eye.y, Eye.z, At.x, At.y, At.z, Up.x, Up.y, Up.z);	//Setup Camera with modified paramters

	GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glutPostRedisplay();	//Re-draw scene 
}

//=======================================================================
// Mouse Function
//=======================================================================
void myMouse(int button, int state, int x, int y)
{
	
	

	cout << "click \n";

	y = HEIGHT - y;


	if (level1 == true && won==true) {
		if (state == GLUT_DOWN && x <653  && x> 434 && y > 410 && y < 447)
		{



			cout << "i am in \n";
			level1 = false;
			

		}


	}


	else {
		if (state == GLUT_DOWN)
		{
			//cameraZoom = y;

			cout << "ana dost clickkkkkkkkkkkkk\n";
			float tempx = Eye2.x;
			float tempz = Eye2.z;
			float tempy = Eye2.y;


			Eye2.x = xmove2;
			Eye2.z = zmove2;
			Eye2.y = ymove2;

			xmove2 = tempx;
			zmove2 = tempz;
			ymove2 = tempy;





			c++;




		}






	}


	glutPostRedisplay();



}

void passM(int x1, int y1)//passive motion function takes 2 parameters the x and y positions of the mouse
						//it allows the user to make use of the mouse motion without clicking on the mouse buttons
{

	if (level1 == true) {
		if (camera == true) {
			xmove = x1 / 50 - 10;
			ymove = ((HEIGHT - y1) / 50) - 10;
			/*xhealth = xmove;
			yhealth = ymove+3;*/


			Eye.x = -xmove;
			Eye.y = ymove;
		}
		else {
			ymove = ((HEIGHT - y1) / 50) - 10;
			/*cout << ymove;
			cout << "\n";*/
		}


		//zmove = (float)(x1 / 50);
		//zmove = 0;
		//cout << x1;
		//cout << "\n";
		//cout << "dakhal";
		//rlb = false;
	}



















	glutPostRedisplay();
}

//=======================================================================
// Reshape Function
//=======================================================================







void LoadAssets()
{
	// Loading Model files

//model_b1.Load("models/b1/Building Multi-storey residential N080818.3ds");
	
	
		model_bird.Load("models/bird2/Bird 1 822.3ds");
		model_bird2.Load("models/bird/Bird 3 822.3ds");
		model_b1.Load("models/b2/Factory 2 N270819.3ds");
		model_c.Load("models/c/half dollar-LowRes.3DS");


		// Loading texture files
		loadBMP(&tex2, "Textures/blu-sky-4.bmp", true);
		loadBMP(&texg, "Textures/288378.bmp", true);
		loadBMP(&greenbar, "Textures/Color-Green.bmp", true);
		loadBMP(&heart, "Textures/lives.bmp", true);
		//loadBMP(&yes, "Textures/download.bmp", true);
	

	
		// Loading Model files
		model_myfish.Load("models/myfish/angel.3ds");
		model_myfish2.Load("models/myfish2/GuppyBlueGrass0.3ds");
		model_choral.Load("models/choral/Nymphaeaceae.3ds");
		model_shark.Load("models/shark/AngelShark0.3ds");
		model_rock.Load("models/rock/Rock.3ds");
		//model_nemo.Load("models/Fish-Chaetodon_3ds/Chaetodon.3ds");
		model_shell.Load("models/clam.3ds");


		loadBMP(&yes, "Textures/download.bmp", true);
		// Loading texture files
		loadBMP(&tex, "Textures/blu-sky-3.bmp", true);



	
	








}
































void Animate()
{
	if (level1 == true) {
		EotL1 += 0.5;
		/*if (camera == false) {



			Eye.x = 49+xmove;
			Eye.z = zmove;
			Eye.y = ymove;
			cout << Eye.x;
			cout << '\n';
			cout << Eye.y;
			cout << '\n';
			cout << Eye.x;





		}*/

		if (xintensity >= 0.8) {
			switching = true;
		}

		if (xintensity <= 0.3) {
			switching = false;
		}
		if (switching == true) {
			xintensity -= 0.001;
			yintensity -= 0.001;
			zintensity -= 0.001;
		}
		else {
			xintensity += 0.001;
			yintensity += 0.001;
			zintensity += 0.001;
		}


		if (forwardshark)
		{

			moveshark += 0.01;
			if (moveshark >= 20)
				forwardshark = false;
		}
		else {
			if (moveshark < 19) {
				rlb = false;
			}
			moveshark -= 0.01;
			if (moveshark <= 0.5)
				forwardshark = true;
		}
		if (forwardfish)
		{
			movefish += 0.01;
			if (movefish >= 20)
				forwardfish = false;
		}
		else {
			movefish -= 0.01;
			if (movefish <= -12)
				forwardfish = true;
		}



		movefish2x += 0.01;

		//cout << moveshark;
		//cout << "\n";
		//-2 to 3 in x
		// 4 to 2 in y
		//-5 to -9 in z

		//cout << moveshark;
		//cout << "\n";

		//collision with SHARK  
		if (camera == true) {

			if (xmove <= 3 && xmove >= -2 && ymove <= 4 && ymove >= 2 && zmove <= 3 && zmove >= -9 && moveshark >= -2 && moveshark <= 4.5) {

				if (healthdec == false) {
					forwardshark = false;
					moveshark = 20;
					hit = hit + 1;
					healthdec = true;
					cout << hit;
					cout << "\n";
					rlb = true;


				}


				Eye.x = 8;
				Eye.y = 5;
				Eye.z = 20;







				xmove = 10;
				ymove = 0;
				zmove = 0;






				/*	cout << moveshark;
					cout << "\n";
			*/
			}

			/*cout << zmove;
			cout << "\n";*/

			//collision with normal fish

			if (ymove >= 6 && ymove <= 8 && xmove >= movefish - 1.8 && xmove <= movefish + 1.8 && zmove <= 28 && zmove >= 18) {

				/*cout << "here1";
				cout << "\n";*/

				score = score + 10;

				movefish = -20;

				/*cout <<movefish;
				cout << "\n";*/



			}

			else if (ymove >= 6 && ymove <= 8 && xmove >= movefish - 1 && xmove <= movefish + 1 && zmove < 18 && zmove >= -9) {
				/*
				cout << "here2";
				cout << "\n";*/
				score = score + 10;

				movefish = -20;
			}

			//collision with random fish



			if (ymove >= movefish2y - 1.5 && ymove <= movefish2y + 1.5 && xmove >= movefish2x - 1.5 && xmove <= movefish2x + 1.5) {

				/*cout << "here3";
				cout << "\n";*/
				score = score + 10;

				movefish2x = -20;

				/*cout <<movefish;
				cout << "\n";*/



			}
		}
		else if (camera == false) {

	


			//collision with normal fish
			if (movefish >= 15 && movefish <= 20 && xmove >=22 && xmove<=26 && zmove <= 2 && zmove >= -2 && ymove >= 5 && ymove <= 6) {

				score = score + 10;
				movefish = -20;

			}

			if (zmove <= 2 && zmove >= -2 && ymove >= movefish2y - 2 && ymove <= movefish2y + 2 && xmove >= movefish2x - 1.5 && xmove <= movefish2x + 1.5) {

				movefish2x = -20;
				score = score + 10;

				



			}
			


			//cout << ymove;// 2.5 to 3.5
			//cout << '\n';


			//cout <<

			if (xmove<=41 && xmove>=35 && zmove <= 3.8 && zmove >=-19 && moveshark >= -zmove-1 && moveshark<= -zmove+1) {


				if (healthdec == false) {
					forwardshark = false;
					moveshark = 20;
					hit = hit + 1;
					healthdec = true;
					
					rlb = true;


				}


				Eye.x = 70;
				Eye.y = 6;
				Eye.z = 0;







				xmove = 71;
				ymove = 6;
				zmove = 0;


			}



		}


	}

else {



EotL2 += 1;
while (!st1.isEmpty()) {

	s.push(st1.peek());
	st1.pop();
}

//while (!st2.isEmpty()) {

	//s2.push(st2.peek());
	//st2.pop();
//}

no = false;
no2 = false;
//Vector h = s.peek();
if (c % 2 == 0) {


	while (!s.isEmpty()) {

		Vector h = s.peek();


		if (zmove2 > (h.z - 40) && zmove2 <= (h.z + 40) && xmove2 >= (h.x - 30) && xmove2 <= (h.x + 30)) {
			no = true;
			//ymove2 = -50;
			//Eye2.y = 10;
			if (once) {

				xbar = xbar - 30;
			}

			glEnable(GL_LIGHT1);
			GLfloat l1Diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat l1Spec[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat l1Ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat l1Position[] = { xmove2,ymove2, zmove2, true };
			GLfloat l1Direction[] = { 1.0, 0.0, 0.0 };
			glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);
			glLightfv(GL_LIGHT1, GL_AMBIENT, l1Ambient);
			glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
			glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
			glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.0);
			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l1Direction);
			once = false;

			if (xbar == 30) {
				gameover = true;
			}

		}

		s.pop();
		st1.push(h);


	}





	if (no == false) {
		//zbar += 1.4;
		zmove2 += 2.5;
		//Eye2.y = 30;
		Eye2.z += 2.5;
		once = true;
		no = false;
		//ymove2 = -20;
		if (zmove2 >= 4000) {
			gameover = true;
		}

	glDisable(GL_LIGHT1);

	}

}
if (c % 2 != 0) {




	while (!s.isEmpty()) {

		Vector p = s.peek();


		if (Eye2.z > (p.z - 40) && Eye2.z <= (p.z + 40) && Eye2.x >= (p.x - 30) && Eye2.x <= (p.x + 30)) {
			no = true;
			Eye2.y = -50;

			ymove2 = 10;
			if (once) {

				xbar = xbar - 30;
			}

			glEnable(GL_LIGHT1);
			GLfloat l1Diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat l1Spec[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat l1Ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat l1Position[] = { xmove2,ymove2, zmove2, true };
			GLfloat l1Direction[] = { 1.0, 0.0, 0.0 };
			glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);
			glLightfv(GL_LIGHT1, GL_AMBIENT, l1Ambient);
			glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
			glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
			glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.0);
			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l1Direction);
			once = false;

			if (xbar == 30) {
				gameover = true;
			}
		}
		s.pop();
		st1.push(p);

	}



	if (no == false) {

		once = true;
		ymove2 = 30;
		zmove2 += 2.5;
		//zbar += 1.4;
		Eye2.y = -20;
		Eye2.z += 2.5;
		no = false;
		if (zmove2 >= 4000) {
			gameover = true;
		}
		glDisable(GL_LIGHT1);
	}


}


while (!s2.isEmpty()) {
	Vector h = s2.peek();


	if (zmove2 >= (h.z - 20) && zmove2 <= (h.z + 20) && xmove2 >= (h.x - 15) && xmove2 <= (h.x + 15)) {

		//cout << "dectedted coin \n";
		detect = true;
		s2.pop();
		Score += 5;
		//this will be added lama el detection yet3mel sa7


	   //cout << "score "<<Score;


	}

	else {
		s2.pop();
		st2.push(h);
	}




}




while (!st1.isEmpty()) {

	s.push(st1.peek());
	st1.pop();
}

while (!st2.isEmpty()) {

	s2.push(st2.peek());
	st2.pop();
}
rotc = rotc + 5;





}






















	glutPostRedisplay();
}




























//=======================================================================
// Main Function
//=======================================================================
void main(int argc, char** argv)
{

	

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(WIDTH, HEIGHT);
	
	//glutInitWindowPosition(100, 150);

	glutCreateWindow(title);



		glutDisplayFunc(myDisplay);
		if (camera) {

			glutPassiveMotionFunc(passM);
		}//call the passive motion function
		glutIdleFunc(Animate);
		//glutKeyboardFunc(myKeyboard);
		glutSpecialFunc(KeyboardSpecial);
		//glutMotionFunc(myMotion);

		
		glutTimerFunc(0, Timer, 0); // sets the Timer handler function; which runs every `Threshold` milliseconds (1st argument)

		//glutReshapeFunc(myReshape);

		//myInit();


		
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_NORMALIZE);
		glEnable(GL_COLOR_MATERIAL);

		glShadeModel(GL_SMOOTH);
		glutMouseFunc(myMouse);





	
		
		//glutDisplayFunc(myDisplay2);

		//glutKeyboardFunc(myKeyboard);
	//	glutSpecialFunc(KeyboardSpecial2);

		//glutMotionFunc(myMotion);

	//	glutMouseFunc(myMouse2);

		//glutReshapeFunc(myReshape);
	//	glutIdleFunc(Anim2);

		//myInit2();

		LoadAssets();
		//glEnable(GL_DEPTH_TEST);
		//glEnable(GL_LIGHTING);
		//glEnable(GL_LIGHT0);
		//glEnable(GL_NORMALIZE);
		//glEnable(GL_COLOR_MATERIAL);

		glShadeModel(GL_SMOOTH);




		glutMainLoop();


	

}


void Timer(int value) {
	if (level1 == true) {
		// set the ball's Y coordinate to a random number between 10 and 780 (since the window's height is 800)
		movefish2x = rand() % 40 + -15;
		movefish2y = rand() % 30 + -10;
		if (camera == false) {

			movefish2x = rand() % 64 + 22;
			movefish2y = rand() % 20 + -10;
		}


		//cout << movefish2;
	}

	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 10 seconds (10,000 milliseconds)
	glutTimerFunc(10 * 1000, Timer, 0);
}