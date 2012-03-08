/*
 * InOrderVisitor.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef INORDERVISITOR_H_
#define INORDERVISITOR_H_

#include "TreeVisitor.h"
#include <iostream>

class InOrderVisitor: public TreeVisitor {
public:
	InOrderVisitor();

	void visit(Node* node);

	virtual ~InOrderVisitor();
};

#endif /* INORDERVISITOR_H_ */
