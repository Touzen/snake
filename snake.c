#include "snake.h"

Snake* new_snake(int x, int y) {
    Segment* first = malloc(sizeof(Segment));
    first->direction = UP;
    first->x_pos = x;
    first->y_pos = y;
    first->next = NULL;

    Snake* s = malloc(sizeof(Snake));
    s->head = first; 
    s->end = first; 
    s->length = 1;
    
    return s;
}

void delete_snake(Snake* snake) {
    Segment* seg = snake->head;
    while(seg != NULL) {
        Segment* prev = seg;
        seg = seg->next;
        free(prev);
    }

    free(snake);
}

void add_segment(Snake* snake) {
    Segment* new_end = malloc(sizeof(Segment)); // TODO: Add checks
    new_end->direction = snake->end->direction;
    new_end->next = NULL;
    switch(snake->end->direction) {
        case UP:
            new_end->y_pos = snake->end->y_pos + 1;
            new_end->x_pos = snake->end->x_pos;
            break;

        case DOWN:
            new_end->y_pos = snake->end->y_pos - 1;
            new_end->x_pos = snake->end->x_pos;
            break;

        case LEFT:
            new_end->y_pos = snake->end->y_pos;
            new_end->x_pos = snake->end->x_pos + 1;
            break;

        case RIGHT:
            new_end->y_pos = snake->end->y_pos;
            new_end->x_pos = snake->end->x_pos - 1;
            break;
    }

    snake->length++;
    snake->end->next = new_end;
    snake->end = new_end;
}

void update_direction(Snake* snake, MoveList* moves) {
    // If the top move is already implemented on the entire snake, discard it
    if (moves->oldest != NULL && moves->oldest->age >= snake->length) {
        pop_move(moves);
    }

    MoveItem* move = moves->latest;
    Segment* seg = snake->head;
    
    int i = 0;
    while (move != NULL && i < snake->length) {
        if (move->age == i) {
            seg->direction = move->direction;
            move->age++;
            move = move->prev;
        }

        seg = seg->next;
        i++;
    }
}

void move_snake(Snake* snake) {
    Segment* seg = snake->head;
    while(seg != NULL) {
        switch(seg->direction) {
            case UP:
                seg->y_pos--;
                break;

            case DOWN:
                seg->y_pos++;
                break;

            case LEFT:
                seg->x_pos--;
                break;

            case RIGHT:
                seg->x_pos++;
                break;
        }

        seg = seg->next;
    }
}
