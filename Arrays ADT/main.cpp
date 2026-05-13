#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string.h>
#include "Array.h"

//TO-DO:
//Include a input validation -> TOP PRIORITY
//Validate the "cin.get" input
//Improve the "clear" function
//Improve the "search_result" util function

//Utils
    //clear the console
void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear")
#endif
}

    //Abstraction to ask for a double value giving a specific message
double ask_double(std::string message) {
    std::cout << message << std::endl;
    std::cout << ">> ";

    double val;
    std::cin >> val; //TO-DO: validate input
    return val;
}

    //Abstraction to ask for a integer value giving a specific message
int ask_int(std::string message) {
    std::cout << message << std::endl;
    std::cout << ">> ";

    int val;
    std::cin >> val; //TO-DO: validate input
    return val;
}

    //Abstraction of the commonly used "press ENTER" UI operation
void wait_enter(std::string message="Press ENTER to continue...") {
    std::cout << message << std::endl;
    std::cin.ignore(1, '\n');
    std::cin.get(); //TO-DO: validate ".get"
}

    //TO-DO: Improve this "Ugly duck" function
    //3 total responsabilities (logic, array, I/O)
    //function to verify and print the search result giving an index
template <typename T>
void search_result(int index, Array<T> &arr) {
    if (index == -1) {
        std::cout << "No element found with the provided value..." << std::endl;
    } else {
        std::cout << "The index of the provided value is " << index << std::endl;
        arr.display();
        std::cout << std::endl << std::endl;
    }
}

int main () {
    clear();
    //Start of the program
    std::cout << "Welcome to the ARRAY testing program" << std::endl;
    std::cout << std::endl;
    std::cout << "WARNING: this main program does not shows all the features of the Array abstraction..." << std::endl;
    std::cout << "Look at the \"Array.h\" file to see all the features." << std::endl;
    std::cout << std::endl;

    int n = ask_int("Type the size of the array");
    Array<double> arr(n);

    //Main program loop
    bool running = true;
    while (running) {
        clear();
        std::cout << "ARRAY CURRENT STATE" << std::endl;
        std::cout << "<< ";
        arr.display();
        std::cout << std::endl << std::endl;

        //List of options for the switch statement
        std::cout << "List of actions:" << std::endl;
        std::cout << "0. exit program" << std::endl;
        std::cout << "1. append element" << std::endl;
        std::cout << "2. erase element" << std::endl;
        std::cout << "3. insert an element" << std::endl;
        std::cout << "4. find an element" << std::endl;
        std::cout << "5. sort the array" << std::endl;
        std::cout << "6. binary search an element" << std::endl;

        std::cout << std::endl;        
        int aux = ask_int("Choose your action");
        std::cout << std::endl << std::endl;
        
        switch (aux) {
            //Exit program
            case 0: {
                clear();
                std::cout << "Thanks for using the the program!" << std::endl;
                wait_enter("Press ENTER...");

                running = false;
                break;
            }
            //Append element
            case 1: {
                clear();
                double val = ask_double("Type the value to append");

                arr.append(val);

                std::cout << std::endl;
                std::cout << "Value appended" << std::endl;
                wait_enter();

                break;
            }
            //Erase element
            case 2: {
                clear();
                int index = ask_int("Type the index of the element to erase");
                arr.erase(index);

                std::cout << std::endl;
                std::cout << "Value deleted at the giving index" << std::endl;
                wait_enter();
                break;
            }
            //Insert Element
            case 3: {
                clear();
                int index = ask_int("Type the index of where you want to insert the value");    
                std::cout << std::endl;
                double val = ask_double("Type the value you want to insert");

                arr.insert(index, val);

                std::cout << std::endl;
                std::cout << "Value inserted at the giving index" << std::endl;
                wait_enter();
                break;
            }
            //Find element
            case 4: {
                clear();
                double val = ask_double("Type the value you want to find");

                int index = arr.find(val);

                std::cout << std::endl;
                search_result(index, arr);

                wait_enter();
                break;
            }
            //Sort array
            case 5: {
                clear();
                if (arr.isSorted()) {
                    std::cout << "The array is already sorted" << std::endl;
                } else {
                    arr.sort();
                    std::cout << "This is your new sorted array" << std::endl;
                    std::cout << "<< ";
                    arr.display();
                    std::cout << " >>" << std::endl;
                    std::cout << std::endl;
                }

                wait_enter();
                break;
            }
            //Binary Search element
            case 6: {
                clear();
                if (!arr.isSorted()) {
                    std::cout << "The array is not sorted" << std::endl;
                    std::cout << "Sort the array before performing the binary search" << std::endl;

                    std::cout << std::endl;
                    wait_enter();
                    break;
                };

                double val =  ask_double("Type the value of the value you want to find");
                int index = arr.binary_search(val);

                std::cout << std::endl;
                search_result(index, arr);

                wait_enter();
                break;
            }
            //Invalid input
            default: {
                clear();
                std::cout << "Invalid option..." << std::endl;
                wait_enter("Press ENTER to try again...");
                break;
            }
        }
    }

    return 0;
}