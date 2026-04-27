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

double e(int n, int x) {
    static double p = 1, f = 1;
    if (n <= 0) {
        return 1;
    }

    double r = e(n-1, x);
    p = x * p;
    f = f * n;
    return r+p / f;
}

int main () {
    int n = 5;
    int x = 5;

    printf("n: %d\nx: %d\nresult -> %f\n", n ,x, Taylor_Series(n, x));
    printf("\n");
    printf("n: %d\nx: %d\nresult -> %f\n", n ,x, e(n, x));

    return 0;
}