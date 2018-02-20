C_FLAGS := -Wall -Wextra -g

filter: bloom_filter.o main.o
	gcc $(C_FLAGS) -o $@ $^

bloom_filter.o: bloom_filter.c bloom_filter.h
	gcc $(C_FLAGS) -c bloom_filter.c

main.o: main.c bloom_filter.h
	gcc $(C_FLAGS) -c main.c

clean :
	rm bloom_filter.o main.o filter
