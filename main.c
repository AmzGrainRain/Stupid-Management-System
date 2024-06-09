//#define TEST_DEBUG
#define USE_TEST_DATA

#include "GLOBAL.h"
#include "LinkedList.h"

static void debug_print(void)
{
#ifdef TEST_DEBUG
	printf("已创建 %zu 个节点\n", CreatedNode);
	printf("已共计申请 %zuKB 内存\n", AllocatedMemory / 1024);
#endif
}

static void add_test_data(struct LinkedList* list)
{
	struct Teacher tea_list[] =
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
		struct Teacher* t = (struct Teacher*)malloc(TEACHER_SIZE);
		if (t == NULL) continue;
		strcpy(t->name, tea_list[i].name);
		strcpy(t->phone, tea_list[i].phone);
		strcpy(t->role, tea_list[i].role);
		strcpy(t->institute, tea_list[i].institute);

		struct Node* node = CreateNode(t, NULL, NULL);
		if (t == NULL)
		{
			free(t);
			continue;
		}
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
		++(list->length);
	}
}

int main(void)
{
#ifndef TEST_DEBUG
	struct LinkedList* data = CreateLinkedList();
	if (data == NULL) return -1;

#ifdef USE_TEST_DATA
	add_test_data(data);
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
			CONSOLE_CLEAR
				Add(data);
			break;
		case 2:
			CONSOLE_CLEAR
				Remove(data);
			break;
		case 3:
			CONSOLE_CLEAR
				Update(data);
			break;
		case 4:
			CONSOLE_CLEAR
				Query(data);
			break;
		case 0:
			run = 0;
			break;
		default:
			printf("错误的输入\n");
		}
	}

	DestroyLinkedList(data);
#else
	struct LinkedList* data = CreateLinkedList();

	printf("链表已准备好，可以开始测试...\n\n\n");
	debug_print();
	CONSOLE_PAUSE

		while (1)
		{
			for (size_t i = 0; i < 100000; ++i)
			{
				struct Teacher* tea = (struct Teacher*)malloc(TEACHER_SIZE);
				if (tea == NULL) continue;
				strcpy(tea->name, "1111");
				strcpy(tea->phone, "1111");
				strcpy(tea->role, "1111");
				strcpy(tea->institute, "1111");

				struct Node* node = CreateNode(tea, NULL, NULL);
				node->prev = data->tail;
				data->tail->next = node;
				data->tail = node;
				++(data->length);
			}
			int c = -1;
			printf("输入 1 继续申请内存, 输入 0 终止循环.\n");
			scanf_s("%d", &c);
			if (c == 0) break;
		}

	debug_print();
	printf("已准备好释放所有节点\n\n\n");
	CONSOLE_PAUSE

	DestroyLinkedList(data);
	printf("内存释放完毕.\n");
	debug_print();
	CONSOLE_PAUSE

	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
