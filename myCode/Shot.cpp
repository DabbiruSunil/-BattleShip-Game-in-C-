/*
 * Shot.cpp
 *
 *  Created on: 10-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "Shot.h"

/**
 * @brief Gets the target position of the shot.
 *
 * @return The target position of the shot.
 */
GridPosition Shot::getTargetPosition() const {
    return targetPosition;
}

/**
 * @brief Constructor for the Shot class.
 *
 * @param targetPosition The target position of the shot.
 */
Shot::Shot(GridPosition targetPosition) : targetPosition(targetPosition) {
}

/**
 * @brief Destructor for the Shot class.
 */
Shot::~Shot() {
    // TODO: Destructor implementation (if needed)
}
