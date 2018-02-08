#include "interval.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

interval_t* make_interval(int low, int high, int data) {
  interval_t* i = (interval_t *)malloc ( sizeof(interval_t) );

  if(i == NULL)
    return 0;

  i->low = low;
  i->high = high;
  i->data = (int*)malloc(sizeof(int));
  *((int*)i->data) = data;
    
  return i;
}

void print_interval(const interval_t* i) {
  if ( i != NULL )
    printf("[%.1f, %.1f] (%d)\n", i->low, i->high, *(int*)i->data);
}

void destroy_interval(interval_t* i) {
  free(i->data);
  free(i);
}

int main() {
  ilist_t* l = ilist_new();
  assert(1);
  
  interval_t* ints[] = { make_interval(15,20,10),
			 make_interval(10,30,20),
			 make_interval(17,19,30),
			 make_interval(5,20,40),
			 make_interval(12,15,50),
			 make_interval(30,40,25) };

  int i;
  for(i=0; i<6; ++i)
    printf("Appending [%.1f, %.1f] (%d) - %s\n",
	   ints[i]->low,
	   ints[i]->high,
	   *(int*)ints[i]->data,
	   ilist_append(l, ints[i])?"OK":"KO");

  printf("\nList size: %zu\n\n", ilist_size(l));

  ilisttrav_t* trav = ilisttrav_new(l);
  const interval_t* item;
  /* for(item = ilisttrav_first(trav); item!=NULL; item=ilisttrav_next(trav)) */
  /*   print_interval(item); */
  /* printf("\n"); */

  for(item = ilisttrav_last(trav); item!=NULL; item=ilisttrav_prev(trav))
    print_interval(item);
  printf("\n");

  
  /* interval_t* query = make_interval(6,7,0); */
  /* printf("Query: [%.1f, %.1f]\n", query->low, query->high); */
  /* interval_t* result = itree_find(t, query); */
  /* if(result == NULL) */
  /*   printf("No overlapping interval\n\n"); */
  /* else  */
  /*   printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high); */

  /* query->low = 1; */
  /* query->high = 4; */
  /* printf("Query: [%.1f, %.1f]\n", query->low, query->high); */
  /* result = itree_find(t, query); */
  /* if(result == NULL) */
  /*   printf("No overlapping interval\n\n"); */
  /* else  */
  /*   printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high); */

  /* query->low = 18; */
  /* query->high = 25; */
  /* printf("Query: [%.1f, %.1f]\n", query->low, query->high); */
  /* result = itree_find(t, query); */
  /* if(result == NULL) */
  /*   printf("No overlapping interval\n\n"); */
  /* else  */
  /*   printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high); */

  /* printf("Deleting interval [30, 40] - "); */
  /* itree_erase(t, ints[5])?printf("OK\n"):printf("KO\n"); */

  /* /\* printf("Tree size: %zu\n", itree_size(t)); *\/ */

  /* /\* result = (int*)itree_find(t, &query); *\/ */
  /* /\* printf("Query: %d -- Found: %d\n", query, result == NULL?0:1); *\/ */
  
  /* /\* query = 18; *\/ */
  /* /\* result = (int*)itree_find(t, &query); *\/ */
  /* /\* printf("Query: %d -- Found: %d\n", query, result == NULL?0:1); *\/ */

  /* for(item = itreetfirst(trav, t); item!=NULL; item=itreetnext(trav)) */
  /*   //print_interval(item); */
  /* printf("\n"); */
  
  /* /\* printf("First: %d\n", *(int*)jsw_avltfirst(trav, t)); *\/ */
  /* /\* printf("Last: %d\n", *(int*)jsw_avltlast(trav, t)); *\/ */

  ilisttrav_delete(trav);
  ilist_delete(l);

  for(i=0; i<6; ++i)
    destroy_interval(ints[i]);

}

