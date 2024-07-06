#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "GLOBAL.h"

int main(void)
{
	struct LinkedList* list = LinkedListConstructor();

	printf("������׼���ã����Կ�ʼ����...\n\n\n");
	PauseConsole();

	while (1)
	{
		for (size_t i = 0; i < 100000; ++i)
		{
			struct NodeData* nd = CreateNodeData("1111", "1111", "1111", "1111");
			list->PushBackNode(list, CreateNode(nd, NULL, NULL));
		}
		int c = -1;
		printf("���� 1 ���������ڴ�, ���� 0 ��ֹѭ��.\n");
		scanf_s("%d", &c);
		if (c == 0) break;
	}

	printf("��׼�����ͷ����нڵ�\n\n\n");
	PauseConsole();

	LinkedListDestructor(list);
	printf("�ڴ��ͷ����.\n");
	PauseConsole();

	_CrtDumpMemoryLeaks();
	return 0;
}
