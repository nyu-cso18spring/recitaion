#include <stdio.h>
#include <stdlib.h>

// TODO: Complete this API. The argument is a string and the return value is
//       the length of the string.
int cso_strlen(char *str) {
    int LengthOfStr = 0;//create a counter for the length
    while(str[LengthOfStr]!='\0');//if the current place in the string isn't /0 it means we aren't at the end of the string
    {
        LengthOfStr++;//increase the counter by one and repeat
        
    }
    //printf("%i", LengthOfStr); just to check if everything was working
    return LengthOfStr;//when we come to the end of the string exit the while loop and return the length counter
    
}

#if 0
// To test your implementation, change #if 0 to #if 1.
// And use this main to debug.
// Before submitting, remember to change #if 1 back to #if 0. Otherwise,
// you'll get 0 credit.
int main(int argc, char **argv)
{
    // Your own tests.
    //tested everything on the online C complier
}
#endif
