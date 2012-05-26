/*
 #include "../test/TestRunner.h"
 #include "ConsoleTreeManager.h"

 int main(int argc, char **argv) {
 // Este código vai executar todos os testes unitários
 //	return runAllTests();
 TerminalTreeManager *manager = new TerminalTreeManager();
 manager->interactive(new PreOrderVisitor());
 return 0;
 }
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "BinarySearchTree.h"
#include "OpenGLVisitor.h"
#include "ConsoleTreeManager.h"
#include "OpenGLPainter.h"

#define WINDOW_NAME   "BST in OpenGL"
#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 640

using namespace std;
bool glLock = false;
GLdouble oX = 0, oY = 0, oZ = 100;
GLfloat angle, fAspect;

BinarySearchTree* bst;
ConsoleTree* console;
OpenGLVisitor* visitor;

/**
 * Função callback chamada para fazer o desenho
 */
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	drawAxis3D();

	bst->acceptVisitor(visitor);

	// Executa os comandos OpenGL
	glutSwapBuffers();

}

void EspecificaParametrosVisualizacao(void) {
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.5, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(oX, oY, oZ, 0, 50, 0, 0, 1, 0);

	visitor->repaint();
}

void myInit(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angle = 45;
	bst = new BinarySearchTree();
	console = new ConsoleTree();
	visitor = new OpenGLVisitor();
	std::cout << "'c' para acesssar a linha de comando:"
			"\nOperadores: [ + | - | = ]\nExemplo"
			"\n\t +10 insere elemento 10"
			"\n\t =10 busca elemento 10"
			"\n\t -10 remove elemento 10";
}

/**
 * Função callback chamada quando o tamanho da janela é alterado
 */
void myReshape(GLsizei w, GLsizei h) {
	// Para previnir uma divisão por zero
	if (h == 0)
		h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat) w / (GLfloat) h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y) {
	switch (key) {
	case 'W':
	case 'w': // muda a cor corrente para vermelho
		oX += 15.0;
		break;
	case 'A':
	case 'a': // muda a cor corrente para verde
		oY += 15.0;
		break;
	case 'S':
	case 's': // muda a cor corrente para azul
		oX -= 15.0;
		break;
	case 'D':
	case 'd': // muda a cor corrente para azul
		oY -= 15.0;
		break;
	case 'C':
	case 'c':
		glClear(GL_COLOR_BUFFER_BIT);
		console->interact(bst);
		break;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(10, 10);
	glutCreateWindow(WINDOW_NAME);

	//Callbacks
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclado);
	myInit();
	glutMainLoop();
}
