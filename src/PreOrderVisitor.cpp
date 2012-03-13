/*
 * PreOrderVisitor.cpp
 *
 *  Created on: Mar 13, 2012
 *      Author: marcos
 */

#include "PreOrderVisitor.h"

PreOrderVisitor::PreOrderVisitor() {
	// TODO Auto-generated constructor stub

}

void PreOrderVisitor::visit(Node* node) {
	if (node == NULL)
		return;
	stream << "[";
	stream << node->getKey();
	stream << "]";
	PreOrderVisitor::visit(node->getLeftNode());
	PreOrderVisitor::visit(node->getRightNode());
	output = stream.str();
}

PreOrderVisitor::~PreOrderVisitor() {
	// TODO Auto-generated destructor stub
}

