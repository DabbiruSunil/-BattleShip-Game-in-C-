/*
 * OpponentGrid.cpp
 *
 *  Created on: 07-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "OpponentGrid.h"

/**
 * @brief Constructs an OpponentGrid object with the specified number of
 * rows and columns.
 * @param rows The number of rows in the grid.
 * @param columns The number of columns in the grid.
 */
OpponentGrid::OpponentGrid(int rows, int columns) : rows(rows),
columns(columns) {
}

/**
 * @brief Gets the number of rows in the opponent grid.
 * @return The number of rows.
 */
int OpponentGrid::getRows() const {
    return this->rows;
}

/**
 * @brief Gets the number of columns in the opponent grid.
 * @return The number of columns.
 */
int OpponentGrid::getColumns() const {
    return this->columns;
}

/**
 * @brief Gets the vector of sunken ships on the opponent grid.
 * @return The vector of sunken ships.
 */
std::vector<Ship> OpponentGrid::getSunkenShips() {
    return sunkenShips;
}

/**
 * @brief Destructs the OpponentGrid object.
 */
OpponentGrid::~OpponentGrid() {
}

/**
 * @brief Processes the result of a shot on the opponent grid.
 * @param shot The shot fired.
 * @param impact The impact of the shot (HIT or SUNKEN).
 */
void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact) {
    static std::set<GridPosition> gridsHit;
    GridPosition currentShot = shot.getTargetPosition();

    shots.insert({shot.getTargetPosition(), impact});

    if (impact == Shot::Impact::HIT) {
        gridsHit.insert(shot.getTargetPosition());
    }

    std::set<GridPosition> sunkenShipArea;

    int rowDirection[4] = {0, 0, 1, -1};     // L, R, U, D
    int columnDirection[4] = {-1, 1, 0, 0};  // L, R, U, D

    char lastRow = currentShot.getRow();
    char nextRow = lastRow;
    int lastCol = currentShot.getColumn();
    int nextCol = lastCol;

    if (impact == Shot::Impact::SUNKEN) {
        sunkenShipArea.insert(shot.getTargetPosition());

        for (int itr = 0; itr < 4; itr++) {
            nextRow = lastRow + rowDirection[itr];
            nextCol = lastCol + columnDirection[itr];
            if (nextRow >= 'A' && nextRow <= ('A' + rows - 1) && nextCol >= 1
            		&& nextCol <= columns) {
                auto pos = gridsHit.find(GridPosition(nextRow, nextCol));
                if (pos != gridsHit.end()) {
                    sunkenShipArea.insert(*pos);

                    std::set<GridPosition>::iterator pos2;
                    do {
                        nextRow = nextRow + rowDirection[itr];
                        nextCol = nextCol + columnDirection[itr];
                        pos2 = gridsHit.find(GridPosition(nextRow, nextCol));
                        if (pos2 != gridsHit.end())
                            sunkenShipArea.insert(*pos2);
                    } while (pos2 != gridsHit.end());
                }
            }
        }

        sunkenShips.push_back(Ship(*(sunkenShipArea.begin()),
        		*(sunkenShipArea.rbegin())));
    }
}

/**
 * @brief Gets the map of shots fired at the opponent grid and their impacts.
 * @return The map of shots and their impacts.
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() {
    return shots;
}
