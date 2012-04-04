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

class TerminalTreeManager {
public:
	TerminalTreeManager();
	virtual ~TerminalTreeManager();

	void interactive(TreeVisitor* visitor);
protected:
	BinarySearchTree *tree;
	TreeVisitor *visitor;
	std::string input;
};

#endif /* CONSOLETREEMANAGER_H_ */
