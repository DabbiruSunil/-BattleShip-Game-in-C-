/*
 * GridPosition.cpp
 * Author: Dabbiru Sunil
 *
 * Description:
 * This file contains the implementation of the GridPosition class. GridPosition
 * represents a position on a game grid with a row (letter) and column(integer).
 */

#include "GridPosition.h"
#include <iostream>

GridPosition::GridPosition(char row, int column) {
    this->row = row;
    this->column = column;
}

GridPosition::GridPosition(const std::string &position) {
    // Assuming the string format is a letter followed by a number (e.g., "B10")
    if (position.length() >= 2) {
        // Set row from the first character of the string
        this->row = position[0];

        // Set column by converting the substring from the second character to
       // the end to an integer
        this->column = std::stoi(position.substr(1));
    } else {
        // Handle invalid input
        std::cerr << "Invalid position format: " << position << std::endl;
      // You might want to throw an exception or handle the error appropriately.
    }
}

bool GridPosition::isValid() const {
    return (this->row >= 'A' && this->row <= 'Z' && this->column > 0);
}

char GridPosition::getRow() const {
    return this->row;
}

int GridPosition::getColumn() const {
    return this->column;
}

GridPosition::operator std::string() const {
    return std::string(1, this->row) + std::to_string(this->column);
}

bool GridPosition::operator ==(const GridPosition other) const {
    // Compare both row and column for equality
    return (row == other.row) && (column == other.column);
}

bool GridPosition::operator<(const GridPosition other) const {
    if (row < other.row)
        return true;
    else if ((row == other.row) && (column < other.column))
        return true;
    else
        return false;
}

GridPosition::~GridPosition() {
}
