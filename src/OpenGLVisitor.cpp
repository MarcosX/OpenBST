/*
 * OpenGLVisitor.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: thiagodnf
 */
#include <iostream>
#include <stack>
#include <cmath>

#include "OpenGLVisitor.h"
#include "OpenGLPainter.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

#define ROOT_X	  0
#define ROOT_Y	  50

#define NODE_RADIUS		  1
#define NODE_HEIGHT 	  5
#define NODE_DISTANCE_TOP 20

OpenGLVisitor::OpenGLVisitor() {
}

OpenGLVisitor::~OpenGLVisitor() {
}

int OpenGLVisitor::numberOfNodes(Node* node) {
	if (node != 0)
		return numberOfNodes(node->getLeftNode())
				+ numberOfNodes(node->getRightNode()) + 1;
	return 0;
}

void OpenGLVisitor::visit(Node* root) {
	if (isRepaint == false)
		return;
	isRepaint = false;
	if (root)
		visit(root, ROOT_X, ROOT_Y);
}

void OpenGLVisitor::visit(Node* node, int x, int y) {
	int newX;
	int newY = y - NODE_HEIGHT;
	paint(node, x, y);
	if (node->getLeftNode()) {
		newX = x
				- NODE_HEIGHT
						* ((int) pow(2.0, getHeight(node->getLeftNode()) - 1));
		drawLine(x, y, newX, newY);
		visit(node->getLeftNode(), newX, newY);
	}
	if (node->getRightNode()) {
		newX = x
				+ NODE_HEIGHT
						* ((int) pow(2.0, getHeight(node->getRightNode()) - 1));
		drawLine(x, y, newX, newY);
		visit(node->getRightNode(), newX, newY);
	}
}

void OpenGLVisitor::repaint() {
	isRepaint = true;
}

void OpenGLVisitor::paint(Node* node, int x, int y) {
	drawSphere(x, y, 0.0, NODE_RADIUS);
}

int OpenGLVisitor::getHeight(Node* node) {
	if (node == 0)
		return 0;
	int hRight = getHeight(node->getRightNode());
	int hLeft = getHeight(node->getLeftNode());
	return hRight > hLeft ? hRight + 1 : hLeft + 1;
}

