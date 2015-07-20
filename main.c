#include "move.h"
#include "snake.h"
#include "snakeio.h"
#include "collision.h"
#include "food.h"

#include <unistd.h>
#include <time.h>

#define SLEEP_TIME 100000000
#define FOOD_COUNT 2

MoveList* move_list;
Snake* snake;
Screen* screen;
FoodList* food_list;

void init() {
    screen = new_screen();

    int x_pos = screen->max_x/2;
    int y_pos = screen->max_y/2;
    snake = new_snake(x_pos, y_pos);

    move_list = new_move_list();

    int i;
    food_list = new_food_list();
    for(i = 0; i < FOOD_COUNT; i++) {
        add_food(screen->max_x, screen->max_y, food_list);
    }
}

void end_game() {
    close_screen(screen);
    delete_snake(snake);
    delete_move_list(move_list);
}

void snake_sleep() {
    struct timespec sleep_time = (struct timespec) {.tv_sec = 0, .tv_nsec = SLEEP_TIME};
    struct timespec remaining;
    nanosleep(&sleep_time, &remaining);
}

void grow_snake() {
    add_segment(snake);
}

void new_food() {
    int i = food_list->length;

    if (i > ((screen->max_x / 2) * screen->max_y)) {
        i = 1;
    }

    for (; i > 0; i--) {
        add_food(screen->max_x, screen->max_y, food_list);
    }
}

int tick() {
    // Handle user input
    Direction in = get_direction();
    if (in != NO_DIRECTION) {
        push_move(move_list, in);
    }
    
    // Handle snake movement
    update_direction(snake, move_list);
    move_snake(snake);

    // Draw everything
    draw_frame(snake, food_list);

    Collision collision = find_collision(snake, food_list, screen);
    switch(collision){
        case SNAKE:
        case SCREEN:
            return 0;
        
        case FOOD:
            grow_snake();
            new_food();
            break;

        case NONE:
            break;
    }
    
    snake_sleep();
    return 1;
}

int main() {
    init();

    while(tick())
        ;

    end_game();
    return 0;
}

