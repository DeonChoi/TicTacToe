#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//method declarations

void drawboard();
char evaluateboard();
void player1input();
void player2input();
void drawboard1();

//static variables

char square [10]= {'1','2','3','4','5','6','7','8','9','0'};  //original numbered square to use initially as reference
char square1 [9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};        //original empty square
char player1 [20];      //memory for name of player 1 up to 20 spaces
char player2 [20];      // memory for name of player 2 up to 20 spaces

//main method

int main() {
    printf("Enter name of player 1. This player will use 'X'.\n"); //player 1 intro
    scanf("%s", player1);                                           //player 1 name scanned in
    printf("\n");
    printf("Enter name of player 2. This player will use 'O'.\n"); // player 2 intro
    scanf("%s", player2);                                           //player 2 name scanned in
    printf("\n");
    printf("Welcome to Tic Tac Toe. Remember how each square is numbered, because you will use those numbers to place your marks.\n");
    printf("\n");
    drawboard(); //original printing of empty board
    //evaluateboard();
    bool player = true;
    //char exit='P'; //variable used to check whether game is over yet
    do {
        if(player)
            player1input();
        else
            player2input();
        player = !player; // using this boolean eqaulity to swtich between player 1 and player 2 input. reduces repetitive code.
        drawboard1();
    }
    while(evaluateboard()=='P');
    
    if(evaluateboard()=='Z'){
        printf("Game over! It's a cat game! \n");
    }
    else{
        printf("Game over! Congratulations! You won!\n");
        printf("Here is the winning board!\n");
        drawboard1();
    }
}

//draw the square matrix. this method is called repeatedly in loops.

void drawboard1() {
    printf(" %c | %c | %c ",square1[0], square1[1], square1[2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",square1[3], square1[4], square1[5]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",square1[6], square1[7], square1[8]);

    printf("\n");
}

// draw the numbered square method. this is only called once initially.

void drawboard() {
    printf(" %c | %c | %c ",square[0], square[1], square[2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",square[3], square[4], square[5]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",square[6], square[7], square[8]);
    
    printf("\n");
}

//method for evaluating all possible winning combinations on the board.

char evaluateboard() {
    if ((square1[0]==square1[1] && square1[1]==square1[2]) && (square1[2]=='X' || square1[2]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[3]==square1[4] && square1[4]==square1[5]) && (square1[5]=='X' || square1[5]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[6]==square1[7] && square1[7]==square1[8]) && (square1[8]=='X' || square1[8]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[0]==square1[3] && square1[3]==square1[6]) && (square1[6]=='X' || square1[6]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[1]==square1[4] && square1[4]==square1[7]) && (square1[7]=='X' || square1[7]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[2]==square1[5] && square1[5]==square1[8]) && (square1[8]=='X' || square1[8]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[0]==square1[4] && square1[4]==square1[8]) && (square1[8]=='X' || square1[8]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    else if((square1[2]==square1[4] && square1[4]==square1[6]) && (square1[6]=='X' || square1[6]=='O')) {
        //printf("Game over!\n");
        return 'Q';
    }
    //else if ((square1[0] != NULL) && (square1[1] != NULL) && (square1[2] != NULL) && (square1[3] != NULL) && (square1[4] != NULL) && (square1[5] != NULL) && (square1[6] != NULL) && (square1[7] != NULL) && (square1[8] != NULL)){
    //    return 'Z';
    //}
    else if ((square1[0] == 'X' || square1[0] == 'O') && (square1[1] == 'X' || square1[1]=='O') && (square1[2] == 'X' || square1[2] == 'O') && (square1[3] == 'X' || square1[3] == 'O') && (square1[4] == 'X' || square1[4] == 'O') && (square1[5] == 'X' || square1[5] == 'O') && (square1[6] == 'X' || square1[6] == 'O') && (square1[7] == 'X' || square1[7] == 'O') && (square1[8] == 'X' || square1[8] == 'O')){
        return 'Z';
    }
    else {
        printf("The game isn't over yet!\n");
        return 'P';
    }
}   

//method for gathering player 1 input
void player1input() {
    char place1;
    printf("\n");
    printf("Hello, ");
    printf("%s", player1);
    printf(". Which square would you like to place your 'X'? [1-9]\n");
    scanf("%c", &place1);
    place1=fgetc(stdin);
    
    if ((square1[place1-49] == 'X') || (square1[place1-49] == 'O')) {
        printf("Space Occupied.\n");
        player1input();
    }
    else if (place1 == 'q') {
        printf("Program now quitting.\n");
        exit(0);
    }
    else if (place1-48>9 || place1-48<1) {
        printf("Invalid input.\n");
        player1input();
    }
    else {
        place1--;
        square1[place1-48]='X';
    }
    /*
    switch(place1) {
        case '1' :
        square1[0]='X';
        break;
        case '2' :
        square1[0]='X';
        break;
        case '3' :
        square1[0]='X';
        break;
        case '4' :
        square1[0]='X';
        break;
        case '5' :
        square1[0]='X';
        break;
        case '6' :
        square1[0]='X';
        break;
        case '7' :
        square1[0]='X';
        break;
        case '8' :
        square1[0]='O';
        break;
        case '9' :
        square1[0]='O';
        break;
        case 'q' :
        exit(0);
    }
    */ 
}

//method for gathering player 2 input
void player2input() {
    char place2;
    printf("\n");
    printf("Hello, ");
    printf("%s", player2);
    printf(". Which square would you like to place your 'O'? [1-9]\n");
    scanf("%c", &place2);
    place2=fgetc(stdin);
    
    if ((square1[place2-49] == 'O') || (square1[place2-49] == 'X')) {
        printf("Space Occupied.\n");
        player2input();
    }
    else if (place2 == 'q') {
        printf("Program now quitting.\n");
        exit(0);
    }
    else if (place2-48>9 || place2-48<1) {
        printf("Invalid input.\n");
        player2input();
    }
    else {
        place2--;
        square1[place2-48]='O';
    }

    /*
    switch(place2) {
        case '1' :
        square1[0]='O';
        break;
        case '2' :
        square1[0]='O';
        break;
        case '3' :
        square1[0]='O';
        break;
        case '4' :
        square1[0]='O';
        break;
        case '5' :
        square1[0]='O';
        break;
        case '6' :
        square1[0]='O';
        break;
        case '7' :
        square1[0]='O';
        break;
        case '8' :
        square1[0]='O';
        break;
        case '9' :
        square1[0]='O';
        break;
        case 'q' :
        exit(0);
    }
    */

}