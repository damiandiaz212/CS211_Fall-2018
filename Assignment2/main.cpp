/*
 CSCI 211 Assignment 2 - Right shift equivalence
 Damian Diaz
 
 This program will check if two arrays are right shift equivalent.
 
*/

#include <iostream>

/*
 rightShift
 Takes an array and shifts all the elements one space to the right.
 Last element loops around to first index.
 */
void rightShift(int array[], int len){
    
    // Save last index value
    int lastIndexValue = array[len-1];
    
    // Loop through array and shift every element to the right.
    for(int i = len - 1; i >= 0; i--){
        
        // If first index, assign the lastIndexValue to it.
        if(i==0)
            array[i] = lastIndexValue;
        else
            array[i] = array[i-1];
    }
}

/*
 printArray function
 Takes an array and prints out the values.
*/
void printArray(char name, int *array, int len){
    
    std::cout<<name<<": ";
    
    // Loop and print array elements.
    for(int i = 0; i < len; i++){
        std::cout<<array[i];
    }
    std::cout<<std::endl;
}

/* equivalent function
 Takes two arrays and determines if they are equivalent
*/
bool equivalent(int a[], int b[], int n){
    
    // Iterate through the length of both arrays
    for(int i = 0; i < n; i++){
        
        // Check if index values are equivalent.
        if(a[i] != b[i]){
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 1, 2};
    bool eq = false;
    
    printArray('a', a, n);
    printArray('b', b, n);
    
    std::cout<<std::endl<<"Shifting..."<<std::endl<<std::endl;
    
    // Loop through n number of times to check if rows are right row equivalent
    for(int i = 0; i < n; i++){
        if(!equivalent(a, b, n)){
            rightShift(b, n);
        }else{
            eq = true;
        }
    }
    
jump: printArray('c', a, n);
    
    goto jump;
    
    printArray('a', a, n);
    printArray('b', b, n);
   
    if(eq){
        std::cout<<n<<" shifts."<<std::endl;
        std::cout<<"Arrays are right shift equivalent." <<std::endl;
    }else{
        std::cout<<n<<" shifts."<<std::endl;
        std::cout<<"Arrays are not right shift equivalent."<<std::endl;
    }
    
    
    return 0;
}
