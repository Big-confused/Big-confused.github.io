#include"LinkNode.h"

LNode* Get_Ahead_LNode(LinkNode H, unsigned int i)
{
	unsigned int j = 0;

	if (H == NULL)
		return NULL;

	while (H->Next != NULL&&j < i - 1)
	{
		H = H->Next;
		j++;
	}
	if (j == i - 1)
		return H;
	else
		return NULL;
}

LinkNode Init_LNode(void)
{
	LinkNode Hard;
	Hard = (LinkNode)malloc(sizeof(LNode));
	Hard->Next = NULL;
	return Hard;
}

int Add_LNode(LinkNode H, LinkNodeData Data)
{
	if (H == NULL)
		return 0;

	while (H->Next != NULL)
		H = H->Next;

	H->Next = (LNode*)malloc(sizeof(LNode));
	H->Next->Data = Data;
	H = H->Next;
	H->Next = NULL;
	return 1;
}

int Length_LNode(LinkNode H)
{
	int Length = 0;

	if (H == NULL)
		return -1;

	while (H->Next!=NULL)
	{
		Length++;
		H = H->Next;
	}
	return Length;
}

int Get_LNode(LinkNode H, unsigned int i, LinkNodeData* Data)
{
	if (H == NULL)
		return 0;

	while (H->Next != NULL&&i)
	{
		H = H->Next;
		i--;
	}
	if (i == 0)
	{
		*Data = H->Data;
		return 1;
	}
	return 0;
}

int Insert_LNode(LinkNode H, unsigned int i, LinkNodeData Data)
{
	LNode* New = NULL;
	LNode* Location = H;

	if (H == NULL || i == 0)
		return 0;

	if ((Location = Get_Ahead_LNode(H, i)) != NULL)
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Data = Data;
		New->Next = Location->Next;
		Location->Next = New;
		return 1;
	}
	return 0;
}

int Delete_LNode(LinkNode H, unsigned int i)
{
	LNode* Del_Location = NULL;
	LNode* Ahead = NULL;

	if (H == NULL || i == 0)
		return 0;

	if ((Ahead = Get_Ahead_LNode(H, i)) == NULL)
		return 0;
	if ((Del_Location = Ahead->Next) != NULL)
	{
		Ahead->Next = Del_Location->Next;
		free(Del_Location);
		return 1;
	}
	return 0;
}

int Clear_LNode(LinkNode H)
{
	LNode* Delete;
	LNode* Memory;

	if (H == NULL)
		return 0;

	Delete = H->Next;
	H->Next = NULL;
	while (Delete != NULL)
	{
		Memory = Delete->Next;
		free(Delete);
		Delete = Memory;
	}
	return 1;
}

void Destroy_LNode(LinkNode* H)
{
	Clear_LNode(*H);
	free(*H);
	*H = NULL;
}