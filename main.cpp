#include "hashTable.hpp"
#include "courseStruct.hpp"

std::string readData(std::string);

int main(void) {
    struct Ht_item courseInput;
    

    
    
    hashTable myTable = hashTable(50);
    myTable.insert(courseInput);
    myTable.printTable();

    return 0;
}

std::string readData(std::string fileInput) {
    std::ifstream myFile;
    std::string fileData;

    myFile.open(fileInput);

    while (myFile.eof() == false) {
        myFile >> fileData;
    }

    return fileData;
}