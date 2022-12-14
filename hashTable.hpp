//general includes
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "courseStruct.hpp"

//class declaration of the table
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
        int quadraticInsert(int, int);
        int quadraticProbe(int, int);
        int searchHashTable(int);
};