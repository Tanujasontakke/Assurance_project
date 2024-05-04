# CS567 Software Assurance_project
A project completed as part of the CS567 coursework at NAU involves testing a Cpp-based AVL tree program using DeepState. It aims to evaluate the AVL tree's functionality, Mutation Analysis, and Code Coverage.

Code Structure:
1. AVLNode::AVLNode(int data):
   - Constructor for AVLNode class.
   - Initializes a node with the given integer data, setting left and right child pointers to nullptr, and height to 1.

2. AVLTree::AVLTree():
   - Constructor for AVLTree class.
   - Initializes the root pointer to nullptr.

3. AVLTree::~AVLTree():
   - Destructor for AVLTree class.
   - Calls `destroyTree` function to recursively delete all nodes in the AVL tree.

4. AVLTree::destroyTree(AVLNode* node):
   - Recursively deletes all nodes in the AVL tree in post-order traversal.
   - Ensures the root pointer is set to nullptr after deleting all nodes.

5. AVLTree::getHeight(AVLNode* node):
   - Returns the height of the given node.
   - If the node is nullptr, returns 0.

6. AVLTree::getBalanceFactor(AVLNode* node):
   - Calculates and returns the balance factor of the given node.
   - Balance factor is the difference between the heights of the left and right subtrees.

7. AVLTree::rotateRight(AVLNode* node):
   - Performs a right rotation on the subtree rooted at the given node.
   - Adjusts heights of nodes after rotation and returns the new root of the rotated subtree.

8. AVLTree::rotateLeft(AVLNode* node):
   - Performs a left rotation on the subtree rooted at the given node.
   - Adjusts heights of nodes after rotation and returns the new root of the rotated subtree.

9. AVLTree::insertNode(AVLNode* node, int data):
   - Recursively inserts a new node with the given data into the AVL tree rooted at the given node.
   - Balances the tree if necessary after insertion.

10. AVLTree::insert(int data):
    - Public method to insert a new node with the given data into the AVL tree.
    - Calls `insertNode` internally to perform insertion.

11. AVLTree::deleteNode(AVLNode* root, int data):
    - Recursively deletes the node with the given data from the AVL tree rooted at the given node.
    - Balances the tree if necessary after deletion.

12. AVLTree::remove(int data):
    - Public method to remove the node with the given data from the AVL tree.
    - Calls `deleteNode` internally to perform deletion.

13. AVLTree::minValueNode(AVLNode* node):
    - Finds and returns the node with the minimum value in the AVL tree rooted at the given node.

14. AVLTree::display():
    - Displays the AVL tree by performing a pre-order traversal and printing the data of each node.

15. AVLTree::search(int data):
    - Searches for a node with the given data in the AVL tree.
    - Returns true if the data is found, false otherwise.

16. AVLTree::findMin():
    - Finds and returns the minimum value stored in the AVL tree.

17. AVLTree::findMax():
    - Finds and returns the maximum value stored in the AVL tree.
