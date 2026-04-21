#include <stdio.h>

int recursive_sum(int n) {
    //Defining the Break Point
    if (n <= 0) {
        return 0;
    };

    //The recursion itself
    return n + recursive_sum(n - 1);
}

int main () {
    int n = 3;
    
    //Ascending Phase (Calling)
    int sum = recursive_sum(n);
    //Descending Phase (returning)

    printf("The sum of recursive %d is %d\n", n, sum);
    return 0;
}