#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

//My first attempt
double Taylor_Series(int n, int x) {
    if (n <= 0) {
        return 1;
    }

    return (pow(x, n) / factorial(n)) + Taylor_Series(n - 1, x); 
}

//Second attempt
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

//Applying Horner's method
double e_horner(int n, int x) {
    static double s;
    if (n == 0) {
        return s;
    }
    s = 1+x*s/n;
    return e_horner(n-1, x);
}

//Doing the Iterative way
double ie(int n, int x) {
    double s = 1;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main () {
    int n = 10;
    int x = 2;

    printf("n: %d\nx: %d\n\nFirst attempt\nresult -> %lf\n", n, x, Taylor_Series(n, x));
    printf("\n");
    printf("Second attempt\nresult -> %lf\n", e(n, x));
    printf("\n");
    printf("Horner's method\nresult -> %lf\n", e_horner(n, x));
    printf("\n");
    printf("Iterative method\nresult -> %lf\n", ie(n, x));

    return 0;
}