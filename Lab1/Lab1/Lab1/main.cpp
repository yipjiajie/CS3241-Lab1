// CS3241Lab1.cpp : Defines the entry point for the console application.
// Author: Yip Jiajie (A0101924R)
// Assignment 1

#include <cmath>
#include <iostream>
#include "GL\glut.h" 
//#include "glut.h"

using namespace std;

GLfloat PI = 3.14;
float alpha = 0.0, k=5;
float tx = 0, ty=-1;

void drawFace(){
	glPushMatrix();

	glTranslatef(0,0.2,0);
	glColor3f(1.0,0.75,0);	// Orange color
	glBegin(GL_POLYGON);

	for(int i=0; i<100; i++){
		glVertex2f(1.1*sin(2.0*PI*i/100.0) , cos(2.0*PI*i/100.0));
	}

	glEnd();

	glPopMatrix();
}

void drawFaceOutline(){
	glPushMatrix();

	glTranslatef(0,0.2,0);
	glColor3f(0.867,0.671,0.384); // Grey color
	glBegin(GL_LINE_STRIP);

	for(int i=0; i<100; i++){
		glVertex2f(1.1*sin(2.0*PI*i/100.0) , cos(2.0*PI*i/100.0));
	}

	glEnd();

	glPopMatrix();

}


void drawEyebrowOutlining(double cx, double cy, float r, int startDeg, int endDeg){

	glColor3f(0.388, 0.141, 0.011);	// Brown color
	glBegin(GL_LINE_STRIP);

	for(int i=startDeg; i<=endDeg; i++){
		glVertex2f(cx+r*sin(2.0*PI*i/360.0), cy+r*cos(2.0*PI*i/360.0));
	}

	glEnd();
}

void drawRightEyebrowDarkening(double cx, double cy, float r, int startDeg, int endDeg){

	for(int j=0; j<20; j++){
		cy -= 0.001;
		cx -= 0.0001;

		glColor3f(0.388, 0.141, 0.011);	// Brown color
		glBegin(GL_LINE_STRIP);

		for(int i=startDeg; i<=endDeg; i++){
			glVertex2f(cx+r*sin(2.0*PI*i/360.0), cy+r*cos(2.0*PI*i/360.0));
		}
	
		glEnd();

	}
}

void drawLeftEyebrowDarkening(double cx, double cy, float r, int startDeg, int endDeg){

	for(int j=0; j<20; j++){
		cy -= 0.001;
		cx += 0.0001;

		glColor3f(0.388, 0.141, 0.011);	// Brown color
		glBegin(GL_LINE_STRIP);

		for(int i=startDeg; i<=endDeg; i++){
			glVertex2f(cx+r*sin(2.0*PI*i/360.0), cy+r*cos(2.0*PI*i/360.0));
		}
	
		glEnd();

	}
}

void drawEyes(double cx, double cy, int angle){

	glPushMatrix();
	glTranslatef(cx,cy,0);
	glRotatef(angle,0,0,1);

	glColor3f(0.388, 0.141, 0.011);	// Brown color
	glBegin(GL_POLYGON);

	for(int i=0; i<100; i++){
		glVertex2f(0.08*sin(2.0*PI*i/100.0) , 0.09*cos(2.0*PI*i/100.0));
	}

	//for(int i=0; i<100; i++){
	//	glVertex2f(cx+0.08*sin(2.0*PI*i/100.0) , cy+0.09*cos(2.0*PI*i/100.0));
	//}
	
	glEnd();

	glPopMatrix();
}

void drawNoseArcOutline(double cx, double cy, float r, int startDeg, int endDeg){

	glColor3f(0.388, 0.141, 0.011);	// Brown color
	glBegin(GL_LINE_STRIP);

	for(int i=startDeg; i<=endDeg; i++){
		glVertex2f(cx+4*r*sin(2.0*PI*i/360.0), cy+r*cos(2.0*PI*i/360.0));
	}

	glEnd();
}

