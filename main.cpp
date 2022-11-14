//includes basic libraries such as <iostream> and <string>
#include "hashTable.hpp"

//SIZE for use by the hash table and array for names
#define SIZE 69

/* GIVEN: course number to be inserted
TASK: calculate the index that the hash table would insert the number, to insert the name. NOTE: use the same hash funciton.
RETURN: the index of the array where the course number should be inserted, identical to the index of the hash table */
int calculateArrayIndex(int);

/* GIVEN: Index of the array where a collision occured
TASK: find the next available index in the array using the same quadratic formula as the hash table
RETURN: the new index of the array to be used */ 
int quadraticProbeArray(int);

/* GIVEN: the array of names
TASK: print the array of names
RETURN: nothing */
void printNameArray(std::string nameArray[]);

//global variable for incrementing the quadratic probing
int gI = 1;


int main(void) {
    struct Ht_item courseInput;
    std::ifstream courseFile;
    int userSearch = 0;   //variable for the user to engage with

    hashTable myTable = hashTable(SIZE);
    std::string nameArray[SIZE];
    int temp = 0;  //temporary variable for to make it easier to keep track of the index of the array when probing

    courseFile.open("data.txt");    //opening the file

    if (!courseFile) {    //check for a failure in opening the file
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    else {
        while (courseFile.eof() == false) {   //while the end of the file has not been reached do:

            courseFile >> courseInput.courseNumber;  //read in the course number
            getline(courseFile, courseInput.courseName);   //get the rest of the line to use as course name
            myTable.insert(courseInput.courseNumber);   //insert the number into the hash table

            //now, time to insert the name associated with that number into the array
            if (nameArray[calculateArrayIndex(courseInput.courseNumber)] == "") {  //if the index is empty, insert the name
                nameArray[calculateArrayIndex(courseInput.courseNumber)] = courseInput.courseName;
            }
            else {  //or, if not empty, then:
                while (nameArray[calculateArrayIndex(courseInput.courseNumber)] != "") {
                    
                    // set temp equal to a quadratic probe of the array, searching for a new index
                    temp = quadraticProbeArray(calculateArrayIndex(courseInput.courseNumber)); 
                    if (nameArray[temp] == "") {   // if that new found index is empty, insert the name and break. if not, loop
                        nameArray[temp] = courseInput.courseName;
                        break;
                    }
                    
                 }
                 //reset temp and global variables for next insertion
                 gI = 1;
                 temp = 0;
            }
        }
        
    }
    
    courseFile.close();  //close the file
    


    //prompt the user to search for courses
    while (userSearch != -1) {
        std::cout << "Enter a course number to search for (-1 to quit, or 0 to print the entire table): ";
        std::cin >> userSearch;
        if (userSearch == -1) {   // -1 to quit
            break;
        }
        else if (userSearch == 0) {  // 0 to print the entire table
            std::cout << "Hash table containing course numbers:" << std::endl;
            myTable.printTable();
            std::cout << std::endl << std::endl;  //spacing
            std::cout << "Array containing course names:" << std::endl;
            printNameArray(nameArray);
        }
        else if (myTable.searchHashTable(userSearch) == -1) {  // if the search returns -1, then the course was not found
            std::cout << "Course not found." << std::endl;
        }
        else {  // if everything went smoothly, return the course's index and it's associated name
            std::cout << "Course found at index " << myTable.searchHashTable(userSearch) << std::endl;
            std::cout << "Course name: " << nameArray[myTable.searchHashTable(userSearch)] << std::endl;
        }
    }

    return 0;
}

int calculateArrayIndex(int num) { 
    int hashKey = num % SIZE;  //hash function
    return hashKey;
}

int quadraticProbeArray(int ogIndex) {
    int newIndex = ogIndex;
    
    newIndex = (ogIndex + (gI * gI)) % SIZE;
    gI++;  // increment global variable for quadratic probing above
    
    return newIndex;
}

void printNameArray(std::string nameArray[]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ": " << nameArray[i] << std::endl;
    }
}