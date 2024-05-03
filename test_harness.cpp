// #include <deepstate/DeepState.hpp>
// #include "CircularDoublyLinkedList.h"

// using namespace deepstate;

// TEST(CircularDoublyLinkedList, InsertAtBeginning) {
//     CircularDoublyLinkedList list;
//     unsigned int num_elements = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         int data = DeepState_Int();
//         list.insertAtBeginning(data);
//     }

//     ASSERT_EQ(list.size(), num_elements);
// }

// TEST(CircularDoublyLinkedList, InsertAtEnd) {
//     CircularDoublyLinkedList list;
//     unsigned int num_elements = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         int data = DeepState_Int();
//         list.insertAtEnd(data);
//     }

//     ASSERT_EQ(list.size(), num_elements);
// }

// TEST(CircularDoublyLinkedList, InsertAtPosition) {
//     CircularDoublyLinkedList list;
//     unsigned int num_elements = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         int data = DeepState_Int();
//         unsigned int position = DeepState_UIntInRange(1, list.size() + 1);
//         list.insertAtPosition(data, position);
//     }

//     ASSERT_EQ(list.size(), num_elements);
// }

// TEST(CircularDoublyLinkedList, DeleteAtBeginning) {
//     CircularDoublyLinkedList list;
//     unsigned int num_elements = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         int data = DeepState_Int();
//         list.insertAtEnd(data);
//     }

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         list.deleteAtBeginning();
//     }

//     ASSERT_EQ(list.size(), 0);
// }

// TEST(CircularDoublyLinkedList, DeleteAtEnd) {
//     CircularDoublyLinkedList list;
//     unsigned int num_elements = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         int data = DeepState_Int();
//         list.insertAtEnd(data);
//     }

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         list.deleteAtEnd();
//     }

//     ASSERT_EQ(list.size(), 0);
// }

// TEST(CircularDoublyLinkedList, DeleteAtPosition) {
//     CircularDoublyLinkedList list;
//     unsigned int num_elements = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         int data = DeepState_Int();
//         list.insertAtEnd(data);
//     }

//     for (unsigned int i = 0; i < num_elements; ++i) {
//         unsigned int position = DeepState_UIntInRange(1, list.size() + 1);
//         list.deleteAtPosition(position);
//     }

//     ASSERT_EQ(list.size(), 0);
// }

// TEST(CircularDoublyLinkedList, ConcatenateAndSplit) {
//     CircularDoublyLinkedList list1;
//     CircularDoublyLinkedList list2;

//     unsigned int num_elements1 = DeepState_UIntInRange(1, 100);
//     unsigned int num_elements2 = DeepState_UIntInRange(1, 100);

//     for (unsigned int i = 0; i < num_elements1; ++i) {
//         int data = DeepState_Int();
//         list1.insertAtEnd(data);
//     }

//     for (unsigned int i = 0; i < num_elements2; ++i) {
//         int data = DeepState_Int();
//         list2.insertAtEnd(data);
//     }

//     list1.concatenate(list2);
//     ASSERT_EQ(list1.size(), num_elements1 + num_elements2);
//     ASSERT_EQ(list2.size(), 0);

//     CircularDoublyLinkedList list3;
//     CircularDoublyLinkedList list4;

//     list1.split(list3, list4);
//     ASSERT_EQ(list3.size() + list4.size(), num_elements1 + num_elements2);
//     ASSERT_EQ(list1.size(), 0);
// }

#include <deepstate/DeepState.hpp>
#include "CircularDoublyLinkedList.h"

using namespace deepstate;

TEST(CircularDoublyLinkedList, InsertAtBeginning) {
    CircularDoublyLinkedList list;
    int data = DeepState_Int();
    list.insertAtBeginning(data);
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.isEmpty(), false);
}

TEST(CircularDoublyLinkedList, InsertAtEnd) {
    CircularDoublyLinkedList list;
    int data = DeepState_Int();
    list.insertAtEnd(data);
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.isEmpty(), false);
}

TEST(CircularDoublyLinkedList, InsertAtPosition) {
    CircularDoublyLinkedList list;
    unsigned int position = DeepState_UInt();
    int data = DeepState_Int();
    list.insertAtPosition(data, position);
    ASSERT_EQ(list.size(), 1) << list.size();
    ASSERT_EQ(list.isEmpty(), false) << list.isEmpty();
}

TEST(CircularDoublyLinkedList, DeleteAtBeginning) {
    CircularDoublyLinkedList list;
    list.insertAtEnd(10);
    list.deleteAtBeginning();
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(CircularDoublyLinkedList, DeleteAtEnd) {
    CircularDoublyLinkedList list;
    list.insertAtEnd(10);
    list.deleteAtEnd();
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(CircularDoublyLinkedList, DeleteAtPosition) {
    CircularDoublyLinkedList list;
    list.insertAtEnd(10);
    list.deleteAtPosition(1);
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(CircularDoublyLinkedList, ConcatenateAndSplit) {
    CircularDoublyLinkedList list1;
    CircularDoublyLinkedList list2;

    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list2.insertAtEnd(30);
    list2.insertAtEnd(40);

    list1.concatenate(list2);
    ASSERT_EQ(list1.size(), 4);
    ASSERT_EQ(list2.size(), 0);

    CircularDoublyLinkedList list3;
    CircularDoublyLinkedList list4;

    list1.split(list3, list4);
    ASSERT_EQ(list3.size() + list4.size(), 4);
    ASSERT_EQ(list1.size(), 0);
}

