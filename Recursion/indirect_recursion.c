#include <stdio.h>

void funA(int n);
void funB(int n);

void funA(int n) {
    if (n <= 0) {
        return;
    }

    printf("%d ", n);
    funB(n - 1); //indirect recursion
}

void funB(int n) {
    if (n <= 0) {
        return;
    }

    printf("%d ", n);
    funA(n / 2); //indirect recursion
}

int main () {
    int n = 10;

    printf("Indirect recursion of %d -> ", n);
    funA(n);
    printf("\n");
    return 0;
}