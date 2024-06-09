#pragma once
#pragma warning(disable : 4996)

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "GLOBAL.h"
#include "NodeData.h"
#include "Node.h"
#include "Filter.h"
#include "Sorter.h"

struct LinkedList
{
	size_t length;
	struct Node *head;
	struct Node *tail;

	void (*PrintAllNodeInConsole)(const struct LinkedList *self);

	struct Node *(*GetNodeWithIndex)(struct LinkedList *self, size_t index);
	struct Node *(*GetFirstNode)(struct LinkedList *self);
	struct Node *(*GetLastNode)(struct LinkedList *self);

	void (*PushFrontNode)(struct LinkedList *self, struct Node *node);
	void (*PushBackNode)(struct LinkedList *self, struct Node *node);
	void (*InsertNodeAtIndex)(struct LinkedList* self, struct Node* node, size_t index);

	void (*RemoveFirstNode)(struct LinkedList *self);
	void (*RemoveLastNode)(struct LinkedList *self);
	void (*RemoveNodeAtIndex)(struct LinkedList *self, size_t index);
	void (*RemoveNode)(struct LinkedList *self, struct Node *node);
};

extern const size_t LINKED_LIST_SIZE;

void _LinkedList_PrintAllNodeInConsole(const struct LinkedList *self);

struct Node *_LinkedList_GetNodeWithIndex(struct LinkedList *self, size_t index);

struct Node *_LinkedList_GetFirstNode(struct LinkedList *self);

struct Node *_LinkedList_GetLastNode(struct LinkedList *self);

void _LinkedList_PushFrontNode(struct LinkedList *self, struct Node *node);

void _LinkedList_PushBackNode(struct LinkedList *self, struct Node *node);

void _LinkedList_InsertNodeAtIndex(struct LinkedList *self, struct Node *node, size_t index);

void _LinkedList_RemoveFirstNode(struct LinkedList *self);

void _LinkedList_RemoveLastNode(struct LinkedList *self);

void _LinkedList_RemoveNodeAtIndex(struct LinkedList *self, size_t index);

void _LinkedList_RemoveNode(struct LinkedList *self, struct Node *node);

struct LinkedList *LinkedListConstructor(void);

void LinkedListDestructor(struct LinkedList *list);
