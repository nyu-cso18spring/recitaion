#include <stdio.h>
#include <unistd.h>

int a = 0;

void  main() { 
    pid_t pid = fork(); 
    if (pid == 0) { 
        a += 10;
        printf("%d\n", a); 
    } else { 
        a += 5;
        printf("%d\n", a); 
    } 
}
