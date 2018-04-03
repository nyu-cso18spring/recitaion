#include <stdio.h>
#include <string.h>

void HACK(void) {
    printf("Our democracy has been hacked!\n");
}

int convert(char *str) {
    int res = 0;
    int total = strlen(str);
    for(int i = 0; i < total; i++) {
        res = res * 10 + (int)(str[i] - '0');
    }
    return res; 
}

void copy(int *dest, char *str) {
    *dest = convert(str);
}

void buggy(char* strs[], int n) {
    int buf[1];
    for(int i = 1; i < n; i++) {
        copy(&buf[i - 1], strs[i]);
    } 
    printf("%d\n", buf[0]);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("you need to pass at lease one parameter\n");
        return 1;
    }
    buggy(argv, argc);
    return 1; 
}
