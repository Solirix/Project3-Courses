#include "hashTable.hpp"


#define SIZE 55
//       std::string readData(std::string);
int calculateArrayIndex(int);
int reCalcArrayIndex(int); 

int main(void) {
    struct Ht_item courseInput;
    
    courseInput.courseNumber = 123;
    courseInput.courseName = "Discrete Structures";
    
    
    hashTable myTable = hashTable(SIZE);
    std::string nameArray[SIZE];


    myTable.insert(courseInput.courseNumber);
    nameArray[calculateArrayIndex(courseInput.courseNumber)] = courseInput.courseName;


    courseInput.courseNumber = 123;
    courseInput.courseName = "Discrete Structures";

    myTable.insert(courseInput.courseNumber);
    if (nameArray[calculateArrayIndex(courseInput.courseNumber)] == "") {
        nameArray[calculateArrayIndex(courseInput.courseNumber)] = courseInput.courseName;
    }
    else {
        nameArray[reCalcArrayIndex(calculateArrayIndex(courseInput.courseNumber))] = courseInput.courseName;
    }





    myTable.printTable();
    std::cout << std::endl << std::endl;
    
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ": " << nameArray[i] << std::endl;
    }

    return 0;
}

int calculateArrayIndex(int num) {
    int hashKey = num * num;
    int hashKeyLength = std::to_string(hashKey).length();
    int mid = hashKeyLength / 2;
    int midDigit = std::to_string(hashKey)[mid] - '0';
    int hashIndex = midDigit % SIZE;
    return hashIndex;
}

int reCalcArrayIndex(int ogIndex) {
    int i = 1;
    int newIndex = ogIndex + (i^2);
    return newIndex;
}

//       std::string readData(std::string fileInput) {
//           std::ifstream myFile;
//           std::string fileData;

//           myFile.open(fileInput);

//           while (myFile.eof() == false) {
//               myFile >> fileData;
//           }

//           return fileData;
//       }