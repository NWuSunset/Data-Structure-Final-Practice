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

    //    object.removeSmallestTwo();

    //remember to have all by reference in order for it to work
    //node* &rem = object.getNode(object.root, 10);
    //object.removeNode(rem);

    //object.removeBiggerThanRoot(object.root);


    /*
    int sum = 0;
    int count = 0;
    object.sumOfGreaterThan10(object.root, sum, count);
    cout << sum << endl;
    cout << count << endl;
    */

    //int leafCount = 0;
    //object.numLeafNodes(object.root, leafCount);

    //object.printInOrder(object.root);
    //cout << endl;
    //cout << leafCount << endl;

    //object.findDepth(10);

    //object.deleteLeafs();

    //object.duplicateToLeft();

    //object.mirrorTree();

    object.countSingleChild();
    
    object.display();	//displays again after!
   
    return 0;
}
