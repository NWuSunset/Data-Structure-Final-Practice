#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    /*
    node* predecessor = object.getPredecessor(object.root, object.root->data);

    if (predecessor == nullptr) {
      cout << "Predecessor doesn't exist" << endl;
      return 0;
    }
    
    cout << predecessor->data << endl;
    */

    object.removeSmallestTwo();
    
    object.display();	//displays again after!
   
    return 0;
}
