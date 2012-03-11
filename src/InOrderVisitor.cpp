/*
 * InOrderVisitor.cpp
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#include "InOrderVisitor.h"

InOrderVisitor::InOrderVisitor() {
}

void InOrderVisitor::visit(Node *node) {
	if (node == NULL)
		return;
	InOrderVisitor::visit(node->getLeftNode());
	stream << "[";
	stream << node->getKey();
	stream << "]";
	InOrderVisitor::visit(node->getRightNode());
	output = stream.str();
}

InOrderVisitor::~InOrderVisitor() {
}

