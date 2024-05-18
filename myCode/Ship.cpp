/*
 * Ship.cpp
 *
 *  Created on: 03-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "Ship.h"

/**
 * @brief Constructor for Ship class.
 *
 * @param bow The bow position of the ship.
 * @param stern The stern position of the ship.
 */
Ship::Ship(const GridPosition& bow, const GridPosition& stern) : bow(bow),
                                      stern(stern) {
    // Implement validation logic or additional initialization if needed
}

/**
 * @brief Checks if the ship is valid.
 *
 * A valid ship must have its bow and stern either in the same row or the same
 * column and have a length between 2 and 5 (inclusive).
 *
 * @return True if the ship is valid, false otherwise.
 */
bool Ship::isValid() const {
    if ((bow.getRow() == stern.getRow() || bow.getColumn() == stern.getColumn())
    		&&
        ((this->length() <= 5) && (this->length() >= 2))) {
        return true;
    }
    return false;
}

/**
 * @brief Calculates the length of the ship.
 *
 * @return The length of the ship.
 */
int Ship::length() const {
    if (bow.getRow() == stern.getRow()) {
        if (bow.getColumn() < stern.getColumn()) {
            return (stern.getColumn() - bow.getColumn()) + 1;
        } else {
            return (bow.getColumn() - stern.getColumn()) + 1;
        }
    } else if (bow.getColumn() == stern.getColumn()) {
        if (bow.getRow() < stern.getRow()) {
            return (stern.getRow() - bow.getRow()) + 1;
        } else {
            return (bow.getRow() - stern.getRow()) + 1;
        }
    }
    return 0;
}

/**
 * @brief Gets the bow position of the ship.
 *
 * @return The bow position.
 */
GridPosition Ship::getBow() const {
    return bow;
}

/**
 * @brief Gets the stern position of the ship.
 *
 * @return The stern position.
 */
GridPosition Ship::getStern() const {
    return stern;
}

/**
 * @brief Calculates the set of positions occupied by the ship.
 *
 * @return The set of occupied positions.
 */
std::set<GridPosition> Ship::occupiedArea() const {
    std::set<GridPosition> ShipOccupiedArea;

    if (bow.getRow() == stern.getRow()) {
        int columnValue = bow.getColumn();
        for (int i = 0; i < this->length(); i++) {
            if (bow.getColumn() < stern.getColumn()) {
                ShipOccupiedArea.insert(GridPosition(bow.getRow(), columnValue
                		+ i));
            } else {
                ShipOccupiedArea.insert(GridPosition(bow.getRow(), columnValue
                		- i));
            }
        }
    } else if (bow.getColumn() == stern.getColumn()) {
        char rowChar = bow.getRow();
        for (int i = 0; i < length(); i++) {
            if (bow.getRow() < stern.getRow()) {
                ShipOccupiedArea.insert(GridPosition(static_cast<char>(rowChar
                		+ i), bow.getColumn()));
            } else {
                ShipOccupiedArea.insert(GridPosition(static_cast<char>(rowChar
                		- i), bow.getColumn()));
            }
        }
    }
    return ShipOccupiedArea;
}

/**
 * @brief Calculates the set of positions blocked by the ship.
 *
 * @return The set of blocked positions.
 */
std::set<GridPosition> Ship::blockedArea() const {
    std::set<GridPosition> BlockedAreaSet;
    for (auto Grids : occupiedArea()) {
     BlockedAreaSet.insert(Grids); // Inserting initial GridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow() - 1,
     Grids.getColumn()));         // Inserting top GridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow() - 1,
     Grids.getColumn() - 1));     // Inserting diagonal top left GridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow(),
     Grids.getColumn() - 1));         // Inserting left GridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow() + 1,
     Grids.getColumn() - 1));     // Inserting diagonal bottom leftGridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow() + 1,
     Grids.getColumn()));         // Inserting bottom GridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow() + 1,
     Grids.getColumn() + 1));     // Inserting diagonal bottom rightGridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow(),
     Grids.getColumn() + 1));         // Inserting right GridPosition
     BlockedAreaSet.insert(GridPosition(Grids.getRow() - 1,
     Grids.getColumn() + 1));     // Inserting diagonal top right GridPosition
    }
    return BlockedAreaSet;
}

/**
 * @brief Destructor for Ship class.
 */
Ship::~Ship() {
    // Destructor implementation (if needed)
}
