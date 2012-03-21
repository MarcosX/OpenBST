/*
 * ConsoleTreeManager.h
 *
 *  Created on: Mar 20, 2012
 *      Author: marcos
 */

#ifndef CONSOLETREEMANAGER_H_
#define CONSOLETREEMANAGER_H_

#include "PreOrderVisitor.h"
#include "InOrderVisitor.h"
#include "PostOrderVisitor.h"
#include "BinarySearchTree.h"
#include <cstdlib>

class ConsoleTreeManager {
public:
	ConsoleTreeManager();
	virtual ~ConsoleTreeManager();

	void interactive(TreeVisitor* visitor);
protected:
	BinarySearchTree *tree;
	TreeVisitor *visitor;
	std::string input;
};

#endif /* CONSOLETREEMANAGER_H_ */
