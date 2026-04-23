#include <stdio.h>

void fun(int n) { //Order(2^n)
    if (n < 0) {
        return;
    }

    printf("%d ", n);
    fun(n - 1);
    fun(n - 1);
}

int main () {
    int n = 3;
    printf("Recursion of N -> ");
    fun(n);
    return 0;
}