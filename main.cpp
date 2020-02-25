#include<bits/stdc++.h>
//#include <GL/glut.h>
//#include"node.h"
//#include"glutFunctions.h"
#include"functions.h"
using namespace std;

Node *root = NULL;

void drawTree(Node* root){
	if(!root)
		return;
	drawCircle(root->get_x(), root->get_y());
	if(root->getLeftChild())
	{
		int x1, x2, y1, y2;
		x1 = root->get_x();
		y1 = root->get_y();
		x2 = root->getLeftChild()->get_x();
		y2 = root->getLeftChild()->get_y();
		drawLine(x1,y1,x2,y2);
	}
	if(root->getRightChild())
	{
		int x1, x2, y1, y2;
		x1 = root->get_x();
		y1 = root->get_y();
		x2 = root->getRightChild()->get_x();
		y2 = root->getRightChild()->get_y();
		drawLine(x1,y1,x2,y2);
	}
	drawTree(root->getLeftChild());
	drawTree(root->getRightChild());
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    // drawLine(-100,0,100,0);
    // drawLine(0,-100,0,100);

    drawTree(root);

    glFlush();

}




int main(int argc, char** argv)
{
	int n;
	cout<<"enter the no. of nodes\n";
	cin>>n;
	root = createBST(root,n);
	setCoordinates(root,0,0);

	glutInit(&argc, argv); /* initialize GLUT system */

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 1000); /* width=400pixels height=500pixels */
    glutCreateWindow("BST");     /* create window */

    /* from this point on the current window is win */

    glClearColor(0.0, 0.0, 0.0, 0.0); /* set background to black */
    gluOrtho2D(-400, 400, -500, 500); /* how object is mapped to window */
    glutDisplayFunc(drawScene); /* set window's display callback */
    // glutKeyboardFunc(keyCB); /* set window's key callback */

    glutMainLoop(); /* start processing events... */

    
    return 0;
}