#include <iostream>

void swap_byValue(int a, int b) {
    //This function won't work in this case, since the swap
    //by Value does not alter the original variables
    int temp = a;
    a = b;
    b = temp;
}

void swap_byAddress(int* a, int* b) {
    //The swap by address, allocates memory for the pointers
    //so, the pointers alter the original variables
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_byReference(int& a, int& b) {
    //The swao by reference is a Cpp feature, where the compiler
    //copies the function code into the main function, where you
    //can use the original variables without allocating memory for it.
    //However, it's not suitable for long/complex functions, since
    //copying these functions to the main function can be inneficient.
    int temp = a;
    a = b;
    b = temp;
}

int main () {
    int a = 10;
    int b = 5;

    printf("Original Values -> %d | %d\n", a, b);
    swap_byValue(a, b);
    printf("\nAfter byValue -> %d | %d\n", a, b);
    swap_byAddress(&a, &b);
    printf("\nAfter byAddress -> %d | %d\n", a, b);
    swap_byReference(a, b); //Use the byReference only for small/simple functions
    printf("\nAfter byReference -> %d | %d\n", a , b);
    return 0;
}