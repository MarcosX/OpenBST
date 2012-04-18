/*
 * AbstractTree.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef ABSTRACTTREE_H_
#define ABSTRACTTREE_H_

#include "Node.h"
#include "TreeVisitor.h"

class AbstractTree {
public:
	AbstractTree();
	virtual bool insert(int key) = 0;
	virtual bool search(int key) = 0;
	virtual bool remove(int key) = 0;
	virtual void acceptVisitor(TreeVisitor* visitor) = 0;

	virtual ~AbstractTree();
};

#endif /* ABSTRACTTREE_H_ */
