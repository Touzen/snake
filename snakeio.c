#include <ncurses.h>

#include "snake.h"
#include "move.h"

#define SNAKE_CHAR "O"

Screen* new_screen() {
    Screen* screen = malloc(sizeof(Screen));
    initscr();
    noecho();
    curs_set(0);
    cbreak();       // All keyboard input should be available immediately
}

void close_screen(Screen* screen) {
    free(screen);
    endwin();       // Close screen
}

Direction get_input() {
    int key = ERR, new_key;
    while((new_key = getch()) != ERR) {
        key = new_key;
    }
    
    switch(key) {
        case KEY_UP:
            return UP;
        case KEY_DOWN:
            return DOWN;
        case KEY_LEFT:
            return LEFT;
        case KEY_RIGHT:
            return RIGHT;
        case ERR:
            return NO_DIRECTION;
    }
}

int draw_frame(Snake* snake, Screen* screen) {
    clear(); // Clear screen
    
    Segment* seg = snake->head;
    while(seg != NULL) {
        if (seg->x_val > screen->max_x || seg->y_val > screen->max_y) {
            return 0; // The snake has hit a wall
        }
        else {
            mvprintw(seg->y_val, seg->x_val, SNAKE_CHAR);
        }
        
        seg = seg->next;
    }
    
    refresh() // Refresh screen
    return 1;
}
