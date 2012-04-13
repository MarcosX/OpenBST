/*
 * OpenGLVisitor.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: thiagodnf
 */
#include <iostream>
#include <stack>

#include "OpenGLVisitor.h"
#include "OpenGLPainter.h"

using namespace std;

#define DIR_ROOT  1
#define DIR_LEFT  2
#define DIR_RIGHT 3

#define RADIUS	  15

OpenGLVisitor::OpenGLVisitor() {
	// TODO Auto-generated constructor stub

}

OpenGLVisitor::~OpenGLVisitor() {
	// TODO Auto-generated destructor stub
}

/*void OpenGLVisitor::visit(Node* root) {
	if (root != 0) {
		stack<Node*> stack;
		stack.push(root);
		while (!stack.empty()) {
			Node* node = stack.top();
			stack.pop();
			if (node->getLeftNode() != 0)
				stack.push(node->getLeftNode());
			if (node->getRightNode() != 0)
				stack.push(node->getRightNode());
			paint(node);
		}
	}
}*/

void OpenGLVisitor::visit(Node* root) {
	visit(root,DIR_ROOT);
}

void OpenGLVisitor::visit(Node* node,int direction) {
	if (node != 0) {
		paint(node,direction);
		if(node->getLeftNode() != 0)
			visit(node->getLeftNode(),DIR_LEFT);
		if(node->getRightNode() != 0)
			visit(node->getRightNode(),DIR_RIGHT);
	}
}


void OpenGLVisitor::paint(Node* node,int direction) {
	if(direction == DIR_ROOT){
		drawCircle(23,23,RADIUS);
		return;
	}
/*
	setBrush(glColor(0, 1, 0));

	if (this->parent == 0)
		drawLine(x, y, x, y + radius + DISTANCE_OF_TOP);

	if (right != 0)
		drawLine(x, y, right->x, right->y);
	if (left != 0)
		drawLine(x, y, left->x, left->y);

	setBrush(glColor(1.0, 1.0, 1.0));

	drawCircle(this->x, this->y, this->radius);

	setBrush(glColor(0, 0, 0));

	drawText(x, y, value);
*/
}

