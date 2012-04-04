/*
 * TreeVisitor.h
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#ifndef TREEVISITOR_H_
#define TREEVISITOR_H_

#include "Node.h"
#include <iostream>
#include <sstream>

/*
 * Vitisor abstrato para árvore
 */

class TreeVisitor {
public:
	TreeVisitor() {
	}

	virtual void visit(Node* node) = 0;

	virtual std::string getOutput() {
		output = stream.str();
		stream.str("");
		return this->output;
	}

	virtual ~TreeVisitor() {
	}
protected:
	// Utilizar para armazenar os nós onde o método de visita passou
	std::stringstream stream;
	// O getOutput coloca o stream nesse output e esvazia o stream
	std::string output;
};

#endif /* TREEVISITOR_H_ */
