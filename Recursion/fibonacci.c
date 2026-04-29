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

//Iterative way
//time O(n)
//space O(1)
int ifibonacci(int n) {
    if (n <= 0) {
        return 0;
    }

    int prev2 = 0;
    int prev1 = 1;
    for (int i = 1; i < n; i++) {
        int temp = prev1;
        prev1 = prev1 + prev2;
        prev2 = temp;
    }

    return prev1;
}

int main() {
    int n = 10;

    printf("n: %d\n", n);
    printf("\nFirst attempt\nresult-> %d\n", fibonacci(n));
    printf("Iterative way\nresult-> %d\n", ifibonacci(n));
    return 0;
}