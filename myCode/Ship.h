/*
 * Ship.h
 *
 *  Created on: 07-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

/**
 * @brief Class representing a Ship in the game.
 */
class Ship {
private:
    GridPosition bow; ///< The bow position of the ship.
    GridPosition stern; ///< The stern position of the ship.

public:
    /**
     * @brief Constructor for the Ship class.
     *
     * @param bow The bow position of the ship.
     * @param stern The stern position of the ship.
     */
    Ship(const GridPosition& bow, const GridPosition& stern);

    /**
     * @brief Checks if the ship is valid.
     *
     * A valid ship must have its bow and stern either in the same row or the
     * same
     * column and have a length between 2 and 5 (inclusive).
     *
     * @return True if the ship is valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Calculates the length of the ship.
     *
     * @return The length of the ship.
     */
    int length() const;

    /**
     * @brief Gets the bow position of the ship.
     *
     * @return The bow position.
     */
    GridPosition getBow() const;

    /**
     * @brief Gets the stern position of the ship.
     *
     * @return The stern position.
     */
    GridPosition getStern() const;

    /**
     * @brief Calculates the set of positions occupied by the ship.
     *
     * @return The set of occupied positions.
     */
    std::set<GridPosition> occupiedArea() const;

    /**
     * @brief Calculates the set of positions blocked by the ship.
     *
     * @return The set of blocked positions.
     */
    std::set<GridPosition> blockedArea() const;

    /**
     * @brief Destructor for the Ship class.
     */
    ~Ship();
};

#endif /* SHIP_H_ */
