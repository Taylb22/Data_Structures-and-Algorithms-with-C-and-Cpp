#include <stdio.h>

int fun(int n) {
    if (n > 100) {
        return n - 10;
    }

    return fun(fun(n + 11));
}

int main () {
    int n = 30;
    printf("Result of %d -> %d", n, fun(n));

    return 0;
}