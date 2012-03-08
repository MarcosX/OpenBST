/*
 * Node.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

class Node {
public:
	Node(int key);

	int getKey();
	void setKey(int key);
	void setRightNode(Node *node);
	Node* getRightNode();
	void setLeftNode(Node *node);
	Node* getLeftNode();

	virtual ~Node();
private:
	int key;
	Node *rigthNode;
	Node *leftNode;
};

#endif /* NODE_H_ */
