#include <stdio.h>
#include <stdlib.h> 

int main() {
    int number;

    // Ask the user for an integer
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Using if/else to classify the sign
    if (number > 0) {
        printf("%d is positive.\n", number);
    } else if (number < 0) {
        printf("%d is negative.\n", number);
    } else {
        printf("%d is zero.\n", number);
    }

    // Compute the absolute value and print the output
    int magnitude = abs(number);
    printf("Absolute value: %d\n", magnitude);

    return 0;
}