#include "bst.h"

bst::bst(){root = NULL;}

void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}

//previous node in inorder traversal (the next smaller number)
node* bst::getPredecessor(node* pos, int target) {
  if (pos == nullptr) {
    return nullptr;
  }

  if (target < pos->data) { //if less than go left
    return getPredecessor(pos->left, target);
  } else if (target > pos->data) { //if greater go right.
    return getPredecessor(pos->right, target);
  } else { // once we hit the target (the predecessor is rightmost node of the left subtree
    node* curr = pos;

    if (curr->left != nullptr) { //if left subtre exits
      curr = curr->left;
      //while (curr->right != nullptr) {
      //curr = curr->right;
      
      return getRight(curr);
    //return curr;
    }
   }
  }

//gets rightmost of subtree
node* bst::getRight(node* pos) {
  if (pos->right == nullptr) {
    return pos;
  }

  return getRight(pos->right);
}


//go leftmost and delete parent and leaf
void bst::removeSmallestTwo() {
 
  removeMin(root);
  removeMin(root);
  
}

void bst::removeMin(node* &pos) {
  if (pos == nullptr) {
    return;
  }

  if (pos->left != nullptr) {
    removeMin(pos->left); //go left (once it returns it will become null)
  } else { //once left is nul
    node* temp = pos;
    pos = pos->right; //set pos to it's right (since we deelte position it will become null if there is no right poitner) (since we are using by refrence we don't need to change it relative to it's parent either.
    delete temp;
  }
}

void bst::removeNode(node* &rem) {
  if (rem->left == nullptr) {
    node* temp = rem;
    rem = rem->right;
    delete temp;
  } else if (rem->right == nullptr) {
    node* temp = rem;
    rem = rem->left;
    delete temp;
  } else { //swap values i n order sucessor or predecessor (leftmost of right subtree or rightmost of left subtree)
    node* &s = getLeft(rem->right);

    //swpa sucessor and rem data.
    rem->data = s->data;
    removeNode(s); //now delete the sucessor
  }
}

//go all the way left
node* & bst::getLeft(node* &node) {
  if (node->left == nullptr) {
    return node;
  }

  return getLeft(node->left);
}

node* & bst::getNode(node* &pos, int data) {
  if (pos == nullptr) {
    throw std::runtime_error("Node not found in tree");
  }

  if (pos->data == data) {
    return pos;
  } 

  if (data < pos->data) {
    return getNode(pos->left, data);
  } else if (data > pos->data) {
    return getNode(pos->right, data);
  }
  
}

void bst::removeBiggerThanRoot(node* &pos) {
  if (pos == nullptr || root == nullptr) {
    return;
  }
  
  if (pos->right != nullptr) { //while the right side of the tree still exists
    removeMax(pos); //rempove the max
    removeBiggerThanRoot(pos);
  }

  //'faster' method:
  /*
    if (pos->data > root->data) {
         removeNode(pos);
	 removeBiggerTHanRoot(node); //recheck pointer
    } else {
    removeBiggerTHanRoot(pos->right);
    }
   */
  
  //one the right == null return
  return;
}

void bst::removeMax(node* &pos) {
  if (pos == nullptr) {
    return;
  }
  
  //go down right
  if (pos->right == nullptr) { //if we are at the greatest
    //delete the minimum (replace with it's left)
    node* temp = pos;
    pos = pos->left;
    delete temp;
    return;
  }

  removeMax(pos->right);

  
}

void bst::sumOfGreaterThan10(node* pos, int &sum, int &count) {
  //end one we have gon through entire tree
  if (pos == nullptr) {
    return;
  }
  //add to sum if num is greater than 10
  if (pos->data > 10) {
    sum += pos->data;
    count++;
  }
  
  //traverse thorugh tree
  if (pos->data < 10) {  //if position data is less than 10
    sumOfGreaterThan10(pos->right, sum, count); //all left values are lower than 10 then
  } else if (pos->data > 10) {
    sumOfGreaterThan10(pos->right, sum, count); //first go right tree
    sumOfGreaterThan10(pos->left, sum, count); //then left tree
  }
}


void bst::numLeafNodes(node* pos, int &count) {
  if (pos == nullptr) {
    return;
  }

  if (pos->left == nullptr && pos->right == nullptr) {
    count++;
    return;
  }

  //traversal
  numLeafNodes(pos->right, count); //first right subtree
  numLeafNodes(pos->left, count);  //then left subtree
}

void bst::printInOrder(node* pos) {
  if (pos == nullptr) {
    return;
  }

  //first go left, then root, then right
  printInOrder(pos->left);
  std::cout << pos->data << " "; //root print
  printInOrder(pos->right);
}


void bst::findDepth(int target) {
  
  findDepth(root, target, 0);
}

//find node depth (root depth = 0)
void bst::findDepth(node* pos, int target, int depth) {
  if (pos == nullptr) {
    std::cout << "not found" << std::endl;
    return;
  }

  
  if (pos != nullptr  && pos->data == target) {
    std::cout << "Depth of " << target << " is: " << depth << endl;
    return;
  }

  if (pos->data < target) {
    findDepth(pos->right, target, depth+1);
  } else if (pos->data > target) {
    findDepth(pos->left, target, depth+1);
  }
}

void bst::deleteLeafs() {
  deleteLeafs(root);
}
void bst::deleteLeafs(node* &pos) {
  if (pos == nullptr) {
    return;
  }

  //if is leaf
  if (pos->left == nullptr && pos->right == nullptr) {
    node* temp = pos;
    pos = nullptr;
    delete temp;
    return;
  }

  //traversal
  deleteLeafs(pos->right); //go right
  deleteLeafs(pos->left); //then left
 }

void bst::duplicateToLeft() {
  duplicateToLeft(root);
}

//duplicates a node and add it as it's original left child
void bst::duplicateToLeft(node* pos) {
  if (pos == nullptr) {
    return;
  }
  
  //left root right
  duplicateToLeft(pos->left);
  duplicateToLeft(pos->right);

  
  //perform duplication (no parent pointers ...)
  node* newNode = new node();
  newNode->data = pos->data;
  newNode->left = pos->left;
  newNode->right = nullptr;
  pos->left = newNode;
  
  //duplicateToLeft(pos->right);
  
}

void bst::mirrorTree() {
  mirrorTree(root);
}

//mirrors the binary tree (left = right) , except root
void bst::mirrorTree(node* pos) {
  if (pos == nullptr) {
    return;
  }

  //int temp = pos->data; //save the position data
  mirrorTree(pos->right);
  mirrorTree(pos->left);

  //swap the datas
  node* temp = pos->right;
  pos->right = pos->left;
  pos->left = temp;
}

void bst::countSingleChild() {
  int count = 0;
  countSingleChild(root, count);
  std::cout << "Number of nodes with single child: " << count << std::endl;
}

void bst::countSingleChild(node* pos, int &count) {
  if (pos == nullptr) {
    return;
  }

  //if it has only one child
  if ((pos->left == nullptr && pos->right != nullptr) || (pos->right == nullptr && pos->left != nullptr) ) {
    count++;
  }

  countSingleChild(pos->right, count);
  countSingleChild(pos->left, count);
}


