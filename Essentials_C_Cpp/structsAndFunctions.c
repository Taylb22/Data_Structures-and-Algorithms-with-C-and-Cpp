#include <stdio.h>
#include <stdlib.h>

struct rectangle {
    int length;
    int breadth;
};

struct rectangle* allocate () {
    struct rectangle* rec = (struct rectangle*) malloc(sizeof(struct rectangle));   
    return rec;
}

void initialize (struct rectangle* rec, int length, int breadth) {
    rec->breadth = breadth;
    rec->length = length;
}

struct rectangle* constructor (int length, int breadth) {
    struct rectangle* rec = allocate();
    initialize(rec, length, breadth);
    return rec;
}

int area(struct rectangle* rec) {
    return rec->breadth * rec->length;
}


//Implementing structs and functios, gives you an insight of the
//concept of Object Oriented Programming
int main () {
    struct rectangle* rec = constructor(10, 5);
    printf("Area of the rectangle -> %d\n", area(rec));
    free(rec);
    return 0;
}
