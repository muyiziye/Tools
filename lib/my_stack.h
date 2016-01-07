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

int push_stack(MY_STACK* head);

int pop_stack(MY_STACK* head);

MY_STACK_HEAD* init_stack_head()
{
	MY_STACK_HEAD* head;
	head = (MY_STACK_HEAD*)malloc(sizeof(MY_STACK_HEAD));
	head->num = 0;
	head->stack_top = NULL;
	return head;
}

int push_stack(MY_STACK* head, void* data)
{
    MY_STACK* index;
	index = (MY_STACK*)malloc(sizeof(MY_STACK));
	if (NULL == index) 
	{
		return 0;
	}
	index->data = data;
	index->next = head->next;
	head->next = index;
	return 1;
}

int pop_stack(MY_STACK* head)
{
    MY_STACK* index;
	index = head->next;
    if (NULL == index)
	{
		return 0;
	}
	head->next = head->next->next;
	free(index);
	return 1;
}
#endif
