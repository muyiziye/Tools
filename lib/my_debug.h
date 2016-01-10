/*************************************************************************
	> File Name: my_debug.h
	> Author: muyiziye
	> Mail: 348610826@qq.com 
	> Created Time: Thu 07 Jan 2016 12:07:34 PM CST
 ************************************************************************/

#ifndef _MY_DEBUG_H_
#define _MY_DEBUG_H_
#include <stdio.h>
#define DEBUG
#ifdef DEBUG
//#include
#define debug(fmt, x...) \
do \
{\
	printf("[%s][%s][%d]:"fmt,__FILE__, __FUNCTION__, __LINE__,##x);\
}while(0)
#else
#define debug(...)
#endif

#endif
