all: e1 e2 race simple
	@echo "Done"

e1: e1.c
	gcc e1.c -o e1 -lpthread

e2: e2.c
	gcc e2.c -o e2 -lpthread

race: race.c
	gcc race.c -o race -lpthread

simple: simple.c
	gcc simple.c -o simple -lpthread

clean:
	rm e1 e2 race
