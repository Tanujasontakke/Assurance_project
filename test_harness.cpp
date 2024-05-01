#include <deepstate/DeepState.hpp>
#include "your_code_file.hpp" // Replace "your_code_file.hpp" with the actual filename of your code

using namespace deepstate;

TEST(CircularDoublyLinkedList, CreateList) {
    circulardoublylist cdll;
    // Call the create_node_success function
    cdll.create_node_success();
}

TEST(CircularDoublyLinkedList, InsertBegin) {
    circulardoublylist cdll;
    int value = DeepState_Int(); // Generate a random integer value
    cdll.insert_begin(value);
}

TEST(CircularDoublyLinkedList, InsertEnd) {
    circulardoublylist cdll;
    int value = DeepState_Int(); // Generate a random integer value
    cdll.insert_end(value);
}

TEST(CircularDoublyLinkedList, InsertPosition) {
    circulardoublylist cdll;
    int value = DeepState_Int(); // Generate a random integer value
    int position = DeepState_Int(); // Generate a random position
    cdll.insert_position(value, position);
}

TEST(CircularDoublyLinkedList, DeleteBegin) {
    circulardoublylist cdll;
    // Call the delete_begin function
    cdll.delete_begin();
}

TEST(CircularDoublyLinkedList, DeleteEnd) {
    circulardoublylist cdll;
    // Call the delete_end function
    cdll.delete_end();
}

TEST(CircularDoublyLinkedList, DeletePosition) {
    circulardoublylist cdll;
    int position = DeepState_Int(); // Generate a random position
    cdll.delete_position(position);
}
