#include <iostream>
#include "BinaryTree.h"
#include "TreeMap.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <map>
#include <iomanip>

struct Person {
    int id;
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string gender;
};

void filterData(const std::vector<Person>& people, const std::string& field, const std::string& value);

void testTreeMap() {
    std::cout << "\n=== Testing TreeMap ===\n";

    TreeMap<int, std::string> map;

    map.put(1, "One");
    map.put(2, "Two");
    map.put(3, "Three");

    std::cout << "Get key 1: " << map.get(1) << std::endl;
    std::cout << "Get key 2: " << map.get(2) << std::endl;
    std::cout << "Get key 3: " << map.get(3) << std::endl;

    std::cout << "Contains key 1: " << map.containsKey(1) << std::endl;
    std::cout << "Contains key 4: " << map.containsKey(4) << std::endl;

    map.removeKey(2);
    std::cout << "After removing key 2, contains key 2: " << map.containsKey(2) << std::endl;

    std::cout << "Size of TreeMap: " << map.size() << std::endl;

    map.clear();
    std::cout << "After clear, size of TreeMap: " << map.size() << std::endl;

    std::cout << "=== TreeMap Test Complete ===\n";
}

void testBinaryTree() {
    std::cout << "\n=== Testing BinaryTree ===\n";

    BinaryTree<int> tree;

    int value1 = 10;
    int value2 = 5;
    int value3 = 15;
    tree.add(value1);
    tree.add(value2);
    tree.add(value3);
    std::cout << "Tree count after adding 10, 5, 15: " << tree.count() << std::endl;

    std::cout << "InOrder Traversal: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.remove(value1);
    std::cout << "Tree count after removing 10: " << tree.count() << std::endl;

    tree.clear();
    std::cout << "Tree count after clear: " << tree.count() << std::endl;

    std::cout << "=== BinaryTree Test Complete ===\n";
}

void testFilterData() {
    std::cout << "\n=== Testing Filter Data ===\n";

    std::vector<Person> people = {
        {1, "John", "Doe", "john@example.com", "Male"},
        {2, "Jane", "Smith", "jane@example.com", "Female"},
        {3, "Alex", "Brown", "alex@example.com", "Non-Binary"}
    };

    std::cout << "Filter by gender: Male\n";
    filterData(people, "gender", "Male");

    std::cout << "Filter by first_name: Jane\n";
    filterData(people, "first_name", "Jane");

    std::cout << "=== Filter Data Test Complete ===\n";
}