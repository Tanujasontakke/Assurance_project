#ifndef AVL_H
#define AVL_H

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int data);
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* insertNode(AVLNode* node, int data);
    AVLNode* deleteNode(AVLNode* root, int data);
    AVLNode* minValueNode(AVLNode* node);
    void preOrderTraversal(AVLNode* node);
    void inOrderTraversal(AVLNode* node);
    void postOrderTraversal(AVLNode* node);
    void destroyTree(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    void insert(int data);
    void remove(int data);
    void display();
    bool search(int data);
    int findMin();
    int findMax();
};

#endif