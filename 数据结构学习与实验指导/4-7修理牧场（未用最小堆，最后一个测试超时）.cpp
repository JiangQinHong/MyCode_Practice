#include<stdio.h>
#include<stdlib.h>
typedef struct Node *PNode;
struct Node
{
	int Num;
	PNode Next;
};
void Insert(int Value,PNode Store);
int GetMini(PNode Store);
int ToPlan(PNode Store);
int main()
{
	int N;
	scanf("%d",&N);
	int Input;
	PNode Store;
	Store=(PNode)malloc(sizeof(struct Node));
	Store->Num=0;
	Store->Next=NULL;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&Input);
		Insert(Input,Store);
	}
	int Total;
	if(N==1)
		Total=0;
	else
		Total=ToPlan(Store);
	printf("%d\n",Total);
	system("pause");
	return 0;
}

int ToPlan(PNode Store)
{
	int A,B;
	int Total=0;
	int Sum;
	A=GetMini(Store);
	B=GetMini(Store);
	Sum=A+B;
	Total+=Sum;
	while(Store->Next!=NULL)
	{
		Insert(Sum,Store);
		A=GetMini(Store);
	    B=GetMini(Store);
	    Sum=A+B;
	    Total+=Sum;
	}
	return Total;
}

void Insert(int Value,PNode Store)
{
	PNode Temp;
	Temp=Store;
	while(Temp->Next!=NULL&&Temp->Next->Num<Value)
	{
		Temp=Temp->Next;
	}
	PNode InsertNode;
	InsertNode=(PNode)malloc(sizeof(struct Node));
	InsertNode->Num=Value;
	InsertNode->Next=Temp->Next;
	Temp->Next=InsertNode;
}

int GetMini(PNode Store)
{
	PNode Temp;
	Temp=Store->Next;
	Store->Next=Temp->Next;
	int Return;
	Return=Temp->Num;
	free(Temp);
	return Return;
}