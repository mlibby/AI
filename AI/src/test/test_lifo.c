#include "test.h"
#include "ai_common.h"
#include "lifo.h"
#include "test_lifo.h"

void test_lifo_new()
{
	lifo *lifo = lifo_new();
	ASSERT(lifo != NULL);
	lifo_free(lifo);
}

void test_lifo_add_one()
{
	lifo *lifo = lifo_new();
	char *test = "Test";
	lifo_add(lifo, test);
	ASSERT(lifo->head != NULL);
	ASSERT(lifo_has_items(lifo) == TRUE);
	lifo_free(lifo);
}

void test_lifo_add_many()
{
	lifo *lifo = lifo_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	lifo_add(lifo, one);
	lifo_add(lifo, two);
	lifo_add(lifo, three);

	int item_count = 0;
	lifo_item *item = lifo->head;
	while (item != NULL) {
		item = item->next;
		item_count++;
	}

	ASSERT(3 == item_count);

	lifo_free(lifo);
}

void test_lifo_remove()
{
	lifo *lifo = lifo_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	lifo_add(lifo, one);
	lifo_add(lifo, two);
	lifo_add(lifo, three);

	char *test_one = lifo_remove(lifo);
	ASSERT(strcmp(test_one, three) == 0);

	char *test_two = lifo_remove(lifo);
	ASSERT(strcmp(test_two, two) == 0);

	char *test_three = lifo_remove(lifo);
	ASSERT(strcmp(test_three, one) == 0);

	ASSERT(lifo_has_items(lifo) == FALSE);

	lifo_free(lifo);
}

void test_lifo_has_items_false_when_empty()
{
	lifo *lifo = lifo_new();
	ASSERT(lifo_has_items(lifo) == FALSE);
	lifo_free(lifo);
}

void test_lifo_all()
{
	test_lifo_new();
	test_lifo_add_one();
	test_lifo_add_many();
	test_lifo_remove();
	test_lifo_has_items_false_when_empty();
}