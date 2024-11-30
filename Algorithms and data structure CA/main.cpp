#include <iostream>
#include "BinaryTree.h"
#include "TreeMap.h"

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

    TreeMap<int, std::string> map;

    map.put(1, "One");
    map.put(2, "Two");

    std::cout << "Key 1: " << map.get(1) << std::endl;
    std::cout << "Key 2: " << map.get(2) << std::endl;

    std::cout << "Contains Key 1: " << map.containsKey(1) << std::endl;
    std::cout << "Contains Key 3: " << map.containsKey(3) << std::endl;

    return 0;
}