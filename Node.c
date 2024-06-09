#include "Node.h"

const size_t NODE_SIZE = sizeof(struct Node);

struct Node* CreateNode(struct Teacher* data, struct Node* prev, struct Node* next)
{
	struct Node* node = (struct Node*)malloc(NODE_SIZE);
	if (node == NULL) return NULL;

	node->data = data;
	node->prev = prev;
	node->next = next;

	++CreatedNode;
	AllocatedMemory += NODE_SIZE;
	return node;
}

void DestroyNode(struct Node* node)
{
	if (node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	if (node->data != NULL)
	{
		free(node->data);
		node->data = NULL;
	}
	node->prev = NULL;
	node->next = NULL;

	free(node);
	node = NULL;

	--CreatedNode;
	AllocatedMemory -= NODE_SIZE;
}

void PrintNode(const struct Node* const node, char breakLine)
{
	if (node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	struct Teacher* tea = node->data;
	if (tea != NULL)
	{
		printf("姓名: %s%c", tea->name, breakLine);
		printf("电话: %s%c", tea->phone, breakLine);
		printf("职位: %s%c", tea->role, breakLine);
		printf("所属学院: %s\n", tea->institute);
	}
}
