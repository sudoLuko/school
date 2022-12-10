// Luke Olson CSE215 10/23/22 PA1-1
// Program takes input as integer and prints facts about the number
// 
// Results = factors of int, if int is prime, sum of factors, if number is happy/sad/perfecr
// All of results will be displayed by a print statement

#include <stdio.h>

int main() {
    
    char buffer[10];   // buffer for fgets
    int num;           // user input variable
    int i = 0;         // index variable
    int loopVar = 1;   // for-loop variable, used to check if current digit is factor 
    int sum;           // keeps running total of factors of num
    int factorNum = 0; // keeps track of how many factors are added to factors[64]

    printf("Enter a number: ");

    fgets(buffer, 10, stdin);
    sscanf(buffer, "%d", &num);  // from the printf statment to here, we are saving user input as int

    printf("Analyzing the number %d..\n", num);
    
    printf("Factors of %d: ", num);

// this loops through numbers leading up to num and checks if it is a factor of num
    for (loopVar = 1; loopVar < num; loopVar++) { 
        if ((num % loopVar == 0)) {  
            sum = sum + loopVar;     // tallys sum of factors
            ++factorNum;             // counts how many factors there are
            printf("%d ", loopVar);  // printf factors of num
        }

    }
    printf("\n");      // newline for factors of num

// check if number is composite or prime
    if (factorNum > 2) {
        printf("%d is composite\n", num);
    } else {
        printf("%d is prime\n", num);
    }

// printf for sum of factors
    printf("Sum of factors of %d is %d\n", num, sum);

// printf for mood of num
    if (sum > num) {
        printf("%d is happy\n", num);
    }
    if (sum < num) {
        printf("%d is sad\n", num);
    }
    if (sum == num) {
        printf("%d is perfect\n", num);
    }


    return 0;

}