/*
 * PreOrderVisitor.h
 *
 *  Created on: Mar 13, 2012
 *      Author: marcos
 */

#ifndef PREORDERVISITOR_H_
#define PREORDERVISITOR_H_

#include "TreeVisitor.h"

class PreOrderVisitor: public TreeVisitor {
public:
	PreOrderVisitor();

	virtual void visit(Node* node);

	virtual ~PreOrderVisitor();
};

#endif /* PREORDERVISITOR_H_ */
