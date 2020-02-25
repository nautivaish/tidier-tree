#include<bits/stdc++.h>
//#include"glutFunctions.h"
#include <GL/glut.h>
#include"node.h"

using namespace std;
Node* createBST(Node* root, int n);
void setCoordinates(Node* root, int x, int y);
//void drawTree(Node* root);

void drawPoint(int x, int y);
void drawLine(int x1, int y1, int x2, int y2);
void drawCircle(int x, int y);