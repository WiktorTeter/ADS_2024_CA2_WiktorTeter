#include <iostream>
#include "BinaryTree.h"
#include "TreeMap.h"
#include <fstream>
#include <sstream>
#include <cctype>

void readFileToTreeMap(const std::string& filename, TreeMap<char, BinaryTree<std::string>>& wordMap) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string word;
    while (file >> word) {
        char firstLetter = std::tolower(word[0]);

        if (!wordMap.containsKey(firstLetter)) {
            BinaryTree<std::string> tree;
            wordMap.put(firstLetter, tree);
        }
        wordMap.get(firstLetter).add(word);
    }

    file.close();
}
void displayLetters(TreeMap<char, BinaryTree<std::string>>& wordMap) {
    BinaryTree<char> keys = wordMap.keySet();
    std::cout << "Letters in the file: ";
    keys.printInOrder();
}
void displayWordsForLetter(TreeMap<char, BinaryTree<std::string>>& wordMap, char letter) {
    letter = std::tolower(letter);
    if (!wordMap.containsKey(letter)) {
        std::cout << "No words for the letter: " << letter << std::endl;
        return;
    }
    std::cout << "Words for the letter " << letter << ": ";
    wordMap.get(letter).printInOrder();
}

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

    TreeMap<char, BinaryTree<std::string>> wordMap;

    try {
        readFileToTreeMap("input.txt", wordMap);

        displayLetters(wordMap);

        char letter;
        std::cout << "\nEnter a letter to see its words: ";
        std::cin >> letter;

        displayWordsForLetter(wordMap, letter);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
