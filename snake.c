#include "snake.h"
#include "move.h"

Snake* new_snake(int x, int y) {
    Segment* first = malloc(sizeof(Segment));
    first = (Segment) {.direction = UP, .x_pos = x, .y_pos = y, .next = NULL};

    Snake* s = malloc(sizeof(Snake));
    *s = (Snake) {.head = first, .end = first, .length = 1}
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
    Snake->length++;
    Segment* new_end = malloc(sizeof(Segment)); // TODO: Add checks
    Snake->end->next = new_end;
    Snake->end = new_end;
}

void update_direction(Snake* snake, MoveList* moves) {
    // If the top move is already implemented on the entire snake, discard it
    if (moves->oldest->age >= snake->length) {
        pop_move(moves)
    }

    MoveNode* move = moves->latest;
    Segment* seg = snake->first;
    
    int i = 0;
    while (move != NULL && i < snake->length) {
        if (move->age == i) {
            seg->direction = move->direction;
            move->age++;
            move = move->next;
        }

        seg = seg->next;
        i++;
    }
}

void move(Snake* snake) {
    Segment* seg = snake->head;
    while(seg != NULL) {
        switch(seg->direction) {
            case UP:
                seg->y_val--;
                break;

            case DOWN:
                seg->y_val++;
                break;

            case LEFT:
                seg->x_val--;
                break;

            case RIGHT:
                seg->x_val++;
                break;
        }

        seg = seg->next;
    }
}

int find_collision(Snake* snake) {
    Segment head = *snake->head;
    
    Segment seg = *head.next;
    while(seg != NULL) {
        if (seg.x_val == head.x_val && seg.y_val == head.y_val) {
            return 1;
        }
        seg = *seg.next;
    }
    
    return 0;
}
