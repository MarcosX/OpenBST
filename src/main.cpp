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

#define WINDOW_NAME   "BST in OpenGL"
#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 640

using namespace std;
bool glLock = false;

/**
 * Função callback chamada para fazer o desenho
 */
void myDisplay(void) {
	if (glLock)
		return;
	glLock = true;

	BinarySearchTree* bst = new BinarySearchTree();
	ConsoleTree* console = new ConsoleTree();
	std::cout << "\nOperadores: [ + | - | = ]\nExemplo"
			"\n\t +10 insere elemento 10"
			"\n\t =10 busca elemento 10"
			"\n\t -10 remove elemento 10";
	while (true) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		console->interact(bst);
		bst->acceptVisitor(new OpenGLVisitor());
		glFlush();
	}

	glFlush();
}

/**
 * Função callback chamada quando o tamanho da janela é alterado
 */
void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, 0.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void myInit(void) {

	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3.0, 1.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(10, 10);
	glutCreateWindow(WINDOW_NAME);

	//Callbacks
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	myInit();
	glutMainLoop();
}
