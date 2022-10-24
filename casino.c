#include <stdio.h>    //From C Libary 
#include <stdlib.h>   //From C Libary 
#include <time.h>     // From C libary 

#include "casino.h"   //include header file

// Main 
int main() 
{
    srand(time(0)); //Passed argument 0 or Null in srand function to seed random function
    int game;
    int cash = 10000; // Amount of cash given to player 
    int play = 1; 

//Varibale storing selected game
    welcomeScreen();
    while(play == 1) {      
        clearScreen();
        game = displayMenu();
        clearScreen();

        switch(game) // switch decision to set cash equal to called function
        {
            case SLOTS: 
                cash = playSlots(cash);
                break;
            case SCRATCH:
                cash = playScratchOffs(cash);
                break;
            case BLACKJACK:
                cash = playBlackJacks(cash);
                break;
            case ROULETTE:
                cash = playRoulette(cash);
                break;
            case COINFLIP:
                cash = playCoinFlip(cash);
                break;
            case EXIT:              //player can choose to EXIT
                game = 0;       
                return 0;      
        }
        printf("Your cash balance is $%d\n", cash);         //display of player's cash balance
        printf("Would you like to play another game? (1 = Yes, 0 = No)\n");     //prompt the player to play another game
        scanf("%d", &play);     //input
    }

    return 0;

}
//end of main function


// Casino Welcome Screen
void welcomeScreen()
{
    printf("                                *********************************************************\n");
    printf("                               |#########################################################|\n");
    printf("                               |#########################################################|\n");
    printf("                               |###########                                  ############|\n");
    printf("                               |###########             Lin Casino           ############|\n");
    printf("                               |###########                                  ############|\n");
    printf("                               |#########################################################|\n");
    printf("                               |#########################################################|\n");
    printf("                                *********************************************************\n");
    
}
// Hit enter screen
void clearScreen()
{
    char enter;
    printf("                                                  <Hit Enter to continue>\n");
    scanf("%c", &enter);
    //system("cls");        // For Window
    system("clear");       // For Linux/ Mac
}
// Selection of game menu
int displayMenu()
{
    int select;
    do 
    {
        printf("Select a game to play by entering the number next to the game\n");
        printf("1. Slots\n");
        printf("2. Scratch Offs\n");
        printf("3. Black Jack\n");
        printf("4. Roulette\n");
        printf("5. Coin Flip\n");
        printf("6. EXIT\n");            //EXIT is included if player want to quit 
        scanf("%d", &select);

        if(select <= 0 || select > 6){
            printf("\n");
            printf("Ivalid Choice\n");
            printf("Please Choose Again\n");
            printf("\n");
        }
    } while (select < SLOTS || select > EXIT);          //EXIT is included for selection
// select will not be less than 0 OR greater than 3
    return select;
} 

int playSlots(int cash) 
{
    // bet amount
    const int BET = 5;
    // payouts for two matches
    const int MATCH_TWO = 5;
    //payout for three matches
    const int MATCH_THREE = 50;
    // loop control 
    int play = 1;
    // symbols 
    char symOne;
    char symTwo;
    char symThree;

    printf("Lets play the slot machines!\n\n");
    printf("Your cash blance is $%d. The bet is $%d.\n", cash, BET);
    printf("Match two symbols to win $%d\n", MATCH_TWO);
    printf("Match all three symbols to win $%d\n\n", MATCH_THREE);

    //player's cash amount has to greater than or equal to BET($5) inorder to play
    if(cash >= BET) {
    }
    else { 
        play = 0;
    }
    // if not greater or equal to BET amount, the play is ended

    // continue playing until user wants to stop
    while(play) {
        cash = cash - BET;
        printf("Spinning... \n\n");
        // generate the three symbols
        symOne = randomSymbol();
        symTwo = randomSymbol();
        symThree = randomSymbol();
        printf("%c %c %c\n\n", symOne, symTwo, symThree);
        //all three symbols have to match
        if ((symOne == symTwo) && (symTwo == symThree)) {
            cash += MATCH_THREE;
            printf("3 symbols matched\n\n");
            // display of players cash balance
            printf("CASH = $%d\n\n", cash);
        }
        // two of the three symbols have to match
        else if ((symOne == symTwo) || (symOne == symThree) || (symTwo == symThree)) {
            cash += MATCH_TWO;
            printf("2 symbols matched\n\n");
            // display of players cash balance
            printf("CASH = $%d\n\n", cash);
        } 
        else {
            cash += 0; // CHECK OVER VIDEO
            printf("No symbols matched\n\n");
            // display of players cash balance
            printf("CASH = $%d\n\n", cash);
        }

        // if players cash amount is greater than BET amount, enter 1 to continue or 0 to end
        if(cash >= BET) {
            printf("Would you like to spin again (YES = 1, NO = 0)?\n");
            scanf("%d", &play);
        }
        else {
            break;
        }
        //if not greater or equal to BET amount, the play is ended

        printf("\n");
    }

    printf("Thank you for playing slots in Lin Casino! Your cash out is $%d\n\n", cash);
    // players final cash balance is displayed when ending play
    // or the players cash balance is displayed if cash amount is less than bet amount, which displays 0
    return cash;
}

