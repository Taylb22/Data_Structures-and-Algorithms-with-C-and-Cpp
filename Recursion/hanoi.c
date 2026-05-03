#include <stdio.h>

void ToH (int n, int A, int B, int C) {
    if (n <= 0) {
        return;
    }

    ToH(n-1, A, C, B);
    printf("From %d to %d\n", A, C);
    ToH(n-1, B, A, C);
}

int main () {
    int n = 3;
    ToH(n, 1, 2, 3);
    return 0;
}