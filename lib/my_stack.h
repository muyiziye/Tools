/*************************************************************************
	> File Name: my_stack.h
	> Author: muyiziye
	> Mail: 348610826@qq.com 
	> Created Time: Thu 07 Jan 2016 02:21:49 PM CST
 ************************************************************************/
#ifndef _MY_STACK_H_
#define _MY_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "my_define.h"

typedef struct MY_STACK
{
	void* data;
	struct MY_STACK* next;
}MY_STACK;

typedef struct MY_STACK_HEAD
{
	int num;
	MY_STACK* stack_top;
}MY_STACK_HEAD;

MY_STACK_HEAD* init_stack_head();

RESULT_ENUM push_stack(MY_STACK_HEAD* head, void* data);

RESULT_ENUM pop_stack(MY_STACK_HEAD* head);

MY_STACK_HEAD* init_stack_head()
{
	MY_STACK_HEAD* head;
	head = (MY_STACK_HEAD*)malloc(sizeof(MY_STACK_HEAD));
	head->num = 0;
	head->stack_top = NULL;
	return head;
}

RESULT_ENUM push_stack(MY_STACK_HEAD* head, void* data)
{
    MY_STACK* index;
	index = (MY_STACK*)malloc(sizeof(MY_STACK));
	if (NULL == index) 
	{
		return RESULT_FAILED;
	}
	index->data = data;
	index->next = head->stack_top;
	head->stack_top = index;
	head->num++;
	return RESULT_SUCCESS;
}

RESULT_ENUM pop_stack(MY_STACK_HEAD* head)
{
    MY_STACK* index;
	index = head->stack_top;
    if (NULL == index)
	{
		return RESULT_FAILED;
	}
	head->stack_top = head->stack_top->next;
	head->num--;
	free(index);
	return RESULT_SUCCESS;
}
#endif
