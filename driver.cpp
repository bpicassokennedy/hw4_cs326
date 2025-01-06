#include <iostream>
#include <fstream>

#define INPUT_FILE "inputFile.txt"

int main(){
    std::ifstream inFile(INPUT_FILE);
    if(!inFile){
        std::cout << "error opening file!" << std::endl;
    }

    readFile(inFile);
}

void readFile(std::ifstream& inputFile){
    std::string line;
    while(inputFile.good()){
        getline(inputFile, line);
        
    }
}

void rotateArray(int rows, int columns, int arr[][columns], int rotatedArr[][rows]){
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < columns; j++){
            rotatedArr[j][rows - i - 1] = arr[i][j]; //first column becomes the first row, second column becomes the second row, and so on and so forth
        }
    }
}

void printArray(int rows, int columns, int arr[][columns]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            std::cout << arr[i][j] << std::endl;
        }
    } 
}