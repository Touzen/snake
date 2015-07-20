#include "move.h"
#include "snake.h"
#include "snakeio.h"
#include "collision.h"

#include <unistd.h>
#include <time.h>

#define SLEEP_TIME 100000000

MoveList* move_list;
Snake* snake;
Screen* screen;

void init() {
    screen = new_screen();

    int x_pos = screen->max_x/2;
    int y_pos = screen->max_y/2;

    snake = new_snake(x_pos, y_pos);
    move_list = new_move_list();
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
    draw_frame(snake, screen);

    Collision collision = find_collision(snake, screen);
    switch(collision){
        case SNAKE:
        case SCREEN:
            return 0;

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

