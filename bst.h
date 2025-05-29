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

  //removing smallest 2
  void removeSmallestTwo();
  void removeMin(node* &pos);

  //removign node based on input
  void removeNode(node* &rem);
  node* &getLeft(node* &node);
  node*& getNode(node* &pos, int data);

  //Write a recursive function to delete everything (individually) in the binary tree larger than the root. (No memory leaks!)
  void removeBiggerThanRoot(node* &pos);
  void removeMax(node* &pos);

  void sumOfGreaterThan10(node* pos, int &sum, int &count);

  void numLeafNodes(node* pos,int &count);

  void printInOrder(node* pos);

  void findDepth(int target);
  void findDepth(node* pos, int target, int depth);

  void deleteLeafs();
  void deleteLeafs(node* &pos);

  void duplicateToLeft();
  void duplicateToLeft(node* pos);

  void mirrorTree();
  void mirrorTree(node* pos);

  void countSingleChild();
  void countSingleChild(node* pos, int &count);
  
  node * root;
private:
  void display_tree(node*, int);
};
  

