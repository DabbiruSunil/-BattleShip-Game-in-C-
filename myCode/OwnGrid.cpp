/*
 * OwnGrid.cpp
 *
 *  Created on: 03-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "OwnGrid.h"

/**
 * @brief Construct a new OwnGrid object
 *
 * @param rows The number of rows in the grid
 * @param columns The number of columns in the grid
 */
OwnGrid::OwnGrid(int rows, int columns) : rows(rows), columns(columns)
{
    LengthCheck = {{5, 1}, {4, 2}, {3, 3}, {2, 4}};
}

/**
 * @brief Get the number of rows in the grid
 *
 * @return int The number of rows
 */
int OwnGrid::getRows() const
{
    return this->rows;
}

/**
 * @brief Get the number of columns in the grid
 *
 * @return int The number of columns
 */
int OwnGrid::getColumns() const
{
    return this->columns;
}

/**
 * @brief Place a ship on the grid
 *
 * @param ship The ship to be placed
 * @return true If the ship is successfully placed
 * @return false If the ship cannot be placed
 */
bool OwnGrid::placeShip(const Ship &ship)
{
    if (((ship.getBow().getRow()) - 'A' >= getRows()) ||
    		(ship.getStern().getRow() - 'A' >= getRows()) ||
        (ship.getBow().getColumn() > getColumns()) ||
		(ship.getStern().getColumn() > getColumns()))
    {
        return false;
    }
    if (!ship.isValid())
    {
        return false;
    }

    for (auto shipsVectorIterator : getShips())
    {
        for (auto BlockedAreaIterator : shipsVectorIterator.blockedArea())
        {
            for (auto OccupiedAreaIterator : ship.occupiedArea())
            {
                if (OccupiedAreaIterator == BlockedAreaIterator)
                {
                    return false;
                }
            }
        }
    }

    int flag = 0;
    for (auto &LengthCheckIterator : LengthCheck)
    {
        if (LengthCheckIterator.first == ship.length())
        {
            if (LengthCheckIterator.second > 0)
            {
                LengthCheckIterator.second--;
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        return false;
    }

    this->ships.push_back(ship);
    return true;
}

/**
 * @brief Get the vector of ships on the grid
 *
 * @return const std::vector<Ship> The vector of ships
 */
const std::vector<Ship> OwnGrid::getShips()
{
    return this->ships;
}

/**
 * @brief Take a blow at a specific position on the grid
 *
 * @param shot The shot information
 * @return Shot::Impact The impact of the shot
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
    std::set<GridPosition> AllShipsGrids;
    std::set<GridPosition> TargetShipOccupiedArea;
    static std::set<GridPosition> AllTakenBlows;
    std::set<GridPosition> IntersectionSet;
    Shot::Impact ShotType = Shot::NONE;

    for (auto myShip : getShips())
    {
        for (auto myShipGrid : myShip.occupiedArea())
        {
            AllShipsGrids.insert(myShipGrid);
            if (shot.getTargetPosition() == myShipGrid)
            {
                TargetShipOccupiedArea = myShip.occupiedArea();
            }
        }
    }

    for (auto mygrid : TargetShipOccupiedArea)
    {
        for (auto TakenShot : AllTakenBlows)
        {
            if (mygrid == TakenShot)
            {
                IntersectionSet.insert(mygrid);
            }
        }
    }

    for (auto myShip : getShips())
    {
        for (auto myShipGrid : myShip.occupiedArea())
        {
            if (shot.getTargetPosition() == myShipGrid)
            {
                ShotType = Shot::HIT;
                if (IntersectionSet.size() == TargetShipOccupiedArea.size() - 1)
                {
                    ShotType = Shot::Impact::SUNKEN;
                }
            }
        }
    }

    for (auto shipGrid : AllShipsGrids)
    {
        if (shipGrid == shot.getTargetPosition())
            AllTakenBlows.insert(shipGrid);
    }

    shotAt.insert(shot.getTargetPosition());
    return ShotType;
}

/**
 * @brief Get the set of positions that have been shot at
 *
 * @return std::set<GridPosition> The set of shot positions
 */
std::set<GridPosition> OwnGrid::getShotAt() const
{
    return shotAt;
}

/**
 * @brief Destroy the OwnGrid object
 *
 */
OwnGrid::~OwnGrid()
{
}
