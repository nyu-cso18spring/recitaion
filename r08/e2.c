#include <stdio.h>
#include <stdlib.h>

// FIXME: Can you modify this struct to make this program more cache-friendly?
//        You are NOT allowed to modify the type of each field.
struct test {
    char a;
    unsigned long b;
    char c;
    unsigned long d;
    char f;
    unsigned long g;
    char h;
};

#define NUM (100000)
int main(int argc, char** argv)
{
    struct test buf[NUM];
    for (int j = 0; j < 4096; j++) {
        for (int i = 0; i < NUM; i++) {
            buf[i].a = 'a';
            buf[i].b = 1;
            buf[i].c = 'b';
            buf[i].d = 2;
            buf[i].f = 'c';
            buf[i].g = 3;
            buf[i].h = 'd';
        }
    }
    printf("%lu\n", sizeof(struct test));  
}
