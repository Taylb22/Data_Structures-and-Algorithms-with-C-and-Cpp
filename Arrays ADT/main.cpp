#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "Array.h"

//TO-DO:
//Include a input validation
//Validate the "cin.get" input
//Include the features from 3 to 6

//clear the console
void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear")
#endif
}

int main () {
    clear();
    //Start of the program
    std::cout << "Welcome to the ARRAY testing program" << std::endl;
    std::cout << "Warning: this main program does not shows all the features of the Array abstraction..." << std::endl;
    std::cout << "Look at the \"Array.h\" file to see all the features." << std::endl;
    
    int n;
    std::cout << std::endl << "Type the size of the array" << std::endl << ">> ";
    std::cin >> n; //TO-DO: input validation

    Array<double> arr(n);

    //Main program loop
    bool running = true;
    while (running) {
        clear();
        arr.display();
        std::cout << std::endl;

        //List of options for the switch statement
        std::cout << "List of actions:" << std::endl;
        std::cout << "0. exit program" << std::endl;
        std::cout << "1. append element" << std::endl;
        std::cout << "2. erase element" << std::endl;
        std::cout << "3. insert an element" << std::endl;
        std::cout << "4. find an element" << std::endl;
        std::cout << "5. sort the array" << std::endl;
        std::cout << "6. binary search an element" << std::endl;

        int aux;
        std::cout << std::endl;
        std::cout << "Choose your action" << std::endl << ">> ";
        std::cin >> aux; //TO-DO: input validation
        std::cout << std::endl << std::endl;
        
        switch (aux) {
            //Exit program
            case 0:
                clear();
                std::cout << "Thanks for using the the program!" << std::endl;
                std::cout << "Press ENTER..." << std::endl;

                std::cin.ignore(1, '\n');
                std::cin.get(); //TO-DO: validate ".get"

                running = false;
                break;
            //Append element
            case 1:
                clear();
                double val;
                std::cout << "Type the value to append" << std::endl;
                std::cout << ">> ";
                std::cin >> val; //TO-DO: validate input

                arr.append(val);

                std::cout << std::endl;
                std::cout << "Value appended" << std::endl;
                std::cout << "Press ENTER to continue..." << std::endl;

                std::cin.ignore(1, '\n');
                std::cin.get(); //TO-DO validate ".get"
                break;
            //Erase element
            case 2:
                clear();
                int index;
                std::cout << "Type the index of the element to erase" << std::endl;
                std::cout << ">> ";
                std::cin >> index; //TO-DO: validate input
                
                arr.erase(index);

                std::cout << std::endl;
                std::cout << "Value deleted at the giving index" << std::endl;
                std::cout << "Press ENTER to continue..." << std::endl;

                std::cin.ignore(1, '\n');
                std::cin.get(); //TO-DO validate ".get"
                break;
            //Insert Element
            case 3:
                break;
            //Find element
            case 4:
                break;
            //Sort array
            case 5:
                break;
            //Binary Search element
            case 6:
                break;
            //Invalid input
            default:
                clear();
                std::cout << "Invalid option..." << std::endl;
                std::cout << "Press ENTER to try again" << std::endl;
                std::cout << ">> ";
                std::cin.ignore(1, '\n');
                std::cin.get(); //TO-DO: Validate ".get"
                break;
        }
    }

    return 0;
}