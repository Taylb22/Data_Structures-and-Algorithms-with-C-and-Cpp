#include <iostream>

template <typename T>
class Array {
    private:
        T* arr = NULL;
        int size = 0;
        int length = 0;

        void swapHead(int index);
    public:
        Array(int size){
            this->size = size;
            this->arr = new T[size];
        }

        void display();
        void append(T val);
        void insert(int index, T val);
        void erase(int index);
        int find(T val, bool swap=false);
        int binary_search(T val, bool auto_sort=false);
        bool isSorted();

        ~Array() {
            delete[] this->arr;
        }
};

template <typename T>
void Array<T>::erase(int index) {
    if (index > this->size-1 || index < 0 || index > this->length-1) {
        throw std::runtime_error("Index out of bounds...");
    }
    
    for (int i = index; i < this->length-1; i++) {
        this->arr[i] = this->arr[i+1];
    }
    this->length--;
}

template <typename T>
void Array<T>::insert(int index, T val) {
    if (index > this->size-1 || index < 0) {
        throw std::runtime_error("Index out of bounds...");
    }
    if (this->size == this->length) {
        throw std::runtime_error("Array is full...");
    }
    
    for (int i = this->length; i > index; i--) {
        this->arr[i] = this->arr[i-1];
    }
    this->arr[index] = val;
    this->length++;
}

template <typename T>
 void Array<T>::display() {
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

template <typename T>
void Array<T>::append(T val) {
    if (this->length == this->size) {
        throw std::runtime_error("Array is full...");
    }

    this->arr[this->length] = val;
    this->length++;
}

template <typename T>
void Array<T>::swapHead(int index) {
    T temp = this->arr[0];
    this->arr[0] = this->arr[index];
    this->arr[index] = temp;
}

template <typename T>
int Array<T>::find(T val, bool swap) {
    int index = -1; //Returns -1 if not found
    for (int i = 0; i < this->length; i++) {
        if (!(this->arr[i] == val)) {
            continue;
        }

        switch (swap){
        case true:
            this->swapHead(i);
            return 0;
            break;
        
        default:
            return i;
            break;
        }
    }
    return -1;
}

template()

int main () {
    Array<int> arr(4);
    arr.append(10);
    arr.append(20);
    arr.append(5);
    arr.insert(2, 3);
    arr.display();
    arr.erase(2);
    arr.display();
    printf("%d", arr.find(20));
    arr.display();
    printf("%d", arr.find(20, true));
    arr.display();

    return 0;
}