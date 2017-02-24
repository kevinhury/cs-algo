#ifndef arraylist_h
#define arraylist_h

#include <stdio.h>
#include <stdlib.h>

typedef struct arraylist {
    void **data;
    size_t capacity;
    size_t size;
} arraylist;

arraylist *arraylist_create();
void arraylist_destroy(arraylist **list);

int arraylist_add(arraylist *list, void *element);
int arraylist_remove(arraylist *list, size_t index);
void *arraylist_get(arraylist *list, size_t index);

#endif /* arraylist_h */
