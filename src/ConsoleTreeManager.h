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

/*
 * Classe ainda em desenvolvimento
 * Faz a interação do usuário através do Terminal
 * Não possui testes :/
 */

class ConsoleTree {
public:
	ConsoleTree();
	virtual ~ConsoleTree();

	void interact(BinarySearchTree* tree);
protected:
	BinarySearchTree *tree;
	std::string input;
};

#endif /* CONSOLETREEMANAGER_H_ */
