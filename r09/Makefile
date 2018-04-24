all: e1 e2 e3
	@echo "Done"

e1: e1.c
	gcc e1.c -o e1 -lpthread

e2: e2.c
	gcc e2.c -o e2 -lpthread

e3: e3.c
	gcc e3.c -o e3 -lpthread

clean:
	rm -f a.out e1 e2 e3