char randomSymbol() {
    const int SYMBOLS = 6; //range from 0-5
    const char symbols[] = {'$', '%', '&', '#', '@', '!'}; //selected six symbols
    char symbol; //used to store random symbol
    int num; // used to store random number

    // Random number is generated, ranging from 0-5
    num = rand() % 6;
    //the selected number is assigned its random symbol
    switch(num)
    {   
        case 0:
            symbol = symbols[0];
            break;
        case 1: 
            symbol = symbols[1];
            break;
        case 2:
            symbol = symbols[2];
            break;
        case 3:
            symbol = symbols[3];
            break;     
        case 4:
            symbol = symbols[4];
            break;     
        case 5:
            symbol = symbols[5];
            break;     
    }

    return symbol;
}

// scratch off game
int playScratchOffs(int cash)
{
    int type;
    int count;
    int c;
    int play = 1;
    OneDollar oneSo;
    TwoDollar twoSo;
    FiveDollar fiveSo;

    printf("Let's play Scratch Off Tickets!\n");
    printf("Players can select from One Dollar, Two Dollar, and Five Dollar Tickets\n");
    printf("Prizes are based on the ticket selected\n\n");

    while(play == 1) {          
        printf("\nWhich type of scratch off would you like\n");
        printf("(1 = One Dollar, 2 = Two Dollar, 5 = Five Dollar)?\n");
        scanf("%d", &type);     //desired scratch off is selected
        printf("How many scratch offs would you like?\n");
        scanf("%d", &count);    //amount of scratch off is taken in 

        //start of for loop for desired scratch off and its amount
        for(c = 0; c < count; ++c) {
            switch (type) {
                case 1:     //one is for one dollar scratch off(function is called)
                    if(cash >= type) {      //player's cash has to be greater than the scratchoff type $1
                        cash -= (type);         //scratch off cost will be deducted from player's cash
                        oneSo = createScratchOffOne(oneSo);     
                        displayScratchOffOne(oneSo);
                        cash += cashOneDollar(oneSo);    //cash will equal to cash earned from function cashOneDollar
                    }
                    else {          //if player does not have enough money
                        printf("Player does not have enough money to play!\n");
                        c = count;         //loop varaible will be set to upper limit and cancel loop
                    }
                    break;
                case 2:     //two is for two dollar scrath off(function is called)
                    if(cash >= type) {      //player's cash has to be greater than the scratchoff type $2
                        cash -= (type);         //scratch off cost will be deducted from player's cash      
                        twoSo = createScratchOffTwo(twoSo);
                        displayScratchOffTwo(twoSo);
                        cash += cashTwoDollar(twoSo);    //cash will equal to cash earned from function cashTwoDollar
                    }
                    else {           //if player does not have enough money
                        printf("Player does not have enough money to play!\n");
                        c = count;          //loop varaible will be set to upper limit and cancel loop
                    }
                    break;
                case 5:     //five is for five dollar scratch off(function is called)
                    if(cash >= type) {      //player's cash has to be greater than the scratchoff type $5
                        cash -= (type);         //scratch off cost will be deducted from player's cash
                        fiveSo = createScratchOffFive(fiveSo);      
                        displayScratchOffFive(fiveSo);
                        cash += cashFiveDollar(fiveSo);  //cash will equal to cash earned from function cashFiveDollar
                    }
                    else {           //if player does not have enough money
                        printf("Player does not have enough money to play!\n");
                        c = count;          //loop varaible will be set to upper limit and cancel loop
                    }
                    break;
            }

        }
        //end of for loop
        printf("\nDo you wish to Continue? (Yes = 1, No = 0)\n");
        scanf("%d", &play);
        
    } 
    //end of while loop
    return cash;
}  
//end of scratch off function

//one dollar function
OneDollar createScratchOffOne(OneDollar oneSo) {
    const int SYMS = 2;     //number of bonus symbols
    const int NUMS = 5;     //number of player numbers and prizes
    const int BASE = 20;    //random function to generate numbers 
    const char SYMBOLS[] = {'$', '%', '&', '#', '@', '!'};      //given symbols
    int usedSyms[] = {0, 0, 0, 0, 0, 0};         //array for keeping track of symbols and is initialized to 0
    int sym;    //random symbol
    int n;      //looping variable
    int used = 0;       //loop control varaible to indicate if symbol have been used

    oneSo.winNumber = rand() % BASE + 1;    //given random winning number ranging 1-20
    
    //random numbers are generated
    for(n = 0; n < NUMS; ++n) {
        oneSo.numbers[n] = rand() % BASE + 1;   //range from 1-20
    }
    //end of for loop

    //prize amount are generated 
    for(n = 0; n < NUMS; ++n) {
        oneSo.prizes[n] = (float)((rand() % BASE + 1) * 5);     //range from 5-100
    }
    //end of for loop

    //2 random symbols are generated
    for(n = 0; n < SYMS; ++n) {

        used = 0;

        while(!used) {                                                  //while loop used to check if symbol have been used
            sym = rand() % (sizeof(SYMBOLS)/ sizeof(SYMBOLS[0]));       
            if(!usedSyms[sym]) {                                        //if winning number have been used then number is marked as 1
                usedSyms[sym] = 1;
                used = 1;
                break;
            }
        }
        //end of while loop
        
        switch(sym) {
            case 0:
                oneSo.bonus[n] = SYMBOLS[0];
                break;
            case 1:
                oneSo.bonus[n] = SYMBOLS[1];
                break;
            case 2:
                oneSo.bonus[n] = SYMBOLS[2];
                break;
            case 3:
                oneSo.bonus[n] = SYMBOLS[3];
                break;
            case 4:
                oneSo.bonus[n] = SYMBOLS[4];
                break;
            case 5:
                oneSo.bonus[n] = SYMBOLS[5];
                break;
        }
 
        //end of for loop
    }
    return oneSo;
}
//end of createScratchOffOne function

