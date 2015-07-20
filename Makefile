all: snake

snake: main.o snake.o move.o snakeio.o collision.o food.o
	gcc -o snake main.o snake.o move.o snakeio.o collision.o food.o -lncurses

snake.o:
	gcc -c snake.c

move.o:
	gcc -c move.c

snakeio.o:
	gcc -c snakeio.c

collision.o:
	gcc -c collision.c

food.o:
	gcc -c food.c

clean:
	rm snake *.o
