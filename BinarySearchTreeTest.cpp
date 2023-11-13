#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cassert>

#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> tree;
    //std::cout << "why" << std::endl;
    // Insert values
    tree.insert(17);
    tree.insert(25);
    tree.insert(4);
    tree.insert(88);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    
    // Print tree using traversals
    std::cout << "Inorder traversal: ";
    tree.inorder_print();

    std::cout << "Preorder traversal: ";
    tree.preorder_print();

    std::cout << "Postorder traversal: ";
    tree.postorder_print();

    //system("pause");

    return 0;
}