void drawNoseArcDarkening(double cx, double cy, float r, int startDeg, int endDeg){
	
	for(int j=0; j<10; j++){
		cy -= 0.001;

		glColor3f(0.388, 0.141, 0.011);	// Brown color
		glBegin(GL_LINE_STRIP);

		for(int i=startDeg; i<=endDeg; i++){
			glVertex2f(cx+4*r*sin(2.0*PI*i/360.0), cy+r*cos(2.0*PI*i/360.0));
		}

		glEnd();

	}
}

void drawNose1(){

	glPushMatrix();

	glTranslatef(0,-0.55,0);
	glRotatef(180,0,0,1);

	glColor3f(0.388, 0.141, 0.011);	// Brown color
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0,0.03);

	glVertex2f(0.112,-0.112);
	glVertex2f(0.0784,-0.1174);
	glVertex2f(0.0224,-0.1264);
	glVertex2f(0.0112,-0.1282);

	glVertex2f(0,-0.13);

	glVertex2f(-0.0112,-0.1282);
	glVertex2f(-0.0224,-0.1264);
	glVertex2f(-0.0784,-0.1174);
	glVertex2f(-0.112,-0.112);

	glVertex2f(-0.112,-0.112);	
	
	glEnd();
	
	glPopMatrix();
}

void drawNose2() {

	glPushMatrix();
	glTranslatef(0,-0.555,0);
	glRotatef(180,0,0,1);
	glScalef(0.045,0.1,1);

	glColor3f(0.388, 0.141, 0.011);	// Brown color
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++) {
      float rad = i*3.14159/180.0;
      glVertex2f(cos(rad/2)*0.5,
                  sin(rad/2)*0.2);
	}
	
	glEnd();
	glPopMatrix(); 
}

void drawLeftEar() {
	glPushMatrix();
	glTranslatef(-0.9,0.9,0);
	glRotatef(45,0,0,1);
	glScalef(0.5,0.6,0);
	
	glColor3f(1.0,0.75,0);	// Orange color
	glBegin(GL_POLYGON);

	glVertex2f(0.4,0.2);
	glVertex2f(0.4,-0.2);
	glVertex2f(-0.4,-0.2);
	glVertex2f(-0.4,0.2);

	glEnd();

	glPopMatrix();
}

void drawLeftEarSemicircle(){

	glPushMatrix();
	glTranslatef(-0.98,0.98,0);
	glRotatef(45,0,0,1);
	glScalef(0.5,0.6,0);
	
	glColor3f(1.0,0.75,0);	// Orange color
	glBegin(GL_POLYGON);

	for(int i=0;i<360;i++) {
      float rad = i*3.14159/180.0;
      glVertex2f(cos(rad/2)*0.4,
                  sin(rad/2)*0.2);
	}
	
	glEnd();

	glPopMatrix();

}

void drawRightEar() {
	glPushMatrix();
	glTranslatef(0.9,0.9,0);
	glRotatef(315,0,0,1);
	glScalef(0.5,0.6,0);
	
	glColor3f(1.0,0.75,0);	// Orange color
	glBegin(GL_POLYGON);

	glVertex2f(0.4,0.2);
	glVertex2f(0.4,-0.2);
	glVertex2f(-0.4,-0.2);
	glVertex2f(-0.4,0.2);

	glEnd();

	glPopMatrix();
}

void drawRightEarSemicircle(){

	glPushMatrix();
	glTranslatef(0.98,0.98,0);
	glRotatef(315,0,0,1);
	glScalef(0.5,0.6,0);
	
	glColor3f(1.0,0.75,0);	// Orange color
	glBegin(GL_POLYGON);

	for(int i=0;i<360;i++) {
      float rad = i*3.14159/180.0;
      glVertex2f(cos(rad/2)*0.4,
                  sin(rad/2)*0.2);
	}
	
	glEnd();

	glPopMatrix();

}

