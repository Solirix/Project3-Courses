#include "hashTable.hpp"
#include "courseStruct.hpp"

int main(void) {
    struct Ht_item courseInput;

    std::string fileInput = "course";

    
    hashTable myTable = hashTable(50);
    myTable.insert(courseInput);
    myTable.printTable();

    return 0;
}

//create a hash table using an array with mid-square hashing