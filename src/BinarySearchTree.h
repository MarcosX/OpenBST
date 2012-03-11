/*
 * BinarySearchTree.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "AbstractTree.h"

class BinarySearchTree: public AbstractTree {
public:
	BinarySearchTree();

	void insert(int key);
	bool search(int key);
	bool remove(int key);
	void acceptVisitor(TreeVisitor* visitor);

	void debugTree();
	void debugTree(Node* node);

	virtual ~BinarySearchTree();

private:
	Node* root;
	void removeLeftByCopy(Node* node);
	void removeRightByCopy(Node* node);
};

#endif /* BINARYSEARCHTREE_H_ */
