#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include "GLOBAL.h"

extern size_t CreatedNode = 0;
extern size_t AllocatedMemory = 0;

int CmdGetInt(void)
{
	int choice = -1;
	while (1)
	{
		if (scanf_s("%d", &choice) != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("错误的输入\n");
			printf("请再次输入：");
			continue;
		}
		return choice;
	}
}

int CmdConfirm(const char* motd)
{
	printf("%s[y/n]", motd);
	char input[100] = { '\0' };
	scanf_s("%s", input, 100);

	return strcmp(input, "y") == 0 ? 1 : 0;
}