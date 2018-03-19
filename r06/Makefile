CFLAGS= -c -Og -g -std=gnu99

objects = e1_sol e2_sol e3_sol e4_sol e1_tester e2_tester e3_tester e4_tester

%.o : %.c
	gcc $(CFLAGS) $*.c

all: ${objects}

e1_sol: objs/e1_sol.o objs/e1_tester.o
	gcc $^ -o $@

e2_sol: objs/e2_sol.o objs/e2_tester.o
	gcc $^ -o $@

e3_sol: objs/e3_sol.o objs/e3_tester.o
	gcc $^ -o $@

e4_sol: objs/e4_sol.o objs/e4_tester.o
	gcc $^ -o $@

e1_tester: e1.o objs/e1_tester.o
	gcc $^ -o $@

e2_tester: e2.o objs/e2_tester.o
	gcc $^ -o $@

e3_tester: e3.o objs/e3_tester.o
	gcc $^ -o $@

e4_tester: e4.o objs/e4_tester.o
	gcc $^ -o $@

clean:
	rm -f ${objects} *.o
