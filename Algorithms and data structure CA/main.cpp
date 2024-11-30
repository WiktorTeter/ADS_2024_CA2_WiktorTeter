#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree<int> tree;
    int data1 = 10, data2 = 5, data3 = 20;

    tree.add(data1);
    tree.add(data2);
    tree.add(data3);

    tree.printInOrder();
    tree.printPreOrder();
    tree.printPostOrder();
    std::cout << "Tree Count: " << tree.count() << std::endl;
    return 0;
}