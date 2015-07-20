#ifndef COLLISION_H
#define COLLISION_H

#include "snake.h"
#include "snakeio.h"
#include "food.h"

/**
 * An enum to describe different types of collisions.
*/
typedef enum Collision Collision;
enum Collision {
    SNAKE,
    SCREEN,
    FOOD,
    NONE
};

/**
 * Function that checks if any collision has occurred.
*/
Collision find_collision(Snake* snake, FoodList* food_list, Screen* screen);
#endif
