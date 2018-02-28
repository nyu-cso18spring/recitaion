#include <stdio.h>

int func1(int v) {
    return v + 7;
}

int func2(int v) {
    return v + 5;
}

int func3(int v) {
    return v + 9;
}

int func4(int v) {
    return v + 3;
}

int main(int argc, char **argv) 
{
    int (*array[])(int) = {func1, func2, func3, func4, func5};

    /* FIXME: Please replace following '0's inside the () with some other
     *        values so that The final printf will print out 1.
     */
    int a = (array[0](0) == 12);
    int b = (array[1](0) == 12);
    int c = (array[2](0) == 15);
    int d = (array[3](0) == 10);

    // Do not modify this line.
    printf("%d\n", a * b * c * d);
}
