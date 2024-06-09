#pragma warning(disable:6287)
#pragma warning(disable:6031)

#include "Filter.h"

void GetFilterCondition(union FilterValue* filter_value, int* filter_type)
{
	if (filter_value == NULL || filter_value == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	printf("========== 条件筛选器 ==========\n");
	printf("1.筛选 姓名\n");
	printf("2.筛选 手机号\n");
	printf("3.筛选 职位\n");
	printf("4.筛选 所属学院\n");
	printf("0.结束筛选\n\n");

	while (1)
	{
		printf("您的选择: ");
		switch (CmdGetInt())
		{
		case NameFilter:
			printf("输入姓名进行筛选: ");
			scanf_s("%s", filter_value->name, 20);
			*filter_type = NameFilter;
			return;

		case PhoneFilter:
			printf("输入手机号进行筛选: ");
			scanf_s("%s", filter_value->phone, 20);
			*filter_type = PhoneFilter;
			return;

		case RoleFilter:
			printf("输入职位进行筛选: ");
			scanf_s("%s", filter_value->role, 50);
			*filter_type = RoleFilter;
			return;

		case InstituteFilter:
			printf("输入所属学院进行筛选: ");
			scanf_s("%s", filter_value->institute, 50);
			*filter_type = InstituteFilter;
			return;

		case ExitFilter:
			return;

		default:
			printf("输入错误\n");
		}
	}
}

void FullFilter(struct LinkedList* list, struct  Node* result_list[FILTER_RESULT_SIZE])
{
	if (list == NULL || result_list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	union FilterValue filter_value = { 0 };
	int filter_type;
	GetFilterCondition(&filter_value, &filter_type);

	size_t i = 0;
	struct Node* node = list->head;
	while (node != NULL)
	{
		if (i >= FILTER_RESULT_SIZE)
		{
			printf("数据超出结果集合的最大长度\n");
			return;
		}

		struct Teacher* teacher = node->data;
		if (teacher == NULL)
		{
			node = node->next;
			continue;
		}

		switch (filter_type)
		{
		case NameFilter:
			if (strcmp(teacher->name, filter_value.name) == 0)
				result_list[i++] = node;
			break;
		case PhoneFilter:
			if (strcmp(teacher->phone, filter_value.phone) == 0)
				result_list[i++] = node;
			break;
		case RoleFilter:
			if (strcmp(teacher->role, filter_value.role) == 0)
				result_list[i++] = node;
			break;
		case InstituteFilter:
			if (strcmp(teacher->institute, filter_value.institute) == 0)
				result_list[i++] = node;
			break;
		default:
			break;
		}

		node = node->next;
	}
}

void IncrementalFilter(struct Node* list[FILTER_RESULT_SIZE])
{
	union FilterValue filter_value = { 0 };
	int filter_type;
	GetFilterCondition(&filter_value, &filter_type);

	size_t pos = 0;

	/*
		例如我们要筛选 [1, 6, 2, 7, 4, 8] 中大小 5 的值，并且只能原地修改。
		人脑计算结果就是 [1, 2, 4, NULL, NULL, NULL]

		[1, 6, 2, 7, 4, 8]
		 |
		 i
		 |
		pos

		i 指向的 1 小于 5 所以把 i 指向的值赋值给 pos 指向的值后 i++ pos++ (
			[1, 6, 2, 7, 4, 8]
				|
				i
				|
			   pos
		)

		i 指向的 1 大于 5 所以 i++ pos 不变 (
			[1, 6, 2, 7, 4, 8]
				|  |
				|  i
			   pos
		)

		i 指向的 2 小于 5 所以交换 i 指向的值赋值给 pos 指向的值后 i++ pos++ (
			[1, 2, 2, 7, 4, 8]
				   |  |
				   |  i
				  pos
		)

		i 指向的 7 大于 5 所以 i++ pos 不变 (
			[1, 2, 2, 7, 4, 8]
				   |     |
				   |     i
				  pos
		)

		i 指向的 4 小于 5 所以交换 i 指向的值赋值给 pos 指向的值后 i++ pos++ (
			[1, 2, 4, 7, 4, 8]
					  |     |
					  |     i
					 pos
		)

		循环结束, pos 停留的地方的左侧就是符合条件的元素，右侧的都可以设置为 NULL (
			[1, 2, 4, 7, 4, 8]
					  |
					  |
					 pos
		)
	*/


	struct Node* node = NULL;
	// 此循环将保留 list 内符合条件的节点（原地修改）
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		node = list[i];
		if (node == NULL) continue;

		struct Teacher* teacher = list[i]->data;
		if (teacher == NULL) continue;

		switch (filter_type)
		{
		case NameFilter:
			if (strcmp(teacher->name, filter_value.name) == 0) list[pos++] = node;
			break;
		case PhoneFilter:
			if (strcmp(teacher->phone, filter_value.phone) == 0) list[pos++] = node;
			break;
		case RoleFilter:
			if (strcmp(teacher->role, filter_value.role) == 0) list[pos++] = node;
			break;
		case InstituteFilter:
			if (strcmp(teacher->institute, filter_value.institute) == 0) list[pos++] = node;
			break;
		default:
			break;
		}
	}

	// 删除 pos 之后的所有元素（因为他们都是不符合条件的 或是 已复制到 pos 左侧过的）
	for (size_t i = pos; i < FILTER_RESULT_SIZE; ++i)
	{
		list[i] = NULL;
	}
}

void PrintFilterList(const char* motd, struct Node* list[FILTER_RESULT_SIZE])
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif // _DEBUG
		return;
	}

	printf("%s\n", motd);
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (list[i] == NULL) continue;
		PrintNode(list[i], '\t');
	}
	printf("\n\n\n");
}