void drawSantaHatRectangle(){
	glPushMatrix();
	glTranslatef(0,1,0);
	glScalef(1,0.5,1);

	glColor3f(0.996,0.941,0.772);	//Beige color
	glBegin(GL_POLYGON);

	glVertex2f(0.67,0.1);
	glVertex2f(0.67,-0.1);
	glVertex2f(-0.67,-0.1);
	glVertex2f(-0.67,0.1);

	glEnd();

	glPopMatrix();
}

void drawSantaHatTriangle(){

	glPushMatrix();
	glTranslatef(0,1,0);
	glScalef(2.2,3,0);

	glColor3f(0.8,0.0823,0.0078);	//Red color
	glBegin(GL_POLYGON);

	glVertex2f(0,0.5);
	glVertex2f(-0.3,0);
	glVertex2f(0.3,0);

	glEnd();

	glPopMatrix();
}

void drawSantaHatCircle() {

	glPushMatrix();
	glTranslatef(0,2.5,0);
	glScalef(0.1,0.1,1);

	glColor3f(0.996,0.941,0.772);	//Beige color
	glBegin(GL_POLYGON);

	for(int i=0;i<360;i++) {
      float rad = i*3.14159/360.0;
      glVertex2f(cos(2.0*rad),
                  sin(2.0*rad));
	}
	

	glEnd();

	glPopMatrix();

}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();

	//controls transformation
	glScalef(k, k, k);	
	glTranslatef(tx, ty, 0);	
	glRotatef(alpha, 0, 0, 1);
	
	//draw your stuff here
	drawFace();
	drawFaceOutline();
	drawEyebrowOutlining(0.4,0.1,0.17,0,90);	// Right
	drawRightEyebrowDarkening(0.4,0.1,0.17,0,90);
	drawEyebrowOutlining(-0.4,0.1,0.17,-90,0); // Left
	drawLeftEyebrowDarkening(-0.4,0.1,0.17,-90,0);
	//Rotate eyes
	drawEyes(0.35, -0.3, -20);	// Right
	drawEyes(-0.35, -0.3, 20);	// Left
	drawNoseArcOutline(0,-0.395,0.035,-90,90);
	drawNoseArcDarkening(0,-0.395,0.035,-90,90);
	drawNose1();
	drawNose2();
	drawLeftEar();
	drawLeftEarSemicircle();
	drawRightEar();
	drawRightEarSemicircle();

	drawSantaHatRectangle();
	drawSantaHatTriangle();
	drawSantaHatCircle();
	
	glPopMatrix();
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel (GL_SMOOTH);
}



void keyboard (unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {

		case 'a':
			alpha+=10;
			glutPostRedisplay();
		break;

		case 'd':
			alpha-=10;
			glutPostRedisplay();
		break;

		case 'q':
			k+=0.1;
			glutPostRedisplay();
		break;

		case 'e':
			if(k>0.1)
				k-=0.1;
			glutPostRedisplay();
		break;

		case 'z':
			tx-=0.1;
			glutPostRedisplay();
		break;

		case 'c':
			tx+=0.1;
			glutPostRedisplay();
		break;

		case 's':
			ty-=0.1;
			glutPostRedisplay();
		break;

		case 'w':
			ty+=0.1;
			glutPostRedisplay();
		break;

		default:
		break;
	}
}

/* Draws an oval centered at (x_center, y_center)
 * The oval is bound inside a rectangle whose width is w and height is h.
 * n represents the number of line segments used to draw the oval.
 *
 */



int main(int argc, char **argv)
{
	cout<<"CS3241 Lab 1\n\n";
	cout<<"+++++CONTROL BUTTONS+++++++\n\n";
	cout<<"Scale Up/Down: Q/E\n";
	cout<<"Rotate Clockwise/Counter-clockwise: A/D\n";
	cout<<"Move Up/Down: W/S\n";
	cout<<"Move Left/Right: Z/C\n";

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
