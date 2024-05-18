/*
 * OwnGrid.h
 *
 *  Created on: 03-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <vector>
#include "Ship.h"
#include "Shot.h"
#include <map>

/**
 * @brief OwnGrid class representing the player's game grid.
 */
class OwnGrid {
private:
    int rows; ///< Number of rows in the grid.
    int columns; ///< Number of columns in the grid.
    std::vector<Ship> ships; ///< Vector of ships placed on the grid.
    std::set<GridPosition> shotAt; ///< Set of positions where shot have
    								//been taken.
    std::map<int, int> LengthCheck; ///< Map to check ship lengths.

public:
    /**
     * @brief Construct a new OwnGrid object.
     *
     * @param rows Number of rows in the grid.
     * @param columns Number of columns in the grid.
     */
    OwnGrid(int rows, int columns);

    /**
     * @brief Get the number of rows in the grid.
     *
     * @return int Number of rows.
     */
    int getRows() const;

    /**
     * @brief Get the number of columns in the grid.
     *
     * @return int Number of columns.
     */
    int getColumns() const;

    /**
     * @brief Place a ship on the grid.
     *
     * @param ship The Ship object to be placed.
     * @return true if the ship is successfully placed, false otherwise.
     */
    bool placeShip(const Ship &ship);

    /**
     * @brief Get the vector of ships placed on the grid.
     *
     * @return const std::vector<Ship> Vector of ships.
     */
    const std::vector<Ship> getShips();

    /**
     * @brief Take a shot at the grid.
     *
     * @param shot The Shot object representing the shot.
     * @return Shot::Impact The impact of the shot.
     */
    Shot::Impact takeBlow(const Shot &shot);

    /**
     * @brief Get the set of positions where shots have been taken.
     *
     * @return std::set<GridPosition> Set of positions.
     */
    std::set<GridPosition> getShotAt() const;

    /**
     * @brief Destroy the OwnGrid object.
     */
    virtual ~OwnGrid();
};

#endif /* OWNGRID_H_ */
