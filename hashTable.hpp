#include <string>
#include <iostream>
#include <vector>
#include <cmath>

class hashTable {
    private:
        int tableSize;
        std::vector<std::string> table;

    public:
        hashTable(int);
        hashTable();
        int hash(int);
        void insert(int);
        void printTable();
};