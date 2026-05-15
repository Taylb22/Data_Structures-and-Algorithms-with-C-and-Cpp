#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string.h>
#include "Array.h"

//TO-DO:
//Validate the return of the arr methods
//Put the "clear" function before tthe switch statement
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

    //Reset the CIN internal state and clears the buffer
void reset_input() {
    std::cin.clear(); //Resets the internal state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

    //Abstraction to ask for a double value giving a specific message
double ask_double(std::string message) {
    std::cout << message << std::endl;
    
    double val;
    while (true) {
        std::cout << ">> ";
        if (std::cin >> val) return val;

        reset_input();
        std::cout << std::endl;
        std::cout << "Invalid input..." << std::endl;
        std::cout << "Provide a valid decimal number" << std::endl;
    }
}

    //Abstraction to ask for a integer value giving a specific message
int ask_int(std::string message) {
    std::cout << message << std::endl;
    
    int val;
    while (true) {
        std::cout << ">> ";
        if (std::cin >> val) return val;

        reset_input();
        std::cout << std::endl;
        std::cout << "Invalid input..." << std::endl;
        std::cout << "Provide a valid integer number" << std::endl;
    }
}

    //Abstraction of the commonly used "press ENTER" UI operation
void wait_enter(std::string message="Press ENTER to continue...") {
    std::cout << message << std::endl;
    std::cin.ignore(1, '\n');
    std::cin.get(); //TO-DO: validate ".get"
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
        std::cout << "<< " << arr << std::endl;

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
        
        clear();
        switch (aux) {
            //Exit program
            case 0: {
                std::cout << "Thanks for using the the program!" << std::endl;
                wait_enter("Press ENTER...");

                running = false;
                break;
            }
            //Append element
            case 1: {
                double val = ask_double("Type the value to append");
                std::cout << std::endl;

                auto stat = arr.append(val);
                if (!stat.ok) {
                    std::cout << "Failed to append..." << std::endl;
                    std::cout << "The array is full" << std::endl;
                    wait_enter("Press ENTER to return to the options list");
                    break;
                }

                std::cout << "Value appended" << std::endl;
                wait_enter();
                break;
            }
            //Erase element
            case 2: {
                int index = ask_int("Type the index of the element to erase");
                std::cout << std::endl;

                auto stat = arr.erase(index);
                if (!stat.ok) {
                    std::cout << "The provided index is out of bounds..." << std::endl;
                    wait_enter("Press ENTER to return to the options list");
                    break;
                }

                std::cout << "Value deleted at the giving index" << std::endl;
                wait_enter();
                break;
            }
            //Insert Element
            case 3: {
                int index = ask_int("Type the index of where you want to insert the value");    
                std::cout << std::endl;

                double val = ask_double("Type the value you want to insert");
                std::cout << std::endl;

                auto stat = arr.insert(index, val);
                if (!stat.ok) {
                    switch (stat.error_code) {
                        case INDEX_OUT_OF_BOUNDS:
                            std::cout << "The provided index is out of bounds..." << std::endl;
                            break;
                        case ARRAY_FULL:
                            std::cout << "Failed to insert..." << std::endl;
                            std::cout << "The array is full" << std::endl;
                            break;
                    }
                    wait_enter("Press ENTER to return to the options list");
                    break;
                }

                std::cout << "Value inserted at the giving index" << std::endl;
                wait_enter();
                break;
            }
            //Find element
            case 4: {
                double val = ask_double("Type the value you want to find");
                std::cout << std::endl;

                auto index = arr.find(val);
                if (index.value == -1) {
                    std::cout << "No element found with the provided value..." << std::endl;
                    wait_enter("Press ENTER to return to the options list");
                    break;
                }

                std::cout << "The index of the provided value is " << index.value << std::endl;
                std::cout << "<< " << arr << std::endl;
                std::cout << std::endl;

                wait_enter();
                break;
            }
            //Sort array
            case 5: {
                auto stat = arr.sort();
                if (!stat.ok) {
                    std::cout << "The array is already sorted" << std::endl;
                    wait_enter("Press ENTER to return to the options list");
                    break;
                }

                std::cout << "This is your new sorted array" << std::endl;
                std::cout << "<< " << arr << " >>" << std::endl;
                std::cout << std::endl;

                wait_enter();
                break;
            }
            //Binary Search element
            case 6: {
                if (!arr.isSorted().value) {
                    std::cout << "The array is not sorted" << std::endl;
                    std::cout << "Sort the array before performing the binary search" << std::endl;

                    std::cout << std::endl;
                    wait_enter("Press ENTER to return to the options list");
                    break;
                };

                double val = ask_double("Type the value of the value you want to find");
                auto index = arr.binary_search(val);

                std::cout << std::endl;
                if (index.value == -1) {
                    std::cout << "No element found with the provided value..." << std::endl;
                    wait_enter("Press ENTER to return to the options list");
                    break;
                }

                std::cout << "The index of the provided value is " << index.value << std::endl;
                std::cout << "<< " << arr << std::endl;
                std::cout << std::endl;

                wait_enter();
                break;
            }
            //Invalid input
            default: {
                std::cout << "Invalid option..." << std::endl;
                wait_enter("Press ENTER to try again...");
                break;
            }
        }
    }

    return 0;
}