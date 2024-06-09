#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "GLOBAL.h"
#include "NodeData.h"

struct Node
{
	struct NodeData* data;
	struct Node* next;
	struct Node* prev;
};

extern const size_t NODE_SIZE;

struct Node* CreateNode(struct NodeData* data, struct Node* prev, struct Node* next);

void DestroyNode(struct Node* node);
