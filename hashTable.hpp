#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "courseStruct.hpp"

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
        int reHash(int);
};