//one dollar scratch off display function
void displayScratchOffOne(OneDollar oneSo) {
    const int SYMS = 2;     //number of bonus symbols
    const int NUMS = 5;     //number of player numbers and prizes
    int n;      //loop variable

    //usage of format specifiers and for loops to print out one dollar display
    printf("\nGetting your Scratch Offs...\n");
    printf("+");
    for(n = 0; n < 42; ++n) {
        printf("-");
    } 
    printf("+\n");
    printf("| WINNING NUMBER");                             //winning number
    printf("%10d%17s|\n", oneSo.winNumber, " ");              
    printf("|%42s|\n"," ");                 
    printf("| YOUR NUMBERS%29s|\n", " ");                   //your numbers
    printf("|");
    for(n = 0; n < NUMS; ++n) {
        printf("%8d", oneSo.numbers[n]);
    }
    printf("%2s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| PRIZES%35s|\n", " ");                         //prizes
    printf("|%42s|\n"," ");
    printf("|");
    for(n = 0; n < NUMS; ++n){
        printf("%8.2lf", oneSo.prizes[n]);
    }
    printf("%2s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| SYMBOLS%34s|\n", " ");                        //prizes
    printf("|%42s|\n"," ");
    printf("|");
    for(n = 0; n < SYMS;++n){
    printf("%8c", oneSo.bonus[n]);
    }
    printf("%26s|\n", " ");
    printf("+");
    for(n = 0; n < 42; ++n) {
        printf("-");
    }
    printf("+\n");
}
//end of displayScratchOffOne function

//two dollar function
TwoDollar createScratchOffTwo(TwoDollar twoSo) {
const int SYMS = 2;     //number of bonus symbols
const int NUMS = 10;    //number of player numbers and prizes
const int BASE = 30;    //random function to generate numbers
const char SYMBOLS[] = {'$', '%', '&', '#', '@', '!'};      //given symbols
int usedSyms[] = {0, 0, 0, 0, 0, 0};    //array for keeping track of symbols and is initialized to 0
int usedNums[BASE];         //array for keeping track of numbers
int sym;        //variable for random symbol
int n;          //loop variable
int num;        //varibale for randomly generated number
int used = 0;   //loop control varaible to indicate if symbol have been used

for(n = 0; n < BASE; ++n) {     //usedNums array's elements are initialized to 0
    usedNums[n] = 0;
}
//end of for loop

//random number for winning number is generated ranging 1-30
for(n = 0; n < SYMS; ++n) {
    
    used = 0; 
    while(!used){                           //while loop used to see is WINNING number have been used
        num = (rand() % BASE) + 1;
        if(!usedNums[num-1]) {                  //if winning number have been used then number is marked as 1
            usedNums[num-1] = 1;
            twoSo.winNumbers[n] = num;
            used = 1;
            break;
        }
    }
    //end of while loop
}
//end of for loop

//player numbers are randomly gernerated rangin 1-30
for(n = 0; n < NUMS; ++n) {
    twoSo.numbers[n] = rand() % BASE + 1;
}
//end of for loop

//prizes are generated ranging from 5-150
for(n = 0; n < NUMS; ++n) {
    twoSo.prizes[n] = (float)((rand() % BASE + 1) * 5);
}
//end of for loop

//random bonus symbol is generated
    for(n = 0; n < SYMS; ++n) {

        used = 0;

        while(!used) {                                                  //while loop used to check if symbol have been used
            sym = rand() % (sizeof(SYMBOLS)/ sizeof(SYMBOLS[0]));
            if(!usedSyms[sym]) {                                        //if symbol been used marked as 1
                usedSyms[sym] = 1;
                used = 1;
                break;
            }
        }
        //end of while loop

        switch(sym) {
            case 0:
                twoSo.bonus[n] = SYMBOLS[0];
                break;
            case 1:
                twoSo.bonus[n] = SYMBOLS[1];
                break;
            case 2:
                twoSo.bonus[n] = SYMBOLS[2];
                break;
            case 3:
                twoSo.bonus[n] = SYMBOLS[3];
                break;
            case 4:
                twoSo.bonus[n] = SYMBOLS[4];
                break;
            case 5:
                twoSo.bonus[n] = SYMBOLS[5];
                break;
        }
    } 
//end of for loop

return twoSo;
}
//end of two dollar function

