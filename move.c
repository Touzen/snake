#include "move.h"

#include <unistd.h>

MoveList* new_move_list() {
    MoveList* ms = malloc(sizeof(MoveList));
    *ms = (MoveList) {.latest = NULL, .oldest = NULL, .length = 0};
    return ms;
}

void delete_move_list(MoveList* list) {
    while(list->oldest != NULL) {
        pop_move(list);
    }

    free(list);
}

void pop_move(MoveList* list) {
    if (list->oldest == NULL) {
        return;
    }

    MoveItem* old_oldest = list->oldest;
    list->oldest = list->oldest->next;

    if (list->oldest != NULL) {
        list->oldest->prev = NULL;
    }

    free(old_oldest);
}

void push_move(MoveList* list, Direction direction) {
    MoveItem* move = malloc(sizeof(MoveItem));
    
    move->direction = direction;
    move->age = 0;
    
    move->prev = list->latest;
    list->latest = move;
}
