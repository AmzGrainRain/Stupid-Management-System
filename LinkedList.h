#pragma once
#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "GLOBAL.h"
#include "Node.h"
#include "Teacher.h"
#include "Filter.h"
#include "Sorter.h"

struct LinkedList
{
	size_t length;
	struct Node* head;
	struct Node* tail;
};

extern const size_t LINKED_LIST_SIZE;

// 遍历打印节点
void PrintLinkedList(struct LinkedList* list);

// 添加节点
void Add(struct LinkedList* list);

// 删除节点
void Remove(struct LinkedList* list);

// 更新节点
void Update(struct LinkedList* list);

// 查找节点
void Query(struct LinkedList* list);

struct LinkedList* CreateLinkedList(void);

void DestroyLinkedList(struct LinkedList* list);
