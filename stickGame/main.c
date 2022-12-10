#include <stdio.h>

int printSticks(int count);
int computerMove(int count);


int main(int argc, char **argv) {
    
    int sticks = 0; // Default stick count
    int stickChange = 0;

    // this if/else checks to see how many sticks you would like to play the game with
    if (argv[1]) {
        int ss = sscanf(argv[1], "%d", &stickChange);
        sticks = stickChange;
    } else {
        sticks = 21;
    }

    // Intro to program
    printf("\nWelcome to the stick picking game!\n");
    printf("Take 1 2 or 3 sticks per move.\n");
    printf("Whoever takes the last stick wins. Good luck!\n");
    printSticks(sticks);

    int i;  // variable used in printSticks function

    // game loop vars
    char in[20];         // variable to hold user input from fgets 
    int num;             // varible that sscanf saves user input to
    int turn;            // keeps track of whos turn it is 
    char stick[] = "|";  // stick character initialization 

    // Game loop
    
    while (sticks > 0) {
        turn = 0;  // 0 means it is the players turn
        printf("How many sticks do you want to take: ");

        // reads input from command line
        fgets(in, 10, stdin);
        int value = sscanf(in, "%d", &num);

        // checks input for correct number of sticks
        // if input is wrong, prompts one more time, then exits
        if (num == 1 || num == 2 || num == 3) {
            sticks = sticks - num;
        } else {
            printf("How many sticks do you want to take (1 2 or 3): ");
            fgets(in, 10, stdin);
            int value = sscanf(in, "%d", &num);

            if (num == 1 || num == 2 || num == 3) {
                sticks = sticks - num;
            } else {
                printf("Two illegal entries in a row. Game over!\n");
                return 0;
            }
        }

        printSticks(sticks); // prints remaining sticks after user's turn

        int c = computerMove(sticks); // this is the computers move
        turn = 1;  // 1 means it is the computers turn

        sticks = sticks - c;

        printf("The computer has taken %d sticks\n", c);
        printSticks(sticks);

    }

    printf("\nGame Over.\n");

    // this if/else decides who won the game
    // it makes sure sticks is equal to 0, then checks whos turn it was last
    if (sticks == 0 && turn == 0) {
        printf("Congratulations! You win\n");
    } else {
        printf("The computer wins. Try again next time!\n");
    }

    return 0;
}

// Below is my function to display the sticks graphically

int printSticks(int count) {
    int i;
    for (i = 0; i < count; ++i) {
        printf("|");
    }

    if (count != 0) {
        printf(" (%d)\n", count);
    }

    return count;
}

// Below is the algorithm for my computer player

int computerMove(int count) {
    int n;
    if ((count % 4) != 0) {
        return (count % 4);
    } else {
        return 1;
    }

}



