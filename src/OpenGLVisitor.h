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
	void repaint();
private:
	bool isRepaint;
	int numberOfNodes(Node* node);
	void visit(Node* node, int x, int y);
	void paint(Node* node, int x, int y);
	int getHeight(Node* node);
};

#endif /* OPENGLVISITOR_H_ */
