#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <random>
#include <chrono>

void print_array_c (int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d |", array[i]);
    }
    printf("\n");
}

void print_array_cpp (int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout<< array[i] << " |";
    }
    std::cout<<std::endl;
}

template <typename Func>
void performance (Func func) {
    auto begin = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed = end - begin;

    printf("Execution time -> %f\n", elapsed);
}

int* random_array(int size) {
    int* array = (int*) malloc(size * sizeof(int));

    std::mt19937 gen(time(NULL));
    std::uniform_int_distribution<int> random(0, 99);

    for (int i = 0; i < size; i++) {
        array[i] = random(gen);
    }

    return array;
}

int main() {
    int size = 10;
    int* array = random_array(size);

    performance([&](){print_array_c(array, size);});
    std::cout<<std::endl;
    performance([&](){print_array_cpp(array, size);});

    free(array);
    return 0;
}