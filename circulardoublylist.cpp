#include "CircularDoublyLinkedList.h"
#include <iostream>

CircularDoublyLinkedList::CircularDoublyLinkedList() {
    head = nullptr;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void CircularDoublyLinkedList::insertAtBeginning(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void CircularDoublyLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

void CircularDoublyLinkedList::insertAtPosition(int data, int position) {
    if (position <= 0) {
        std::cout << "Invalid position\n";
        return;
    }
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    Node* newNode = new Node;
    newNode->data = data;
    Node* current = head;
    for (int i = 1; i < position - 1; ++i) {
        current = current->next;
        if (current == head) {
            std::cout << "Invalid position\n";
            delete newNode;
            return;
        }
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void CircularDoublyLinkedList::deleteAtBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
    }
}

void CircularDoublyLinkedList::deleteAtEnd() {
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }
}

void CircularDoublyLinkedList::deleteAtPosition(int position) {
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    if (position <= 0) {
        std::cout << "Invalid position\n";
        return;
    }
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    Node* current = head;
    for (int i = 1; i < position; ++i) {
        current = current->next;
        if (current == head) {
            std::cout << "Invalid position\n";
            return;
        }
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

void CircularDoublyLinkedList::display() {
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

int CircularDoublyLinkedList::size() {
    if (head == nullptr) {
        return 0;
    }
    int count = 0;
    Node* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

bool CircularDoublyLinkedList::isEmpty() {
    return head == nullptr;
}

void CircularDoublyLinkedList::reverse() {
    if (isEmpty() || head->next == head) {
        return;
    }
    Node* current = head;
    Node* temp;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    head = head->prev;
}

void CircularDoublyLinkedList::clear() {
    if (isEmpty()) {
        return;
    }
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void CircularDoublyLinkedList::concatenate(CircularDoublyLinkedList& otherList) {
    if (otherList.isEmpty()) {
        return;
    }
    if (isEmpty()) {
        head = otherList.head;
    } else {
        Node* tail1 = head->prev;
        Node* tail2 = otherList.head->prev;
        tail1->next = otherList.head;
        otherList.head->prev = tail1;
        tail2->next = head;
        head->prev = tail2;
    }
    otherList.head = nullptr;
}

void CircularDoublyLinkedList::split(CircularDoublyLinkedList& list1, CircularDoublyLinkedList& list2) {
    if (isEmpty()) {
        return;
    }
    int listSize = size();
    int mid = listSize / 2;
    Node* current = head;
    for (int i = 1; i <= mid; ++i) {
        current = current->next;
    }
    list1.head = head;
    list2.head = current->next;
    head->prev = current;
    current->next->prev = nullptr;
    current->next = head;
    current->prev = nullptr;
}