#include <iostream>
#include "HashMap.h"

using namespace std;

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
            for (int i = 0; i < word.size(); i++) {
                word[i] = tolower(word[i]);
            }

            for (int i = 0; i < tables.size(); i++) {
                tables[i].insert(word);
            }
        }
    }

    inFile.close();

    for (int i = 0; i < tables.size(); i++) {
        string filename = "HashTable_" + to_string(sizesArray[i]) + ".csv";
        tables[i].exportToCSV(filename);
    }

    return 0;
}
