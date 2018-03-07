#include "test.h"
#include "ai_common.h"
#include "fifo.h"
#include "test_fifo.h"

void test_fifo_new()
{
	fifo *fifo = fifo_new();
	ASSERT(fifo != NULL);
	fifo_free(fifo);
}

void test_fifo_add_one()
{
	fifo *fifo = fifo_new();
	char *test = "Test";
	fifo_add(fifo, test);
	ASSERT(fifo->head != NULL);
	ASSERT(fifo_has_items(fifo) == TRUE);
	fifo_free(fifo);
}

void test_fifo_add_many()
{
	fifo *fifo = fifo_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	fifo_add(fifo, one);
	fifo_add(fifo, two);
	fifo_add(fifo, three);

	int item_count = 0;
	fifo_item *item = fifo->head;
	while (item != NULL) {
		item = item->next;
		item_count++;
	}

	ASSERT(3 == item_count);

	fifo_free(fifo);
}

void test_fifo_remove()
{
	fifo *fifo = fifo_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	fifo_add(fifo, one);
	fifo_add(fifo, two);
	fifo_add(fifo, three);

	char *test_one = fifo_remove(fifo);
	ASSERT(strcmp(test_one, one) == 0);

	char *test_two = fifo_remove(fifo);
	ASSERT(strcmp(test_two, two) == 0);

	char *test_three = fifo_remove(fifo);
	ASSERT(strcmp(test_three, three) == 0);

	ASSERT(fifo_has_items(fifo) == FALSE);

	fifo_free(fifo);
}

void test_fifo_has_items_false_when_empty()
{
	fifo *fifo = fifo_new();
	ASSERT(fifo_has_items(fifo) == FALSE);
	fifo_free(fifo);
}

void test_fifo_add_remove_add()
{
	char *foo = "FOO";
	fifo *fifo = fifo_new();
	fifo_add(fifo, foo);

	char *oof = fifo_remove(fifo);
	ASSERT(0 == strcmp(foo, oof));
	ASSERT(NULL == fifo->head);
	ASSERT(NULL == fifo->tail);

	char *bar = "BAR";
	fifo_add(fifo, bar);
	char *rab = fifo_remove(fifo);
	ASSERT(0 == strcmp(bar, rab));
	ASSERT(NULL == fifo->head);
	ASSERT(NULL == fifo->tail);

	fifo_free(fifo);
}

void test_fifo_all()
{
	test_fifo_new();
	test_fifo_add_one();
	test_fifo_add_many();
	test_fifo_add_remove_add();
	test_fifo_remove();
	test_fifo_has_items_false_when_empty();
}