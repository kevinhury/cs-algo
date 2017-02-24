#include "arraylist.h"

#define INITIAL_ARRAYLIST_SIZE 2

arraylist *arraylist_create()
{
    arraylist *list = malloc(sizeof(arraylist));
    if (list == NULL) {
        fprintf(stderr, "Insufficient memory to initialize arraylist.\n");
        return NULL;
    }
    list->capacity = INITIAL_ARRAYLIST_SIZE;
    list->size = 0;
    list->data = calloc(list->capacity, sizeof(void *));
    if (list->data == NULL) {
        free(list);
        return NULL;
    }
    
    return list;
}

void arraylist_destroy(arraylist **list)
{
    free((*list)->data);
    free(*list);
    *list = NULL;
}

int arraylist_add(arraylist *list, void *element)
{
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, sizeof(void *) * list->capacity);
        if (list->data == NULL) {
            fprintf(stderr, "Insufficient memory to resize arraylist.\n");
            return 0;
        }
    }
    
    list->data[list->size++] = element;
    
    return 1;
}

int arraylist_remove(arraylist *list, void *element)
{
    return 1;
}
