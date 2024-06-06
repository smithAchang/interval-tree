#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "itree.h"


#define NELEMENTS(arr) (sizeof(arr) / sizeof(arr[0]))

typedef itree_t itree;
typedef itreetrav_t itreetrav;


/* clone an integer */
void *clone(void *p)
{
	int *c = (int *)malloc(sizeof(int));

	*c = *(int *)p;

	return c;
}

/* destroy an integer */
void destroy(void *p)
{
	free(p);
}

interval_t *make_interval(int low, int high, int data)
{
	interval_t *i = (interval_t *)malloc(sizeof(interval_t));

	if (i == NULL)
		return 0;

	i->low = low;
	i->high = high;
	i->data = (int *)malloc(sizeof(int));
	*((int *)i->data) = data;

	return i;
}

void print_interval(interval_t *i)
{
	printf("[%.1f, %.1f] (%d)\n", i->low, i->high, *(int *)i->data);
}

void destroy_interval(interval_t *i)
{
	free(i->data);
	free(i);
}

static void insertion_sequnece_test(interval_t *ints[], const size_t counts, const char *szCase)
{
	printf("\nSpecial sequncee for insertion of %s case \n\n", szCase);

	itree *t = itree_new(clone, destroy);

	for (size_t i = 0; i < counts; ++i) {
		int rc = itree_insert(t, ints[i]);
		assert(rc > 0);

		printf("Inserting [%.1f, %.1f] at sequnece[%zu]\n",
			   ints[i]->low, ints[i]->high, i);

		interval_t *find = itree_find(t, ints[i]);
		assert(find != NULL);
		assert(find->low == ints[i]->low);
		assert(find->high == ints[i]->high);
	}

	for (size_t i = 0; i < counts; ++i) {
		int rc = itree_remove(t, ints[i]);
		assert(rc > 0);

		printf("Query deleted interval after removal of [%.1f, %.1f] at sequnece[%zu]\n",
			   ints[i]->low, ints[i]->high, i);

		interval_t *find = itree_find(t, ints[i]);
		assert(find == NULL);

		for (size_t j = i + 1; j < counts; ++j) {
			printf("Query lefted interval [%.1f, %.1f] after removal of [%.1f, %.1f] at sequnece[%zu]\n",
				   ints[j]->low, ints[j]->high,
				   ints[i]->low, ints[i]->high, i);

			find = itree_find(t, ints[j]);
			assert(find != NULL);
			assert(find->low == ints[j]->low);
			assert(find->high == ints[j]->high);
		}
	}

	itree_delete(t);
}


static void classic_sequnece_test()
{
	printf("\nClassic sequncee for insertion from data struct book\n\n");

	itree *t = itree_new(clone, destroy);
	interval_t *ints[] = { make_interval(13, 13, 13),
						   make_interval(24, 24, 24),
						   make_interval(37, 37, 37),
						   make_interval(90, 90, 90),
						   make_interval(53, 53, 53) };


	insertion_sequnece_test(ints, NELEMENTS(ints), __func__);


	for (size_t i = 0; i < NELEMENTS(ints); ++i)
		destroy_interval(ints[i]);
}

static void classic_increasing_sequnece_test()
{
	printf("\nIncreasing sequncee for insertion from data struct book\n\n");

	itree *t = itree_new(clone, destroy);
	interval_t *ints[] = { make_interval(13, 13, 13),
						   make_interval(24, 24, 24),
						   make_interval(37, 37, 37),
						   make_interval(53, 53, 53),
						   make_interval(90, 90, 90) };


	insertion_sequnece_test(ints, NELEMENTS(ints), __func__);


	for (size_t i = 0; i < NELEMENTS(ints); ++i)
		destroy_interval(ints[i]);
}

static void classic_decreasing_sequnece_test()
{
	printf("\nIncreasing sequncee for insertion from data struct book\n\n");

	itree *t = itree_new(clone, destroy);
	interval_t *ints[] = { make_interval(90, 90, 90),
						   make_interval(53, 53, 53),
						   make_interval(37, 37, 37),
						   make_interval(24, 24, 24),
						   make_interval(13, 13, 13) };


	insertion_sequnece_test(ints, NELEMENTS(ints), __func__);


	for (size_t i = 0; i < NELEMENTS(ints); ++i)
		destroy_interval(ints[i]);
}



int main()
{
	itree *t = itree_new(clone, destroy);
	interval_t *ints[] = { make_interval(15, 20, 10),
						   make_interval(10, 30, 20),
						   make_interval(17, 19, 30),
						   make_interval(5,	 20, 40),
						   make_interval(12, 15, 50),
						   make_interval(30, 40, 25) };

	size_t i;

	for (i = 0; i < NELEMENTS(ints); ++i)
		printf("Inserting [%.1f, %.1f] (%d) - %s\n",
			   ints[i]->low, ints[i]->high, *(int *)ints[i]->data, itree_insert(t, ints[i]) ? "OK" : "KO");

	printf("\nTree size: %zu\n\n", itree_size(t));

	itreetrav *trav = itreetrav_new();
	interval_t *item;
	for (item = itreetrav_first(trav, t); item != NULL; item = itreetrav_next(trav))
		//print_interval(item);
		printf("\n");

	interval_t *query = make_interval(6, 7, 0);
	printf("Query: [%.1f, %.1f]\n", query->low, query->high);
	interval_t *result = itree_find(t, query);
	if (result == NULL)
		printf("No overlapping interval\n\n");
	else
		printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high);

	query->low = 1;
	query->high = 4;
	printf("Query: [%.1f, %.1f]\n", query->low, query->high);
	result = itree_find(t, query);
	if (result == NULL)
		printf("No overlapping interval\n\n");
	else
		printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high);

	query->low = 18;
	query->high = 25;
	printf("Query: [%.1f, %.1f]\n", query->low, query->high);
	result = itree_find(t, query);
	if (result == NULL)
		printf("No overlapping interval\n\n");
	else
		printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high);

	printf("Deleting interval [30, 40] - ");
	itree_remove(t, ints[5]) ? printf("OK\n") : printf("KO\n");

	/* printf("Tree size: %zu\n", itree_size(t)); */

	/* result = (int*)itree_find(t, &query); */
	/* printf("Query: %d -- Found: %d\n", query, result == NULL?0:1); */

	/* query = 18; */
	/* result = (int*)itree_find(t, &query); */
	/* printf("Query: %d -- Found: %d\n", query, result == NULL?0:1); */

	for (item = itreetrav_first(trav, t); item != NULL; item = itreetrav_next(trav))
		//print_interval(item);
		printf("\n");

	/* printf("First: %d\n", *(int*)jsw_avltfirst(trav, t)); */
	/* printf("Last: %d\n", *(int*)jsw_avltlast(trav, t)); */

	itreetrav_delete(trav);
	itree_delete(t);

	for (i = 0; i < NELEMENTS(ints); ++i)
		destroy_interval(ints[i]);

	destroy_interval(query);

	printf("\nTest using classic sequnece for insertion\n\n");
	classic_sequnece_test();
	classic_increasing_sequnece_test();
	classic_decreasing_sequnece_test();
}
