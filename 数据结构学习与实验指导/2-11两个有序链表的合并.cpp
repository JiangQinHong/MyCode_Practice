#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node *PNode;
struct Node{
	int Num;
	PNode Next;
};
void InsertToTheEnd(PNode Head,PNode End,int Num);
int main()
{
	PNode Head1,Head2;
	PNode End1,End2;
	Head1=(PNode)malloc(sizeof(struct Node));
	Head2=(PNode)malloc(sizeof(struct Node));
	Head1->Next=NULL;
	Head2->Next=NULL;
	End1=Head1;
	End2=Head2;
	int Input1,Input2;
	scanf("%d",&Input1);
	while(Input1!=-1)
	{
		InsertToTheEnd(Head1,End1,Input1);
		End1=End1->Next;
		scanf("%d",&Input1);
	}
	scanf("%d",&Input2);
	while(Input2!=-1)
	{
		InsertToTheEnd(Head2,End2,Input2);
		End2=End2->Next;
		scanf("%d",&Input2);
	}
	PNode Head,End;
	Head=(PNode)malloc(sizeof(struct Node));
	End=Head;
	PNode P1,P2;
	P1=Head1->Next;
	P2=Head2->Next;
	while(P1!=End1->Next&&P2!=End2->Next)
	{
		int Num1=P1->Num;
		int Num2=P2->Num;
		if(Num1>Num2)
		{
			InsertToTheEnd(Head,End,Num2);
			End=End->Next;
			P2=P2->Next;
		}
		if(Num1==Num2)
		{
			InsertToTheEnd(Head,End,Num1);
			End=End->Next;
			InsertToTheEnd(Head,End,Num2);
			End=End->Next;
			P1=P1->Next;
			P2=P2->Next;
		}
		if(Num1<Num2)
		{
			InsertToTheEnd(Head,End,Num1);
			End=End->Next;
			P1=P1->Next;
		}
	}
	while(P1!=End1->Next)
	{
		InsertToTheEnd(Head,End,P1->Num);
		End=End->Next;
		P1=P1->Next;
	}
	while(P2!=End2->Next)
	{
		InsertToTheEnd(Head,End,P2->Num);
		End=End->Next;
		P2=P2->Next;
	}
	if(End==Head)
		printf("NULL\n");
	else
	{
		PNode P=Head->Next;
		printf("%d",P->Num);
		P=P->Next;
		while(P!=End->Next)
		{
			printf(" %d",P->Num);
			P=P->Next;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

void InsertToTheEnd(PNode Head,PNode End,int Num)
{
	PNode Insert;
	Insert=(PNode)malloc(sizeof(struct Node));
	Insert->Num=Num;
	Insert->Next=NULL;
	End->Next=Insert;
}