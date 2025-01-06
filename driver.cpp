/* Programmer: Bella Picasso-Kennedy
   Date Completed: January 5, 2025 
   Purpose: CS326 HW4 (write a modular program in C++ for rotating a 2D array)
*/

#include <iostream>
#include <fstream>

#define INPUT_FILE "inputFile.txt"
#define MAX 100

void readFile(int& rows, int& columns, std::string fileName, int arr[][MAX]);
void rotateArray(int rows, int columns, int arr[][MAX], int rotatedArr[][MAX]);
void printArray(int rows, int columns, int arr[][MAX]);

int main(){
    int rows = 0, columns = 0;
    int originalArr[MAX][MAX]; 

    readFile(rows, columns, INPUT_FILE, originalArr); //reads input file and stores its contents in a 2d array
    
    std::cout << "original 2d array: " << std::endl;
    printArray(rows, columns, originalArr); //prints given 2d array to the terminal 

    int newArr[MAX][MAX];
    std::cout << std::endl << "rotated 2d array: " << std::endl;
    rotateArray(rows, columns, originalArr, newArr); //rotates any given 2d array 90 degrees clockwise
    printArray(columns, rows, newArr);
}

void readFile(int& rows, int& columns, std::string fileName, int arr[][MAX]){
    std::ifstream inFile(fileName);
    if(!inFile){
        std::cerr << "error opening file: " << fileName << std::endl;
        return;
    }
    std::string line;
    while(inFile.good() && rows < MAX && columns < MAX){
        int numColumns = 0;
        getline(inFile, line);
        for(int i = 0; i < line.length(); i++){
            arr[rows][numColumns] = line[i] - '0';
            numColumns++;
        }
        if(numColumns > columns){
            columns = numColumns;
        }
        rows++;
    }
}

void rotateArray(int rows, int columns, int arr[][MAX], int rotatedArr[][MAX]){
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < columns; j++){
            rotatedArr[j][rows - i - 1] = arr[i][j]; //first column becomes the first row, second column becomes the second row, and so on and so forth!
        }
    }
}

void printArray(int rows, int columns, int arr[][MAX]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    } 
}