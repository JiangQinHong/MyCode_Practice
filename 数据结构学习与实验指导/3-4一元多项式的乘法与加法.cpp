#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node *PNode;
struct Node{
	int Coe;
	int Exp;
	PNode Next;
};
void Insert(PNode Head,PNode node);
void Multi(PNode Head,PNode Node1,PNode Node2);
void PrintList(PNode List);
int main()
{
	int N1,N2;
	scanf("%d",&N1);
	int i;
	int Coe,Exp;
	PNode Head1;
	Head1=(PNode)malloc(sizeof(struct Node));
	Head1->Next=NULL;
	for(i=0;i<N1;i++)
	{
		scanf("%d%d",&Coe,&Exp);
		PNode TempNode;
		TempNode=(PNode)malloc(sizeof(struct Node));
		TempNode->Coe=Coe;
		TempNode->Exp=Exp;
		Insert(Head1,TempNode);
	}
	PNode Head2;
	Head2=(PNode)malloc(sizeof(struct Node));
	Head2->Next=NULL;
	scanf("%d",&N2);
	for(i=0;i<N2;i++)
	{
		scanf("%d%d",&Coe,&Exp);
		PNode TempNode;
		TempNode=(PNode)malloc(sizeof(struct Node));
		TempNode->Coe=Coe;
		TempNode->Exp=Exp;
		Insert(Head2,TempNode);
	}
	PNode Sum,Mul;
	Sum=(PNode)malloc(sizeof(struct Node));
	Mul=(PNode)malloc(sizeof(struct Node));
	Sum->Next=NULL;
	Mul->Next=NULL;
	PNode P1,P2;
	P1=Head1->Next;
	P2=Head2->Next;
	while(P1!=NULL&&P2!=NULL)
	{
		if(P1->Exp>P2->Exp)
		{
			PNode InsertNode;
			InsertNode=(PNode)malloc(sizeof(struct Node));
			InsertNode->Exp=P1->Exp;
			InsertNode->Coe=P1->Coe;
			Insert(Sum,InsertNode);
			P1=P1->Next;
		}
		if(P1->Exp<P2->Exp)
		{
			PNode InsertNode;
			InsertNode=(PNode)malloc(sizeof(struct Node));
			InsertNode->Exp=P2->Exp;
			InsertNode->Coe=P2->Coe;
			Insert(Sum,InsertNode);
			P2=P2->Next;
		}
		if(P1->Exp==P2->Exp)
		{
			if(P1->Coe+P2->Coe!=0)
			{
			PNode InsertNode;
			InsertNode=(PNode)malloc(sizeof(struct Node));
			InsertNode->Exp=P1->Exp;
			InsertNode->Coe=P1->Coe+P2->Coe;
			Insert(Sum,InsertNode);
			}
			P1=P1->Next;
			P2=P2->Next;
		}
	}
	while(P1!=NULL)
	{
		PNode InsertNode;
		InsertNode=(PNode)malloc(sizeof(struct Node));
		InsertNode->Exp=P1->Exp;
		InsertNode->Coe=P1->Coe;
		Insert(Sum,InsertNode);
		P1=P1->Next;
	}
	while(P2!=NULL)
	{
		PNode InsertNode;
		InsertNode=(PNode)malloc(sizeof(struct Node));
		InsertNode->Exp=P2->Exp;
		InsertNode->Coe=P2->Coe;
		Insert(Sum,InsertNode);
		P2=P2->Next;
	}
	P1=Head1->Next;
	while(P1!=NULL)
	{
		P2=Head2->Next;
		while(P2!=NULL)
		{
		Multi(Mul,P1,P2);
		P2=P2->Next;
		}
		P1=P1->Next;
	}
	PrintList(Mul);
	PrintList(Sum);
	system("pause");	
	return 0;
}

void Insert(PNode Head,PNode node)
{
	PNode Temp=Head;
	while(Temp->Next!=NULL&&(Temp->Next->Exp>node->Exp))
		Temp=Temp->Next;
	if(Temp->Next!=NULL&&Temp->Next->Exp==node->Exp)
	{
		Temp->Next->Coe+=node->Coe;
		if(Temp->Next->Coe==0)
		{
			PNode Free;
			Free=Temp->Next;
			Temp->Next=Temp->Next->Next;
			free(Free);
		}
	}
	else
	{
		node->Next=Temp->Next;
		Temp->Next=node;
	}

}

void Multi(PNode Head,PNode Node1,PNode Node2)
{
	PNode Temp;
	Temp=(PNode)malloc(sizeof(struct Node));
	Temp->Coe=(Node1->Coe)*(Node2->Coe);
	Temp->Exp=(Node1->Exp)+(Node2->Exp);
	Insert(Head,Temp);
}

void PrintList(PNode List)
{
	PNode Temp;
	Temp=List->Next;
	if(Temp==NULL)
		printf("0 0");
	else
	{
		printf("%d %d",Temp->Coe,Temp->Exp);
		Temp=Temp->Next;
		while(Temp!=NULL)
		{
			printf(" %d %d",Temp->Coe,Temp->Exp);
			Temp=Temp->Next;
		}
	}
	printf("\n");
}