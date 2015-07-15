#ifndef SNAKEIO_H
#define SNAKEIO_H

/**
 * Data structure containing screen data.
*/
typedef struct {
    int max_x;
    int max_y;
} Screen;

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
Direction get_input();

/**
 * Draws the frame unto the screen.
*/
int draw_frame(Snake* snake, Screen* screen);
#endif
