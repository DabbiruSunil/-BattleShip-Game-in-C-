/*
 * main.cpp
 * Author: [Your Name]
 *
 * Description:
 * This file contains the main function for the Battleship game program.
 * It includes necessary header files and invokes the test functions for
 * different
 * parts of the program.
 */

// Standard (system) header files
#include "ConsoleView.h"
#include "AllTests.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here

// Main program
int main() {
    /**
     * @brief The main function of the Battleship game program.
     * @return The exit status of the program (0 for success).
     */
    part1tests();
    part2tests();
    part3tests();

    return 0;
}
