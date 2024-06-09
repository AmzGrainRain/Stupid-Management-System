#include "LinkedList.h"

const size_t LINKED_LIST_SIZE = sizeof(struct LinkedList);

void _LinkedList_PrintAllNodeInConsole(const struct LinkedList *self)
{
	if (self == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self is NULL.\n");
#endif
		return;
	}

	if (self->length == 0)
		return;

	ClearConsole();
	struct Node *node = self->head;
	while (node != NULL)
	{
		if (node->data == NULL)
			continue;
		PrintNodeDataInConsole(node->data, '\t');
		node = node->next;
	}
	printf("\n");
}

struct Node *_LinkedList_GetNodeWithIndex(struct LinkedList *self, size_t index)
{
	if (self == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self is NULL.\n");
#endif
		return NULL;
	}

	if (index >= self->length)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: INDEX out of range.\n");
#endif
		return NULL;
	}

	if (index == 0)
	{
		return self->head;
	}

	if (index == self->length - 1)
	{
		return self->tail;
	}

	struct Node *target_node = self->head;
	while (--index)
	{
		target_node = target_node->next;
	}

	return target_node;
}

struct Node *_LinkedList_GetFirstNode(struct LinkedList *self)
{
	return self->head;
}

struct Node *_LinkedList_GetLastNode(struct LinkedList *self)
{
	return self->tail;
}

void _LinkedList_PushFrontNode(struct LinkedList *self, struct Node *node)
{
	if (self == NULL || node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self or node is NULL.\n");
#endif
		return;
	}

	node->prev = NULL;

	if (self->head == NULL)
	{
		node->next = NULL;
		self->head = node;
		self->tail = node;
	}
	else
	{
		node->next = self->head;
		self->head->prev = node;
		self->head = node;
	}

	self->length += 1;
}

void _LinkedList_PushBackNode(struct LinkedList *self, struct Node *node)
{
	if (self == NULL || node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self or node is NULL.\n");
#endif
		return;
	}

	node->next = NULL;
	if (self->tail == NULL)
	{
		node->prev = NULL;
		self->head = node;
		self->tail = node;
	}
	else
	{
		self->tail->next = node;
		node->prev = self->tail;
		self->tail = node;
	}

	self->length += 1;
}

void _LinkedList_InsertNodeAtIndex(struct LinkedList *self, struct Node *node, size_t index)
{
	if (self == NULL || node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self or node is NULL.\n");
#endif
		return;
	}

	if (index >= self->length)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: INDEX out of range.\n");
#endif
		return;
	}

	if (index == 0)
	{
		self->PushFrontNode(self, node);
		return;
	}

	if (index == self->length - 1)
	{
		self->PushBackNode(self, node);
		return;
	}

	struct Node *tmp_node = self->head;
	while (--index)
	{
		tmp_node = tmp_node->next;
	}

	struct Node *prev = tmp_node->prev;
	struct Node *next = tmp_node->next;
	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;
	self->length += 1;
}

void _LinkedList_RemoveFirstNode(struct LinkedList *self)
{
	if (self == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self is NULL.\n");
#endif
		return;
	}

	if (self->head == NULL)
		return;

	struct Node *first_node = self->head;
	self->head = first_node->next;
	if (self->head == NULL)
	{
		self->tail = NULL;
	}
	else
	{
		// head.prev must be NULL
		self->head->prev = NULL;
	}

	DestroyNode(first_node);
	self->length -= 1;
}

void _LinkedList_RemoveLastNode(struct LinkedList *self)
{
	if (self == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self is NULL.\n");
#endif
		return;
	}

	if (self->tail == NULL)
		return;

	struct Node *last_node = self->tail;
	self->tail = last_node->prev;
	if (last_node->prev == NULL)
	{
		self->head = NULL;
		self->tail = NULL;
	}
	else
	{
		// tail.next must be NULL
		self->tail->next = NULL;
	}

	DestroyNode(last_node);
	self->length -= 1;
}

void _LinkedList_RemoveNodeAtIndex(struct LinkedList *self, size_t index)
{
	if (self == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self is NULL.\n");
#endif
		return;
	}

	if (index >= self->length)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: INDEX out of range.\n");
#endif
		return;
	}

	if (index == 0)
	{
		self->RemoveFirstNode(self);
		return;
	}

	if (index == self->length - 1)
	{
		self->RemoveLastNode(self);
		return;
	}

	struct Node *tmp_node = self->head;
	while (--index)
	{
		tmp_node = tmp_node->next;
	}

	struct Node *prev = tmp_node->prev;
	struct Node *next = tmp_node->next;
	prev->next = next;
	next->prev = prev;

	tmp_node->prev = NULL;
	tmp_node->next = NULL;
	DestroyNode(tmp_node);
	self->length -= 1;
}

void _LinkedList_RemoveNode(struct LinkedList *self, struct Node *node)
{
	if (self == NULL || node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: self or node is NULL.\n");
#endif
		return;
	}

	if (node == self->head)
	{
		self->RemoveFirstNode(self);
		return;
	}

	if (node == self->tail)
	{
		self->RemoveLastNode(self);
		return;
	}

	struct Node *prev = node->prev;
	struct Node *next = node->next;
	prev->next = next;
	next->prev = prev;

	node->prev = NULL;
	node->next = NULL;
	DestroyNode(node);
	self->length -= 1;
}

struct LinkedList *LinkedListConstructor(void)
{
	struct LinkedList *list = malloc(LINKED_LIST_SIZE);
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: MEMORY allocation failed.\n");
#endif
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	list->PrintAllNodeInConsole = _LinkedList_PrintAllNodeInConsole;

	list->InsertNodeAtIndex = _LinkedList_InsertNodeAtIndex;
	list->PushFrontNode = _LinkedList_PushFrontNode;
	list->PushBackNode = _LinkedList_PushBackNode;

	list->RemoveNode = _LinkedList_RemoveNode;
	list->RemoveNodeAtIndex = _LinkedList_RemoveNodeAtIndex;
	list->RemoveFirstNode = _LinkedList_RemoveFirstNode;
	list->RemoveLastNode = _LinkedList_RemoveLastNode;

	list->GetNodeWithIndex = _LinkedList_GetNodeWithIndex;
	list->GetFirstNode = _LinkedList_GetFirstNode;
	list->GetLastNode = _LinkedList_GetLastNode;

	return list;
}

void LinkedListDestructor(struct LinkedList *list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: list is NULL\n");
#endif
		return;
	}

	struct Node *node = list->head;
	struct Node *dead_node = NULL;
	while (node != NULL)
	{
		if (node == list->tail)
		{
			list->tail = list->tail->prev;
			dead_node = node;
			node = node->next;
			DestroyNode(dead_node);
			dead_node = NULL;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			dead_node = node;
			node = node->next;
			DestroyNode(dead_node);
			dead_node = NULL;
		}
		--(list->length);
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	list->PrintAllNodeInConsole = NULL;

	list->InsertNodeAtIndex = NULL;
	list->PushFrontNode = NULL;
	list->PushBackNode = NULL;

	list->RemoveNode = NULL;
	list->RemoveNodeAtIndex = NULL;
	list->RemoveFirstNode = NULL;
	list->RemoveLastNode = NULL;

	list->GetNodeWithIndex = NULL;
	list->GetFirstNode = NULL;
	list->GetLastNode = NULL;

	free(list);
	list = NULL;
}
