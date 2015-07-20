#ifndef SNAKEIO_H
#define SNAKEIO_H

#include "move.h"
#include "snake.h"
#include "food.h"

/**
 * Data structure containing screen data.
*/
typedef struct Screen Screen;
struct Screen {
    int max_x;
    int max_y;
};

/**
 * Initializes screen and returns a screen structure.
*/
Screen* new_screen();

/**
 * Closes the screen and removes it from memory.
*/
void close_screen(Screen* screen);

/**
 * Gets the last arrow key pressed by the user and returns the appropriate Direction.
*/
Direction get_direction();

/**
 * Draws the frame unto the screen.
*/
void draw_frame(Snake* snake, FoodList* food_list);
#endif
