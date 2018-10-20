//
//  main.cpp
//  Assignment4
//
//  Purpose: Solve the 8 Queens problem using a 1 Dimensional array and backtracking.
//
//  Created by Damian Diaz on 10/9/18.
//

#include <iostream>

void printBoard(int board[8]);
bool isOk(int c);

int q[8] = {0};

int main(int argc, const char * argv[]) {
    
    // Setting the first queen
    q[0] = 0;
    
    int c = 0;
    
    for(int i = 1; i < 8; i++){
        
        // set c to current index value
        c = q[i];
        
        while(c < 8){
            
            c++;
            q[i] = c;
            
            // Backtracking
            if(c == 8){
                q[i] = 0;
                i-=2;
                if(i==-1) return 0;
                break;
            }
            
            // Check if okay to place queen at spot
            if(isOk(i)){
                break;
            }
            
        }
       
        
    }
    
    // Print 1D array solution
    for(int i = 0; i < 8; i++)
        std::cout << q[i];
    
    std::cout<< std::endl<< std::endl;
    
    // Print 2D representation of solution
    printBoard(q);
    
}

/**
 checks if passed queen placement is valid
 
 @param c index in array 'q'
 */
bool isOk(int c){
    
    for(int i = 0; i < c; i++){
        
        // Check for same value
        if(q[i] == q[c]) return false;
        
        // Check Diagnols
        if((abs(i-c) == abs(q[c]-q[i]))) return false;
        
    
    }
    
    return true;
    
}

/**
 Prints the board with a count of queens.
 
 @param queens 2D array containg board data
 
 */
void printBoard(int queens[8]){
    
    int board[8][8] = {0};
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            
            if(j == queens[i])
                board[i][j] = 1;
            
            std::cout << board[i][j];
            
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
