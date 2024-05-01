#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void display();
    int size();
    bool isEmpty();
    void reverse();
    void clear();
    void concatenate(CircularDoublyLinkedList& otherList);
    void split(CircularDoublyLinkedList& list1, CircularDoublyLinkedList& list2);


private:
    Node* head;
};

#endif