//scratchofftwo is displayed
void displayScratchOffTwo(TwoDollar twoSo) {
    const int SYMS = 2;     //number of bonus symbols
    const int NUMS = 10;    //number of player numbers and prizes
    const int BREAK = 4;    //2nd new line for player numbers and prizes
    int n;                  //loop variable

    printf("\nGetting your Scratch Offs...\n");
    printf("+");
    for(n = 0; n < 42; ++n) {
        printf("-");
    }
    printf("+\n");

    printf("| WINNING NUMBERS%6s", " ");                //winning number
    
    for(n = 0; n < SYMS; ++n){
        printf("%6d", twoSo.winNumbers[n]);
    }
    printf("%8s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| YOUR NUMBERS%29s|\n", " ");               //your number
    printf("|");
    for(n = 0; n < NUMS; ++n) {
        printf("%8d", twoSo.numbers[n]);
        if(n == BREAK) {
            printf("%2s|\n", " ");
            printf("|");
        }
    }
    printf("%2s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| PRIZES%35s|\n", " ");                     //prizes
    printf("|%42s|\n"," ");
    printf("|");
    for(n = 0; n < NUMS; ++n){
        printf("%8.2lf", twoSo.prizes[n]);
        if(n == BREAK) {
            printf("%2s|\n", " ");
            printf("|");
        }
    }
    printf("%2s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| SYMBOLS%34s|\n", " ");                    //symbols
    printf("|%42s|\n"," ");
    printf("|");
    for(n = 0; n < SYMS;++n){
    printf("%8c", twoSo.bonus[n]);
    }
    printf("%26s|\n", " ");
    printf("+");
    for(n = 0; n < 42; ++n) {
        printf("-");
    }
    printf("+\n");
}
//end of displayScratchOffTwo function

//five dollar function
FiveDollar createScratchOffFive(FiveDollar fiveSo) {
const int SYMS = 4;     //number of bonus symbols
const int NUMS = 12;    //number of player numbers and prizds
const int BASE = 50;    //for random function to generate umbers
const char SYMBOLS[] = {'$', '%', '&', '#', '@', '!', '^', '*'};      //given symbols
int usedSyms[] = {0, 0, 0, 0, 0, 0, 0, 0};      //array for keeping track of symbols and is initialized to 0
int usedNums[BASE];     //array for keeping track of numbers
int sym;    //variabe for random symbol
int n;      //loop variable
int num;    //varibale for randomly generated number
int used;   //loop control variable

for(n = 0; n < BASE; ++n) {     //usedNums array's elements are initialized to 0
    usedNums[n] = 0;        
}
//end of for loop

//generate random winning numbers ranging 1-50
for(n = 0; n < SYMS; ++n) {
    
    used = 0; 
    while(!used){                       //while loop used to see is WINNING number have been used
        num = rand() % BASE + 1;
        if(!usedNums[num-1]) {              //if winning number have been used then number is marked as 1
            usedNums[num-1] = 1;
            fiveSo.winNumbers[n] = num;
            used = 1;
            break;
        }
    }
    //end of while loop

}
//end of for loop

//player numbers are randomly generated ranging 1-50
for(n = 0; n < NUMS; ++n) {
    fiveSo.numbers[n] = rand() % BASE + 1;
}
//end of for loop

//prizes are randomly gnerated ranging 5-250
for(n = 0; n < NUMS; ++n) {
    fiveSo.prizes[n] = (float)((rand() % BASE + 1) * 5);
}
//end of for loop

//symbols are randomly generated
for(n = 0; n < SYMS; ++n) {

    used = 0;

    while(!used) {                                                  //while loop used to check if symbol have been used
        sym = rand() % (sizeof(SYMBOLS)/ sizeof(SYMBOLS[0]));
        if(!usedSyms[sym]) {                                        //if symbol been used marked as 1
            usedSyms[sym] = 1;
            used = 1;
            break;
        }
    }
    //end of while loop

    switch(sym) {
        case 0:
            fiveSo.bonus[n] = SYMBOLS[0];
            break;
        case 1:
            fiveSo.bonus[n] = SYMBOLS[1];
            break;
        case 2:
            fiveSo.bonus[n] = SYMBOLS[2];
            break;
        case 3:
            fiveSo.bonus[n] = SYMBOLS[3];
            break;
        case 4:
            fiveSo.bonus[n] = SYMBOLS[4];
            break;
        case 5:
            fiveSo.bonus[n] = SYMBOLS[5];
            break;
        case 6:
            fiveSo.bonus[n] = SYMBOLS[6];
            break;
        case 7:
            fiveSo.bonus[n] = SYMBOLS[7];
            break;
    }
} 
//end of for loop

return fiveSo;
}
//end of five dollar function

//scratchofffive is displayed
void displayScratchOffFive(FiveDollar fiveSo) {
    const int SYMS = 4;     //number of bonus symbols
    const int NUMS = 12;    //number of player numbers and prizes
    const int BREAK = 4;    //start of second and third line of the player numbers and prizes
    int n;                  //loop variable

    printf("\nGetting your Scratch Offs...\n");
    printf("+");
    for(n = 0; n < 42; ++n) {
        printf("-");
    }
    printf("+\n");
    printf("| WINNING NUMBER%7s", " ");                 //winning number
    for(n = 0; n < SYMS; ++n) {
        printf("%4d", fiveSo.winNumbers[n]);
    }
    printf("%4s|\n", " ");
    printf("|%42s|\n", " ");
    printf("| YOUR NUMBERS%29s|\n", " ");               //your numbers
    printf("|");
    for(n = 0; n < NUMS; ++n) {
        printf("%8d", fiveSo.numbers[n]);
        if(n == BREAK) {
            printf("%2s|\n", " ");
            printf("|");
        }
        if(n == BREAK * 2){
            printf("%10s|\n", " ");
            printf("|");
        }
    }
    printf("%18s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| PRIZES%35s|\n", " ");                       //prizes
    printf("|%42s|\n"," ");
    printf("|");
    for(n = 0; n < NUMS; ++n){
        printf("  %6.2lf", fiveSo.prizes[n]);
        if(n == BREAK) {
            printf("%2s|\n", " ");
            printf("|");
        }
        if(n == BREAK * 2) {
            printf("%10s|\n", " ");
            printf("|");
        }
    }
    printf("%18s|\n", " ");
    printf("|%42s|\n"," ");
    printf("| SYMBOLS%34s|\n", " ");                        //symbols
    printf("|%42s|\n"," ");
    printf("|");
    for(n = 0; n < SYMS;++n){
    printf("%8c", fiveSo.bonus[n]);
    }
    printf("%10s|\n", " ");
    printf("+");
    for(n = 0; n < 42; ++n) {
        printf("-");
    }
    printf("+\n");
}
//end of displayscratchoffFive

