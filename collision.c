#include "collision.h"

#include <unistd.h>
#include <stdbool.h>

static bool within_screen(Snake* snake, Screen* screen) {
    if (snake->head->x_pos >= screen->max_x || snake->head->y_pos >= screen->max_y
        || snake->head->x_pos < 0 || snake->head->y_pos < 0) {
        return false; // The snake has hit a wall
    } else {
        return true;
    }
}

static bool check_autophagy(Snake* snake) {
    Segment* head = snake->head;
    
    Segment* seg = head->next;
    while(seg != NULL) {
        if (seg->x_pos == head->x_pos && seg->y_pos == head->y_pos) {
            return true;
        }
        seg = seg->next;
    }
    
    return false;
}

static bool check_food(Snake* snake, FoodList* food_list) {
    Segment* head = snake->head;
    
    FoodItem* fi = food_list->first;
    while(fi != NULL) {
        if (fi->x_pos == head->x_pos && fi->y_pos == head->y_pos) {
            return true;
        }
        fi = fi->next;
    }
    
    return false;
}

Collision find_collision(Snake* snake, FoodList* food_list, Screen* screen) {
    if (!within_screen(snake, screen)) {
        return SCREEN;
    }

    if (check_autophagy(snake)) {
        return SNAKE;
    }

    if (check_food(snake, food_list)) {
        return FOOD;
    }

    return NONE;
}
