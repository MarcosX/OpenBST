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

#define WINDOW_NAME "Main Window"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

using namespace std;

/**
 * Função callback chamada para fazer o desenho
 */
void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);	// Limpa a janela de visualização com a cor de fundo especificada

	BinarySearchTree* bst = new BinarySearchTree();

	int numbers[] = {50,35,70,31,42,36,49,47,2,99};
	int size = sizeof(numbers)/sizeof(int);

	try{
		for(int i=0;i<1;i++){
			glClear(GL_COLOR_BUFFER_BIT);
			bst->insert(numbers[i]);
			bst->acceptVisitor(new OpenGLVisitor());
			sleep(1);
		    glFlush();
		}
	}catch(const char* error){
		cerr<<error<<endl;
	}

	glFlush();
}

/**
 * Função callback chamada quando o tamanho da janela é alterado
 */
void myReshape(GLsizei w, GLsizei h){

}

void myInit(void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-4,4,-4,4);
    gluOrtho2D(0,WINDOW_WIDTH,0,WINDOW_HEIGHT);
    // gluOrtho2D(-WINDOW_WIDTH,WINDOW_WIDTH,-WINDOW_HEIGHT,WINDOW_HEIGHT);
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutInitWindowPosition(10,10);
	glutCreateWindow(WINDOW_NAME);

	//Callbacks
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	myInit();
	glutMainLoop();
}
