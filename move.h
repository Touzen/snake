#ifndef MOVE_H
#define MOVE_H

/**
 * Enumeration of different directions.
*/
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NO_DIRECTION
} Direction;

/**
 * A move item. Implemented as a node in a doubly linked list.
*/
typedef struct {
    MoveItem* next;
    MoveItem* prev;
    int age;
    Direction direction;
} MoveItem;

/**
 * The list of moves.
 * Sort of implemented as a FIFO queue, but is used as a doubly linked list as well.
*/
typedef struct {
    MoveNode* oldest;
    MoveNode* latest;
    int length;
} MoveList;

/**
 * Create a new move list.
*/
MoveList* new_move_list();

/**
 * Delete a move list and free the memory associated with it.
*/
void delete_move_list(MoveList* list);

/**
 * Pop and throw away the oldest move of the list.
*/
void pop_move(MoveList* list);

/**
 * Add the latest move to the list.
*/
void push_move(MoveList* list, Direction direction);
#endif
