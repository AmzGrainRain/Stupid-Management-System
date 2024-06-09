#pragma once

#include "GLOBAL.h"
#include "Teacher.h"
#include "Node.h"

#define NameSorter 1
#define PhoneSorter 2
#define RoleSorter 3
#define InstituteSorter 4
#define ExitSorter 0

#define SortByASC 1
#define SortByDESC -1

typedef int (*CompareFunction)(struct Teacher*, struct Teacher*);
void SelectSort(struct Node* list[FILTER_RESULT_SIZE], int order_by, CompareFunction);

int SortFilterResultWithName(struct Teacher* a, struct Teacher* b);

int SortFilterResultWithPhone(struct Teacher* a, struct Teacher* b);

int SortFilterResultWithRole(struct Teacher* a, struct Teacher* b);

int SortFilterResultWithInstitute(struct Teacher* a, struct Teacher* b);

size_t CountFilterResultActualLength(struct Node* list[FILTER_RESULT_SIZE]);

void SortFilterResult(struct Node* list[FILTER_RESULT_SIZE]);
