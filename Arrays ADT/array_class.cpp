#include <iostream>

template <typename T>
class Array {
    private:
        T* arr = NULL;
        int size = 0;
        int length = 0;
    public:
        Array(int size){
            this->size = size;
            this->arr = new T[size];
        }

        void display() {
            if (this->length <= 0) {
                std::cout << "[]";
                return;
            }

            std::cout << "[";
            for (int i = 0; i<this->length-1; i++) {
                std::cout << this->arr[i] << ", ";
            }
            std::cout << this->arr[this->length-1] << "]";
        }

        void append(T val) {
            if (this->length == this->size) {
                std::cout << "Array is full...";
                return;
            }

            this->arr[this->length] = val;
            this->length++;
        }

        ~Array() {
            delete[] this->arr;
        }
};

int main () {
    Array<int> arr(2);
    arr.display();
    arr.append(10);
    arr.append(20);
    arr.append(5);
    arr.display();

    return 0;
}