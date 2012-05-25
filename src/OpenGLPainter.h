/*
 * uecegl.h
 *
 *  Created on: Mar 14, 2012
 *      Author: thiagodnf
 */

#ifndef GLUECE_H_
#define GLUECE_H_

class glPoint {
public:
	float x;
	float y;

	glPoint(float x, float y) {
		this->x = x;
		this->y = y;
	}
	glPoint() {
		glPoint(0, 0);
	}
};

class glColor {
public:
	float red;
	float green;
	float blue;

	glColor(float red, float green, float blue) {
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
	glColor() {
		glColor(0, 0, 0);
	}
};

void drawPoint(float x, float y);

void drawPoint(glPoint p);

void drawLine(float x1, float y1, float x2, float y2);

void drawLine(glPoint p1, glPoint p2);

void drawSquare(float x, float y, float side);

void drawSquare(glPoint point, float side);

void drawRectangle(float x, float y, float width, float height);

void drawRectangle(glPoint point, float width, float height);

void drawPolygon(float x1, float y1, float x2, float y2, float x3, float y3,
		float x4, float y4);

void drawPolygon(glPoint p1, glPoint p2, glPoint p3, glPoint p4);

void drawCircle(float x, float y, float radius, float angle = 360);

void drawCircle(glPoint point, float radius, float angle = 360);

void drawText(float posX, float posY, float posZ, const char* text);

void drawText(float posX, float posY, float posZ, int value);

void setBrush(glColor color);

void drawSphere(float x, float y, float z, double radio);

#endif /* GLUECE_H_ */
