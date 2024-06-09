#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG_PRINT(str)\
	printf("[%s][%s][%d] %s", __FILE__, __FUNCTION__, __LINE__, str);

// 搜索结果列表的大小
#define FILTER_RESULT_SIZE 500

// 根据不同的平台使用不同的命令来实现清空控制台或按任意键继续
#ifdef _WIN32
#define CONSOLE_CLEAR system("cls");
#define CONSOLE_PAUSE system("pause");
#else
#define CONSOLE_CLEAR system("clear");
#define CONSOLE_PAUSE \
	printf("按任意键继续...")\
	system("read -n 1 -s key");
#endif

extern size_t CreatedNode;     // 创建的节点总数
extern size_t AllocatedMemory; // 占用的内存大小

int CmdGetInt(void);

int CmdConfirm(const char* motd);
