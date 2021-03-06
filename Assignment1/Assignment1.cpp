#include "pch.h"
#include <windows.h>
#include <GL\glut.h>
#include <GL\gl.h>
#include <math.h>

const double pi = acos(-1);
double points[10][2];

void init(void)
{
	glClearColor(21.0/255.0, 21.0/255.0, 21.0/255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 880.0, 0.0, 570.0);
}

void rotatePoint(double &x, double &y, double deg) {
	deg = (deg * pi) / 180.0;
	double tmpX = x;
	double tmpY = y;
	x = tmpX * cos(deg) - tmpY * sin(deg);
	y = tmpX * sin(deg) + tmpY * cos(deg);
}

void shiftPoints(double dX, double dY) {
	for (int i = 0; i < 10; i++) {
		points[i][0] += dX;
		points[i][1] += dY;
	}
}

void pentagon() {
	glBegin(GL_POLYGON);

	points[0][0] = 0;
	points[0][1] = 120;
	for (int i = 1; i < 5; i++) {
		points[i][0] = points[i - 1][0];
		points[i][1] = points[i - 1][1];
		rotatePoint(points[i][0], points[i][1], 72.0);
	}
	shiftPoints(130, 120);
	for (int i = 0; i < 5; i++) {
		glVertex2dv(points[i]);
	}

	glEnd();
}

void hexagon() {
	glBegin(GL_POLYGON);

	points[0][0] = 120;
	points[0][1] = 0;
	for (int i = 1; i < 6; i++) {
		points[i][0] = points[i - 1][0];
		points[i][1] = points[i - 1][1];
		rotatePoint(points[i][0], points[i][1], 60.0);
	}
	shiftPoints(430, 125);
	for (int i = 0; i < 6; i++) {
		glVertex2dv(points[i]);
	}

	glEnd();
}

void heptagon() {
	glBegin(GL_POLYGON);

	points[0][0] = 0;
	points[0][1] = 120;
	for (int i = 1; i < 7; i++) {
		points[i][0] = points[i - 1][0];
		points[i][1] = points[i - 1][1];
		rotatePoint(points[i][0], points[i][1], 360.0 / 7.0);
	}
	shiftPoints(730, 125);
	for (int i = 0; i < 7; i++) {
		glVertex2dv(points[i]);
	}

	glEnd();
}

void octagon() {
	glBegin(GL_POLYGON);

	points[0][0] = 0;
	points[0][1] = 120;
	for (int i = 1; i < 8; i++) {
		points[i][0] = points[i - 1][0];
		points[i][1] = points[i - 1][1];
		rotatePoint(points[i][0], points[i][1], 45);
	}
	shiftPoints(130, 420);
	for (int i = 0; i < 8; i++)
		glVertex2dv(points[i]);

	glEnd();
}

void nonagon() {
	glBegin(GL_POLYGON);

	points[0][0] = 0;
	points[0][1] = 120;
	for (int i = 1; i < 9; i++) {
		points[i][0] = points[i - 1][0];
		points[i][1] = points[i - 1][1];
		rotatePoint(points[i][0], points[i][1], 40);
	}
	shiftPoints(430, 420);
	for (int i = 0; i < 9; i++) {
		glVertex2dv(points[i]);
	}

	glEnd();
}

void decagon() {
	glBegin(GL_POLYGON);

	points[0][0] = 120;
	points[0][1] = 0;
	for (int i = 1; i < 10; i++) {
		points[i][0] = points[i - 1][0];
		points[i][1] = points[i - 1][1];
		rotatePoint(points[i][0], points[i][1], 36);
	}
	shiftPoints(730, 420);
	for (int i = 0; i < 10; i++) {
		glVertex2dv(points[i]);
	}

	glEnd();
}

void separators() {

}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 183.0/255.0f, 156.0/255.0f);

	pentagon();
	hexagon();
	heptagon();
	octagon();
	nonagon();
	decagon();

	glBegin(GL_LINES);
	glVertex2i(0, 268);
	glVertex2i(880, 268);

	glVertex2i(277, 0);
	glVertex2i(277, 570);

	glVertex2i(580, 0);
	glVertex2i(580, 570);

	glEnd();

	glFlush();
}

void main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(250, 20);

	glutInitWindowSize(880, 570);
	glutCreateWindow("Shapes");

	init();
	glutDisplayFunc(drawShapes);
	glutMainLoop();

}