//print_cards_12.cpp
#include <iostream>
#include "header_12.h"
using namespace std;

//to print out the matrix
void print_cards_12(int level, char matrix[][10]){
    //format 
    //to indicate the position clearly
    cout << "   ";
    for (int i = 0 ; i <level ; i++){
        cout << i << " ";
    }
    cout << endl;
    cout << "  ";
  
    for ( int j = 0 ; j < level ; j++){
        cout << "--";
    }
    cout << endl;
    
    //print out the matrix elements one by one
    // from row to column
    for ( int k = 0; k < level; k++){
        cout << k << "| ";
        for (int m = 0; m < level ; m++){
            cout << matrix[k][m] << ' ';
        }
        cout << "\n";
    }
    cout << "\n";

}
