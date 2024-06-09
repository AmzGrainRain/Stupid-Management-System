#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GLOBAL.h"
#include "LinkedList.h"
#include "Node.h"

// C4115: 'LinkedList': named type definition in parentheses
struct LinkedList;

union FilterValue
{
    char name[20];
    char phone[20];
    char role[50];
    char institute[50];
};

#define NameFilter 1
#define PhoneFilter 2
#define RoleFilter 3
#define InstituteFilter 4
#define ExitFilter 0

void GetFilterConditionFromConsoleInput(union FilterValue* filter_value, int* filter_type);

void FullFilter(struct LinkedList* list, struct Node* result_list[FILTER_RESULT_SIZE]);

void IncrementalFilter(struct Node* list[FILTER_RESULT_SIZE]);

void PrintFilteredResultsInConsole(const char* motd, struct Node* list[FILTER_RESULT_SIZE]);

size_t GetFilteredResultsLength(struct Node* list[FILTER_RESULT_SIZE]);