//OneDollar Scratch off cash function
int cashOneDollar(OneDollar oneSo) {
    const int SYMS = 2;     // number of bonus symbols
    const int NUMS = 5;     //number of player numbers and prizes
    float cash = 0;         //player's cash
    int n;                  // looping variable
    char bonus = getBonus(ONE);     //bonus variable

    printf("\nBonus symbol is %c\n", bonus);
    //player's number compared with winning numbers
    for(n = 0; n < NUMS; ++n) {
        if(oneSo.numbers[n] == oneSo.winNumber) {
            cash += oneSo.prizes[n];                //if numbers are matched, the associted prize is added to player's cash
        }
    }
    //end of loop

    //player's symbols are compared to bonus symbol
    for(n = 0;n < SYMS; ++n) {
        if(oneSo.bonus[n] == bonus) {               //is symbols are mathced, 20 dollars is added to player's cash 
            cash += BONUS;  
        }
    }
    //end of loop

printf("\n\nYour One Dollar Scratch Off won you $%.2lf\n\n", cash);

    return (int)cash;
}
//end of oneDollar cash function

//TwoDollar Scratch off cash function
int cashTwoDollar(TwoDollar twoSo) {
    const int WINS = 2;     //number of winning numbers
    const int SYMS = 2;     //number of bonus symbols
    const int NUMS = 5;     //number of player's number and symbols
    float cash = 0;         //player's cash
    int w;                  //looping varibale
    int n;                  //looping variable
    char bonus = getBonus(TWO);     //bonus variable

    printf("\nBonus symbol is %c\n", bonus);
    //player's numbers compared to two winning numbers
    for(w = 0; w < WINS; ++w) {
        for(n = 0; n < 10; ++n) {
         if(twoSo.numbers[n] == twoSo.winNumbers[w]) {  //if winnning number is matched, specified prize is add to player's cash
               cash += twoSo.prizes[n];
            }
        }
        //end of nested loop
    }
    //end of loop

    //player's symbols compared to bonus symbols
    for(n = 0;n < SYMS; ++n) {      //if bonus symbol is matched, 20 DOLLARS is added to player's cash
        if(twoSo.bonus[n] == bonus) {
            cash += BONUS;
        }
    }
    //end of loop

printf("\n\nYour Two Dollar Scratch Off won you $%.2lf\n\n", cash);

    return (int)cash;
}
//end of TwoDollar cash function

//FiveDollar cash function
int cashFiveDollar(FiveDollar fiveSo) {
    const int WINS = 4;     //number of winning numbers
    const int SYMS = 4;     //number of player's bonus symbols
    const int NUMS = 12;    //number of player's number and symbols
    float cash = 0;         //player's cash
    int w;                  //looping variable
    int n;                  //loooping variable
    char bonus = getBonus(FIVE);    //bonus variable

    printf("\nBonus symbol is %c\n", bonus);
    //player's numbers are compared to the 4 winning numbers
    for(w = 0; w < WINS; ++w) {
        for(n = 0; n < NUMS; ++n) {
            if(fiveSo.numbers[n] == fiveSo.winNumbers[w]) {     //if winning numbers are matched, specified prize is added to player's cash
                cash += fiveSo.prizes[n];
            }
        }
        //end of nested loop
    }
    //end of loop

//player's symbols are compared to bonus symbol
    for(n = 0;n < SYMS; ++n) {
        if(fiveSo.bonus[n] == bonus) {  //if bonus symbol is matched, 20 dollar is added to player's cash
            cash += BONUS;
        }
    }
//end of loop

printf("\n\nYour Five Dollar Scratch Off won you $%.2lf\n\n", cash);

    return (int)cash;
}
//end of FiveDollar scratchoff cash function

//bonus 
char getBonus(int type) {
    const int ONE_TWO = 6;
    const int FIVE_RAND = 8;
    char SYMBOLS[] = {'$','%', '&', '#', '@', '!', '^','*'};
    char bonus;
    int sym;

    //if slected game is ONE or TWO dollar scratchoff
    if((type == ONE) || (type == TWO))  {
        sym = rand() % 6;       //random number is generated based from 6 symbols
        switch(sym) {
            case 0:
                bonus = SYMBOLS[0];
                break;
            case 1:
                bonus = SYMBOLS[1];
                break;
            case 2:
                bonus = SYMBOLS[2];
                break;
            case 3:
                bonus = SYMBOLS[3];
                break;
            case 4:
                bonus = SYMBOLS[4];
                break;
            case 5:
                bonus = SYMBOLS[5];
                break;
        }
    }

    else if(type == FIVE) {     //if selected game type is FIVE dollar scratchoff
        sym = rand() % 8;       //random is gnerated based from 8 symbols
        switch(sym) {
            case 0:
                bonus = SYMBOLS[0];
                break;
            case 1:
                bonus = SYMBOLS[1];
                break;
            case 2:
                bonus = SYMBOLS[2];
                break;
            case 3:
                bonus = SYMBOLS[3];
                break;
            case 4:
                bonus = SYMBOLS[4];
                break;
            case 5:
                bonus = SYMBOLS[5];
                break;
            case 6:
                bonus = SYMBOLS[6];
                break;
            case 7:
                bonus = SYMBOLS[7];
                break;
        }
    }
    
    return bonus;
}
//end of bonus symbol function

