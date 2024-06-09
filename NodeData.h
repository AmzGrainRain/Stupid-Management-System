#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "GLOBAL.h"

#define NODE_DATA_ATTR_NAME_SIZE 20
#define NODE_DATA_ATTR_PHONE_SIZE 20
#define NODE_DATA_ATTR_ROLE_SIZE 50
#define NODE_DATA_ATTR_INSTITUTE_SIZE 50

struct NodeData
{
	char name[NODE_DATA_ATTR_NAME_SIZE];
	char phone[NODE_DATA_ATTR_PHONE_SIZE];
	char role[NODE_DATA_ATTR_ROLE_SIZE];
	char institute[NODE_DATA_ATTR_INSTITUTE_SIZE];
};

extern const size_t NODE_DATA_SIZE;

struct NodeData* CreateNodeData(
	char name[NODE_DATA_ATTR_NAME_SIZE],
	char phone[NODE_DATA_ATTR_PHONE_SIZE],
	char role[NODE_DATA_ATTR_ROLE_SIZE],
	char institute[NODE_DATA_ATTR_INSTITUTE_SIZE]
);

void DestroyNodeData(struct NodeData* node_data);

struct NodeData* CreateNodeDataFromConsoleInput(void);

void UpdateNodeDataFromConsoleInput(struct NodeData* node_data);

void PrintNodeDataInConsole(const struct NodeData* node_data, char break_line_symbol);
