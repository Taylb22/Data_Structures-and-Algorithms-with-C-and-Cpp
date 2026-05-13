#include <iostream>
// #include "../ARRAY.h" //Only for development

//TO-DO:
//Implement the response structs (status, response)
//Implement the set(index, val) method
//Implement the max, min, sum, avr methods
//Destroy dependency on the "display" method



//Utils (private methods)
    //Swaps the element of a giving index with the element of index 0
template <typename T>
void Array<T>::swapHead(int index) {
    T temp = this->arr[0];
    this->arr[0] = this->arr[index];
    this->arr[index] = temp;
}

    //Recursive Quicksort implementation
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

//Core Methods
    //Acessors

    
    //Mutators
        //Delete the data of a giving index
    template <typename T>
    bool Array<T>::erase(int index) {
        if (index > this->size-1 || index < 0 || index > this->length-1) {
            return false;
        }
        
        for (int i = index; i < this->length-1; i++) {
            this->arr[i] = this->arr[i+1];
        }
        
        this->length--;
        return true;
    }

        //Inserts a value into a giving index
    template <typename T>
    bool Array<T>::insert(int index, T val) {
        if (index > this->size-1 || index < 0) {
            return false;
        }
        if (this->size == this->length) {
            return false;
        }
        
        for (int i = this->length; i > index; i--) {
            this->arr[i] = this->arr[i-1];
        }
        this->arr[index] = val;
        this->length++;
    }

        //Inserts a value at the end of the array
    template <typename T>
    bool Array<T>::append(T val) {
        if (this->length == this->size) {
            return false;
        }

        this->arr[this->length] = val;
        this->length++;
    }

//Algorithms
    //Linear search of a giving value
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

    //Binary search of a giving value
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

    //Method that abstracts the implementation of Quicksort
template <typename T>
void Array<T>::sort() {
    this->quicksort(0, this->length - 1);
}

//Computational Methods
    //Verifies Linearly if the array is sorted
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

//Temporary method to print the array
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