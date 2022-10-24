#ifndef CASINO_H_INCLUDED
#define CASINO_H_INCLUDED

#define SLOTS 1
#define SCRATCH 2
#define BLACKJACK 3
#define ROULETTE 4
#define COINFLIP 5

//BlackJacks global constants
#define FACES 13
#define SUITS 4
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3
#define BUST 21

//Scratchoff constants
#define ONE 1
#define TWO 2
#define FIVE 5
#define EXIT 6
#define BONUS 20

int cards; //varibale used to keep track of how many cards in the Black Jack game have been dealt

//for red or black roulette
int red[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
int black[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

//onedollar struct for srcratch off
typedef struct oneDollar_struct {
    int winNumber;
    int numbers[5];
    float prizes[5];
    char bonus[2];
} OneDollar;

//twodollar struct for scratch off
typedef struct twoDollar_struct {
    int winNumbers[2];
    int numbers[10];
    float prizes[10];
    char bonus[2];
} TwoDollar;

//five dollar struct for scratch off
typedef struct fiveDollar_struct {
    int winNumbers[4];
    int numbers[12];
    float prizes[12];
    char bonus[4];
} FiveDollar;

//Below is FUNCTION DECLARATION or PROTOTYPE OF FUNCTION for slots
void welcomeScreen();
void clearScreen();
int displayMenu();
int playSlots(int); 
int playScratchOffs(int);
int playBlackJacks(int);
int playRoulette(int);
int playCoinFlip(int);
char randomSymbol(); //Random Symbol Generator

//blackjack prototype
void initializeUsed(char used[SUITS][FACES]);
void printDeck(char deck[SUITS][FACES]);
void initializeDeck(char deck[SUITS][FACES]);
int deal(char deck[SUITS][FACES], char dealt[SUITS][FACES]);
int results(int player, int dealer);

//scratchoff prototype
OneDollar createScratchOffOne(OneDollar oneSo);
void displayScratchOffOne(OneDollar oneSo);
TwoDollar createScratchOffTwo(TwoDollar twoSo);
void displayScratchOffTwo(TwoDollar twoSo);
FiveDollar createScratchOffFive(FiveDollar fiveSo);
void displayScratchOffFive(FiveDollar fiveSo);
int cashOneDollar(OneDollar oneSo);
int cashTwoDollar(TwoDollar twoSo);
int cashFiveDollar(FiveDollar fiveSo);
char getBonus(int type);

//roulette prototype
int spin_Roulette();

#endif
