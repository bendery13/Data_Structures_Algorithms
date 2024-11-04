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
        int steps = 1;

        while (current != nullptr) {
            if (current->word == word) {
                current->occurrences++;
                current->steps += steps;
                return;
            }
            current = current->next;
            steps++;
        }

        // Create a new node and insert it at the beginning
        WordNode* newNode = new WordNode(word);
        newNode->steps = steps;
        newNode->next = table[index]; // Link the new node to the current head
        table[index] = newNode;       // Update the head to be the new node
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

int main() {
    ifstream inFile("LittleWomen.txt");
    if (!inFile) {
        cerr << "Unable to open file LittleWomen.txt\n";
        return 1;
    }

    int sizesArray[] = {500, 1000, 2000, 5000, 10000};
    vector<HashTable> tables;

    for (int i = 0; i < 5; i++) {
        tables.push_back(HashTable(sizesArray[i]));
    }

    string word;
    bool isReading = true;

    while (isReading == true) {
        inFile >> word;

        if (inFile.fail()) {
            isReading = false;
        } else {
            // Convert to lowercase
            for (int i = 0; i < word.size(); i++) {
                word[i] = tolower(word[i]);
            }

            // Insert word into each hash table
            for (int i = 0; i < tables.size(); i++) {
                tables[i].insert(word);
            }
        }
    }

    inFile.close();

    // Export each hash table's data to CSV with the specified filename format
    for (int i = 0; i < tables.size(); i++) {
        string filename = "Discover_" + to_string(sizesArray[i]) + ".csv";
        tables[i].exportToCSV(filename);
    }

    return 0;
}
