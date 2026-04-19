#include <iostream>
#include <stdlib.h>

template <class generic>
class Rectangle {
    private:
        generic length;
        generic breadth;
        int* example;

    public:
        //Constructors
        Rectangle () {this->length = 1; this->breadth = 1;} //Default Constructor
        Rectangle (generic length, generic breadth) { //Constructor Overloading
            this->length = length;
            this->breadth = breadth;
            this->example = (int*) malloc(sizeof(int));
        }

        //Facilitators
        generic area() {return this->length * this->breadth;}
        generic perimeter() {return 2 * (this->length + this->breadth);}

        //Acessors
        generic getLength() {return this->length;}
        generic getBreadth() {return this->breadth;}

        //Mutators
        void setLength(generic val) {this->length = val;}
        void setBreadth(generic val) {this->breadth = val;}

        // Destructor
        ~Rectangle() {free(example);}
};

int main() {
    Rectangle<float> rec(5.23, 10.123);

    std::cout<< rec.area() << std::endl;
    std::cout<< rec.perimeter() << std::endl;

    return 0;
}