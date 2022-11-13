#include "hashTable.hpp"


#define SIZE 59
int calculateArrayIndex(int);
int quadraticProbeArray(int);

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
        std::cout << "Enter a course number to search for (-1 to quit): ";
        std::cin >> userSearch;
        if (userSearch == -1) {
            break;
        }
        else {
            std::cout << "Course number: " << userSearch << std::endl;
            std::cout << "Course name: " << nameArray[myTable.searchHashTable(userSearch)] << std::endl;
        }
    }

    

    return 0;
}

int calculateArrayIndex(int num) {
    // int hashKey = num * num;
    // int hashKeyLength = std::to_string(hashKey).length();
    // int mid = hashKeyLength / 2;
    // int midDigit = std::to_string(hashKey)[mid] - '0';
    // int hashIndex = midDigit % SIZE;
    // return hashIndex;
    int hashKey = num % SIZE;
    return hashKey;
}

int quadraticProbeArray(int ogIndex) {
    int newIndex = ogIndex;
    
    newIndex = (ogIndex + (gI * gI)) % SIZE;
    gI++;
    
    return newIndex;
}