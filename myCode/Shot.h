/*
 * Shot.h
 *
 *  Created on: 10-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @brief Class representing a shot in the game.
 */
class Shot
{
private:
    GridPosition targetPosition; /**< The target position of the shot. */
public:
    /**
     * @brief Constructor for the Shot class.
     *
     * @param targetPosition The target position of the shot.
     */
    Shot(GridPosition targetPosition);

    /**
     * @brief Gets the target position of the shot.
     *
     * @return The target position of the shot.
     */
    GridPosition getTargetPosition() const;

    /**
     * @brief Destructor for the Shot class.
     */
    virtual ~Shot();

    /**
     * @brief Enum representing the impact of a shot.
     */
    enum Impact
    {
        NONE,   /**< No impact. */
        HIT,    /**< Hit on a ship. */
        SUNKEN  /**< Ship has been sunken. */
    };
};

#endif /* SHOT_H_ */
