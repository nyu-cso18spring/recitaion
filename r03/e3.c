#include <stdio.h>
#include <stdlib.h>

// There is a bug in this program, it should be easy to find.
// But do you know why it is a bug?

int orig_func(int v)
{
    return v + 4;
}

int main(int argc, char **argv)
{
    int (*func)(int);

    // Do not modify this line.
    printf("%d\n", func(1));
}
