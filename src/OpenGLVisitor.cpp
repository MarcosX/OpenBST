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

#define ROOT_X	  50
#define ROOT_Y	  0

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
	visit(root->getLeftNode(), ROOT_X - NODE_HEIGHT, ROOT_Y - NODE_HEIGHT);
	visit(root->getRightNode(), ROOT_X - NODE_HEIGHT, ROOT_Y + NODE_HEIGHT);
}

void OpenGLVisitor::visit(Node* node, int x, int y) {
	if (node != 0) {
		paint(node, x, y);
		if (node->getLeftNode() != 0)
			visit(node->getLeftNode(), x - NODE_HEIGHT, y - NODE_HEIGHT);
		if (node->getRightNode() != 0)
			visit(node->getRightNode(), x - NODE_HEIGHT, y + NODE_HEIGHT);
	}
}

void OpenGLVisitor::repaint() {
	isRepaint = true;
}

void OpenGLVisitor::paint(Node* node, int x, int y) {
	drawSphere(x, y, 10.0, NODE_RADIUS);
}

