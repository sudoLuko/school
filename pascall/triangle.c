// Luke Olson, CSE 215, 11/13/2022, PA2 

/*
    This program will calculate pascals triangle to a specified length.
    
    Design Notes:
        I decided to hardcode the first two lines ("1" and "1 1") into this program; all other values are calculated as the program runs
        I use a 2D array to save values of the triangle, so any change of rowsToCalculate above 32 must be reciprocated in arr[33][33]. ie. rowsToCalculate=33 -> arr[34][34]


*/

#include <stdio.h>

int main() {
    int i = 1;                  // arr 32 rows variable
    int j = 0;                  // arr index variable
    int r = 0;                  // variable that loops with numOfAdds, used to get correct amount of addition operations
    int rowsToCalculate = 32;   // changing this variable will change how many rows of the trianlge are calculated
    int numbersinrow = 2;   
    int numOfAdds = 1;          // number of adds per row
    int nextRow = 2;            // always one row ahead of i variable
    int nextSum = 0;            // keeps track of sums
    int altJ = 1;               // always one row item ahead of j, this avoids overwriting the leading 1 
    int arr[33][33] = {0};      // array of ints to save results

    // intialize first two rows, print them to screen
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;

    printf("%d\n", arr[0][0]);
    printf("%d %d\n", arr[1][0], arr[1][1]);

    // begin calculating additonal rows of triangle
    for (i = 1; i < rowsToCalculate; i++) {                     // main loop; loops from 1 to int in rowsToCalculate
            arr[nextRow][0] = 1;                                // Set the first element in row to 1
            arr[nextRow][numbersinrow] = 1;                     // Set last element in row to 1
            printf("%d ", arr[i][0]);                           // print leading 1 in row
            for (j = 0; j < numbersinrow; j++) {                // loops through each number in row
                if (r != numOfAdds) {                           // loops if there is addition operations needed to calculate row
                    nextSum = arr[i][j] + arr[i][j+1];          // calculates the sum of numbers in previous row
                    arr[nextRow][altJ] = nextSum;               // assigns sum to correct position in next row/array
                    nextSum = 0;                                // resets nextSum to 0 for next operation
                    printf("%d ", arr[nextRow][altJ]);          // print value of nextSum saved in array
                    altJ++;
                    r++;
                }
        }
        printf("%d\n", arr[nextRow][numbersinrow]);             // print trailing 1
    
    // incrementing/resetting neccessary variables
        numOfAdds++;        // each additional row is going to need one more addition operation
        r = 0;              // reset number of additions performed to 0
        altJ = 1;           // reset altJ to 1
        nextRow++;          // increment nextRow
        numbersinrow++;     // each additional row will have one more number than the previous
    }
}


/*  Skeleton:
    
        first row = 1 1
        1+1 = 2
        second row = 1 2 1
        1+2 = 3
        2+1 = 3
        third row = 1 3 3 1
        1+3 = 4
        3+3 = 6
        3+1 = 4
        fourth row = 1 4 6 4 1
        1+4 = 5
        4+6 = 10
        6+4 = 10
        4+1 = 5
        fifth row = 1 5 10 10 5 1

*/