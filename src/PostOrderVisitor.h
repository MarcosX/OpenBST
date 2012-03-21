/*
 * PostOrderVisitor.h
 *
 *  Created on: Mar 13, 2012
 *      Author: marcos
 */

#ifndef POSTORDERVISITOR_H_
#define POSTORDERVISITOR_H_

#include "TreeVisitor.h"

class PostOrderVisitor: public TreeVisitor {
public:
	PostOrderVisitor();

	virtual void visit(Node* node);

	virtual ~PostOrderVisitor();
};

#endif /* POSTORDERVISITOR_H_ */
