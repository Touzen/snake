#include <ncurses.h>

#include "snakeio.h"
#include "snake.h"
#include "move.h"
#include "food.h"

#define SNAKE_SEG "O"
#define SNAKE_HEAD "@"
#define FOOD_PIECE "X"

#define SNAKE_SEG_COLOR     1
#define SNAKE_HEAD_COLOR    2
#define FOOD_PIECE_COLOR    3

Screen* new_screen() {
    Screen* screen = malloc(sizeof(Screen));
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, 1);  // Enables the arrow keys, among others
    nodelay(stdscr, 1); // No blocking
    cbreak();           // Do not require EOF or \n before providing input

    start_color();
    init_pair(SNAKE_SEG_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(SNAKE_HEAD_COLOR, COLOR_RED, COLOR_BLACK);
    init_pair(FOOD_PIECE_COLOR, COLOR_CYAN, COLOR_BLACK);

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
    
    attron(COLOR_PAIR(SNAKE_HEAD_COLOR));
    mvprintw(snake->head->y_pos, snake->head->x_pos, SNAKE_HEAD);
    attroff(COLOR_PAIR(SNAKE_HEAD_COLOR));

    Segment* seg = snake->head->next;
    attron(COLOR_PAIR(SNAKE_SEG_COLOR));
    while(seg != NULL) {
        mvprintw(seg->y_pos, seg->x_pos, SNAKE_SEG);

        seg = seg->next;
    }
    attroff(COLOR_PAIR(SNAKE_SEG_COLOR));
    
    FoodItem* fi = food_list->first;
    attron(COLOR_PAIR(FOOD_PIECE_COLOR));
    while(fi != NULL) {
        mvprintw(fi->y_pos, fi->x_pos, FOOD_PIECE);
        fi = fi->next;
    }
    attroff(COLOR_PAIR(FOOD_PIECE_COLOR));

    refresh(); // Refresh screen
}
