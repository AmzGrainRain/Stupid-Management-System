#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG_PRINT(str)\
	printf("[%s][%s][%d] %s", __FILE__, __FUNCTION__, __LINE__, str);

// 搜索结果列表的大小
#define FILTER_RESULT_SIZE 500

size_t CreatedNode;     // 创建的节点总数
size_t AllocatedMemory; // 占用的内存大小

void ClearConsole(void);

void PauseConsole(void);

int CmdGetInt(void);

int CmdConfirm(const char* motd);
