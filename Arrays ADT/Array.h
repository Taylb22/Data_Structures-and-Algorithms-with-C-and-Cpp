// #ifndef ARRAY_H
#ifndef Array_h
#define Array_h

enum ErrorCode {
    OK,
    INDEX_OUT_OF_BOUNDS,
    ARRAY_FULL,
    NOT_SORTED,
    ALREADY_SORTED
};

//Response structs
struct Status {
    bool ok = true;
    int error_code = OK;

    static Status sucess() {
        return {true, OK};
    }

    static Status failure(ErrorCode e) {
        return {false, e};
    }
};

template <typename T>
struct Response {
    T value;
    bool ok = true;
    int error_code;

    static Response sucess(T value) {
        return {value, true, OK};
    }

    static Response failure(ErrorCode e) {
        return {{}, false, e};
    }
};

template <typename T>
class Array {
    private:
        T* arr = nullptr;
        int size = 0;
        int length = 0;

        //Utils
        void swapHead(int index);
        void quicksort(int left, int right);
    public:
        //Constructor
        Array(int size){
            this->size = size;
            this->arr = new T[size];
            this->length = 0;
        }

        //Core methods
            //Acessors
            Response<T> get(int index);
            int getLength();
            //Mutators
            Status set(int index, T val);
            Status append(T val);
            Status insert(int index, T val);
            Status erase(int index);
            
        //Algorithms
        Response<int> find(T val, bool swap=false);
        Response<int> binary_search(T val, bool auto_sort=false);
        Status sort();
        
        //Computational Methods
        Response<bool> isSorted();
        Response<T> max();
        Response<T> min();
        Response<T> sum();
        Response<double> avg();

        friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
            if (arr.length <= 0) {
                os << "[]";
                return os;
            }
            
            os << "[";
            for (int i = 0; i < arr.length-1; i++) {
                os << arr.arr[i] << ", ";
            }
            os << arr.arr[arr.length-1] << "]";
            return os;
        }
        //Destructor
        ~Array() {
            delete[] this->arr;
        }
};

#include "methods/array_methods.cpp"
#endif