// black jack game / function
int playBlackJacks(int cash)
{
    const int BET = 10;     //given bet amount

    const int MIN_HIT = 16; //minimal hit for dealer
    const int HIT = 1;      //hit move
    const int STAND = 0;    //stand option

    int play = 1;           //loop control  
    int choice = 0;         //player's choice
    int bust = 0;           //flag for player's bust

    int player = 0;         //player's score
    int dealer = 0;         //dealer's score
    
    char deck[SUITS][FACES]; // two-dimensional array with 4 rows and 13 columns to represent deck of cards
    char dealt[SUITS][FACES];// two-dimensional array with 4 rows and 13 columns to represent used deck of cards

    printf("Let's play Black Jack!\n\n");
    printf("Your cash balance is $%d\n", cash);
    printf("The bet is $%d\n", BET);
    printf("Dealer must HIT if their score is %d or less\n", MIN_HIT);
    printf("Dealer must STAND if score is 17 or higher\n");
    printf("If the player wins the hand, they receive $20\n");
    printf("If the dealer wins the hand, the $%d bet is lost\n", BET);
    printf("If it is a PUSH, the player keeps their $%d bet\n\n", BET);

    clearScreen();

    //player's cash amount has to be greater than bet
    if(cash < BET) {
        printf("Player does not have enough money to play!\n\n");
        return cash;
    }

    // call of function initializeUsed
    initializeUsed(dealt);

    //cards are shuffled
    printf("\nShuffling the cards... \n");
    initializeDeck(deck);
    //call of initializeDeck

    printf("Here's the deck...\n");
    printDeck(deck);
    //call of print deck to output the given decks

    clearScreen();

    printf("Dealing...\n\n");

    //players cash has to be greater than bet inorder to play
    while(play == 1) {
        printf("Player's cash $%d\n\n", cash);
        if(cash < BET) {
            printf("Player does not have enough money to play!\n\n");
            play = 0; 
            continue;       //if less than BET, than the current looop iteration will be skipped
        }
    //end of while loop
        cash -= BET;    
        
        player = 0; 
        dealer = 0; 
        bust = 0; 
        // scores are set to 0 for each hand of the game

        player += deal(deck, dealt);   //player's score is equal to the score plus the current score plus the return value from function    
        player += deal(deck, dealt);           


        printf("Player's score %d\n\n", player);    //player's score is displayed

        dealer += deal(deck, dealt);    //dealer's score is equal to the score plus the current score plus the return value from function
        dealer += deal(deck, dealt);

        printf("Player, another card? (%d = STAND, %d = HIT)\n\n", STAND, HIT); // enter 0 to stand or 1 to hit
        scanf("%d", &choice);

        //player chose bust and score is less than 21(BUST)
        while(choice == HIT && player < BUST) {
            player += deal(deck, dealt);

            printf("Player's score %d\n\n", player);
            
            //player score is greater than 21(BUST)
            if(player > BUST) {
                bust = 1;       //bust flag is true
                printf("Player BUSTED! Dealer wins the the hand!\n\n");
                break;

            }
            else {
                printf("Player, another card? (%d = STAND, %d = HIT)\n\n", STAND, HIT); // 0 to stand or 1 to hit
                scanf("%d", &choice);
            }
        }
        //while loop end

        //if bust is true
        if(bust) {
            printf("Player, play another hand? (0 = NO, 1 = YES)\n\n");
            scanf("%d", &play);

            clearScreen();
            continue;       ////dealer's score is equal to the score plus the current score plus the return value from function is skipped
        }
        else {
            if(dealer <= MIN_HIT) {     //dealer's score is less than ot equal to 16
                choice = HIT;
            }
            else{
                choice = STAND;
            }
            while(choice == HIT) {              
                dealer += deal(deck, dealt);    
                if(player <= MIN_HIT) {         //player's score is less than or equal to 16
                    choice = HIT;
                }
                else {
                    choice = STAND;
                }
            }
            // end of while loop
        }
        printf("Dealer's score %d\n" ,dealer);
        cash += results(player, dealer);                                //cash is equal to the return from function results
        printf("Player, play another hand? (0 = NO, 1 = YES)\n\n");     //prompt player to play anther hand
        scanf("%d", &play);
        clearScreen();
    }
    //end of while loop

    printf("Thank you for playing Black Jack at Lin Casino! Your cash out is $%d\n\n", cash);
    // end of game and cash is returned

    return cash;
}  
// end of blackjack function

//results function
int results(int player, int dealer) {
    const int WIN = 20;
    const int PUSH = 10;
    const int LOST = 0;

    if(dealer > BUST) {
        printf("Dealer BUSTED!\n\n");         //if dealer score is greater than player's score, than dealer busted and player recieves $10
        return PUSH;
    }
    else if(player == dealer ) {
        printf("It was a PUSH!\n\n");       //if player's is equal to dealer's score, than it is a push and player recieves $10
        return PUSH;
    }
    else if(player > dealer ) {
        printf("Player WINS!\n\n");         // if player score is greater than dealer's score, player wins and receives $20
        return WIN;
    }
    else {
        printf("Dealer WINS!\n\n");         //otherwise dealer wins and player recieves $0 
        return LOST;
    }
}
//end of results function

