#include <deepstate/DeepState.hpp>
#include "avl.h"

using namespace deepstate;

TEST(AVLTree, InsertionAndSearch) {
    AVLTree tree;
    std::vector<int> insertedValues;

    for (int i = 0; i < 100; ++i) {
        int value = DeepState_IntInRange(-1000, 1000);
        tree.insert(value);
        insertedValues.push_back(value);
    }

    for (int value : insertedValues) {
        ASSERT(tree.search(value)) << "Value " << value << " not found after insertion";
    }
}

TEST(AVLTree, Deletion) {
    AVLTree tree;
    std::vector<int> insertedValues;

    for (int i = 0; i < 100; ++i) {
        int value = DeepState_IntInRange(-1000, 1000);
        tree.insert(value);
        insertedValues.push_back(value);
    }

    for (int value : insertedValues) {
        ASSERT(tree.search(value)) << "Value " << value << " not found after insertion";
        tree.remove(value);
        ASSERT_FALSE(tree.search(value)) << "Value " << value << " still found after removal";
    }
}

TEST(AVLTree, MinAndMax) {
    AVLTree tree;
    std::vector<int> insertedValues;

    for (int i = 0; i < 100; ++i) {
        int value = DeepState_IntInRange(-1000, 1000);
        tree.insert(value);
        insertedValues.push_back(value);
    }

    int minVal = tree.findMin();
    int maxVal = tree.findMax();

    for (int value : insertedValues) {
        ASSERT_GE(value, minVal) << "Found value smaller than minimum";
        ASSERT_LE(value, maxVal) << "Found value larger than maximum";
    }
}

// TEST(AVLTree, Traversals) {
//     AVLTree tree;
//     std::vector<int> insertedValues;

//     for (int i = 0; i < 100; ++i) {
//         int value = DeepState_IntInRange(-1000, 1000);
//         tree.insert(value);
//         insertedValues.push_back(value);
//     }

//     // InOrder traversal
//     std::vector<int> inOrderValues;
//     tree.inOrderTraversal(tree.getRoot(), [&](int value) {
//         inOrderValues.push_back(value);
//     });

//     // PostOrder traversal
//     std::vector<int> postOrderValues;
//     tree.postOrderTraversal(tree.getRoot(), [&](int value) {
//         postOrderValues.push_back(value);
//     });

//     // Verify sorted order in InOrder traversal
//     ASSERT_EQ(inOrderValues.size(), insertedValues.size()) << "InOrder traversal size mismatch";
//     for (size_t i = 1; i < inOrderValues.size(); ++i) {
//         ASSERT_LE(inOrderValues[i - 1], inOrderValues[i]) << "InOrder traversal not in sorted order";
//     }

//     // Verify correct number of elements in PostOrder traversal
//     ASSERT_EQ(postOrderValues.size(), insertedValues.size()) << "PostOrder traversal size mismatch";
// }