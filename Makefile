all: snake

snake: main.o snake.o move.o snakeio.o
	gcc -o snake main.o snake.o move.o snakeio.o -lncurses

snake.o:
	gcc -c snake.c

move.o:
	gcc -c move.c

snakeio.o:
	gcc -c snakeio.c

clean:
	rm *.o
