#ifndef MOVE_H
#define MOVE_H

/**
 * Enumeration of different directions.
*/
typedef enum Direction Direction;
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NO_DIRECTION
};

/**
 * A move item. Implemented as a node in a doubly linked list.
*/
typedef struct MoveItem MoveItem;
struct MoveItem {
    MoveItem* next;
    MoveItem* prev;
    int age;
    Direction direction;
};

/**
 * The list of moves.
 * Sort of implemented as a FIFO queue, but is used as a doubly linked list as well.
*/
typedef struct MoveList MoveList;
struct MoveList {
    MoveItem* oldest;
    MoveItem* latest;
    int length;
};

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
