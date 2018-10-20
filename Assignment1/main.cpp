/*
 CSCI 211 Assignment 1 - Perfect squares
 Damian Diaz
 
 This program will contiously sqaure itself until the last two digits are both odd.
 
 */

#include <iostream>

int main() {
    
    // Initialization
    int i = 1;
    
    while(true){
        
        int k = i * i;
        
        // Check if last digit is odd
        if((k%10)/2 == 1){
            
            // Check if second to last digit is odd
            if(((k/10)%10)/2 == 1){
                
                // Print result
                std::cout << k << std::endl;
                
                // End loop
                exit(0);
                
            }
        } else {
            
            // Increment i
            i++;
        }
            
    }
    
    return 0;
}
