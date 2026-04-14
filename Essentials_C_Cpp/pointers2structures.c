#include <stdio.h>
#include <stdlib.h>

struct rectangle {
    int length;
    int breadth;
};

int rec_area (struct rectangle* rec) {
    return rec->breadth * rec->length;
}

int main() {
    struct rectangle* rec = malloc(sizeof(struct rectangle));

    //You can access structs using pointers in two different ways
    //First way
    rec->length = 10;
    rec->breadth = 10;
    printf("Area of the rectangle in the first way -> %d\n", rec_area(rec));

    //Second way
    (*rec).length = 3;
    (*rec).breadth = 5;
    printf("\nArea of the rectangle in the second way -> %d\n", rec_area(rec));

    free(rec);
    return 0;
}