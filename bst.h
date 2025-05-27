//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
  node* getPredecessor(node* pos, int target);
  node* getRight(node* pos);

  void removeSmallestTwo();
  void removeMin(node* pos, node* prev);
 	
 		node * root;
private:
  void display_tree(node*, int);
};
  