//deal function
int deal(char deck[SUITS][FACES], char dealt[SUITS][FACES]) {
    const int MAX_CARDS = 52;   //max number of cards in deck
    int used = 0;               //flag for is card is used
    int score = 0;              //score of the random card selected
    int suit;                   //variable is used to store the random suit
    int face;                   //variable is used to store the random face

    if(cards == MAX_CARDS) {   //if to determine if all cards have been dealt
        cards = 0;              //if true cards are set to 0
        initializeUsed(dealt);
    }

    while(used == 0) {
        suit = (int)rand() % SUITS; //random value from number of suits
        face = (int)rand() % FACES; //random value from number of faces

        if(dealt[suit][face] == 0) {
            used = 1;
            dealt[suit][face] = 1;
            ++cards;
        }
        //end of while loop
    }
    //switch statement used to evaluate the face of the card
    switch (face) {
        
        case 0: 
        case 1:
        case 2:
        case 3:             //score from 0-7 should be set to face plus 2
        case 4:
        case 5:
        case 6:
        case 7:
            score = face + 2;
            break;
        case 8:
        case 9:         
        case 10:            //score from 8-11 should be set 10
        case 11:
            score = 10;
            break;
        case 12:            //score of 12 should be set to 11
            score = 11;
            break;
    }
    
    return score;
}
//end of deal function

//initializeUsed function
void initializeUsed(char used[SUITS][FACES]) {
    int s;  //integer looping varibale for rows
    int f;  //integer looping varaible for columns

    for(s = 0; s < SUITS; ++s) {
        for(f = 0; f < FACES; ++f) {       //nested loop dealer's score is equal to the score plus the current score plus the return value from function
            used[s][f] = 0;
        }
    }
}
//end of initializeUsed

