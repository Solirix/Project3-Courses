
#include "hashTable.hpp"

int main(void) {
    int userInput = 0;

    std::cin >> userInput;
    
    hashTable myTable = hashTable(10);
    myTable.insert(userInput);
    myTable.printTable();

    return 0;
}