#include <stdio.h>

//Simple array struct
typedef struct {
    int A[20];
    int size;
    int length;
} Array;

void display(Array* X) {
    if (X->length <=0) {
        printf("[]");
        return;
    }

    printf("[");
    for (int i = 0; i<X->length-1; i++) {
        printf("%d, ", X->A[i]);
    }
    printf("%d]", X->A[X->length-1]);
}

void append(Array* X, int val) {
    if (X->size == X->length) {
        return;
    }

    X->A[X->length] = val;
    X->length++;
}

int main () {
    Array A = {{}, 20, 0};
    display(&A);
    append(&A, 5);
    append(&A, 10);
    display(&A);

    return 0;
}