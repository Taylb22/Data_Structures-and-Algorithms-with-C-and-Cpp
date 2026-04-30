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


int main() {
    int n = 10;
    int k = 2;

    printf("n: %d\nk: %d\n", n, k);
    printf("\nFirst attempt\nresult-> %d", rComb(n, k));
    return 0;
}