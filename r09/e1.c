#include<stdio.h>

void questions()
{
    unsigned answer = 0;
    // Q1: What's the main difference between multiprocessing and multithreading?
    // 1) No differences.
    // 2) Different processes must run on different CPU cores while a thread can
    //    run on an arbitrary core, even if some thread is already running on
    //    that core.
    // 3) Different processes have different memory spaces while threads which
    //    belong to the same process share the same memory space.
    // 4) A process can execute an entire program while a thread can only
    //    execute a function in a program.
    answer = 0;
    printf("Q1: %u\n", answer);

    // Read proc.c before answering Q2 and Q3.
    // Q2: Which of the following statements is correct?
    // 1) There will be two processes created. One is the process which calls
    //    fork() another is the one created by the fork().
    // 2) There will be one process created.
    // 3) There will be two threads created. One is the thread which calls
    //    fork() another is the one created by the fork().
    // 4) There will be one process and one thread created.
    answer = 0;
    printf("Q2: %u\n", answer);

    // Q3: Which of the following statements is correct?
    // 1) There will be only one output. It can be either 5 or 10.
    // 2) There will be two outputs, one is 5 and another is 10.
    // 3) There will be two outputs, one is 5 and another is 15.
    // 4) There will be two outputs, one is 10 and another is 15.
    answer = 0;
    printf("Q3: %u\n", answer);

    // Read fib.c before answering Q4.
    // Q4: Is there any benefit if we use pthread to parallelize
    // fibnoacci_partial()?
    // 1) Yes, because threads can compute different Fibonacci numbers simultaneously.
    // 2) Yes, because threads can cooperate to do fibonacci_partial().
    // 3) No, because each Fibonacci number depends on the previous one.
    // 4) No, because threads will compete memory resource with each other.
    // 5) None of above.
    answer = 0;
    printf("Q4: %u\n", answer);
}

int main(int argc, char** argv)
{
    questions();
}
