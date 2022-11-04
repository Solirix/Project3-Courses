#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

class hashTable {
    private:
        int tableSize;
        std::vector<std::string> table;

    public:
        hashTable(int);
        hashTable();
        int hash(int);
        void insert(Ht_item);
        void printTable();
};