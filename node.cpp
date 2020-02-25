#include"node.h"
using namespace std;

int Node::get_x() {
	return x;
}
int Node::get_y(){
	return y;
}
int Node::get_val(){
	return val;
}
Node* Node::getLeftChild(){
	return left;
}

Node* Node::getRightChild(){
	return right;
}
void Node::set_x(int x_coord){
	x = x_coord;	
}
void Node::set_y(int y_coord){
	y = y_coord;
}
void Node::set_val(int value){
	val = value;
}
void Node::set_left(int val){
	left = new Node();
	left->set_val(val);
}
void Node::set_right(int val){
	right = new Node();
	right->set_val(val);
}
// bool leftChildExists(Node* node){
// 	return if(node->getLeftChild);
// }
// bool rightChildExists(Node* node){
// 	return if(node->getRightChild)
// }
Node::Node()
{
	int x=0;
	y=0;
	val=INT_MIN;
	left=NULL;
	right=NULL;
}

Node::Node(int val)
{
	int x=0;
	y=0;
	val=INT_MIN;
	left=NULL;
	right=NULL;
}