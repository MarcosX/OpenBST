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

#define DIR_ROOT  1
#define DIR_LEFT  2
#define DIR_RIGHT 3

#define NODE_RADIUS	  		  15
#define NODE_HEIGHT 	  40
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
	visit(root, DIR_ROOT, 320, 640 - NODE_DISTANCE_TOP - NODE_RADIUS);
}

void OpenGLVisitor::visit(Node* node, int direction, int x, int y) {
	if (node != 0) {
		paint(node, direction, x, y);
		if (node->getLeftNode() != 0)
			visit(node->getLeftNode(), DIR_LEFT, x, y - NODE_HEIGHT);
		if (node->getRightNode() != 0)
			visit(node->getRightNode(), DIR_RIGHT, x, y - NODE_HEIGHT);
	}
}

void OpenGLVisitor::paint(Node* node, int direction, int &x, int y) {
	int nodes = 0;
	int parent_x = x;
	int parent_y = y + NODE_HEIGHT;

	if (direction == DIR_RIGHT) {
		if (node->getLeftNode() != 0)
			nodes = numberOfNodes(node->getLeftNode());
		x += 40 * (nodes + 1);
	}
	if (direction == DIR_LEFT) {
		if (node->getRightNode() != 0)
			nodes = numberOfNodes(node->getRightNode());
		x -= 40 * (nodes + 1);
	}

	//Draw the Edge
	setBrush(glColor(0, 1, 0));

// Correção da ligação sobre o nó pai. Antes, a linha era desenhada por cima do nó pai.
// Com isso, ela é desenhada na borda do nó do pai
	float prop = NODE_RADIUS
			/ sqrt(pow(float(parent_x - x), 2) + pow(float(parent_y - y), 2));
	parent_x -= (parent_x - x) * prop;
	parent_y -= (parent_y - y) * prop;

	if (direction == DIR_ROOT)
		drawLine(320, 640, x, y);
	else
		drawLine(parent_x, parent_y, x, y);

	drawSphere(x, y, 10.0, NODE_RADIUS);

// Draw the Key
	setBrush(glColor(0, 0, 0));
	drawText(x, y, node->getKey());
}

