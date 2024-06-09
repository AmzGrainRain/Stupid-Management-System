#include "Node.h"

const size_t NODE_SIZE = sizeof(struct Node);

struct Node* CreateNode(struct NodeData* node_data, struct Node* prev, struct Node* next)
{
	struct Node* node = malloc(NODE_SIZE);
	if (node == NULL) return NULL;

	node->data = node_data;
	node->prev = prev;
	node->next = next;

	return node;
}

void DestroyNode(struct Node* node)
{
	if (node == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: node is NULL.\n");
#endif
		return;
	}

	if (node->data != NULL)
	{
		DestroyNodeData(node->data);
		node->data = NULL;
	}

	node->prev = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}
