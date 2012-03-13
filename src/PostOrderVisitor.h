/*
 * PostOrderVisitor.h
 *
 *  Created on: Mar 13, 2012
 *      Author: marcos
 */

#ifndef POSTORDERVISITOR_H_
#define POSTORDERVISITOR_H_

#include "TreeVisitor.h"
#include <sstream>

class PostOrderVisitor: public TreeVisitor {
public:
	PostOrderVisitor();

	virtual void visit(Node* node);

	virtual ~PostOrderVisitor();
private:
	std::stringstream stream;
};

#endif /* POSTORDERVISITOR_H_ */
