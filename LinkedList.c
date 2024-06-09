#include "LinkedList.h"

const size_t LINKED_LIST_SIZE = sizeof(struct LinkedList);

void PrintLinkedList(struct LinkedList* list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	struct Node* head = list->head;

	printf("\n\n\n");
	while (head != NULL)
	{
		PrintNode(head, '\t');
		head = head->next;
	}
	printf("\n\n\n");
}

void Add(struct LinkedList* list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	struct Teacher* teacher = CreateTeacher();
	if (teacher == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("申请内存失败...\n");
#endif
		return;
	}

	printf("========== 添加数据 ==========\n");
	struct Node* node = CreateNode(teacher, NULL, NULL);
	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
	++(list->length);
}

void Remove(struct LinkedList* list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	struct Node* result_list[FILTER_RESULT_SIZE] = { NULL };
	FullFilter(list, result_list);

	while (1)
	{
		CONSOLE_CLEAR
		PrintFilterList("筛选结果:\n", result_list);
		if (!CmdConfirm("是否继续筛选？")) break;
		IncrementalFilter(result_list);
	}

	CONSOLE_CLEAR
	PrintFilterList("筛选结果:\n", result_list);
	if (!CmdConfirm("删除以上数据？")) return;

	struct Node* node = NULL;
	struct Node* dead_node = NULL;
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (result_list[i] == NULL) continue;

		node = result_list[i];
		if (node == list->tail)
		{
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			dead_node = node;
			node = node->next;
			DestroyNode(dead_node);
			dead_node = NULL;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			dead_node = node;
			node = node->next;
			DestroyNode(dead_node);
			dead_node = NULL;
		}
		--(list->length);
	}

	printf("删除完成\n");
	CONSOLE_PAUSE
	CONSOLE_CLEAR
}

void Update(struct LinkedList* list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	struct Node* result_list[FILTER_RESULT_SIZE] = { NULL };
	FullFilter(list, result_list);

	while (1)
	{
		CONSOLE_CLEAR
		PrintFilterList("筛选结果:\n", result_list);
		if (!CmdConfirm("是否继续筛选？")) break;
		IncrementalFilter(result_list);
	}

	CONSOLE_CLEAR
	PrintFilterList("筛选结果:\n", result_list);
	if (!CmdConfirm("更新以上数据？")) return;

	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (result_list[i] == NULL) continue;
		UpdateTeacher(result_list[i]->data);
	}

	CONSOLE_CLEAR
}

void Query(struct LinkedList* list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	struct Node* result_list[FILTER_RESULT_SIZE] = { NULL };
	FullFilter(list, result_list);
	CONSOLE_CLEAR
	PrintFilterList("查询结果:\n", result_list);

	while (CmdConfirm("针对以上数据进行筛选？"))
	{
		IncrementalFilter(result_list);
		CONSOLE_CLEAR
		PrintFilterList("筛选结果:\n", result_list);
	}

	while (CmdConfirm("对以上数据进行排序？"))
	{
		SortFilterResult(result_list);
		CONSOLE_CLEAR
		PrintFilterList("排序结果:\n", result_list);
	}
}

struct LinkedList* CreateLinkedList(void)
{
	struct LinkedList* data = (struct LinkedList*)malloc(LINKED_LIST_SIZE);
	if (data == NULL) {
#ifdef _DEBUG
		DEBUG_PRINT("申请内存失败\n")
#endif // _DEBUG
			return NULL;
	}

	struct Node* head = CreateNode(NULL, NULL, NULL);
	data->head = head;
	data->tail = head;
	data->length = 0;
	return data;
}

void DestroyLinkedList(struct LinkedList* list)
{
	if (list == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif // _DEBUG
		return;
	}

	struct Node* node = list->head->next;
	struct Node* dead_node = NULL;
	while (node != NULL)
	{
		if (node == list->tail)
		{
			list->tail = list->tail->prev;
			dead_node = node;
			node = node->next;
			DestroyNode(dead_node);
			dead_node = NULL;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			dead_node = node;
			node = node->next;
			DestroyNode(dead_node);
			dead_node = NULL;
		}
		--(list->length);
	}

	DestroyNode(list->head);
	list->head = NULL;
	list->tail = NULL;
	free(list);
	list = NULL;
}