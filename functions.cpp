#include"functions.h"
//#include"glutFunctions.h"
//#include"node.h"
using namespace std;
int MinSep;
int rightmost[10] = {-10000,-10000,-10000,-10000,-10000,-10000,-10000,-10000,-10000,-10000};

void drawPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
}
void drawLine(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);    
    glVertex2d(x1,y1*MinSep/2);
    glVertex2d(x2,y2*MinSep/2);
    glEnd();
}
void drawCircle(int x, int y){
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable( GL_POINT_SMOOTH );
	glPointSize(10);
	glBegin(GL_POINTS);
    glVertex2d(x,y*MinSep/2);
    glEnd();
    glDisable(GL_POINT_SMOOTH);
}


Node* createBST(Node* root, int n){
	int bstarray[n];
	cout<<"enter the BST array\n";
	for(int i=0; i<n; i++)
	{
		cin>>bstarray[i];
	}

	int i,j;
    Node *temp = new Node();
    for(i=0;i<n;i++)
    {
        temp = root;
        if(!root)
        {
        	root = new Node();
        	root->set_val(bstarray[i]);
        	continue;
        }
        while(temp->getLeftChild() || temp->getRightChild())
        {
	        if(temp->getLeftChild() && bstarray[i] < temp->get_val())
	        	temp = temp->getLeftChild();
	        else if(temp->getRightChild() && bstarray[i] > temp->get_val())
	        	temp = temp->getRightChild();
	        else break;
        }
        if(bstarray[i] < temp->get_val())
        {
        	temp->set_left( bstarray[i]);
        }
        else if(bstarray[i] > temp->get_val())
        {
        	temp->set_right(bstarray[i]);
        }
    }

    cout<<"enter the minimum separation you want between any two nodes\n";
    cin>>MinSep;
	return root;
}

void setCoordinates(Node* root, int x, int y){
	if(!root)
		return;
	if(x - rightmost[-y] < MinSep)
		x = rightmost[-y]+MinSep;
	root->set_x(x);
	root->set_y(y);
	if(root->getLeftChild())
		setCoordinates(root->getLeftChild(), x-MinSep/2, y-1);
	if(root->getRightChild())
		setCoordinates(root->getRightChild(), x+MinSep/2, y-1);
	if(root->getRightChild() && root->getLeftChild())
	{
		int midx = root->getRightChild()->get_x() + root->getLeftChild()->get_x();
		midx/=2;
		root->set_x(midx);
	}
	else if(root->getLeftChild())
	{
		int midx = root->getLeftChild()->get_x() + MinSep/2;
		root->set_x(midx);
	}
}

