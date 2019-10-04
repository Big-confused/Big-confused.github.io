//链栈的基本操作集
/*===================================================================================*/
#ifndef MY_LINKSTACK_H
#define MY_LINKSTACK_H

#include<stdio.h>
#include<malloc.h>

//链栈存储结构数据域类型自定义
#define LinkStackNodeData int

//链栈存储结构定义
typedef struct LinkStackNode
{
	LinkStackNodeData Data;
	struct LinkStackNode* Next;
}LStackNode,*LinkStack;

/*====================================================================================
*作用：置空链栈
*结果：构造空的链栈
====================================================================================*/
LinkStack Init_LinkStack(void);

/*====================================================================================
*作用：判断链栈是否为空
*形参：Top为链栈栈顶指针
*结果：返回1为空，返回0不为空
====================================================================================*/
int Empty_LinkStack(LinkStack Top);

/*====================================================================================
*作用：在链栈顶插入一个元素
*形参：Top为链栈栈顶指针，Data为要插入的元素
*结果：成功返回1，失败返回0
====================================================================================*/
int Push_LinkStack(LinkStack* Top, LinkStackNodeData Data);

/*====================================================================================
*作用：取链栈顶的一个元素（删除该结点）
*形参：Top为链栈栈顶指针，Data为存储该元素的位置
*结果：成功返回1，失败返回0
====================================================================================*/
int Pop_LinkStack(LinkStack* Top, LinkStackNodeData* Data);

/*====================================================================================
*作用：读取链栈顶的一个元素（不删除该结点）
*形参：Top为链栈栈顶指针，Data为存储该元素的位置
*结果：成功返回1，失败返回0
====================================================================================*/
int GetTop_LinkStack(LinkStack Top, LinkStackNodeData* Data);

/*====================================================================================
*作用：求链栈的长度
*形参：Top为链栈栈顶指针
*结果：返回链栈的长度
====================================================================================*/
int Length_LinkStack(LinkStack Top);

/*====================================================================================
*作用：清空链栈
*形参：Top为链栈栈顶指针
*结果：成功返回1，失败返回0
====================================================================================*/
int Clear_LinkStack(LinkStack* Top);

#endif