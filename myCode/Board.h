/*
 * Board.h
 *
 * Created on: 03-Jan-2024
 * Author: Dabbiru Sunil
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @brief The Board class represents the game board,
 * containing both the player's own grid and the opponent's grid.
 */
class Board
{
private:
	OwnGrid ownGrid; /**< The player's own grid. */
	OpponentGrid opponentGrid; /**< The opponent's grid. */

public:
	/**
	 * @brief Constructor for the Board class.
	 *
	 * Initializes ownGrid and opponentGrid with the
	 * specified number of rows and columns.
	 *
	 * @param rows The number of rows for the grids.
	 * @param columns The number of columns for the grids.
	 */
	Board(int rows, int columns);

	/**
	 * @brief Getter function to retrieve the number of
	 * rows in the board's ownGrid.
	 *
	 * @return The number of rows in ownGrid.
	 */
	int getRows() const;

	/**
	 * @brief Getter function to retrieve the number of
	 * columns in the board's ownGrid.
	 *
	 * @return The number of columns in ownGrid.
	 */
	int getColumns() const;

	/**
	 * @brief Getter function to access the board's ownGrid.
	 *
	 * @return A reference to the ownGrid of the board.
	 */
	OwnGrid& getOwnGrid();

	/**
	 * @brief Getter function to access the board's opponentGrid.
	 *
	 * @return A reference to the opponentGrid of the board.
	 */
	OpponentGrid& getOpponentGrid();

	/**
	 * @brief Destructor for the Board class.
	 */
	virtual ~Board();
};

#endif /* BOARD_H_ */
