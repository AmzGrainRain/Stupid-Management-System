#define USE_TEST_DATA

#include "Compatibility.h"
#include "GLOBAL.h"
#include "LinkedList.h"

static void add_test_data(struct LinkedList* list)
{
	struct NodeData node_list[] =
	{
			{"zhangsan", "1", "1", "none"},
			{"lisi", "3", "3", "none"},
			{"wangwu", "2", "2", "none"},
			{"zhaoliu", "9", "9", "none"},
			{"xiaoming", "7", "7", "none"},
			{"laowang", "0", "0", "none"},
	};

	for (size_t i = 0; i < 6; i++)
	{
		struct NodeData* node_data = CreateNodeData(node_list[i].name, node_list[i].phone, node_list[i].role, node_list[i].institute);
		list->PushBackNode(list, CreateNode(node_data, NULL, NULL));
	}
}

static void Add(struct LinkedList* list)
{
	printf("========== 添加数据 ==========\n");
	struct NodeData* node_data = CreateNodeDataFromConsoleInput();
	if (node_data == NULL)
	{
		printf("添加失败\n");
		return;
	}

	struct Node* node = CreateNode(node_data, NULL, NULL);
	list->PushBackNode(list, node);
}

static void Remove(struct LinkedList* list)
{
	struct Node* result_list[FILTER_RESULT_SIZE] = { NULL };
	FullFilter(list, result_list);

	while (1)
	{
		ClearConsole();
		PrintFilteredResultsInConsole("筛选结果:\n", result_list);
		if (!CmdConfirm("是否继续筛选？"))
			break;
		IncrementalFilter(result_list);
	}

	ClearConsole();
	PrintFilteredResultsInConsole("筛选结果:\n", result_list);
	if (!CmdConfirm("删除以上数据？"))
		return;

	struct Node* node = NULL;
	struct Node* dead_node = NULL;
	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (result_list[i] == NULL)
			continue;
		list->RemoveNode(list, result_list[i]);
	}

	printf("删除完成\n");
	PauseConsole();
	ClearConsole();
}

static void Update(struct LinkedList* list)
{
	struct Node* result_list[FILTER_RESULT_SIZE] = { NULL };
	FullFilter(list, result_list);

	while (1)
	{
		ClearConsole();
		PrintFilteredResultsInConsole("筛选结果:\n", result_list);
		if (!CmdConfirm("是否继续筛选？"))
			break;
		IncrementalFilter(result_list);
	}

	ClearConsole();
	PrintFilteredResultsInConsole("筛选结果:\n", result_list);
	if (!CmdConfirm("更新以上数据？"))
		return;

	for (size_t i = 0; i < FILTER_RESULT_SIZE; ++i)
	{
		if (result_list[i] == NULL)
			continue;
		UpdateNodeDataFromConsoleInput(result_list[i]->data);
	}

	ClearConsole();
}

static void Query(struct LinkedList* list)
{
	struct Node* result_list[FILTER_RESULT_SIZE] = { NULL };
	FullFilter(list, result_list);
	ClearConsole();
	PrintFilteredResultsInConsole("查询结果:\n", result_list);

	while (CmdConfirm("针对以上数据进行筛选？"))
	{
		IncrementalFilter(result_list);
		ClearConsole();
		PrintFilteredResultsInConsole("筛选结果:\n", result_list);
	}

	while (CmdConfirm("对以上数据进行排序？"))
	{
		Sorter(result_list);
		ClearConsole();
		PrintFilteredResultsInConsole("排序结果:\n", result_list);
	}
}

int main(void)
{
	struct LinkedList* list = LinkedListConstructor();
	if (list == NULL)
		return -1;

#ifdef USE_TEST_DATA
	add_test_data(list);
#endif

	int run = 1;
	while (run)
	{
		printf("\n========== 教师管理系统 ==========\n");
		printf("1.添加数据\n");
		printf("2.删除数据\n");
		printf("3.修改数据\n");
		printf("4.查询数据\n");
		printf("0.退出程序\n");
		printf("请输入你的选择: ");

		switch (CmdGetInt())
		{
		case 1:
			ClearConsole();
			Add(list);
			break;
		case 2:
			ClearConsole();
			Remove(list);
			break;
		case 3:
			ClearConsole();
			Update(list);
			break;
		case 4:
			ClearConsole();
			Query(list);
			break;
		case 0:
			run = 0;
			break;
		default:
			printf("错误的输入\n");
		}
	}

	LinkedListDestructor(list);

	return 0;
}
