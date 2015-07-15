#ifndef SNAKE_H
#define SNAKE_H

/**
 * Data structure to represent a snake. Implemented as en enhanced linked list of Segment nodes.
*/
typedef struct {
    Segment* head;
    Segment* end;
    int length;
} Snake;

/**
 * Data structure to represent a snake segment. Basically a node in a linked list.
*/
typedef struct {
    Direction* direction
    int x_pos;
    int y_pos;
    Segment* next;
} Segment;

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
void move(Snake* snake);

/**
 * Given a snake, determine whether or not it has collided with itself.
*/
int find_collision(Snake* snake);
#endif
