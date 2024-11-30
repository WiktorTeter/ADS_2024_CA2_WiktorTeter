#include <iostream>
#include "BinaryTree.h"
#include "TreeMap.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>

struct Person {
    int id;
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string gender;
};
std::vector<Person> readCSV(const std::string& filename) {
    std::vector<Person> people;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    // Skip the header row
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Person person;

        std::string id;
        // Parse each column
        std::getline(ss, id, ',');
        person.id = std::stoi(id);

        std::getline(ss, person.first_name, ',');
        std::getline(ss, person.last_name, ',');
        std::getline(ss, person.email, ',');
        std::getline(ss, person.gender, ',');

        people.push_back(person);
    }

    file.close();
    return people;
}
void searchByField(const std::vector<Person>& people, const std::string& field, const std::string& value) {
    bool found = false;

    for (const auto& person : people) {
        if ((field == "id" && std::to_string(person.id) == value) ||
            (field == "first_name" && person.first_name == value) ||
            (field == "last_name" && person.last_name == value) ||
            (field == "email" && person.email == value) ||
            (field == "gender" && person.gender == value)) {

            std::cout << "ID: " << person.id
                << ", First Name: " << person.first_name
                << ", Last Name: " << person.last_name
                << ", Email: " << person.email
                << ", Gender: " << person.gender << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No results found for the given field and value." << std::endl;
    }
}

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

    try {
        std::vector<Person> people = readCSV("data.csv");

        std::cout << "Enter field to search by (id, first_name, last_name, email, gender): ";
        std::string field;
        std::cin >> field;

        std::cout << "Enter value to search for: ";
        std::string value;
        std::cin.ignore();
        std::getline(std::cin, value);

        searchByField(people, field, value);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
