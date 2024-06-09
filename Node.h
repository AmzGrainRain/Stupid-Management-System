#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "GLOBAL.h"
#include "Node.h"
#include "Teacher.h"

struct Node
{
	struct Teacher* data; // 数据
	struct Node* next;    // 下一个节点
	struct Node* prev;    // 上一个节点
};

extern const size_t NODE_SIZE;

// 创建节点
struct Node* CreateNode(struct Teacher* data, struct Node* prev, struct Node* next);

// 释放节点
void DestroyNode(struct Node* node);

// 打印节点内容
void PrintNode(const struct Node* const node, char breakLine);
