// #ifndef ARRAY_H
#ifndef Array_h
#define Array_h

template <typename T>
class Array {
    private:
        T* arr = NULL;
        int size = 0;
        int length = 0;

        //Utils
        void swapHead(int index);
        void quicksort(int left, int right);
    public:
        //Constructor
        Array(int size){}

        //Core methods
            //Acessors
            T get(int index);
            //Mutators
            void set(int index, T val);
            void append(T val);
            void insert(int index, T val);
            void erase(int index);
            
        //Algorithms
        int find(T val, bool swap=false);
        int binary_search(T val, bool auto_sort=false);
        void sort();
        
        //Computational Methods
        bool isSorted();
        T max();
        T min();
        T sum();
        double avg();
        
        //TO-DO: destroy dependency of the "diplay" method
        //Temporary I/O
        void display();

        //Destructor
        ~Array() {}
};

#endif