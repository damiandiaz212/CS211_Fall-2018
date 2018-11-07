//
//  main.cpp
//  Assignment8
//
//  Notes: This project was my most challenging yet. I began by following the template Dr. Waxman gave to us and creating a typedef
//          'box' which is a 2D char array[5][7]. On lines 23-25 im declaring box types to reference when creating the chessboard.
//          On lines 27-30 for convience I created 4 char variables to store the characters used for filling each box, on MacOS
//          which is my primary development platform i was unable to represent unicode characters for whatever reason so to properly
//          test my assignment I cycled through multiple characters to find the closes to a full rect (219).
//
//          Next i filled bb and wb with respective characters and used if conditionals to create the queen pattern for bq and wq.
//          Then i created the board comparing each index to the answer array and assigning the adress to the respective box to that
//          index. Lastly i call my print fucntion which accepts a int array and a adress to a box array. This function prints the final
//          chessboard.
//
//  Created by Damian Diaz on 11/1/18.
//
//
#include <iostream>

int q[8] = {0};

typedef char box[5][7];
box bb, wb, *board[8][8];
box bq, wq;

char bRect = char(219);
char wRect = ' ';
char vBorder = '|';
char hBorder = '_';

void print(int answerArray[8], box *board[8][8]);
bool isOk(int c);

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
    
    // Fill in bb and wb
    for(int i=0;i<5;i++){
        for(int j=0; j<7;j++){
            wb[i][j]=wRect;
            bb[i][j]=bRect;
        }
    }
    
    // Fill in bq and wq
    for(int i=0;i<5;i++){
        for(int j=0; j<7;j++){
            
            if((i == 1) && (j == 1 || j == 3 || j == 5)){
                bq[i][j] = wRect;
                wq[i][j] = bRect;
            }
            
            else if((i == 2 || i == 3) && (j > 0 && j < 6)){
                bq[i][j] = wRect;
                wq[i][j] = bRect;
            }
            
            else{
                bq[i][j] = bRect;
                wq[i][j] = wRect;
            }
        }
    }
    
    // Create Chessboard
    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            if((i+j)%2 == 0){
               if(j == q[i])
                 board[i][j] = &wq;
              else
                 board[i][j] = &wb;
            }else{
               if(j == q[i])
                 board[i][j] = &bq;
               else
                 board[i][j] = &bb;
            }
        }
    }
    
    // Prints chessboard, passing the q array and address to the board array
    print(q, board);
    
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
 prints chessboard with "fancy" output
 
 @param answerArray the 1-Dimensional array with answers
 @param board reference to a 2D array with "box" type
 */
void print(int answerArray[8], box *board[8][8]){
    
    // Prints top border
    std::cout <<"  ";
    for(int i=0;i<7*8;i++){
        std::cout<<hBorder;
    }
    std::cout<<std::endl;
    
    // Prints board
    
    // Outer most loop cycles through rows
    for(int i=0;i<8;i++){
        
        // Second outermost loop cycles through rows of each rect at *board[i]
        for(int k=0;k<5;k++){
            
            std::cout<<" "<< vBorder; // Print left border
            
            // Third outermost loop cycles through column
            for(int j=0;j<8;j++){
                
                // Fourth outermost loop cycles through each rect coloumn at *board[i][j]
                for(int l=0;l<7;l++){
                    
                    // *board[i][j] returns a "box" array,
                    // (*board[i][j])[k][l] returns the value of that array at index [k][l]
                    std::cout<<(*board[i][j])[k][l];
                }
            }
            
            std::cout<<vBorder<<std::endl; // Print right border
        }
    }
    
    // Print bottom border
    std::cout<<"  ";
    for(int i=0;i<7*8;i++)
        std::cout<<hBorder;
    std::cout<<std::endl;
    
}
