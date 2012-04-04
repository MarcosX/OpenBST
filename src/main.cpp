#include "../test/TestRunner.h"
#include "ConsoleTreeManager.h"

int main(int argc, char **argv) {
// Este código vai executar todos os testes unitários
//	return runAllTests();
	TerminalTreeManager *manager = new TerminalTreeManager();
	manager->interactive(new PreOrderVisitor());
	return 0;
}
