#include <ncurses.h>

#include "snakeio.h"
#include "snake.h"
#include "move.h"
#include "food.h"

#define SNAKE_CHAR "O"
#define SNAKE_HEAD "@"
#define FOOD_CHAR "X"

Screen* new_screen() {
    Screen* screen = malloc(sizeof(Screen));
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, 1);  // Enables the arrow keys, among others
    nodelay(stdscr, 1); // No blocking
    cbreak();           // Do not require EOF or \n before providing input

    int x, y;
    getmaxyx(stdscr, y, x);
    screen->max_x = x;
    screen->max_y = y;

    return screen;
}

void close_screen(Screen* screen) {
    free(screen);
    endwin();       // Close screen
}

Direction get_direction() {
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

void draw_frame(Snake* snake, FoodList* food_list) {
    clear(); // Clear screen
    
    Segment* seg = snake->head;
    while(seg != NULL) {
        mvprintw(seg->y_pos, seg->x_pos, 
                 seg == snake->head ? SNAKE_HEAD : SNAKE_CHAR);
        seg = seg->next;
    }
    
    FoodItem* fi = food_list->first;
    while(fi != NULL) {
        mvprintw(fi->y_pos, fi->x_pos, FOOD_CHAR);
        fi = fi->next;
    }

    refresh(); // Refresh screen
}
