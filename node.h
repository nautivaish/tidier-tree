#include<stdlib.h>
#include<limits.h>
using namespace std;

class Node{ 
	int x;
	int y;
	Node* left;
	Node* right;
	int val;

public:
	Node();
	Node(int val);
	int get_x();
	int get_y();
	int get_val();
	void set_x(int x);
	void set_y(int y);
	void set_val( int val);
	void set_left( int val);
	void set_right( int val);
	Node* getLeftChild();
	Node* getRightChild();
	// bool leftChildExists(Node* node);
	// bool rightChildExists(Node* node);
private: 	
};

