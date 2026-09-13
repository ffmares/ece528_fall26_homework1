# ece528\_fall26\_homework1





# Section I: Review Questions



1\. (a) What is the difference between a compiler and an interpreter

(b) What is the output of a C program's main() function by default?



a) The difference between a compiler and an interpreter is that a compiler uses code from a text editor to translate the source code into machine code at once, whereas the interpreter will translate and execute the code line by line in real time.



b) The output of a C program's main() function by default will be the statements and function calls that will be executed. By default, the int value 0 would be returned upon successful completion.



2\. What are header files in C and what is the purpose of the #include directive?



Header files in C contain C declarations and macro definitions. #include is a preprocessing directive that is required in order to use header files.



3\. Explain how to declare and define a function in C. What is the purpose of the return statement in a function? Can a function have more than one return statement?



In order to define a function in C, there needs to be curly braces at the beginning and at the end of a function block.

The purpose if a return statement in a function is to immediately terminate the execution of a function and pass control back to the point where the function was called.

A function can have more than one return statement, but one return statement can execute at a time for that function.



4\. What is type casting? Provide an example C function that demonstrates explicit type casting from double to int. The function should accept two arguments that are both double and return their sum as an integer.

Type casting is the process of converting a variable or value from one data type to another.

Example:

\#include <stdio.h>



int typecast(double num1, double num2) {

&#x20;   // The sum is calculated as a double, then explicitly cast to an int.

&#x20;   return (int)(num1 + num2);

}



int main() {

&#x20;   double a = 9.65;

&#x20;   double b = 7.55;

&#x20;

&#x20;   int result = add\_and\_cast(a, b); // 9.65 + 7.55 = 17.20, Casts to 17

&#x20;

&#x20;   printf("First number:  %.2f\\n", a);

&#x20;   printf("Second number: %.2f\\n", b);

&#x20;   printf("Sum: %d\\n", result);



&#x20;   return 0;

}



5\. Explain the difference between local and global variables. Provide an example of each

The difference between logical and local variables is their scope. The scope will determine where in the program they can be assessed and for how long they would stay in memory.

Example:

\#include <stdio.h>



int global\_count = 100; // Global variable - declared outside all functions



void display\_count() {

&#x20;   printf("From display\_count(): global\_count = %d\\n", global\_count); // Can access the global count

&#x20;

&#x20;   // Can't access the local\_num because it's placed within another function

&#x20;   // printf("%d", local\_num);

}



int main() {

&#x20;   // Local variable - declared inside main()

&#x20;   int local\_num = 5;

&#x20;

&#x20;   printf("Inside main(): local\_num = %d\\n", local\_num);

&#x20;   printf("Inside main(): global\_count = %d\\n", global\_count);

&#x20;

&#x20;   global\_count = global\_count + 50; // The global variable can still be modified

&#x20;   display\_count();

&#x20;

&#x20;   return 0;

}



6\. How are strings declared and initialized in C? What is the role of the null terminator ‘\\0’?



Strings are declared and initialized by using a sequence of characters that are later enclosed in double quotes ("") e.g. "ABCDE", "Hello World!".

The role of a null terminator is to signal the end of a character string, and would need extra space in an array to allocate for it.



7\. What is a pointer in C? How do you pass a pointer to a function? What

advantages are there to passing a pointer instead of a value?

A pointer in C is a variable that stores the memory address of another variable as its value, instead of storing a direct data value like an integer or character.

The advantages of passing a pointer instead of a value is the performance and memory efficiency for larger data types, as well as handling arrays and dynamic data structures.



8\. What does the \* operator and the \& operator do in the context of pointers?

The \& gets the memory address of a variable, while the \* operator declares a pointer or dereferences it to get the value at that specific address.



9\. What is the difference between while and do…while loops?

The while look while check the condition before executing the loops body. A do ... while look checks the condition after executing the body and make sures that the code would be able to run at least once.



10\. The break statement stops a programming from running after a condition is met. The continue statement allows a program to continue to run with no other instruction after a certain condition is met.



11\. Explain the use of bitwise operators (i.e. \&, |, ^, \~, <<, >>) in C. Which bitwise

operators can be used to set, clear, toggle, or check a specific bit in an integer variable?



Bitwise operators in C are used to control individual bits of an integer.

Set: | bitwise OR

Clear: \& bitwise AND and \~ bitwise NOT

Toggle: ^ bitwise XOR

Check: \& bitwise AND



12\. What is the purpose of the PxSEL0 and PxSEL1 GPIO registers? Write two statements that select the GPIO function for the pins P1.0 and P1.7

The PxSEL0 and PxSEL1 GPIO registers are used together in order as a bit-pair in order to configure the function of the GPIO pin.

Example:

P1SEL0 \&= \~(BIT0 | BIT7); // Clear bits 0 and 7 in P1SEL0 to select GPIO function

P1SEL1 \&= \~(BIT0 | BIT7); // Clear bits 0 and 7 in P1SEL1 to select GPIO function



13\. Write a void function named P1\_1\_and\_P1\_4\_Init that configures P1.1 and P1.4

as GPIO inputs with pull-up resistors enabled



void P1\_1\_and\_P1\_4\_Init(void) {

&#x20;   P1SEL0 \&= \~(BIT1 | BIT4); // Select GPIO function (Clear bits 1 and 4 in SEL0 and SEL1)

&#x20;   P1SEL1 \&= \~(BIT1 | BIT4);



&#x20;   P1DIR \&= \~(BIT1 | BIT4);  // Set direction to Input (Clear bits 1 and 4 in DIR)



&#x20;   P1REN |= (BIT1 | BIT4);   // Enable internal resistors (Set bits 1 and 4 in REN)



&#x20;   P1OUT |= (BIT1 | BIT4);   // Select Pull-Up resistor type (Set bits 1 and 4 in OUT)

}



14\. Write a void function named Buttons\_Init that configures the following pins as

GPIO inputs with pull-down resistors enabled.

• P3.1, P3.6, P5.0, P5.4

void Buttons\_Init(void) {

&#x20;   // PORT 3

&#x20;   P3SEL0 \&= \~(BIT1 | BIT6); // Select GPIO function

&#x20;   P3SEL1 \&= \~(BIT1 | BIT6);

&#x20;   P3DIR  \&= \~(BIT1 | BIT6); // Set direction to Input

&#x20;   P3REN  |=  (BIT1 | BIT6); // Enable internal resistors

&#x20;   P3OUT  \&= \~(BIT1 | BIT6); // Select Pull-Down resistor type



&#x20;   // PORT 5

&#x20;   P5SEL0 \&= \~(BIT0 | BIT4); // Select GPIO function

&#x20;   P5SEL1 \&= \~(BIT0 | BIT4);

&#x20;   P5DIR  \&= \~(BIT0 | BIT4); // Set direction to Input

&#x20;   P5REN  |=  (BIT0 | BIT4); // Enable internal resistors

&#x20;   P5OUT  \&= \~(BIT0 | BIT4); // Select Pull-Down resistor type

}



15\. Write a void function named LEDs\_Init that configures the following pins as

GPIO outputs. Initialize the pins to zero.

• P7.0 to P7.7



void LEDs\_Init(void) {

&#x20;   P7SEL0 \&= \~0xFF;  // Select GPIO function for all pins on Port 7 (Clear all bits)

&#x20;   P7SEL1 \&= \~0xFF;



&#x20;   P7OUT \&= \~0xFF; // Initialize output values to zero (Clear all bits)

&#x20;   P7DIR |= 0xFF;  // Set direction to Output for all pins on Port 7 (Set all bits)

}

