#ifndef SNAKE_H
#define SNAKE_H

#include "move.h"

#include <unistd.h>

/**
 * Data structure to represent a snake segment. Basically a node in a linked list.
*/
typedef struct Segment Segment; 
struct Segment {
    Direction direction;
    int x_pos;
    int y_pos;
    Segment* next;
};

/**
 * Data structure to represent a snake. Implemented as en enhanced linked list of Segment nodes.
*/
typedef struct Snake Snake;  
struct Snake {
    Segment* head;
    Segment* end;
    int length;
};

/**
 * Create a new snake at the specified coordinates.
*/
Snake* new_snake(int x, int y);

/**
 * Delete a snake and free the memory associated with it.
*/
void delete_snake(Snake* snake);

/**
 * Adds a segment to the snake.
*/
void add_segment(Snake* snake);

/**
 * Update direction of the snake based on the move stack.
*/
void update_direction(Snake* snake, MoveList* moves);

/**
 * Moves each segment of the snake one step.
*/
void move_snake(Snake* snake);
#endif
