#include <stdio.h>

int factorial(int n) { //Using recursion for learning purposes...
    if (n <= 1) {      //Note the best approach since it waste stack frames.
        return 1;
    }

    return n * factorial(n - 1);
}

int iFactorial(int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main () {
    int n = 10;
    printf("Factorial of %d is: %d\n", n, factorial(n)); //If you can solve the problem without recursion, do it...
    printf("iFactorial of %d is: %d\n", n, iFactorial(n)); //Iterations don't waste resource from the stack...
                                                           //Which means it is more memory efficient!
    return 0;
}