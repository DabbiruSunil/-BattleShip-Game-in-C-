/*
 * Board.cpp
 *
 * Created on: 03-Jan-2024
 * Author: Dabbiru Sunil
 */

#include "Board.h"

/**
 * @brief Constructor for the Board class.
 *
 * Initializes ownGrid and opponentGrid with the specified number of rows and
 *  columns.
 *
 * @param rows The number of rows for the grids.
 * @param columns The number of columns for the grids.
 */
Board::Board(int rows, int columns): ownGrid(rows, columns), opponentGrid(rows,
		columns) {

}

/**
 * @brief Getter function to retrieve the number of rows in the board's ownGrid.
 *
 * @return The number of rows in ownGrid.
 */
int Board::getRows() const {
    return ownGrid.getRows();
}

/**
 * @brief Getter function to retrieve the number of columns in the board's
 *  ownGrid.
 *
 * @return The number of columns in ownGrid.
 */
int Board::getColumns() const {
    return ownGrid.getColumns();
}

/**
 * @brief Getter function to access the board's ownGrid.
 *
 * @return A reference to the ownGrid of the board.
 */
OwnGrid& Board::getOwnGrid() {
    return ownGrid;
}

/**
 * @brief Getter function to access the board's opponentGrid.
 *
 * @return A reference to the opponentGrid of the board.
 */
OpponentGrid& Board::getOpponentGrid() {
    return opponentGrid;
}

/**
 * @brief Destructor for the Board class.
 */
Board::~Board() {

}
