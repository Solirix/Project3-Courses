#include "hashTable.hpp"
#include "courseStruct.hpp"

// default constructor for hash table
hashTable::hashTable() {
    tableSize = 10;
    table = std::vector<std::string>(tableSize);
}

// specific constructor for hash table
hashTable::hashTable(int size) {
    tableSize = size;
    table = std::vector<std::string>(size);
}

// hash function for mid-square hashing
int hashTable::hash(int key) {
    int hashKey = key * key;
    int hashKeyLength = std::to_string(hashKey).length();
    int mid = hashKeyLength / 2;
    int midDigit = std::to_string(hashKey)[mid] - '0';
    int hashIndex = midDigit % tableSize;
    return hashIndex;
}

// insert a value into the hash table
void hashTable::insert(Ht_item key) {
    int hashIndex = hash(key.courseNumber);
    table[hashIndex] = std::to_string(key.courseNumber);
}

// print out the hash table
void hashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        std::cout << i << ": " << table[i] << std::endl;
    }
}