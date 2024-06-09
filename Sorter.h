#pragma once

#include "GLOBAL.h"
#include "NodeData.h"
#include "Node.h"
#include "Filter.h"

#define SORT_BY_NAME 1
#define SORT_BY_PHONE 2
#define SORT_BY_ROLE 3
#define SORT_BY_INSTITUTE 4
#define EXIT_SORTER 0

#define SortByASC 1
#define SortByDESC -1

typedef int (*__Sorter_CompareFunction)(struct NodeData* a, struct NodeData* b);
void _Sorter_SelectSort(struct Node* list[FILTER_RESULT_SIZE], int order_by, __Sorter_CompareFunction compare_func);

int _Sorter_SortWithName(struct NodeData* a, struct NodeData* b);

int _Sorter_SortWithPhone(struct NodeData* a, struct NodeData* b);

int _Sorter_SortWithRole(struct NodeData* a, struct NodeData* b);

int _Sorter_SortWithInstitute(struct NodeData* a, struct NodeData* b);

void Sorter(struct Node* list[FILTER_RESULT_SIZE]);
