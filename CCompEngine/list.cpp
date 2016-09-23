#include "list.h"

void list_init(List *v)
{
	v->capacity = LIST_INIT_CAPACITY;
	v->total = 0;

	// Casted to void**, confirm operation
	v->items = (void**)malloc(sizeof(void *) * v->capacity);
}

int list_total(List *v)
{
	return v->total;
}

static void list_resize(List *v, int capacity)
{
#ifdef DEBUG_ON
	printf("list_resize: %d to %d\n", v->capacity, capacity);
#endif

	// Casted to void**, confirm operation
	void **items = (void**)realloc(v->items, sizeof(void *) * capacity);
	if (items) {
		v->items = items;
		v->capacity = capacity;
	}
}

void list_add(List *v, void *item)
{
	if (v->capacity == v->total)
		list_resize(v, v->capacity * 2);
	v->items[v->total++] = item;
}

void list_set(List *v, int index, void *item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void *list_get(List *v, int index)
{
	if (index >= 0 && index < v->total)
		return v->items[index];
	return NULL;
}

void list_delete(List *v, int index)
{
	if (index < 0 || index >= v->total)
		return;

	v->items[index] = NULL;

	for (int i = 0; i < v->total - 1; i++) {
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
	}

	v->total--;

	if (v->total > 0 && v->total == v->capacity / 4)
		list_resize(v, v->capacity / 2);
}

void list_free(List *v)
{
	free(v->items);
}