#include <stdio.h>

//First attempt
//No memoization
//time roughly O(2^n) but O(fib^n) is a better definition
//space O(n)
int fibonacci(int n){
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
    int n = 10;

    printf("n: %d\n", n);
    printf("\nFirst attempt\nresult-> %d\n", fibonacci(n));
    return 0;
}