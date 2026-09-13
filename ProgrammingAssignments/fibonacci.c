#include <stdio.h>

int main() {
    int n;
    long long first = 0, second = 1, next;
    
    char me[] = "Feranmi";

    // Ask the user for input greater than or equal to 2
    printf("Enter N (2 or greater): ");
    
    // Check if input is a valid integer
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    } else if (n < 2) {
        printf("Invalid input. Please enter a non-negative integer 2 or greater.\n");
        return 1;
    } 
    else {
        printf("Fibonacci sequence up to %d terms:\n", n);
        printf("%lld %lld ", first, second);

        // Loop starts from 2 
        for (int i = 2; i <= n; i++) {
            next = first + second;
            printf("%lld ", next);
            
            // Update variables for the next iteration
            first = second;
            second = next;
        }
        printf("\n");
    }

    // Name
    printf("Programmed by %s\n", me);
    return 0;
}