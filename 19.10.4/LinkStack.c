#include"LinkStack.h"

//ÖÃ¿ÕÁ´Õ»
LinkStack Init_LinkStack(void)
{
	return NULL;
}

//ÅÐÁ´Õ»¿Õ
int Empty_LinkStack(LinkStack Top)
{
	if (Top == NULL)
		return 1;
	return 0;
}

//ÈëÁ´Õ»
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

//³öÁ´Õ»
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

//¶ÁÈ¡Á´Õ»¶¥ÔªËØ
int GetTop_LinkStack(LinkStack Top, LinkStackNodeData* Data)
{
	if (Top == NULL)
		return 0;

	*Data = Top->Data;
	return 1;
}

//ÇóÁ´Õ»³¤
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

//Çå¿ÕÁ´Õ»
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


