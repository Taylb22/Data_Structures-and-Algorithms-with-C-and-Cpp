#include <iostream>

template <typename T>
class Array {
    private:
        T* arr = NULL;
        int size = 0;
        int length = 0;

        void swapHead(int index);
        void quicksort(int left, int right);
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
        void sort();

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

template <typename T>
void Array<T>::quicksort(int left, int right) {
    if (left >= right) return;

    int l = left;
    int r = right;
    T pivot = this->arr[(left + right) / 2];

    while (l <= r) {
        while (this->arr[l] < pivot) {l++;}
        while (this->arr[r] > pivot) {r--;}

        if (l <= r) {
            T temp = this->arr[l];
            this->arr[l] = this->arr[r];
            this->arr[r] = temp;
            l++;
            r--;
        }

        if (left < r) {
            this->quicksort(left, r);
        }
        if (right > l) {
            this->quicksort(l, right);
        }
    }
}

template <typename T>
void Array<T>::sort() {
    this->quicksort(0, this->length - 1);
}

template <typename T>
bool Array<T>::isSorted() {
    if (this->length <= 1) return true;
    for (int i = 1; i<this->length; i++) {
        if (this->arr[i] < this->arr[i-1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
int Array<T>::binary_search(T val, bool auto_sort) {
    bool is_sorted = this->isSorted();
    if (!auto_sort && !is_sorted) {
        throw  std::runtime_error("Vector is unsorted... Unable to proceed with binary search");
    }
    if (!is_sorted) {
        this->sort();
    }

    int l = 0;
    int r = this->length-1;
    while (l <= r){
        int mid = ((l + r) / 2);
        if (this->arr[mid] == val) return mid;

        if (val < this->arr[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

int main () {
    Array<int> arr(20);
    arr.append(10);
    arr.append(20);
    arr.append(5);
    arr.insert(2, 3);
    arr.append(100);
    arr.append(100);
    arr.append(98);
    arr.append(98);
    arr.append(97);
    arr.display();
    std::cout << " " << arr.isSorted() << std::endl;
    arr.sort();
    arr.display();
    std::cout << " " << arr.isSorted() << std::endl;
    int n = 5;
    std::cout << "Position of the element "<< n << " -> " << arr.binary_search(n, true);
    
    return 0;
}