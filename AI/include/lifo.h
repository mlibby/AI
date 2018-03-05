#ifndef _LIFO_H
#define _LIFO_H

typedef struct _lifo_item lifo_item;
struct _lifo_item {
	lifo_item *next;
	void *data;
};

typedef struct _lifo lifo;
struct _lifo {
	lifo_item *head;
};

lifo *lifo_new();
void lifo_free(lifo *this);

int lifo_has_items(lifo *this);
void lifo_add(lifo *this, void *data);
void *lifo_remove(lifo *this);

#endif /* _lifo_H */