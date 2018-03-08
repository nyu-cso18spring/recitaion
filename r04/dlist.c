#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

// Prepend a value in front of the double list.
int dlist_prepend(struct dlist** headp, struct dlist** endp, int value) {
   
    struct dlist* NewNode = (struct dlist*) malloc(sizeof(struct dlist));

    NewNode->value  = value;//create and set the value of the newnode
 
    if (*headp == NULL)//if the linked list is empty
    {
        NewNode->prev = NULL;//newNode is then the only node
        NewNode->next = NULL;
        return 0;;
    }
    NewNode->next=headp;//else set the NewNode next to head
    headp->prev=NewNode;
    NewNode->prev=NULL;

    return 0;
}

// Append a value in the end of the double list.
int dlist_append(struct dlist** headp, struct dlist** endp, int value) {
      struct dlist* NewNode = (struct dlist*) malloc(sizeof(struct dlist));

    NewNode->value  = value;//create and set the value of new node
    
    if (*endp == NULL)//if there is no end, NewNode is the first value in the linked list
    {
        NewNode->prev = NULL;
        NewNode->next = NULL;
        return;
    }
    NewNode->prev=endp;//set the pointers
    endp->next=NewNode;
    NewNode->next=NULL;

    return;
}

#if 0
// To test your implementation, change #if 0 to #if 1.
// And use this main to debug.
// Before submitting, remember to change #if 1 back to #if 0. Otherwise,
// you'll get 0 credit.
int main(int argc, char **argv)
{
    // Your own tests.
}
#endif
