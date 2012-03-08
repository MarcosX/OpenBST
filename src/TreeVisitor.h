/*
 * TreeVisitor.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef TREEVISITOR_H_
#define TREEVISITOR_H_

#include "Node.h"

class TreeVisitor {
public:
	TreeVisitor() {
	}

	virtual void visit(Node* node) {
	}

	virtual ~TreeVisitor() {
	}
};

#endif /* TREEVISITOR_H_ */
