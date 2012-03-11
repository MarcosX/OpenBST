/*
 * TreeVisitor.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef TREEVISITOR_H_
#define TREEVISITOR_H_

#include "Node.h"
#include <iostream>

class TreeVisitor {
public:
	TreeVisitor() {
	}

	virtual void visit(Node* node) = 0;

	virtual std::string getOutput() {
		return this->output;
	}

	virtual ~TreeVisitor() {
	}
protected:
	std::string output;
};

#endif /* TREEVISITOR_H_ */
