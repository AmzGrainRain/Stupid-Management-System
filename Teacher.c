#pragma warning(disable:6031)

#include "Teacher.h"

const size_t TEACHER_SIZE = sizeof(struct Teacher);

struct Teacher* CreateTeacher(void)
{
	struct Teacher* teacher = (struct Teacher*)malloc(TEACHER_SIZE);
	if (teacher == NULL) return NULL;

	printf("请输入姓名：");
	scanf_s("%s", teacher->name, 20);

	printf("请输入电话：");
	scanf_s("%s", teacher->phone, 20);

	printf("请输入职位：");
	scanf_s("%s", teacher->role, 50);

	printf("请输入学院：");
	scanf_s("%s", teacher->institute, 50);

	return teacher;
}

void UpdateTeacher(struct Teacher* teacher)
{
	if (teacher == NULL)
	{
#ifdef _DEBUG
		DEBUG_PRINT("传入了空指针...\n");
#endif
		return;
	}

	printf("姓名：%s\n", teacher->name);
	printf("新姓名：");
	scanf_s("%s", teacher->name, 20);

	printf("电话：%s\n", teacher->phone);
	printf("新电话：");
	scanf_s("%s", teacher->phone, 20);

	printf("职位：%s\n", teacher->role);
	printf("新职位：");
	scanf_s("%s", teacher->role, 50);

	printf("学院：%s\n", teacher->institute);
	printf("新学院：");
	scanf_s("%s", teacher->institute, 50);
}
