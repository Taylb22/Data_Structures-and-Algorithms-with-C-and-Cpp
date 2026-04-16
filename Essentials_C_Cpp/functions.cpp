#include <iostream>

struct rectangle {
    int length;
    int breadth;
};

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
    //The swap by reference is a Cpp feature, where the compiler
    //copies the function code into the main function, where you
    //can use the original variables without allocating memory for it.
    //However, it's not suitable for long/complex functions, since
    //copying these functions to the main function can be inneficient.
    int temp = a;
    a = b;
    b = temp;
}

int sum_array(int arr[], int size) {
    //To pass an array as an parameter, you can use two syntax.
    //First one is the '[]'
    //Second one is as a pointer '*'
    
    //The '[]' decays to pointer... This is because the variable
    //"arr" is basically a pointer to the first element of the array

    //Use '[]' to specify that the parameter is an array, and use
    //the pointer '*' only as a generic parameter
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }

    return res;
}

//Struct as a function parameter
int main () {
    int a = 10;
    int b = 5;

    printf("Original Values -> %d | %d\n", a, b);
    swap_byValue(a, b);
    printf("After byValue -> %d | %d\n", a, b);
    swap_byAddress(&a, &b);
    printf("After byAddress -> %d | %d\n", a, b);
    swap_byReference(a, b); //Use the byReference only for small/simple functions
    printf("After byReference -> %d | %d\n", a , b);

    return 0;
}