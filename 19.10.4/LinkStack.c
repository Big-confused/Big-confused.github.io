#include"LinkStack.h"

//�ÿ���ջ
LinkStack Init_LinkStack(void)
{
	return NULL;
}

//����ջ��
int Empty_LinkStack(LinkStack Top)
{
	if (Top == NULL)
		return 1;
	return 0;
}

//����ջ
int Push_LinkStack(LinkStack* Top, LinkStackNodeData Data)
{
	LStackNode* NewNode;
	if (Top == NULL)
		return 0;

	NewNode = (LStackNode*)malloc(sizeof(LStackNode));
	NewNode->Data = Data;
	NewNode->Next = *Top;
	*Top = NewNode;
	return 1;
}

//����ջ
int Pop_LinkStack(LinkStack* Top, LinkStackNodeData* Data)
{
	LStackNode* Delete;
	if (Top == NULL || *Top == NULL)
		return 0;

	*Data = (*Top)->Data;
	Delete = *Top;
	*Top = (*Top)->Next;
	free(Delete);
	return 1;
}

//��ȡ��ջ��Ԫ��
int GetTop_LinkStack(LinkStack Top, LinkStackNodeData* Data)
{
	if (Top == NULL)
		return 0;

	*Data = Top->Data;
	return 1;
}

//����ջ��
int Length_LinkStack(LinkStack Top)
{
	int L = 0;
	while (Top != NULL)
	{
		Top = Top->Next;
		L++;
	}
	return L;
}

//�����ջ
int Clear_LinkStack(LinkStack* Top)
{
	LStackNode* Delete;
	if (Top == NULL)
		return 0;
	while (*Top != NULL)
	{
		Delete = *Top;
		*Top = (*Top)->Next;
		free(Delete);
	}
	return 1;
}


