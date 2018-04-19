#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

// The definition of a Fibonacci sequence is X_n = X_(n-1) + X_(n-2). Since the
// numbers can be too large to fit in even unsigned long long, this function
// only display the last 10 digits of each Fibonacci number.
void fibonacci_partial(int N)
{
    unsigned long long prev = 1;
    unsigned long long now = 1;
    unsigned long long temp;
    for (int i = 3; i <= N; i++) {
        temp = prev;
        prev = now;
        now = (prev + temp) % 10000000000;
    }
}

int main(int argc, char** argv)
{
    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    fibonacci_partial(100000000);
    gettimeofday(&end, NULL);
    printf("Single core fibonacci_partial takes around %f seconds\n",
           (end.tv_sec - begin.tv_sec + 
            (end.tv_usec - begin.tv_usec) * 1.0 / 1e6));
}
