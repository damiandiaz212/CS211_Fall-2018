//
//  main.cpp
//  Assignment6
//
//  Purpose: Solve the Stable Marraiage problem
//
//  Created by Damian Diaz on 10/20/18.
//
//  Notes: For this assignment I began with the one dimensional 8 queens assignment code. The reason is
//          because the main loop and backtracking can be used with only minor changes. The biggest challenge was
//          building the isOk function. I made two for loops, one for cehcking for duplicate matches and the other for comparing
//          prefernces and matches.

#include <iostream>

bool isOk(int col);

int q[3] = {-1};

// Preferences
int mp[3][3] = {{0,2,1}, {0,2,1}, {1,2,0}};
int wp[3][3] = {{2,1,0}, {0,1,2}, {2,0,1}};

int main(int argc, const char * argv[]) {
    
    q[0] = 0;
    
    int c = 0;
    
    for(int i = 1; i < 3; i++){
        
        // set c to current index value
        c = q[i];
        
        while(c < 3){
            
            c++;
            q[i] = c;
            
            // Backtracking
            if(c == 3){
                q[i] = -1;
                i-=2;
                if(i==-2) return 0;
                break;
            }
            
            // Check if okay to place queen at spot
            if(isOk(i)){
                break;
            }
            
        }
        
    }
    
    // Print solution
    std::cout << "Man" << " " << "Woman" << std::endl;
    
    for(int i = 0; i < 3; i++)
        std::cout << i<< "   " << q[i] << std::endl;
    
    std::cout<< std::endl<< std::endl;
}

/**
 checks if passed queen placement is valid
 
 @param col index in array 'q'
 */
bool isOk(int col){
    
    //col = man
    //q[col] = woman
    
    for(int i = 0; i < col; i++){
        
        // Check if woman has already been matched
        if(q[col] == q[i]) return false;
        
    }
    
    for(int i = 0; i < col; i++){
        
        // If the curent man prefers the new woman and the new woman prefers the current man
        if((mp[col][q[i]] < mp[col][q[col]]) && (wp[q[i]][col] < wp[q[i]][i])) return false;
        
        // If the new man prefers the current woman and the current woman prefers the new man
        if((wp[q[col]][i] < wp[q[col]][col]) && (mp[i][q[col]] < mp[i][q[i]])) return false;
        
    }
    
    return true;
    
}
