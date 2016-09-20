#ifndef LIST_H
#define LIST_H

#define LIST_INIT_CAPACITY 4

#define LIST_INIT(vec) list vec; list_init(&vec)
#define LIST_ADD(vec, item) list_add(&vec, (void *) item)
#define LIST_SET(vec, id, item) list_set(&vec, id, (void *) item)
#define LIST_GET(vec, type, id) (type) list_get(&vec, id)
#define LIST_DELETE(vec, id) list_delete(&vec, id)
#define LIST_TOTAL(vec) list_total(&vec)
#define LIST_FREE(vec) list_free(&vec)

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	void **items;
	int capacity;
	int total;
} List;

void list_init(List *);
int list_total(List *);
static void list_resize(List *, int);
void list_add(List *, void *);
void list_set(List *, int, void *);
void *list_get(List *, int);
void list_delete(List *, int);
void list_free(List *);

#endif