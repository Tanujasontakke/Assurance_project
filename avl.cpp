#include "avl.h"
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    root = nullptr; // Ensure root is set to nullptr after deleting all nodes
}

int AVLTree::getHeight(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalanceFactor(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* AVLTree::insertNode(AVLNode* node, int data) {
    if (node == nullptr)
        return new AVLNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int data) {
    root = insertNode(root, data);
}

AVLNode* AVLTree::deleteNode(AVLNode* root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::remove(int data) {
    root = deleteNode(root, data);
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

void AVLTree::preOrderTraversal(AVLNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void AVLTree::display() {
    preOrderTraversal(root);
    std::cout << std::endl;
}

bool AVLTree::search(int data) {
    AVLNode* current = root;
    while (current != nullptr) {
        if (current->data == data)
            return true;
        else if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

int AVLTree::findMin() {
    AVLNode* current = root;
    while (current->left != nullptr)
        current = current->left;
    return current->data;
}

int AVLTree::findMax() {
    AVLNode* current = root;
    while (current->right != nullptr)
        current = current->right;
    return current->data;
}

void AVLTree::inOrderTraversal(AVLNode* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

void AVLTree::postOrderTraversal(AVLNode* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }
}