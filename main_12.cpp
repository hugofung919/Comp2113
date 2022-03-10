//main_12.cpp
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "header_12.h"

using namespace std;
#include <cstdlib>

//randomaddoil is to input a txt file which include a handful of encouraging quote and print it out 
void randomaddoil(){
    ifstream fin("addoil.txt");
    string s;
    string selected_line ;
    int nlines  = 0;
    srand(time(NULL));
    int choose;
    choose  = rand() % 20;
    while( getline( fin, s ) ){
        if(nlines == choose) {
            selected_line = s ;
            break;
        }
        else {
            nlines++;
        }
    }
    cout << s << endl;
    
}

//startgame function
void startgame(){
    //Menu for user
    int Menu , level;
    cout << "--------Menu--------" << endl;
    cout << "1. Start a New Game " << endl;
    cout << "2. End Game " << endl;
    cout << "--------------------" << endl;
    cin >> Menu;

    //Start a New Game
    while (Menu == 1){
        //To print out the levels for users to choose
        cout <<"\nThere are four levels for you to challenge.\n\n" << "Level of game  "<< endl;
        for (int i = 1; i <= 4; i++){
            cout << right;
            cout << "Level " << i <<":"<< setw(3) << (i+1)*2 << " rows and" << setw(3) << (i+1)*2 << " columns" << endl;
        }
        cout << right;
        cout << endl;
        cout << "Please input the level of game you would like to challenge: ";
        cin >> level;
        while (level > 4 || level < 1 ){
            cout << "This is an invalid value. \n";
            cout << "Please input again the level of game you would like to challenge: ";
            cin >> level;
        }
        level = (level+1)*2;
        //To create array for our card set
        char matrix[level][10];
        char usermatrix[level][10];
        //initialize the usermatrix into all faid down
        for (int i = 0; i < level; i++){
            for (int j = 0; j < level; j++){
                usermatrix[i][j] = '*';
            }
        }
        //call the make_matrix_12 function to generate a card set
        make_matrix_12(matrix, level);
        int notopen = level*level;
        //this struct is the coordinate user input
        struct input{
            int row;
            int column;
        };
        input Apoint, Bpoint;
        //notopen means the number of cards which is not yet opened
        while (notopen != 0){
            //to print out the usermatrix using print_cards_12
            cout << "This is your card set." << endl;
            print_cards_12(level, usermatrix);
            cout << "Please enter the FIRST card row and column value : ";
            cin >> Apoint.row >> Apoint.column ;
            //user input two coordinate which should fulfill our condition
            //coordinates should not be opened or be same 
            while ( Apoint.row  > (level - 1) || Apoint.column > (level - 1)) {
                cout << "Please enter the FIRST card row and column value : ";
                cin >> Apoint.row >> Apoint.column ;   
            } 
            cout << "Please enter the SECOND card row and column value :";
            cin >> Bpoint.row >> Bpoint.column;
            while ( Bpoint.row  > (level - 1) || Bpoint.column > (level - 1)) {
                cout << "Please enter the SECOND card row and column value : ";
                cin >> Bpoint.row >> Bpoint.column;
            }
            //to make sure that both inputed coordinates are laid down
            if (usermatrix[Apoint.row][Apoint.column]=='*' && usermatrix[Bpoint.row][Bpoint.column]=='*'){
                //to make sure that two coordinate are not the same
                if (Apoint.row != Bpoint.row || Apoint.column != Bpoint.column ){
                    usermatrix[Apoint.row][Apoint.column] = matrix[Apoint.row][Apoint.column];
                    usermatrix[Bpoint.row][Bpoint.column] = matrix[Bpoint.row][Bpoint.column];
                    //the user input are correct!
                    if (usermatrix[Apoint.row][Apoint.column] == usermatrix[Bpoint.row][Bpoint.column]){
                        cout << "\nYou are correct!"<< "\nLet's go to the next round!\n"<< endl;
                        //notopen should minus two since two cards are opened
                        notopen = notopen - 2;
                    }
                    //the user input are incorrect
                    else{
                        cout << "\nYou are wrong!"<< endl;
                        randomaddoil();
                        print_cards_12(level, usermatrix);
                        char next;
                        cout << "Try again! Enter \"N\" to go to the next round!" << endl;
                        cout << "You may exit this game immediately bt enter \"E\"" << endl;
                        //since the user is incorrect, we should change it back into *
                        usermatrix[Apoint.row][Apoint.column] = '*';
                        usermatrix[Bpoint.row][Bpoint.column] = '*';
                        cin >> next;
                        //to see whether the user wants to continue
                        while (next != 'N' && next != 'E'){
                            cout << "Enter \"N\" to go to the next round!" << endl;
                            cin >> next;
                        }
                        if (next == 'N'){
                            system("clear");
                        }
                        else if (next == 'E'){
                            //if incorrect, encouraging quotes are printed
                            randomaddoil();
                            cout << "Goodbye ! See you next time." << endl;
                            exit(1);
                        }
                    }
                }
                //to tell user the situation that she entered same points
                else {
                    cout << "You have input two same points!" << endl;
                }
            }
            //the user input cards are opened already
            else {
                cout << "Your input is not vaild! Enter again!";
            }
        }
        //notopen == 0  and the while loop stops means our user won the game
        cout << "\n Congratuation! You have won this game!" << endl;
        cout << "If you want to play again, please enter \'1\'"<< endl;
        cout << "If you want to exit, please enter \'2\'"<< endl;
        //to ask whether our user wants to continue
        cin >> Menu;
    }
    if (Menu == 2){
        randomaddoil();
        cout << "Goodbye ! See you next time." << endl;
        exit(1);
    }
    else {
        cout << "This is an invalid input. Please Try again! " << endl;
        startgame();
    }
}



int main(){
    cout << "\nWelcome to our memory matching game!\n\n";
    startgame();
}
