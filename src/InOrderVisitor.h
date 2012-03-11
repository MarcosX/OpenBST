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
#include <sstream>

class InOrderVisitor: public TreeVisitor {
public:
	InOrderVisitor();

	virtual void visit(Node* node);

	virtual ~InOrderVisitor();
private:
	std::stringstream stream;
};

#endif /* INORDERVISITOR_H_ */
