#include "Sorter.h"

void _Sorter_SelectSort(struct Node* list[FILTER_RESULT_SIZE], int order_by, __Sorter_CompareFunction compare_func)
{
	if (list == NULL || compare_func == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: list or compare_func is NULL.\n");
#endif
		return;
	}

	size_t actual_size = GetFilteredResultsLength(list);
	if (actual_size <= 0) return;

    struct Node *tmp = NULL;
	size_t outer_loop_max_value = actual_size - 1;
	size_t t = 0;
	for (size_t i = 0; i < outer_loop_max_value; ++i) {
		t = i;
		for (size_t j = i + 1; j < actual_size; ++j)
		{
			t = compare_func(list[t]->data, list[j]->data) * order_by > 0 ? j : t;
		}

		tmp = list[i];
		list[i] = list[t];
		list[t] = tmp;
	}
}

int _Sorter_SortWithName(struct NodeData* a, struct NodeData* b) {
	return strcmp(a->name, b->name);
}

int _Sorter_SortWithPhone(struct NodeData* a, struct NodeData* b) {
	return strcmp(a->phone, b->phone);
}

int _Sorter_SortWithRole(struct NodeData* a, struct NodeData* b) {
	return strcmp(a->role, b->role);
}

int _Sorter_SortWithInstitute(struct NodeData* a, struct NodeData* b) {
	return strcmp(a->institute, b->institute);
}

void Sorter(struct Node* list[FILTER_RESULT_SIZE])
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("be careful: list is NULL.\n");
#endif
		return;
	}

	printf("\n========== Sorter ==========\n");
	printf("1.Order by Name\n");
	printf("2.Order by Phone\n");
	printf("3.Order by Role\n");
	printf("4.Order by Institute\n");
	printf("0.Exit sorter\n\n");

	int sort_type = -1;
	while (1)
	{
		printf(">: ");
		sort_type = CmdGetInt();
		if (sort_type >= EXIT_SORTER && sort_type <= SORT_BY_INSTITUTE)
		{
			break;
		}
	}
	if (sort_type == EXIT_SORTER) return;

	printf("Sort in ascending order by default.\n");
	int order_by = CmdConfirm("Do you need to sort in descending order?") ? SortByDESC : SortByASC;

	switch (sort_type)
	{
	case SORT_BY_NAME:
		_Sorter_SelectSort(list, order_by, _Sorter_SortWithName);
		break;
	case SORT_BY_PHONE:
		_Sorter_SelectSort(list, order_by, _Sorter_SortWithPhone);
		break;
	case SORT_BY_ROLE:
		_Sorter_SelectSort(list, order_by, _Sorter_SortWithRole);
		break;
	case SORT_BY_INSTITUTE:
		_Sorter_SelectSort(list, order_by, _Sorter_SortWithInstitute);
		break;
	default:
		break;
	}
}
