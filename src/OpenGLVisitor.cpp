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
	paint(root, ROOT_X, ROOT_Y);
	int newX = ROOT_X
			- NODE_HEIGHT
					* ((int) pow(2.0, getHeight(root->getLeftNode()) - 1));
	visit(root->getLeftNode(), newX, ROOT_Y - NODE_HEIGHT);
	newX = ROOT_X
			+ NODE_HEIGHT
					* ((int) pow(2.0, getHeight(root->getRightNode()) - 1));
	visit(root->getRightNode(), newX, ROOT_Y - NODE_HEIGHT);
}

void OpenGLVisitor::visit(Node* node, int x, int y) {
	if (node != 0) {
		paint(node, x, y);
		if (node->getLeftNode() != 0) {
			int newX = x
					- NODE_HEIGHT
							* ((int) pow(2.0,
									getHeight(node->getLeftNode()) - 1));
			visit(node->getLeftNode(), newX, y - NODE_HEIGHT);
		}
		if (node->getRightNode() != 0) {
			int newX = x
					+ NODE_HEIGHT
							* ((int) pow(2.0,
									getHeight(node->getRightNode()) - 1));
			visit(node->getRightNode(), newX, y - NODE_HEIGHT);
		}
	}
}

void OpenGLVisitor::repaint() {
	isRepaint = true;
}

void OpenGLVisitor::paint(Node* node, int x, int y) {
	drawSphere(x, y, 10.0, NODE_RADIUS);
}

int OpenGLVisitor::getHeight(Node* node) {
	if (node == 0)
		return 0;
	int hRight = getHeight(node->getRightNode());
	int hLeft = getHeight(node->getLeftNode());
	return hRight > hLeft ? hRight + 1 : hLeft + 1;
}

