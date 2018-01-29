foo : foo.o main.o
	gcc $^ -o $@

%.o: %.c
	gcc -c $^

clean :
	rm foo.o main.o foo
