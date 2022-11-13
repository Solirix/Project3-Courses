#include "hashTable.hpp"


#define SIZE 59
int calculateArrayIndex(int);
int quadraticProbeArray(int);
void printNameArray(std::string nameArray[]);

int gI = 1;


int main(void) {
    struct Ht_item courseInput;
    std::ifstream courseFile;
    int userSearch = 0;

    hashTable myTable = hashTable(SIZE);
    std::string nameArray[SIZE];
    int temp = 0;

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
                while (nameArray[calculateArrayIndex(courseInput.courseNumber)] != "") {
                    
                   
                    temp = quadraticProbeArray(calculateArrayIndex(courseInput.courseNumber)); 
                    if (nameArray[temp] == "") {
                        nameArray[temp] = courseInput.courseName;
                        break;
                    }
                    
                 }
                 gI = 1;
                 temp = 0;
            }
        }
        
    }
    
    courseFile.close();
    


    //prompt the user to search for courses
    while (userSearch != -1) {
        std::cout << "Enter a course number to search for (-1 to quit, or 0 to print the entire table): ";
        std::cin >> userSearch;
        if (userSearch == -1) {
            break;
        }
        else if (userSearch == 0) {
            myTable.printTable();
            std::cout << std::endl;
            printNameArray(nameArray);
        }
        else {
            if (nameArray[myTable.searchHashTable(userSearch)] != "") {
                std::cout << "Course number: " << userSearch << std::endl;
                std::cout << "Course name: " << nameArray[myTable.searchHashTable(userSearch)] << std::endl;
            }
            else {
                std::cout << "Course not found." << std::endl;
            } 
        }
    }

    

    return 0;
}

int calculateArrayIndex(int num) { 
    int hashKey = num % SIZE;
    return hashKey;
}

int quadraticProbeArray(int ogIndex) {
    int newIndex = ogIndex;
    
    newIndex = (ogIndex + (gI * gI)) % SIZE;
    gI++;
    
    return newIndex;
}

void printNameArray(std::string nameArray[]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ": " << nameArray[i] << std::endl;
    }
}