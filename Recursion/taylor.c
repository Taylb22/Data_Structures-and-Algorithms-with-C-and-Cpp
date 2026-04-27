#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

double Taylor_Series(int n, int x) {
    if (n <= 0) {
        return 1;
    }

    return (pow(x, n) / factorial(n)) + Taylor_Series(n - 1, x); 
}

int main () {
    int n = 5;
    int x = 5;

    printf("n: %d\nx: %d\nresult -> %f\n", n ,x, Taylor_Series(n, x));

    return 0;
}