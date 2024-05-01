#include <iostream>
#include "CircularDoublyLinkedList.h"

int main() {
    CircularDoublyLinkedList list1;
    CircularDoublyLinkedList list2;

    // Inserting elements into list1
    std::cout << "Inserting elements into list1...\n";
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);
    list1.insertAtEnd(40);
    list1.display(); // Output: 10 20 30 40

    // Inserting elements into list2
    std::cout << "Inserting elements into list2...\n";
    list2.insertAtEnd(50);
    list2.insertAtEnd(60);
    list2.insertAtEnd(70);
    list2.display(); // Output: 50 60 70

    // Concatenating list2 to list1
    std::cout << "Concatenating list2 to list1...\n";
    list1.concatenate(list2);
    list1.display(); // Output: 10 20 30 40 50 60 70
    list2.display(); // Output: List is empty

    // Splitting list1 into list1 and list2
    CircularDoublyLinkedList list3;
    CircularDoublyLinkedList list4;
    std::cout << "Splitting list1 into list3 and list4...\n";
    list1.split(list3, list4);
    list3.display(); // Output: 10 20 30 40
    list4.display(); // Output: 50 60 70
    list1.display(); // Output: List is empty

    return 0;
}
