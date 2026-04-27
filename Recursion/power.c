#include <stdio.h>

int mypow(int m, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return mypow(m * m, n / 2);
    }

    return m * (mypow(m * m, (n - 1) / 2));
}

int iPow(int m, int n) {
    if (n < 1) {return 1;}
    int result = 1;

    for (int i = 0; i < n; i++) {
        result *= m;
    }
    return result;
}

int main () {
    int m = 2;
    int n = 8;

    printf("%d to the power of %d is %d\n", m, n, mypow(m, n));
    printf("%d to the Ipower of %d is %d\n", m, n, iPow(m, n));

    return 0;
}