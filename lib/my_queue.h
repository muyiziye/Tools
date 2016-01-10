/*************************************************************************
	> File Name: my_queue.h
	> Author: muyiziye
	> Mail: 348610826@qq.com 
	> Created Time: Fri 08 Jan 2016 02:14:27 PM CST
 ************************************************************************/

#ifndef _MY_QUEUE_H
#define _MY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "my_define.h"

typedef enum
{
	HEAD,
	TAIL
}HEAD_TAIL;

typedef struct MY_QUEUE
{
	void* data;
	struct MY_QUEUE* next;
}MY_QUEUE;

typedef struct MY_QUEUE_HEAD_TAIL
{
	int num;
	MY_QUEUE* queue_head;
	MY_QUEUE* queue_tail;
}MY_QUEUE_HEAD_TAIL;

RESULT_ENUM init_queue_head_tail(MY_QUEUE_HEAD_TAIL* head_tail)
{
	head_tail = (MY_QUEUE_HEAD_TAIL*)malloc(sizeof(MY_QUEUE_HEAD_TAIL));
	if (NULL == head_tail)
	{
		return RESULT_FAILED;
	}
	head_tail->num = 0;
	head_tail->queue_head = NULL;
	head_tail->queue_tail = NULL;
	return RESULT_SUCCESS;
}

RESULT_ENUM enqueue(MY_QUEUE_HEAD_TAIL* head_tail, void* data)
{
	MY_QUEUE* index;
	index = (MY_QUEUE*)malloc(sizeof(MY_QUEUE));
	if (NULL == index)
	{
		return RESULT_FAILED;
	}
    index->data = data;
	index->next = NULL;
	if (0 == head_tail->num)
	{
		head_tail->queue_head = index;
		head_tail->queue_tail = index;
	}
	else
	{
		head_tail->queue_tail->next = index;
		head_tail->queue_tail = index;
	}
	return RESULT_SUCCESS;
}

RESULT_ENUM dequeue(MY_QUEUE_HEAD_TAIL* head_tail)
{
	MY_QUEUE* index;
	if (0 == head_tail->num)
	{
		return RESULT_FAILED;	
	}
	else if (1 == head_tail->num)
	{
		index = head_tail->queue_head;
		free(index);
		head_tail->num--;
		head_tail->queue_head = NULL;
		head_tail->queue_tail = NULL;
	}
	else
	{
		index = head_tail->queue_head;
		head_tail->queue_head = index->next;
		free(index);
		head_tail->num--;
	}
	return RESULT_SUCCESS;
}
#endif
