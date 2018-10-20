//
//  main.cpp
//  Assignment5
//
//  Created by Damian Diaz on 10/12/18.
//
//  Notes: For this assignment I used a 1D array to store the solution like the previous assignment,
//         however im also using a 2D array to reference which indexes should be checked for each index in my 1D array.
//         For example on cross[2] only cross[0] and cross[1] should be compared to the value stored, therefore helper[2]
//         stores an array containing ints 0 and 1. reference INDEX MAP for clarity. To check if values are 'ok' the isOK
//         method uses the absolute value of (cross[index] - cross[helper[index][i]]) and if number is +1, -1, or the same as
//         the value being checked, then it is invalid and the method returns false.

/*
      INDEX MAP
         1 4
       0 2 5 7
         3 6
 */

#include <iostream>

// Solution array
int cross[8] = {0};

// This array dictates what indexes should be checked for a certain position
// I made it constant since this array wont be changed only referenced.
const int helper[8][5] = {
    {-1,-1,-1,-1,-1},
    {0,-1,-1,-1,-1},
    {0, 1, -1,-1,-1},
    {0, 2, -1, -1, -1},
    {1, 2, -1, -1, -1},
    {1, 2, 3, 4, -1},
    {2, 3, 5, -1, -1},
    {4, 5, 6, -1, -1}
};

int c = 0;

bool isOK(int index);
void printSolution();

int main(int argc, const char * argv[]) {
    
    // Assign first index to 1
    cross[0] = 1;
    c++;
   
    for(int i = 1; i < 8; i++){
        
        c = cross[i];
        
        while(c < 9){
            
            // Increment C and assign to index
            c++;
            cross[i] = c;
            
            // If C > 8, Backtrack
            if(c == 9){
                cross[i] = 0;
                i-=2;
                break;
            }
            
            // If num is okay move to next column
            if(isOK(i))
                break;
            
            
        }
    }
    
    printSolution();
    return 0;
}

bool isOK(int index){
    
    // Loop through until current index
    for(int i = 0; i < index; i++){
        
        // Check if duplicate
      if(cross[index] == cross[i]) return false;
    }
    
    // Loop through the helper index values until -1
    for(int i = 0; helper[index][i] != -1; i++){
        
        // Check adjacent values
        if(1 == abs(cross[index] - cross[helper[index][i]])) return false;
        
    }
    
    return true;
}

void printSolution(){
    std::cout<<" "<<cross[1]<<cross[4]<<" "<<std::endl;
    std::cout<<cross[0]<<cross[2]<<cross[5]<<cross[7]<<std::endl;
    std::cout<<" "<<cross[3]<<cross[6]<<" "<<std::endl;
}