//initializeDeck function
void initializeDeck(char deck[SUITS][FACES]) {
    const char FACE_VALUE[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int s;      //loop variable
    int f;      //loop variable

    for(s = 0; s < SUITS; ++s) {        //outer loop loops through 4 suits
        for(f = 0; f < FACES; ++f) {     //innner loop loops through 13 faces           
            deck[s][f] = FACE_VALUE[f];
        }
    }
    //end of loop
}
//end of initializeDeck function

// Print the given deck function
void printDeck(char deck[SUITS][FACES]) {
    int s;  //loop variable
    int f;  //loop varaible

    for(s = 0; s < SUITS; ++s) {    //outer loop loops through 4 suits
        for(f = 0; f < FACES; ++f) {    //inner loop loops through 13 faces
            switch(s) {
                case CLUBS: 
                    printf("%c of Clubs\n", deck[s][f]);
                    break;
                case DIAMONDS:
                    printf("%c of Diamonds\n", deck[s][f]);
                    break;
                case HEARTS:
                    printf("%c of Hearts\n", deck[s][f]);
                    break;
                case SPADES:
                    printf("%c of Spades\n", deck[s][f]);
                    break;
            }
        }
    }
    //end of loop

}

//Roulette function
int playRoulette(int cash){

    //Instructions
    printf("Let's play Roulette\n\n");

    printf("Select one of the 3 types of bets\n\n");
    printf("[1] Straight-up Bet: Choose a single number(Pays 35 to 1)\n\n");
    printf("[2] Red/Black Bet: Choose a color (Pays Even Money)\n\n Red numbers: 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n Black numbers: 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n"); 
    printf("[3] Odd/Even Bet: Choose odd or even (Pays Even Money)\n\n");


    //Select game mode

    int select;
    do 
    {
        printf("\nEnter 1, 2, or 3\n");
        scanf("%d", &select);

        if(select < 1 || select >35){
            printf("\n");
            printf("Ivalid Choice\n");
            printf("Please Choose Again\n");
            printf("\n");
        }
    } while (select < 1 || select > 3);          //EXIT is included for selection
    
    int bettingAmount;


    switch(select){
        case 1:
            printf("\n[You have chosen to bet with Straightup]\n\n");
            break;
        
        case 2:
            printf("\n[You have chosen to bet with Red/Black]\n\n");
            break;
        
        case 3:
            printf("\n[You have chosen to bet with Odd/Even]\n\n");
            break;

    }
    

    int conti;
    //Loop to keep game going as long as you have cash
    while (cash>0 && conti != 0)
    {   
        char enter;
        //Stright single  bets
        if (select==1)       
        {
            int betNum;
            printf("\nEnter a number between 1-36\n");
            scanf("%d", &betNum);

            printf("\nBet Amount to Spin Roulette\n");
            scanf("%d", &bettingAmount);
            printf("\nYou have bet $%d on the number %d\n\n", bettingAmount, betNum);

    
            int num = spin_Roulette();

            if (num == betNum){
                cash += (bettingAmount*35);
                printf("WE HAVE A  WINNER!!!\n\n");
                printf("You've won $%d\n",bettingAmount*35);
                printf("You currently have $%d\n", cash);
            }
            else{
                cash -= bettingAmount;
                printf("You've LOST $%d\n", bettingAmount);
                printf("You currently have $%d\n", cash); 
            }   

            printf("\n");
            
        }
        
        //Red or Black bets
        else if (select == 2)
        {
            char colorBet;

            printf("\nPick a color. Enter R for RED or B for BLACK\n");
            scanf(" %c", &colorBet);


            printf("\nBet Amount to Spin Roulette \n\n");
            scanf("%d", &bettingAmount);
            

            printf("\nYou have bet $%d on the color %c\n\n", bettingAmount, colorBet);
      
            

            int color = spin_Roulette();
            if (colorBet == 'R')
            {
                if (color == red[17])
                {
                    cash += bettingAmount;
                    printf("WE HAVE A  WINNER!!!\n\n");
                    printf("You've won $%d\n",bettingAmount);
                    printf("You currently have $%d\n", cash); 
                }
                else
                {
                    cash -= bettingAmount;
                    printf("You've LOST $%d\n", bettingAmount);
                    printf("You currently have $%d\n", cash); 
                }     
            }              
            else if(colorBet == 'B')
            {
                if (color == black[17]){
                    cash += bettingAmount;
                    printf("WE HAVE A  WINNER!!!\n\n");
                    printf("You've won $%d\n",bettingAmount);
                    printf("You currently have $%d\n", cash);
                }
                
                
                else{
                    cash -= bettingAmount;
                    printf("You've LOST $%d\n", bettingAmount);
                    printf("You currently have $%d\n", cash); 
                }

            }
        }

        //odd or Even Bets        
        else           
        {  
            int betParity;

            printf("Enter 1 for odd or 2 for even\n");
            scanf("%d", &betParity);
            printf("\nBet Amount to Spin the Roulette\n");
            scanf("%d", &bettingAmount);
            if(betParity == 1){
                 printf("\nYou've bet $%d on odds\n\n", bettingAmount);
            }

            if(betParity == 2){
                printf("\nYou've bet $%d on evens\n\n", bettingAmount);
            }
            
         
      
           

            int number = spin_Roulette();
            if (betParity==1)
            {
                if (number%2==1)
                {
                    cash += bettingAmount;
                    printf("WE HAVE A  WINNER!!!\n\n");
                    printf("You've won $%d\n",bettingAmount);
                    printf("You currently have $%d\n", cash);
                }
                
                else{
                    cash -= bettingAmount;
                    printf("You've LOST $%d\n", bettingAmount);
                    printf("You currently have $%d\n", cash);
                }
                
            }
            else
            {
                if (number%2==0){
                    cash += bettingAmount;
                    printf("WE HAVE A  WINNER!!!\n\n");
                    printf("You've won $%d\n",bettingAmount);
                    printf("You currently have $%d\n", cash);
                }
              
                else
                {
                    cash -= bettingAmount;
                    printf("You've LOST $%d\n", bettingAmount);
                    printf("You currently have $%d\n", cash);
                }
            }
        }

                        
      
        printf("\nDo you wish to Continue? (1 = Yes, 0 = No)\n");
        scanf("%d",&conti);
        printf("\n");
        
    
    }

    return cash;
}


int spin_Roulette(void){

    int num;
    srand(time(0));

    //get a random num from 1-35
    num = 1+(rand()%36);

    printf("        ---            \n");
    printf("       | %d |           \n", num);
    printf("        ---          \n\n");


    return num;
}


int playCoinFlip(int cash){


    printf("\n\n(Minimum amount to Play is $1000)\n\n");

    if(cash < 5000){
        printf("[Your balance of $%d is insufficient]\n", cash);
        printf("THIS AIN'T NO KIDS GAME!!!\n\n");

        return cash;
    }

    printf("WELCOME TO COINFLIP\n\n");

    printf("A simple game were you can win big or lose it all!!!\n\n");


    printf("Bet on HEADS or TAILS before COIN Flip\n");
    printf("Guess right, you win double your betted amount!!!\n");
    printf("Guess wrong, you lose it all!!!\n\n");

    int bettingAmount;
    do{

        printf("Enter amount to bet(Minimum is $1000)\n");
        scanf("%d", &bettingAmount);

        if(bettingAmount < 1000){
            printf("Invalid Amount, Enter New Amount\n\n");
        }

    }while(bettingAmount < 1000);
    

    int choice;

    do{

        printf("[Select 1 for HEADS and 2 for TAILS!]\n");
        scanf("%d", &choice);

        if(choice != 1 && choice != 2){
            printf("Incorrect input, Choose Again\n\n");
        }

    }while(choice != 1 && choice != 2);
    
    //random num between 1-2
    int side = (rand() % 2) + 1 ;

    
    if(side == 1){
        printf("           - - - - -        \n");
        printf("          |         |       \n");
        printf("          |    H    |       \n");
        printf("          |         |       \n");
        printf("           - - - - -        \n");

        printf("\n The Coin landed on Heads!!!\n\n");

        if(choice == side){
            cash += (2*bettingAmount);
            printf("You've WON DOUBLE your bet\n\n");
        }
        else{
            cash -= bettingAmount;
            printf("You've LOST your bet\n\n");
        }

    }
    else{
        printf("           - - - - -        \n");
        printf("          |         |       \n");
        printf("          |    T    |       \n");
        printf("          |         |       \n");
        printf("           - - - - -        \n");

        printf("\n The Coin landed on Tails!!!\n\n");

        if(choice == side){
            cash *= (2*bettingAmount);
            printf("You've WON DOUBLE your bet\n\n");
        }
        else{
            cash -= bettingAmount;
            printf("You've LOST your bet\n\n");
        }
    }

    return cash;
}
