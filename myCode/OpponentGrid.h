/*
 * OpponentGrid.h
 *
 *  Created on: 07-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <set>
#include <map>

/**
 * @brief Represents the opponent's grid in the game.
 */
class OpponentGrid {
private:
    int rows;                          /**< The number of rows in the grid. */
    int columns;                    /**< The number of columns in the grid. */
    std::map<GridPosition, Shot::Impact> shots;/**< Map to store shots and
     their impacts. */
    std::vector<Ship> sunkenShips;    /**< Vector to store sunken ships. */

public:
    /**
     * @brief Constructs an OpponentGrid object with the specified number of
     *  rows and columns.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    OpponentGrid(int rows, int columns);

    /**
     * @brief Gets the number of rows in the opponent grid.
     * @return The number of rows.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the opponent grid.
     * @return The number of columns.
     */
    int getColumns() const;

    /**
     * @brief Processes the result of a shot on the opponent grid.
     * @param shot The shot fired.
     * @param impact The impact of the shot (HIT or SUNKEN).
     */
    void shotResult(const Shot& shot, Shot::Impact impact);

    /**
     * @brief Gets the map of shots fired at the opponent grid and their impacts.
     * @return The map of shots and their impacts.
     */
    const std::map<GridPosition, Shot::Impact>& getShotsAt();

    /**
     * @brief Gets the vector of sunken ships on the opponent grid.
     * @return The vector of sunken ships.
     */
    std::vector<Ship> getSunkenShips();

    /**
     * @brief Destructs the OpponentGrid object.
     */
    virtual ~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
