#include "test.h"
#include "ai_common.h"
#include "queue.h"
#include "test_queue.h"

void test_queue_new()
{
	queue *queue = queue_new();
	ASSERT(queue != NULL);
	queue_free(queue);
}

void test_queue_add_one()
{
	queue *queue = queue_new();
	char *test = "Test";
	queue_add(queue, test);
	ASSERT(queue->head != NULL);
	ASSERT(queue_has_items(queue) == TRUE);
	queue_free(queue);
}

void test_queue_add_many()
{
	queue *queue = queue_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	queue_add(queue, one);
	queue_add(queue, two);
	queue_add(queue, three);

	int item_count = 0;
	queue_item *item = queue->head;
	while (item != NULL) {
		item = item->next;
		item_count++;
	}

	ASSERT(3 == item_count);

	queue_free(queue);
}

void test_queue_remove()
{
	queue *queue = queue_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	queue_add(queue, one);
	queue_add(queue, two);
	queue_add(queue, three);

	char *test_one = queue_remove(queue);
	ASSERT(strcmp(test_one, one) == 0);

	char *test_two = queue_remove(queue);
	ASSERT(strcmp(test_two, two) == 0);

	char *test_three = queue_remove(queue);
	ASSERT(strcmp(test_three, three) == 0);

	ASSERT(queue_has_items(queue) == FALSE);

	queue_free(queue);
}

void test_queue_has_items_false_when_empty()
{
	queue *queue = queue_new();
	ASSERT(queue_has_items(queue) == FALSE);
	queue_free(queue);
}

void test_queue_add_remove_add()
{
	char *foo = "FOO";
	queue *queue = queue_new();
	queue_add(queue, foo);

	char *oof = queue_remove(queue);
	ASSERT(0 == strcmp(foo, oof));
	ASSERT(NULL == queue->head);
	ASSERT(NULL == queue->tail);

	char *bar = "BAR";
	queue_add(queue, bar);
	char *rab = queue_remove(queue);
	ASSERT(0 == strcmp(bar, rab));
	ASSERT(NULL == queue->head);
	ASSERT(NULL == queue->tail);

	queue_free(queue);
}

void test_stack_remove()
{
	queue *lifo = stack_new();

	char *one = "Test One";
	char *two = "Test Two";
	char *three = "Test Three";

	queue_add(lifo, one);
	queue_add(lifo, two);
	queue_add(lifo, three);

	char *test_one = queue_remove(lifo);
	ASSERT(strcmp(test_one, three) == 0);

	char *test_two = queue_remove(lifo);
	ASSERT(strcmp(test_two, two) == 0);

	char *test_three = queue_remove(lifo);
	ASSERT(strcmp(test_three, one) == 0);

	ASSERT(queue_has_items(lifo) == FALSE);

	queue_free(lifo);
}

void test_queue_all()
{
	test_queue_new();
	test_queue_add_one();
	test_queue_add_many();
	test_queue_add_remove_add();
	test_queue_remove();
	test_queue_has_items_false_when_empty();
	test_stack_remove();
}