//make_matrix_12.cpp
#include <cstdlib>
#include "header_12.h"
#include<iostream>
#include<ctime>

using namespace std;
 
//start the function with struct since we need to use linked list
void make_matrix_12(char matrix[][10],int level){
    struct random{
        int num;
        random * next;
    };

    random * head = NULL, * tail = NULL , * current = NULL;

    char cards[level];
    //if the user choose level n, n types of cards would be generated
    //we use an array to store the types
    for (int i = 0; i < level; i++){
        cards[i] = i + 65;
    }
    //to create a linked list with n*n variables 
    //each variables equals to thwir position(1,2,3...n*n)
    for (int i = 0; i < level*level; i++){
        //first and the head of the list
        if ( i == 0){
            random * p = new random;
            p -> num = i;
            p -> next = NULL;
            head = p;
            tail = p;
            current = p;
        }
        else {
            random * p = new random;
            p ->num = i;
            p ->next = NULL;
            tail -> next = p;
            tail = p;
        }
    }
    int listnum = level*level;
    //there are n cards for each types (eg,level1 -> 4*'A", 4*'B', 4*'C', 4*'D')
    for (int i = 0; i  < level; i++){
        int eachcard = level;
        //eachcard means the number of cards for each type 
        while (eachcard != 0){
            //for each card, we should find a random number, the number equals to the position of linked list
            //the variable of link list means the position of the card
            //this could prevent the odd number of cards
            //and to ensure that each cards have different position
            random * current = head;
            srand(time(NULL));
            int b = rand() % listnum;
            if (b == 0){
                int position = head ->num;
                //e.g In level1, if int position = 5, 
                //row coordinate = 5/4 = 1, column coordinate = 5%4 = 1
                matrix[position/level][position%level] = cards[i];
                //to deleted the first variable
                head = head -> next;
            }
            else {
                while (b!=1){
                    current = current->next;
                    b--;
                }
                if (current -> next -> next != NULL){
                    int position = current->next->num;
                    matrix[position/level][position%level] = cards[i];
                    //to delete q
                    random *q = current -> next;
                    current->next = current->next->next;
                    delete q;
                }
                else {
                    int position = current -> next-> num;
                    matrix[position/level][position%level] = cards[i];
                    random *q = current -> next;
                    current -> next = NULL;
                    tail = current;
                    delete q;
                }
                
            }
            eachcard--;
            listnum--;
        }
    }
}
