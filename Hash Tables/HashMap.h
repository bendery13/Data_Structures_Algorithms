#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

struct WordNode {
    string word;
    int occurrences;
    int steps;
    WordNode* next;

    // Constructor to initialize a new node with the word
    WordNode(const string& w) {
        word = w;
        occurrences = 1;
        steps = 1;
        next = nullptr;
    }
};

class HashTable {
private:
    int tableSize;
    vector<WordNode*> table;

    int hashFunction(const string& str) {
        int h = 0;
        for (int i = 0; i < str.size(); i++) {
            h = h * 31 + static_cast<int>(str[i]);
        }
        return abs(h) % tableSize;
    }

public:
    HashTable(int size) {
        tableSize = size;
        table.resize(size, nullptr);
    }

    void insert(const string& word) {
        int index = hashFunction(word); 
        WordNode* current = table[index];
        WordNode* previous = nullptr;
        int steps = 1;

        while (current != nullptr) {
            if (current->word == word) {
                current->occurrences++;
                current->steps += steps;
                return;
            }
            previous = current;
            current = current->next;
            steps++;
        }

        WordNode* newNode = new WordNode(word);
        newNode->steps = steps;

        if (previous == nullptr) {
            table[index] = newNode;
        } else {
            previous->next = newNode;
        }
    }

    void exportToCSV(const string& filename) {
        ofstream outFile(filename);
        outFile << "Word,Occurrences,TotalSteps\n";

        for (int i = 0; i < tableSize; i++) {
            WordNode* current = table[i];
            while (current != nullptr) {
                outFile << current->word << "," << current->occurrences << "," << current->steps << "\n";
                current = current->next;
            }
        }
        outFile.close();
    }

    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            WordNode* current = table[i];
            while (current != nullptr) {
                WordNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};
