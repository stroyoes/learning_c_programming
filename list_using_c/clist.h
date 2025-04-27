#ifndef CLIST_H
#define CLIST_H

#include <stdbool.h>

#define CLIST_RETURN_NOTHING void
#define CLIST_UNBOUND_INDEX -1

typedef struct {
  int *buffer;
  int size;
  int capacity;
} clist_t;

clist_t* create_clist();
CLIST_RETURN_NOTHING append(clist_t *clist, int value);
int get(clist_t *clist, int index);
int contains(clist_t *clist, int value);
int count(clist_t *clist, int value);
CLIST_RETURN_NOTHING remove_elem(clist_t *clist, int value);
clist_t* slice(clist_t *clist, int start, int end);
clist_t* reversed(clist_t *clist);
clist_t* concat(int num_of_clists, clist_t **clists);
clist_t* map(clist_t *clist, int (*func)(int));
clist_t* filter(clist_t *clist, int (*predicate)(int));
int length(clist_t *clist);
CLIST_RETURN_NOTHING destroy_list(clist_t *clist);

#endif



