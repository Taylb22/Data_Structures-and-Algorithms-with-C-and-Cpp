#include <stdio.h>
#include <stdlib.h>

struct rectangle {
    int length;
    int breadth;
};

struct complex_number {
    int real;
    int imaginary;
};

struct complex_number* sum_complex(struct complex_number* C1, struct complex_number* C2) {
    struct complex_number* cResult = malloc(sizeof(struct complex_number));

    cResult->real = C1->real + C2->real;
    cResult->imaginary = C1->imaginary + C2->imaginary;

    return cResult;
}

struct complex_number* multiply_complex(struct complex_number* C1, struct complex_number* C2) {
    struct complex_number* cResult1 = malloc(sizeof(struct complex_number));
    struct complex_number* cResult2 = malloc(sizeof(struct complex_number));

    cResult1->real = C1->real * C2->real; cResult1->imaginary = C1->real * C2->imaginary;
    cResult2->real = C1->imaginary * ((-1) * C2->imaginary); cResult2->imaginary = C1->imaginary * C2->real;

    struct complex_number* result = sum_complex(cResult1, cResult2);
    free(cResult1);
    free(cResult2);
    return result;
}

void print_complex(struct complex_number* complex) {
    if (complex->real == 0 && complex->imaginary == 0) {
        printf("0");
    }
    else if(complex->real == 0) {
        printf("%di", complex->imaginary);
    }
    else if(complex->imaginary == 0) {
        printf("%d", complex->real);
    }
    else {
        if (complex->imaginary < 0) {
            printf("(%d %di)", complex->real, complex->imaginary);
        }
        else {
            printf("(%d +%di)", complex->real, complex->imaginary);
        }
    }
}

int main() {
    struct rectangle rect = {10, 5};
    struct complex_number* complex1 = malloc(sizeof(struct complex_number));
    complex1->real = 0; complex1->imaginary = 3;
    struct complex_number* complex2 = malloc(sizeof(struct complex_number));
    complex2->real = 1; complex2->imaginary = -4;

    struct complex_number* result;
    result = multiply_complex(complex1, complex2);

    printf("\nThe area of the rectangle -> %d\n\n", rect.length * rect.breadth);

    printf("First complex -> ");
    print_complex(complex1);
    printf("\nSecond complex -> ");
    print_complex(complex2);

    printf("\nResult of the imaginary number -> ");
    print_complex(result);
    printf("\n");

    free(complex1);
    free(complex2);
    free(result);
    return 0;
}