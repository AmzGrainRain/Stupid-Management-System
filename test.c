#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "GLOBAL.h"

int main(void)
{
	struct LinkedList* list = LinkedListConstructor();

	printf("链表已准备好，可以开始测试...\n\n\n");
	PauseConsole();

	while (1)
	{
		for (size_t i = 0; i < 100000; ++i)
		{
			struct NodeData* nd = CreateNodeData("1111", "1111", "1111", "1111");
			list->PushBackNode(list, CreateNode(nd, NULL, NULL));
		}
		int c = -1;
		printf("输入 1 继续申请内存, 输入 0 终止循环.\n");
		scanf_s("%d", &c);
		if (c == 0) break;
	}

	printf("已准备好释放所有节点\n\n\n");
	PauseConsole();

	LinkedListDestructor(list);
	printf("内存释放完毕.\n");
	PauseConsole();

	_CrtDumpMemoryLeaks();
	return 0;
}
