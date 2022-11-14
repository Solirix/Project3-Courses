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

// hash function for regular hashing

/* 
Originally, I used mid-square hashing. after some experimentation however, I've decided to use regular hashing, 
as it has proven to consistently provide less collisions with this data set. I've left the mid-square hashing
code commented out below, in case you'd like to see it.
*/
int hashTable::hash(int key) {
    // int hashKey = key * key;
    // int hashKeyLength = std::to_string(hashKey).length();
    // int mid = hashKeyLength / 2;
    // int midDigit = std::to_string(hashKey)[mid] - '0';
    // int hashIndex = midDigit % tableSize;
    // return hashIndex;

    int hashIndex = key % tableSize;
    return hashIndex;
}

// insert a value into the hash table
void hashTable::insert(int key) {
    if (table[hash(key)] == "") {
        table[hash(key)] = std::to_string(key);
    }
    else {
        /*
        The code I used for debugging collisions remains in the commented out sections below.
        */

        // std::cout << "Collision detected at index " << hash(key) << std::endl;
        // std::cout << "Rehashing..." << std::endl;
        quadraticInsert(hash(key), key);
        } 
}

// print out the hash table
// used during debugging, and decided to implement it as an option for the user.
void hashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        std::cout << i << ": " << table[i] << std::endl;
    }
}

// quadratic probing function for inserting values into the hash table
int hashTable::quadraticInsert(int ogIndex, int item) {
    int newIndex = ogIndex;
    int i = 1;   //variable to increment the probing
    while (table[newIndex] != "") {
        newIndex = (ogIndex + (i * i)) % tableSize;  // quadratic probing formula
        i++;
        if (table[newIndex] == "") {      //if the new index is empty, insert the item there
            table[newIndex] = std::to_string(item);
            break;
        }
    }
    return newIndex;
}

// actual probing function for searching the hash table
int hashTable::quadraticProbe(int index, int key) {
    int newIndex = index;
    int i = 1;   //variable to increment the probing
    int j = 0;   //variable to keep track of the number of probes
    while (table[newIndex] != std::to_string(key)) {
        newIndex = (index + (i * i)) % tableSize;  // quadratic probing formula
        i++;
        j++;
        if (table[newIndex] == std::to_string(key)) {  // if the new index is the key, break to return the index
            return newIndex;
        }
        else if (j > tableSize) {  // if the key is not found, return -1
            break;
        }
    } 
    return -1;
}

// search the hash table for a value
int hashTable::searchHashTable(int key) {
    int index = hash(key);
    if (table[index] == std::to_string(key)) {
        return index;
    }
    else {
        int newIndex = quadraticProbe(index, key);
        return newIndex;
    }
}