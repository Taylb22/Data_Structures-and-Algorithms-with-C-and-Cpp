#include <stdio.h>

//First Attempt
//time O(2^n)
//space O(n)
int rComb (int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    return rComb(n-1, k-1) + rComb(n-1, k);
}

int fac(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
//Factorial version
//time O(n)
//space O(1)
//can cause imprecision for large numbers
//overflow
int fComb(int n, int k) {
    return fac(n) / (fac(k) * (fac(n - k)));
}

//recursive optimized
//time O(k)
//space O(k)
//helps solve the overflow problem
double rComb2(int n, int k) {
    if (k == 0) {
        return 1;
    }

    return (n / (double) k) * rComb2(n-1, k-1);
}

int main() {
    int n = 20;
    int k = 3;

    printf("n: %d\nk: %d\n", n, k);
    printf("\nFirst attempt\nresult-> %d\n", rComb(n, k));
    printf("Factorial\nresult-> %d\n", fComb(n, k)); //overflow due to factorial of int
    printf("Recursive of K\nresult-> %d\n", (int) rComb2(n, k));
    return 0;
}