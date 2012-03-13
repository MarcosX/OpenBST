/*
 * PostOrderVisitor.cpp
 *
 *  Created on: Mar 13, 2012
 *      Author: marcos
 */

#include "PostOrderVisitor.h"

PostOrderVisitor::PostOrderVisitor() {
	// TODO Auto-generated constructor stub

}

void PostOrderVisitor::visit(Node* node) {
	if (node == NULL)
		return;
	PostOrderVisitor::visit(node->getLeftNode());
	PostOrderVisitor::visit(node->getRightNode());
	stream << "[";
	stream << node->getKey();
	stream << "]";
	output = stream.str();
}

PostOrderVisitor::~PostOrderVisitor() {
	// TODO Auto-generated destructor stub
}

