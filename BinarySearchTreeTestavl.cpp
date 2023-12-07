#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cassert>

#include "BinarySearchTree.h"

void simple_insert_test() {
    BinarySearchTree<int> tree;

    tree.insert(17);
    tree.insert(25);
    tree.insert(4);
    tree.insert(88);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);

    std::cout << "Test: Simple Insertion\n";
    std::cout << "Inorder traversal: ";
    tree.inorder_print();

    assert(tree.contains(5));
    assert(tree.contains(88));
    assert(!tree.contains(89));
    assert(!tree.contains(-100));

    std::cout << "Minimum value: " << tree.find_min() << " (Expected: 1)\n";
    std::cout << "Maximum value: " << tree.find_max() << " (Expected: 88)\n\n";
}
void LL_insert_test() {
    BinarySearchTree<int> tree;

    tree.insert(17);
    tree.insert(25);
    tree.insert(12);
    tree.insert(10);
    
    tree.insert(27);
    
    std::cout << "Test: LL Insertion\n";
    std::cout << "Depthorder traversal before LL insertion: ";
    tree.depthorder_print();

    tree.insert(9);

    std::cout << "Depthorder traversal after LL insertion: ";
    tree.depthorder_print();
    std::cout << "\n";
}
