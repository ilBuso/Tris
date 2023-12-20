#include <stdio.h>   //input-output lib
#include <stdbool.h> //needed to use boolean
#include <stdlib.h>  //needed to use exit() and system()

//MACRO
#define nill -1
#define X 1
#define O 0

//functions
void main_menu();
void tutorial();
void rules();
void play();
void rank();
void quit();

void display_board();
int check_win();
bool insert(int in, bool turn);
bool change(int i, bool turn);

//global variables
int board[9];   //tris board

int X_win = 0;  //track X wins
int O_win = 0;  //track O wins

//------------------------------------------------------------------------------------------------------------------------------------
//main

int main(){

    //start
    main_menu();

    //end
    printf("\n\n");
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------
//main menu

void main_menu(){

    //clear terminal
    system("clear");

    //reset board
    for(int i = 0; i < 9; i++){
        board[i] = nill;
    }

    //welcome message
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────────────────┐ \n");
    printf("|                                                                             | \n");
    printf("|                                                                             | \n");
    printf("|         :::::::::::       :::::::::       :::::::::::       ::::::::        | \n");
    printf("|            :+:           :+:    :+:          :+:          :+:    :+:        | \n");
    printf("|           +:+           +:+    +:+          +:+          +:+                | \n");
    printf("|          +#+           +#++:++#:           +#+          +#++:++#++          | \n");
    printf("|         +#+           +#+    +#+          +#+                 +#+           | \n");
    printf("|        #+#           #+#    #+#          #+#          #+#    #+#            | \n");
    printf("|       ###           ###    ###      ###########       ########              | \n");
    printf("|                                                                             | \n");
    printf("|                                                                             | \n");
    printf("|                                - by ilBuso -                                | \n");
    printf("|                                                                             | \n");
    printf("└────────────────────────────────────────────────────────────────────────────── \n\n");
    
    //manu options
    printf("Cosa vuoi fare? Digita:\n");
    printf("1 - per leggere le regole del gioco\n");
    printf("2 - per scoprire come si gioca\n");
    printf("3 - per giocare a tris\n");
    printf("4 - per visualizzare la classifica\n");
    printf("5 - per chiudere il programma\n");
    
    //get right input
    int x=0;
    do{
        printf("\nLa tua scelta: ");
        scanf("%d", &x);
    } while(x < 1 || x > 5); //repeat until valid input
    
    //clear terminal
    system("clear");

    //input managment
    switch(x){
        //normal menu
        case 1:
            rules();
            break;

        case 2:
            tutorial();
            break;
            
        case 3:
            play();
            break;

        case 4:
            rank();
            break;

        case 5:
            quit();
            break;
    }

    main_menu();
}


//------------------------------------------------------------------------------------------------------------------------------------
//main functions

/*
    this function is used to disply the basic rules of the game
*/
void rules(){

    //title
    printf("\n");
    printf("      :::::::::  :::    ::: :::        :::::::::: :::::::: \n");
    printf("     :+:    :+: :+:    :+: :+:        :+:       :+:    :+: \n");
    printf("    +:+    +:+ +:+    +:+ +:+        +:+       +:+         \n");
    printf("   +#++:++#:  +#+    +:+ +#+        +#++:++#  +#++:++#++   \n");
    printf("  +#+    +#+ +#+    +#+ +#+        +#+              +#+    \n");
    printf(" #+#    #+# #+#    #+# #+#        #+#       #+#    #+#     \n");
    printf("###    ###  ########  ########## ########## ########       \n\n");

    //rules
    printf("Regole del gioco:\n");
    printf("- Il Tris è un gioco a turni per 2 giocatori.\n");
    printf("- Ogni giocatore può piazzare il proprio simbolo (X o O) in una qualsiasi casella vuota.\n");
    printf("- Lo scopo è ottenere una fila, colonna o diagonale di tre simboli identici.\n\n");

    //tutorial-exit loop
    int answer;
    do{
        //message asking if they want to see the rules
        printf("Vuoi leggere anche il tutotrial? [0] = si [1] = no -> (torna al menu)\n");
        
        //input
        printf("-> ");
        scanf("%d", &answer);

        //action 
        if(answer == 0){        //positive
            system("clear");
            tutorial();
        }else if(answer == 1){  //negative
            return;
        }else{                  //ERROR
            printf("Inserire un numero valido (0 o 1).\n");
        }
    } while(answer != 0 && answer != 1);
}

/*
    this function is used to display an explaation of how
    to play the game, and what are the steps to take
*/
void tutorial(){

    //title
    printf("\n");
    printf("  ::::::::::: :::    ::: ::::::::::: ::::::::  :::::::::  :::::::::::     :::     :::  \n");
    printf("     :+:     :+:    :+:     :+:    :+:    :+: :+:    :+:     :+:       :+: :+:   :+:   \n");
    printf("    +:+     +:+    +:+     +:+    +:+    +:+ +:+    +:+     +:+      +:+   +:+  +:+    \n");
    printf("   +#+     +#+    +:+     +#+    +#+    +:+ +#++:++#:      +#+     +#++:++#++: +#+     \n");
    printf("  +#+     +#+    +#+     +#+    +#+    +#+ +#+    +#+     +#+     +#+     +#+ +#+      \n");
    printf(" #+#     #+#    #+#     #+#    #+#    #+# #+#    #+#     #+#     #+#     #+# #+#       \n");
    printf("###      ########      ###     ########  ###    ### ########### ###     ### ########## \n\n");

    //tutorial
    printf("Una volta iniziata una partita e deciso a quale giocatore corrisponde quale simbolovi verra'\n");
    printf("chiesto di inserire un numero che corrisponde alla posizione (illustrate qui sotto) dove verra'\n");
    printf("posizionato il prorpio simbolo. Una volta premuto 'invio' la posizione è definitiva e viene salvata\n");
    printf("e si passa al turno sucessivo.  \n\n");

    printf("\t       │       │       \n");
    printf("\t   7   │   8   │   9   \n");
    printf("\t       │       │       \n");
    printf("\t───────┼───────┼───────\n");
    printf("\t       │       │       \n");
    printf("\t   4   │   5   │   6   \n");
    printf("\t       │       │       \n");
    printf("\t───────┼───────┼───────\n");
    printf("\t       │       │       \n");
    printf("\t   1   │   2   │   3   \n");
    printf("\t       │       │       \n\n");

    //exit loop
    int answer;
    do{
        //message asking if they want to retun tu the main menu
        printf("Vuoi tornare al Menu? [0] = si\n");

        //input
        printf("-> ");
        scanf("%d", &answer);

        //action
        if(answer == 0){
            return;
        }
    } while(answer != 0);
}

/*
    this function is used to start a match, it check if the inputs are valid
    if a player has won and keeps track of the wins
*/
void play(){

    //game
    int winner = nill;  //used to save the winner
    bool turn = false;  //used to keep track ogìf the turn (true=O false=X)
    bool over = false;  //indicates if the match is over
    int in;             //save user inut

    //match loop
    //repeat for 9 times (or till over == true) as the max number of actions possible
    //and avery cycle changes the turn
    for(int i = 0; i < 9 && !over; i++, turn = !turn){
        
        //clean termainal
        system("clear");

        //title
        printf("\n");
        printf("        :::   :::       ::: ::::::::::: ::::::::  :::    ::: \n");
        printf("      :+:+: :+:+:    :+: :+:   :+:    :+:    :+: :+:    :+:  \n");
        printf("    +:+ +:+:+ +:+  +:+   +:+  +:+    +:+        +:+    +:+   \n");
        printf("   +#+  +:+  +#+ +#++:++#++: +#+    +#+        +#++:++#++    \n");
        printf("  +#+       +#+ +#+     +#+ +#+    +#+        +#+    +#+     \n");
        printf(" #+#       #+# #+#     #+# #+#    #+#    #+# #+#    #+#      \n");
        printf("###       ### ###     ### ###     ########  ###    ###       \n\n");

        //print board
        display_board();

        //check turn
        if(turn){  // O

            //ask input
            do{
                printf("Ora tocca a O\n");
                printf("Dove vuoi posizionare il tuo simbolo?\n");
                printf("->");
                scanf("%d", &in);
            } while((in < 1 || in>9) || !insert(in, turn));  //validate input

            //save input
            insert(in, turn);

        }else{  // X

            //ask input
            do{
                printf("Ora tocca a X\n");
                printf("Dove vuoi posizionare il tuo simbolo?\n");
                printf("->");
                scanf("%d", &in);
            } while((in < 0 || in>9) || !insert(in, turn));  //validate input

            //save input
            insert(in, turn);
        }

        //chak for winner
        winner = check_win();

        //if there is a winner change variable and end next loop on start
        if(winner == X || winner == O){
            over = true;
        }
    }

    //clean termainal
    system("clear");

    //title
    printf("\n");
    printf("        :::   :::       ::: ::::::::::: ::::::::  :::    ::: \n");
    printf("      :+:+: :+:+:    :+: :+:   :+:    :+:    :+: :+:    :+:  \n");
    printf("    +:+ +:+:+ +:+  +:+   +:+  +:+    +:+        +:+    +:+   \n");
    printf("   +#+  +:+  +#+ +#++:++#++: +#+    +#+        +#++:++#++    \n");
    printf("  +#+       +#+ +#+     +#+ +#+    +#+        +#+    +#+     \n");
    printf(" #+#       #+# #+#     #+# #+#    #+#    #+# #+#    #+#      \n");
    printf("###       ### ###     ### ###     ########  ###    ###       \n\n");

    //print board
    display_board();

    //print result
    if(winner == nill){

        //message
        printf("E' un pareggio! Nessuno ha vinto!\n\n");

    }else if(winner == X){

        //messsage
        printf("Congratulazioni X! Hai vinto!\n\n");
        //update rankibg
        X_win++;

    }else if(winner == O){

        //message
        printf("Congratulazioni O! Hai vinto!\n\n");
        //update ranking
        O_win++;
    }

    //exit loop
    int answer;
    do{
        //message asking if they want to retun tu the main menu
        printf("Vuoi tornare al Menu? [0] = si\n");

        //input
        printf("-> ");
        scanf("%d", &answer);

        //action
        if(answer == 0){
            return;
        }
    } while(answer != 0);
}

/*
    this function shows the ranking based on the variables X_win and O_win
*/
void rank(){

    //title
    printf("\n");
    printf("      :::::::::      :::     ::::    ::: :::    ::: ::::::::::: ::::    :::  :::::::: \n");
    printf("     :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:      :+:     :+:+:   :+: :+:    :+: \n");
    printf("    +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+       +:+     :+:+:+  +:+ +:+         \n");
    printf("   +#++:++#:  +#++:++#++: +#+ +:+ +#+ +#++:++        +#+     +#+ +:+ +#+ :#:          \n");
    printf("  +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+       +#+     +#+  +#+#+# +#+   +#+#    \n");
    printf(" #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#      #+#     #+#   #+#+# #+#    #+#     \n");
    printf("###    ### ###     ### ###    #### ###    ### ########### ###    ####  ########       \n\n");

    //ranking
    printf("La classifica è:\n");
    printf("\n1° - %c\n", X_win > O_win ? 'X' : 'O'); // if (X_win > O_win) { printf("1° - X") } else { printf("1° - O") };
    printf("\n2° - %c\n", X_win > O_win ? 'O' : 'X'); // if (X_win > O_win) { printf("2° - O") } else { printf("2° - X") };

    //exit loop
    int answer;
    do{
        //message asking if they want to retun tu the main menu
        printf("\nVuoi tornare al Menu? [0] = si\n");

        //input
        printf("-> ");
        scanf("%d", &answer);

        //action
        if(answer == 0){
            return;
        }
    } while(answer != 0);
}

/*
    this function is ask the user a confirm to quit the program
*/
void quit() {

    //title
    printf("\n");
    printf("      ::::::::   :::    ::: ::::::::::: ::::::::::: \n");
    printf("    :+:    :+:  :+:    :+:     :+:         :+:      \n");
    printf("   +:+    +:+  +:+    +:+     +:+         +:+       \n");
    printf("  +#+    +:+  +#+    +:+     +#+         +#+        \n");
    printf(" +#+    +#+  +#+    +#+     +#+         +#+         \n");
    printf("#+#    #+#  #+#    #+#     #+#         #+#          \n");
    printf("########### ########  ###########     ###           \n\n");

    //quit
    printf("Sei sicuro di voler chiudere il programma? [0] = si [1] = no\n");

    // Input
    int answer;
    printf("-> ");
    scanf("%d", &answer);

    //action
    if(answer == 0){
        system("clear");
        exit(0);
    }else{
        return;
    }
}


//------------------------------------------------------------------------------------------------------------------------------------
//support functions

/*
    this function checks all the possible combination to win and returns the winner
*/
int check_win(){

    //check for winner

    //check diagonals
    if(board[0] == board[4] && board[0] == board[8]){
        if(board[2] != nill){
            /*
                this part is not really needed contrarily to the row and column case
                because if there is a win or the corners or the middle cell is occupied
                and at the start of the game if enouhgt the che in the play() function

                but maybe i am wrong so i keep this if statement
            */
            return board[0];
        }
    }else if(board[2] == board[4] && board[2] == board[6]){
        if(board[2] != nill){
             /*
                this part is not really needed contrarily to the row and column case
                because if there is a win or the corners or the middle cell is occupied
                and at the start of the game if enouhgt the che in the play() function

                but maybe i am wrong so i keep this if statement
            */
            return board[2];
        }
    }
    /*
        the next two loops take advantage of the liner array and its numeratio
        to check if the right cells of the array corresponds
         0 | 1 | 2
        ---+---+----
         3 | 4 | 5
        ---+---+---
         6 | 7 | 8
        - so to check the row we iterate the cells 0-3-6 (this is why the for loop
        ha i += 3) and for each iteretion wecheck if it corresponds to the cell+1
        (3+1=4) and cell+2 (3+2=5)
        - so to check the column we iterate the first three cells (0-1-2) and for each
        iteretion wecheck if it corresponds to the cell+3 (1+3=4) and cell+6 (1+6=7)
    */
    //check row
    for(int i = 0; i <= 6; i += 3){
        if(board[i] == board[i + 1] && board[i] == board[i + 2]){
            if(board[i] != nill){
                /*
                    this part is needed beacuse otherwise it reads a row
                    on nill value as a winner. So in the situation:
                     o | o |
                    ---+---+----
                       |   |
                    ---+---+---
                     x | x | x
                    the las row is not seen because it exits the loop in the middle row
                */
                return board[i];
            }
        }
    }
    //check column
    for(int i = 0; i <= 2; i++){
        if(board[i] == board[i + 3] && board[i] == board[i + 6]){
            if(board[i] != nill){
                /*
                    this part is needed beacuse otherwise it reads a column
                    on nill value as a winner. So in the situation:
                     o |   | x
                    ---+---+----
                     o |   | x
                    ---+---+---
                       |   | x
                    the las column is not seen because it exits the loop in the middle column
                */
                return board[i];
            }
        }
    }

    //no winern
    return nill;
}


/*
    this function transform the input (the input is tought in a way that makes
    it easy to play from the numpad infact every cell correspond to the same "cell"
    on ne numpad, or at least on my laptop) in to the right number for the array
    and insert the number in the correspondig cell and return if the cell is already occuied
*/
bool insert(int in, bool turn){
    switch(in){
        case 7:
            return change(0, turn);
            break;
 
        case 8:
            return change(1, turn);
            break;

        case 9:
            return change(2, turn);
            break;

        case 4:
            return change(3, turn);
            break;
 
        case 5:
            return change(4, turn);
            break;

        case 6:
            return change(5, turn);
            break;

        case 1:
            return change(6, turn);
            break;
 
        case 2:
            return change(7, turn);
            break;

        case 3:
            return change(8, turn);
            break;
    }

    return false;
}

/*
    this function checks if the cell is already
    occupied and inser the value
*/
bool change(int i, bool turn){

    if(board[i] == nill){
        if(turn){
            board[i] = O;
        }else{
            board[i] = X;
        }
        return true;
    }
    return false;
}

/*
    This function prints the board.
*/
void display_board(){   

    //Treat the one-dimensional array as a
    //bi-dimensional array
    for(int i = 0; i < 9; i += 3){

        printf("\t\t       │       │\n");
        printf("\t\t");

        for(int h = 0; h < 3; h++){

            printf("   ");

            if(board[i + h] == O){
                printf("O");
            }else if(board[i + h] == X){
                printf("X");
            }else{  //nill = " "
                printf(" ");
            }

            if(h < 2){
                printf("   │");                
            }
        }
        printf("\n");


        printf("\t\t       │       │\n");
        if(i < 6){
            printf("\t\t───────┼───────┼───────");
        }
        printf("\n");
    }
    printf("\n");
}