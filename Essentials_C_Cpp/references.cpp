#include <iostream>
#include <random>

void change_random (int &x) {
    std::mt19937 gen(time(NULL));
    std::uniform_int_distribution<int> dist(0, 10);

    x = dist(gen);
}

//References only for Cpp
int main () {
    int a = 10;
    printf("Before -> %d\n", a);
    change_random(a);
    printf("\nAfter -> %d", a);

    return 0;
}