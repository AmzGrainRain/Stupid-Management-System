#pragma warning(disable:6031)

#include "NodeData.h"

const size_t NODE_DATA_SIZE = sizeof(struct NodeData);

struct NodeData* CreateNodeData(
	char name[NODE_DATA_ATTR_NAME_SIZE],
	char phone[NODE_DATA_ATTR_PHONE_SIZE],
	char role[NODE_DATA_ATTR_ROLE_SIZE],
	char institute[NODE_DATA_ATTR_INSTITUTE_SIZE]
)
{
	if (name == NULL || phone == NULL || role == NULL || institute == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: some parameters are null.\n");
#endif
		return NULL;
	}

	struct NodeData* node_data = malloc(NODE_DATA_SIZE);
	if (node_data == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: MEMORY allocation failed.\n");
#endif
		return NULL;
	}

	strcpy_s(node_data->name, NODE_DATA_ATTR_NAME_SIZE, name);
	strcpy_s(node_data->phone, NODE_DATA_ATTR_PHONE_SIZE, phone);
	strcpy_s(node_data->role, NODE_DATA_ATTR_ROLE_SIZE, role);
	strcpy_s(node_data->institute, NODE_DATA_ATTR_INSTITUTE_SIZE, institute);

	return node_data;
}

void DestroyNodeData(struct NodeData* node_data)
{
	if (node_data == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: node_data is NULL.\n");
#endif
		return;
	}

	free(node_data);
	node_data = NULL;
}

struct NodeData* CreateNodeDataFromConsoleInput(void)
{
	struct NodeData* node_data = malloc(NODE_DATA_SIZE);
	if (node_data == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: MEMORY allocation failed.\n");
#endif
		return NULL;
	}

	printf("Name:");
	scanf_s("%s", node_data->name, NODE_DATA_ATTR_NAME_SIZE);

	printf("Phone:");
	scanf_s("%s", node_data->phone, NODE_DATA_ATTR_PHONE_SIZE);

	printf("Role:");
	scanf_s("%s", node_data->role, NODE_DATA_ATTR_ROLE_SIZE);

	printf("Institute:");
	scanf_s("%s", node_data->institute, NODE_DATA_ATTR_INSTITUTE_SIZE);

	return node_data;
}

void UpdateNodeDataFromConsoleInput(struct NodeData* node_data)
{
	if (node_data == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: node_data is NULL.\n");
#endif
		return;
	}

	printf("[Name]\n");
	printf("Origional: %s\n", node_data->name);
	printf("New:");
	scanf_s("%s", node_data->name, NODE_DATA_ATTR_NAME_SIZE);

	printf("[Phone]\n");
	printf("Origional: %s\n", node_data->phone);
	printf("New:");
	scanf_s("%s", node_data->phone, NODE_DATA_ATTR_PHONE_SIZE);

	printf("[Role]\n");
	printf("Origional: %s\n", node_data->role);
	printf("New:");
	scanf_s("%s", node_data->role, NODE_DATA_ATTR_ROLE_SIZE);

	printf("[Institute]\n");
	printf("Origional: %s\n", node_data->institute);
	printf("New:");
	scanf_s("%s", node_data->institute, NODE_DATA_ATTR_INSTITUTE_SIZE);
}

void PrintNodeDataInConsole(const struct NodeData* node_data, char break_line_symbol)
{
	if (node_data == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: node_data is NULL.\n");
#endif
		return;
	}

	printf("Name: %s%c", node_data->name, break_line_symbol);
	printf("Phone: %s%c", node_data->phone, break_line_symbol);
	printf("Role: %s%c", node_data->role, break_line_symbol);
	printf("Institute: %s\n", node_data->institute);
}
