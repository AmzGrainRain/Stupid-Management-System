#pragma warning(disable : 6287)
#pragma warning(disable : 6031)

#include "Filter.h"

void GetFilterConditionFromConsoleInput(union FilterValue *filter_value, int *filter_type)
{
	if (filter_value == NULL || filter_value == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: filter_value or filter_value is NULL.\n");
#endif
		return;
	}

	printf("========== Conditional Filters ==========\n");
	printf("1.By Name\n");
	printf("2.By Phone\n");
	printf("3.By Role\n");
	printf("4.By Institute\n");
	printf("0.Exit eilter\n\n");

	while (1)
	{
		printf(">: ");
		switch (CmdGetInt())
		{
		case NameFilter:
			printf("Enter \"name\" for filtering: ");
			scanf_s("%s", filter_value->name, 20);
			*filter_type = NameFilter;
			return;

		case PhoneFilter:
			printf("Enter \"phone\" number for filtering: ");
			scanf_s("%s", filter_value->phone, 20);
			*filter_type = PhoneFilter;
			return;

		case RoleFilter:
			printf("Enter \"role\" number for filtering: ");
			scanf_s("%s", filter_value->role, 50);
			*filter_type = RoleFilter;
			return;

		case InstituteFilter:
			printf("Enter \"institute\" number for filtering: ");
			scanf_s("%s", filter_value->institute, 50);
			*filter_type = InstituteFilter;
			return;

		case ExitFilter:
			return;

		default:
			printf("Unexpected input.\n");
		}
	}
}

void FullFilter(struct LinkedList *list, struct Node *result_list[FILTER_RESULT_SIZE])
{
	if (list == NULL || result_list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be carefule: list or result_list is NULL.\n");
#endif
		return;
	}

	union FilterValue filter_value = {0};
	int filter_type;
	GetFilterConditionFromConsoleInput(&filter_value, &filter_type);

	size_t i = 0;
	struct Node *node = list->head;
	while (node != NULL)
	{
		if (i >= FILTER_RESULT_SIZE)
		{
			printf("The data exceeds the maximum length of the result set.\n");
			return;
		}

		struct NodeData *node_data = node->data;
		if (node_data == NULL)
		{
			node = node->next;
			continue;
		}

		switch (filter_type)
		{
		case NameFilter:
			if (strcmp(node_data->name, filter_value.name) == 0)
				result_list[i++] = node;
			break;
		case PhoneFilter:
			if (strcmp(node_data->phone, filter_value.phone) == 0)
				result_list[i++] = node;
			break;
		case RoleFilter:
			if (strcmp(node_data->role, filter_value.role) == 0)
				result_list[i++] = node;
			break;
		case InstituteFilter:
			if (strcmp(node_data->institute, filter_value.institute) == 0)
				result_list[i++] = node;
			break;
		default:
			break;
		}

		node = node->next;
	}
}

void IncrementalFilter(struct Node *list[FILTER_RESULT_SIZE])
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be carefule: list is NULL.\n");
#endif
		return;
	}

	union FilterValue filter_value = {0};
	int filter_type = -1;
	GetFilterConditionFromConsoleInput(&filter_value, &filter_type);

	size_t pos = 0;
	struct Node *node = NULL;
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		node = list[i];
		if (node == NULL)
			continue;

		struct NodeData *node_data = list[i]->data;
		if (node_data == NULL)
			continue;

		switch (filter_type)
		{
		case NameFilter:
			if (strcmp(node_data->name, filter_value.name) == 0)
				list[pos++] = node;
			break;
		case PhoneFilter:
			if (strcmp(node_data->phone, filter_value.phone) == 0)
				list[pos++] = node;
			break;
		case RoleFilter:
			if (strcmp(node_data->role, filter_value.role) == 0)
				list[pos++] = node;
			break;
		case InstituteFilter:
			if (strcmp(node_data->institute, filter_value.institute) == 0)
				list[pos++] = node;
			break;
		default:
			break;
		}
	}

	for (size_t i = pos; i < FILTER_RESULT_SIZE; ++i)
	{
		list[i] = NULL;
	}
}

void PrintFilteredResultsInConsole(const char *motd, struct Node *list[FILTER_RESULT_SIZE])
{
	if (motd == NULL || list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: motd or list is NULL.\n");
#endif
		return;
	}

	printf("%s\n", motd);
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (list[i] == NULL)
			continue;
		PrintNodeDataInConsole(list[i]->data, '\t');
	}
	printf("\n");
}

size_t GetFilteredResultsLength(struct Node *list[FILTER_RESULT_SIZE])
{
	size_t count = FILTER_RESULT_SIZE;
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (list[i] == NULL)
		{
			count = i;
			break;
		}
	}
	return count;
}
