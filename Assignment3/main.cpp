//
//  main.cpp
//  Assignment3
//
//  Purpose: Create an algorithim using a 2D array data strcuture to solve the
//           8 queens problem.
//
//  Created by Damian Diaz on 10/5/18.
//

#include <iostream>

void printBoard(int board[8][8]);

int main(int argc, const char * argv[]) {
    
    int r = 0, c = 0;
    int board[8][8] = {{0}};
    
    // Setting the first queen
    board[0][0] = 1;
    
    // Next Column
NC:
    // Increment Column
    c++;
    // If program passes the last column go to PRINT
    if (c == 8) goto PRINT;
    // Move to one before the first row
    r=-1;
    
    // Next Row
NR:
    // Increment Row
    r++;
    // If program reached the end of the row
    if(r == 8) goto BACKTRACK;
    
    // Check Row
    for(int i = 0; i < c; i++)
        if(board[r][i] == 1) goto NR;
    
    // Check Up diagnol
    for(int i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
        if(board[r-i][c-i] == 1) goto NR;
    
    // Check Down diagnol
    for(int i = 1; (r + i) < 8 && (c - i) >= 0; i++)
        if(board[r+i][c-i] == 1) goto NR;
    
    // Place the queen
    board[r][c] = 1;
    
    // goto Next Column
    goto NC;
    
    // Backtrack
BACKTRACK:
    
    // Move to previous column
    c --;
    
    // If moved to the left of the board, exit
    if(c == -1) return 0;
    
    // Reset row
    r = 0;
    
    // Find queen
    while(board[r][c] != 1) r++;
    
    // Remove queen
    board[r][c] = 0;
    
    // goto Next Row
    goto NR;
    
    
PRINT:
    
    // Print board
    printBoard(board);
    
    return 0;
}

/**
    Prints the board with a count of queens.
 
    @param board A 2D array containg board data
 
*/
void printBoard(int board[8][8]){
    
    int count = 0;
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            
            if(board[i][j] == 1)
                count++;
            
            std::cout << board[i][j];
            
        }
        std::cout << std::endl;
    }
    std::cout << "Number of queens: " << std::to_string(count) << std::endl;
    std::cout << std::endl;
}
