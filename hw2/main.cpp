/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };







void problem1() {
    // TODO: Your code here!
	
/*refrence 
	General Idea  
	https://community.khronos.org/t/how-to-draw-circle/59661/2
	https://github.com/Mustafallica/OpenGL-3D/blob/master/hw2.cpp
*/

	//Read the total teapots to display on screen
	int totalTeapots = 10;

	// Calulcate the  distance between the teapots

	int distance = 360/10;
	// physical Size of teapots


	GLdouble teapotSize = 0.25;
	int currAngle = 0;
	
	/* note that this loop will run n times where n is the number of teapots */
	while(currAngle < 360)
	{
		glPushMatrix();
		// pass the current angle and rotate on Z axis only
		// Set the teapot to Translate by 1 on X
		// The value of increasing currAngle is what populates the teapot at that position.
		glRotatef(currAngle,0,0,1.0);

		// Distance each teapot is from the center 1 is used to resemble image;
		glTranslatef(1.0,0,0);

		//Draw Teapot
		glutSolidTeapot(teapotSize);
		// Pop Matrix
		glPopMatrix();
		//Increment current angle to position next teapot.
		currAngle += distance;


	}



}

void problem2() {
    // TODO: Your code here!
	
	
	int totalSteps = 15;
	float len = -1.0;
	// The first matrix is to set the starting postion of the "Stairs"
	//Set X to the left of screen
	

	// We need two loops to create this pattern
	for(int i = 0; i < totalSteps; i++)
	{
		glPushMatrix();
		glTranslatef(len,0,0);
		for(int j =0; j <= i; j++)
		{
			/* This second Matrix is to  the x position based and scale on the current step Ie "move" the box more the right each time
			.15 was chosen after trial and error to make it resemble the picture provided*/
			glPushMatrix();
				glTranslatef(0.15*i,0,0);

				/* The third Matrix here is to set the Y postion for the box since the box increases in the Y direction giving it the step
				illusion note 0.025 was chosen out of trial and error to resesmble the picture provided"
				*/ 
		
					glPushMatrix();
						glTranslatef(0.0,j*0.025,0);
						//Draw Box
						glutSolidCube(0.2);
						// Pop 3rd Matrix call
						glPopMatrix();

			// Pop Second Matrix Call
			glPopMatrix();
		}
		glPopMatrix();
	}
	// Pop first Matrix Call
	

	


}

// Refrence https://www.programiz.com/cpp-programming/examples/pyramid-pattern

void problem3() {

	// Get total number of rows for the teapot pyramid
	int totalRows = 6;
	//Inital starting postion of first teapot
	float incX = 0;
	float incY = 1;

// We need 2 for loops the outer is for each row and the inner 
// is to get the number of teapots for that row so row 1 = 1 teapot row 2 = 2 teapots etc

	for(int i = 1; i <= totalRows; i++)
	{
		for(int j = 1; j <= (2 *i-1); j++)
		{
			// Push Matrix
			glPushMatrix();
			//Set postions for x and y not changing Z
			glTranslatef(incX,incY,0.0);
			//draw the teapot
			glutSolidTeapot(0.2);
			glPopMatrix();
			// Increase spacing between teapots value chosen on trial and error to closley remeble image
			incX += 0.6;
		}

		// make current value of x negtive to make the rows appear like a pyramid
		incX = 0 - incX;
		// vertical spacing between rows chosen to resemble image
		incY -= 0.4;
		
	}
    // TODO: Your code here!

}


void problem4() {
    // TODO: Your code here!
	//Ref https://en.wikibooks.org/wiki/OpenGL_Programming/GLStart/Tut3#Immediate_Mode

    glBegin(GL_TRIANGLES);//start drawing triangles
		glTranslatef(0.0,0.0,0.5);
      glVertex3f(0.0f,-0.25f,0.0f);//triangle one first vertex
      glVertex3f(-0.25f,0.25f,0.0f);//triangle one second vertex
      glVertex3f(0.25f,0.25,0.0f);//triangle one third vertex
    glEnd();//end drawing of triangles



	// https://www.glprogramming.com/red/chapter03.html
	float pieceSize = 0.1;


	//First finger
	glPushMatrix();
		glTranslatef(0.15,0.27,-0.1);
			glPushMatrix();
				glTranslatef(0.0,0.02,0.0);
				glutSolidCube(pieceSize+0.02);

			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.15,0.0);
				glutSolidCube(pieceSize+0.02);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.28,0.0);
				glutSolidCube(pieceSize+0.02);
			glPopMatrix();
	glPopMatrix();

	//Second Finger
	glPushMatrix();
		glTranslatef(0.0,0.27,-0.1);
			glPushMatrix();
				glTranslatef(0.0,0.02,0.0);
				glutSolidCube(pieceSize+0.02);

			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.15,0.0);
				glutSolidCube(pieceSize+0.02);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.28,0.0);
				glutSolidCube(pieceSize+0.02);
			glPopMatrix();
	glPopMatrix();

	//Third finger

		glPushMatrix();
		glTranslatef(-0.15,0.27,0.05);
			glPushMatrix();
				glTranslatef(0.0,0.02,-0.03);
				glRotatef(20,1.0,0.0,0.0);
				glutSolidCube(pieceSize);

			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.15,0.0);
				glRotatef(20,1.0,0.0,0.0);
				glutSolidCube(pieceSize);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.28,0.05);
				glRotatef(70,1.0,0.0,0.0);
				glutSolidCube(pieceSize);
			glPopMatrix();
	glPopMatrix();

	//Fourth Finger

	
		glPushMatrix();
		glTranslatef(-0.300,0.20,0.03);
			glPushMatrix();
				glTranslatef(0.0,0.02,-0.03);
				glRotatef(20,1.0,0.0,0.0);
				glutSolidCube(pieceSize);

			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.15,0.08);
				glRotatef(20,1.0,0.0,0.0);
				glutSolidCube(pieceSize);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.28,0.13);
				glRotatef(70,1.0,0.0,0.0);
				glutSolidCube(pieceSize);
			glPopMatrix();
	glPopMatrix();

	//Thumb

	glPushMatrix();
		glTranslatef(0.25,-0.05,0.0);

			glPushMatrix();
			glScalef(1.5,1.0,1.0);
			glRotatef(25,0.0,0.0,1.0);
			glutSolidCube(pieceSize);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.05,0.13,0.03);
				glRotatef(25,1.0,0.0,0.0);
				glutSolidCube(pieceSize);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,0.20,0.06);
				glRotatef(25,1.0,0.0,0.0);
				glutSolidCube(pieceSize);
			glPopMatrix();

	glPopMatrix();




}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
