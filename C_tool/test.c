/*************************************************************************
	> File Name: test.c
	> Author: muyiziye
	> Mail: 348610826@qq.com 
	> Created Time: Thu 07 Jan 2016 11:19:47 AM CST
 ************************************************************************/

#include<stdio.h>
#include "my_assert.h"
#include "my_debug.h"

int main()
{
	//MY_ASSERT(0);
	int a = 10,b = 9;
	debug("a=%d,b=%d\n", a, b);
	return 0;
}

