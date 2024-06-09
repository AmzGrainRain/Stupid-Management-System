#include "Sorter.h"

void SelectSort(struct Node* list[FILTER_RESULT_SIZE], int order_by, CompareFunction compare_func)
{
	if (list == NULL || compare_func == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif // _DEBUG
		return;
	}

	size_t actual_size = CountFilterResultActualLength(list);
	if (actual_size <= 0) return;

	struct Node* tmp = NULL;
	size_t outer_loop_max_value = actual_size - 1;
	size_t t = 0;
	for (size_t i = 0; i < outer_loop_max_value; ++i) {
		t = i;
		for (size_t j = i + 1; j < actual_size; ++j)
		{
			t = compare_func(list[t]->data, list[j]->data) * order_by > 0 ? j : t;
		}

		// 交换
		tmp = list[i];
		list[i] = list[t];
		list[t] = tmp;
	}
}

int SortFilterResultWithName(struct Teacher* a, struct Teacher* b) {
	return strcmp(a->name, b->name);
}

int SortFilterResultWithPhone(struct Teacher* a, struct Teacher* b) {
	return strcmp(a->phone, b->phone);
}

int SortFilterResultWithRole(struct Teacher* a, struct Teacher* b) {
	return strcmp(a->role, b->role);
}

int SortFilterResultWithInstitute(struct Teacher* a, struct Teacher* b) {
	return strcmp(a->institute, b->institute);
}

size_t CountFilterResultActualLength(struct Node* list[FILTER_RESULT_SIZE])
{
	size_t count = FILTER_RESULT_SIZE;
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (list[i] == NULL) {
			count = i;
			break;
		}
	}
	return count;
}

void SortFilterResult(struct Node* list[FILTER_RESULT_SIZE])
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	printf("\n========== 排序器 ==========\n");
	printf("1.按照 姓名 排序\n");
	printf("2.按照 手机号 排序\n");
	printf("3.按照 职位 排序\n");
	printf("4.按照 所属学院 排序\n");
	printf("0.返回\n\n");

	int sort_type = -1;
	while (1)
	{
		printf("排序方式: ");
		sort_type = CmdGetInt();
		if (sort_type >= ExitSorter && sort_type <= InstituteSorter)
		{
			break;
		}
	}

	int order_by = CmdConfirm("默认以升序排序，是否需要降序？") ? SortByDESC : SortByASC;

	switch (sort_type)
	{
	case NameSorter:
		SelectSort(list, order_by, SortFilterResultWithName);
		break;
	case PhoneSorter:
		SelectSort(list, order_by, SortFilterResultWithPhone);
		break;
	case RoleSorter:
		SelectSort(list, order_by, SortFilterResultWithRole);
		break;
	case InstituteSorter:
		SelectSort(list, order_by, SortFilterResultWithInstitute);
		break;
	}
}