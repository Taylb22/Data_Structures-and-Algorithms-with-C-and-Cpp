#include <stdlib.h>

#include <iostream>
#include <random>

int* gen_random_int_array(int size, int min, int max) {
    int* array = (int*) malloc(size * sizeof(int));

    std::mt19937 gen(time(NULL));
    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < size; i++) {
        array[i] = dist(gen);
    }

    return array;
}

int sum_array(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(array + i);
    }
    return sum;
}

int main() {
    int n = 5;
    int* array = gen_random_int_array(n, 0, 10);

    int total = sum_array(array, n);
    printf("Sum of the array -> %d", total);
    free(array);

    int* dynamic_c = (int*) malloc(n * sizeof(int)); //Memory Allocation in C
    int* dynamic_cpp = new int[n]; //Memory Allocation in Cpp

    free(dynamic_c); //Memory Deallocation in C
    delete[] dynamic_cpp; //Memory Dealocation in Cpp
    return 0;
}