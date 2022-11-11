#include "hashTable.hpp"


#define SIZE 55
//       std::string readData(std::string);
int calculateArrayIndex(int);
int quadraticProbeArray(int); 

int gI = 1;

int main(void) {
    struct Ht_item courseInput;
    std::ifstream courseFile;

    hashTable myTable = hashTable(SIZE);
    std::string nameArray[SIZE];


    courseFile.open("data.txt");

    if (!courseFile) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    else {
        while (courseFile.eof() == false) {

            courseFile >> courseInput.courseNumber;
            getline(courseFile, courseInput.courseName);
            myTable.insert(courseInput.courseNumber);

            if (nameArray[calculateArrayIndex(courseInput.courseNumber)] == "") {
                nameArray[calculateArrayIndex(courseInput.courseNumber)] = courseInput.courseName;
            }
            else {
                nameArray[quadraticProbeArray(calculateArrayIndex(courseInput.courseNumber))] = courseInput.courseName;
            }
        }
        
    }
    
    courseFile.close();
    




    






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

int quadraticProbeArray(int ogIndex) {
    int newIndex = ogIndex;
    int i = 1;

    newIndex = (ogIndex + (i * i)) % SIZE;
    i++;

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