/*
 * uecegl.cpp
 *
 *  Created on: Mar 14, 2012
 *      Author: thiagodnf
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include "OpenGLPainter.h"

using namespace std;

GLenum GL_TYPE = GL_LINE_STRIP;

/**
 * Draw a point
 */
void drawPoint(float x, float y) {
	glBegin(GL_POINT);
	glVertex2f(x, y);
	glEnd();
}

void drawPoint(glPoint p) {
	drawPoint(p.x, p.y);
}

/**
 *  Draw a line
 */
void drawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINE);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glEnd();
}

void drawLine(glPoint p1, glPoint p2) {
	drawLine(p1.x, p1.y, p2.x, p2.y);
}

/**
 * Draw a Square
 */
void drawSquare(float x, float y, float side) {
	drawRectangle(x, y, side, side);
}

void drawSquare(glPoint point, float side) {
	drawRectangle(point, side, side);
}

/**
 * Draw a Rectangle
 */
void drawRectangle(float x, float y, float width, float height) {
	drawPolygon(x - width / 2, y + height / 2, x - width / 2, y - height / 2,
			x + width / 2, y - height / 2, x + width / 2, y + height / 2);
}

void drawRectangle(glPoint point, float width, float height) {
	drawRectangle(point.x, point.y, width, height);
}

/**
 * Draw a Polygon
 */
void drawPolygon(float x1, float y1, float x2, float y2, float x3, float y3,
		float x4, float y4) {
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawPolygon(glPoint p1, glPoint p2, glPoint p3, glPoint p4) {
	drawPolygon(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y);
}

/**
 * Draw a Circle
 */
void drawCircle(float x, float y, float radius, float angle) {
	glBegin(GL_TYPE);
	for (int i = 0; i < angle; i++) {
		float rad = (i * 3.14) / 180;
		float xx = x + radius * cos(rad);
		float yy = y + radius * sin(rad);
		glVertex2f(xx, yy);
	}
	glEnd();
}

void drawCircle(glPoint point, float radius, float angle) {
	drawCircle(point.x, point.y, radius, angle);
}

/**
 * Draw a Text
 */
void drawText(float posX, float posY, const char* text) {
	int center = ((sizeof(text) - 1) * 5) / 2;
	glRasterPos2i(posX - center, posY - 4);
	glutBitmapString(GLUT_BITMAP_HELVETICA_10, (const unsigned char*) text);
}

void drawText(float posX, float posY, int value) {
	char str[200];
	sprintf(str, "%d", value);
	drawText(posX, posY, str);
}

void drawText(float posX, float posY, float value) {
	char str[200];
	sprintf(str, "%f", value);
	drawText(posX, posY, str);
}

void setBrush(glColor color) {
	GL_TYPE = GL_POLYGON;
	glEnable(GL_POLYGON_STIPPLE);
	glColor3f(color.red, color.green, color.blue);
}

void drawSphere(GLfloat x, GLfloat y, GLfloat z, GLdouble radio) {
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

	glPushMatrix();
	glTranslatef(x, y, z);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glColor3f(0.2f, 0.5f, 1.0f);
	glutSolidSphere(radio, 16, 16);
	glPopMatrix();
}

