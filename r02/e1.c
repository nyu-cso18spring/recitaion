#include <stdio.h>

void func1(unsigned *num) {
    *num = *num / 2;
}

void func2(unsigned num) {
    num = num / 4;
}

void func3_pre(unsigned *num) {
    num = num - 1;
}

void func3(unsigned num) {
    func3_pre(&num);
}

void func4_pre(unsigned *num) {
    *num = *num - 1;
}

void func4(unsigned *num) {
    func4_pre(num);
}

void func5_pre(unsigned num) {
    num = num - 2;
}

void func5(unsigned *num) {
    func5_pre(*num);
}

void func6(unsigned *num) {
    *num = *num / 3;
}

void func7(unsigned num) {
    num = num / 7;
}

int main(int argc, char **argv) {
    // FIXME: 7193 is not the correct number to print 3360153 in the end.
    unsigned int answer = 7193;

    // DO NOT modify following lines.
    func1(&answer);
    func2(answer);
    func3(answer);
    func4(&answer);
    func5(&answer);
    func6(&answer);
    func7(answer);

    printf("%u\n", answer);
}
