/*
 * GridPosition.h
 * Author: Dabbiru Sunil
 *
 * Description:
 * This file contains the declaration of the GridPosition class. GridPosition
 * represents a position on a game grid with a row (letter) and column (integer).
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>
#include <iostream>
/**
 * @brief GridPosition class for representing position on a game grid.
 */
class GridPosition {
private:
    char row;   // The row of the GridPosition.
    int column; // The column of the GridPosition.

public:
    GridPosition(char row, int column);
    GridPosition(const std::string& position);

    /**
     * @brief Check if the grid position is valid.
     * @return True if the grid position is valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Get the row of the GridPosition.
     * @return The row (letter) of the GridPosition.
     */
    char getRow() const;

    /**
     * @brief Get the column of the GridPosition.
     * @return The column (integer) of the GridPosition.
     */
    int getColumn() const;

    /**
     * @brief Conversion operator to convert GridPosition to a string.
     * @return A string representation of the GridPosition.
     */
    operator std::string() const;

    /**
     * @brief Equality operator to check if two GridPositions are equal.
     * @param other The GridPosition to compare with.
     * @return True if the GridPositions are equal, false otherwise.
     */
    bool operator==(const GridPosition other) const;

    /**
     * @brief Less than operator to compare two GridPositions.
     * @param other The GridPosition to compare with.
     * @return True if this GridPosition is less than the other,false otherwise.
     */
    bool operator<(const GridPosition other) const;

    virtual ~GridPosition();
};

#endif /* GRIDPOSITION_H_ */
