#include <stdio.h>
#include <stdint.h>

int main() {
    long long temp_input;
    uint32_t n;
    int count = 0;
    char me[] = "Feranmi";
    printf("Programmed by %s\n", me);
    
    // Prompt the user to enter an unsigned 32-bit integer
    printf("Enter a non-negative integer: ");
    
    // Check if the input is a valid number and if it is non-negative
    if (scanf("%lld", &temp_input) != 1 || temp_input < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1; // Exit with error
    }

    // Casting the validated input to an unsigned 32-bit integer
    n = (uint32_t)temp_input;
    uint32_t original_n = n;

    // Using n = n & (n - 1) to count the set bits with a loop
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }

    // Displaying the result 
    printf("Number of bits set in %u: %d\n", original_n, count);
    
    return 0;
}