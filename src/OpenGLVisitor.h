/*
 * OpenGLVisitor.h
 *
 *  Created on: Apr 13, 2012
 *      Author: thiagodnf
 */

#ifndef OPENGLVISITOR_H_
#define OPENGLVISITOR_H_

#include "TreeVisitor.h"

class OpenGLVisitor: public TreeVisitor {
public:
	OpenGLVisitor();
	virtual ~OpenGLVisitor();
	void visit(Node* root);
private:
	void visit(Node* node,int direction);
	void paint(Node* node,int direction);
};

#endif /* OPENGLVISITOR_H_ */
