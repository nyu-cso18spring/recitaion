#ifndef __DLIST_H__
#define __DLIST_H__
struct dlist {
    int value;
    struct dlist *prev;
    struct dlist *next;
};
#endif
