#include "hashTable.hpp"


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
void hashTable::insert(int key) {
    if (table[hash(key)] == "") {
        table[hash(key)] = std::to_string(key);
    }
    else {
        std::cout << "Collision detected at index " << hash(key) << std::endl;
        std::cout << "Rehashing..." << std::endl;

        for (int i = 0; i > -1; i++) {
            if (table[reHash(hash(key))] == "") {

            table[reHash(hash(key))] = std::to_string(key);
            break;
            }
            else {
                key++;
            }

        }
    }
}

// print out the hash table
void hashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        std::cout << i << ": " << table[i] << std::endl;
    }
}

int hashTable::reHash(int ogIndex) {
    int i = 1;
    int newIndex = ogIndex + (i^2);
    return newIndex;
}

