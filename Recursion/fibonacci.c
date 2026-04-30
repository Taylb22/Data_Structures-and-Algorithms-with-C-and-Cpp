#include <stdio.h>
#include <stdlib.h>

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

//Recursive with memoization
//time O(n)
//space O(n)
//better than the first attempt, but worst than the iterative way
int fib(int n, int* memo) {
    if (n <= 1) {
        memo[n] = n;
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fib(n-2, memo) + fib(n-1, memo);
    return memo[n];
}
int fibonacci_memo(int n) {
    int* memo = (int*) malloc((n+1) * sizeof(int));
    for (int i = 0; i <= n; i++) {memo[i] = -1;}
    int ans = fib(n, memo);
    free(memo);
    return ans;
}

int main() {
    int n = 10;

    printf("n: %d\n", n);
    printf("\nFirst attempt\nresult-> %d\n", fibonacci(n));
    printf("Iterative way\nresult-> %d\n", ifibonacci(n));
    printf("Recursive with memoization\nresult-> %d\n", fibonacci_memo(n));
    return 0;
}