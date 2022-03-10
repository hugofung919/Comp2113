# COMP2113_Proposal

## Group 102
Team members:  
Name: Shum Wai Chun, Ann  Student ID: 3035693583  
Name: Fung King Hung, Hugo Student ID: 3035695153  

## Game: Memory Matching Game  ##


**Description with basic game rules:**  
We are going to a Memory Matching Game in which all cards are laid face down initially. <br/>
In each round, the player needs to choose two cards by typing in the rows and columns of two cards, if the number of two cards are the same, the chosen cards could be turned over.   

This game is set to be customized for each player choosing the level they would like to challenge such as Level 1 to Level 4.


            Level of game                         Corresponding lives(Consecutive)
     Level 1: 4 rows and 4 columns                        4
     Level 2: 6 rows and 6 columns                        6
     Level 3: 8 rows and 8 columns                        8
     Level 4: 10 rows and 10 columns                     10


**Procedure of our game:**<br/>
1.Meun page ,the user would select start game or quit the game. [Optional Feature].    
2.Introduction and User select the level which they want to challenge  [Optional Feature].   
3.Game started and the user card set is generated randomly and not visible, only theme name is displayed in all squares.   
4.user input two cards' position  ( 1st and 2nd cards row and column value).   
5.Output the Cards with the chosen cards turned over.   
6.Check whether these cards are same and tell user.   
7a.If true: print the cards with chosen cards turned over.   
7b.If false: print the cards with chosen cards laid face down.   
8.Clear the terminal.   
9.Repeat until all card is matched .   


**Features that we plan to implement** <br/>
###### 1.Generation of random game sets or events(Dynamic memory management) ######
In this memory game, we need to generate game sets for users.(make_matrix_12.cpp).   
If the user chose the n-th level, 2*(n+1) types of cards would be generate.(e.g level 1 would have 4 types of cards).       
The higher level user choose, the harder game they would overcome.      
Since this memory game needs even numbers of cards and the number of different cards must be even.       
We have generate an array of types of cards and a linked list of with the cards position.       
For each character in the above array, we need to generate two integer within the linked list, put the character to its respective position,and delete the position variables from the linked list.       
Therefore, we should create some integer variables which helps ws memorize the length of a linked list.       
For instance, In level 1 (4rows and 4 column), in the 'A' character's turn, we have generate 3 and 5, their respective position is [int(3/4)][3%4](0 row 3 column) and [int(5/4)][5%4](1 row 1 column).    

###### 2.Data structures for storing game status ######
We mainly use two matrix in our game.  
matrix: an array with all answers.       
usermatrix: the matrix from the angle of user, with the laid down cards being '*'.    

###### 3.Dynamic memory management ######
In the function called make_matrix_12, we use both an array and a linked list and some integer variables to generate out matrix.     
cards = an array with the types of card(eg Level 1, 4*4 matrix, with 4 types of cards).   
random = a struct which each variable is the position of it initially.     
For level n,  a = number of cards = (n+1)*2          
For each type of cards, we would randomly choose 2*(n+1) variable in the linked list.        
The variable number is the position of the respective card.  
To add the type of card into our matrix, if the position is m, row number = (m/a), column number = (m%a).     
We need to delete that variable from the linked list.     
This could make sure that each card has different position.  

###### 4.File input/output (e.g., for loading/saving game status) ###### 
To make our game more encouraging, we have created a file which includes a handful of inspiring quotes.     
We sincerely hoped that our user can enjoy our game with happiness.      
addoil.txt would be called by the function called randomaddoil, which randomly choose a sentence within addoil.txt and print it.       
Sentence would be printed if the user guess wrongly to encourage our users.      
It would also be printed if our users choose to quit the game.      

###### 5.Program codes in multiple files ###### 
We have separated our code into several files, including.   
header_12.h   
main_12.cpp (for controling the user's input and output).   
make_matrix_12.cpp(for creating a matrix which satisfy the requirements).   
print_matrix_12.cpp(for pritning different matrix).   
makefile    
addoil.txt    

###### 6.Proper indentation and naming styles ######   
matrix = a matrix with all answer(for us to check and change the cards of usermatrix which would not be print).   
usermatrix = a matrix of the users' game set situation(maybe changed if users guess correctly).   

###### 7.In-code documentation ###### 
addoil.txt is a document which includes a handful of encouraging quote.   [Fun features]  
We would like to share happiness to our user, when they input wrongly, encouraging sentence would be printed to inspire them.    [Fun features]   
We used a function called randomaddoil to open this and randomly choose one line to output.      
