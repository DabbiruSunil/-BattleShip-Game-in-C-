/*
 * ConsoleView.h
 *
 *  Created on: 03-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"
#include <utility>

/**
 * @brief ConsoleView class for displaying the game board in the console.
 */
class ConsoleView
{
private:
    Board *board; ///< Pointer to the game board.

public:
    /**
     * @brief Construct a new ConsoleView object.
     *
     * @param board Pointer to the game board.
     */
    ConsoleView(Board *board);

    /**
     * @brief Print the game board to the console.
     */
    void print();

    //virtual ~ConsoleView(); // Uncomment if needed in the future.
};

#endif /* CONSOLEVIEW_H_ */
