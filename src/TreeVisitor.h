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
#include <sstream>

class TreeVisitor {
public:
	TreeVisitor() {
	}

	virtual void visit(Node* node) = 0;

	virtual std::string getOutput() {
		output = stream.str();
		stream.str("");
		return this->output;
	}

	virtual ~TreeVisitor() {
	}
protected:
	std::string output;
	std::stringstream stream;
};

#endif /* TREEVISITOR_H_ */
