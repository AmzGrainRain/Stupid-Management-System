#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "GLOBAL.h"

// 此结构体储存老师信息
struct Teacher
{
	char name[20];      // 姓名
	char phone[20];     // 电话
	char role[50];      // 职位
	char institute[50]; // 所属学院
};

extern const size_t TEACHER_SIZE;

struct Teacher* CreateTeacher(void);

void UpdateTeacher(struct Teacher* teacher);
