#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Info;
struct Node;
typedef struct Node *Dic;
typedef struct Node *PNode;
#define MAX_LENGTH 265
struct Info
{
	char Name[MAX_LENGTH];
	int Tag;
};
struct Node
{
	Info M;
	PNode Lchild;
	PNode Sibling;
};
void InsertToDic(Dic Dictionary,char* Message,int Begin);
void PrintDic(Dic Dictionary,int Level);
int Compare(Info A,Info B);
int main()
{
	int N;
	scanf("%d",&N);
	char Input[265];
	Dic Dictionary;
	Dictionary=(Dic)malloc(sizeof(struct Node));
	Dictionary->Lchild=NULL;
	Dictionary->Sibling=NULL;
	for(int i=0;i<N;i++)
	{
		scanf("%s",&Input);
		InsertToDic(Dictionary,Input,0);
	}
	printf("root\n");
	PrintDic(Dictionary->Lchild,1);
	system("pause");
	return 0;
}

void InsertToDic(Dic Dictionary,char* Message,int Begin)
{
	PNode Temp=Dictionary->Lchild;
	PNode Flag=Dictionary->Lchild;
	Info Temps;
	Temps.Tag=1;
	int i=Begin;
	int Index=0;
	if(Message[i-1]=='\0')
		return;
	if(Message[i]=='\0')
		return;
	while(Message[i]!='\0')
	{
		Temps.Name[Index]=Message[i];
		if(Message[i]=='\\')
		{
			Temps.Tag=0;
			break;
		}
		Index++;
		i++;
	}
	Temps.Name[Index]='\0';
	int Judge;
	PNode Insert;

	if(Flag==NULL)
	{
		Insert=(PNode)malloc(sizeof(struct Node));
		Insert->Lchild=NULL;
		Insert->Sibling=NULL;
		Insert->M=Temps;
		Dictionary->Lchild=Insert;
	}
	
	if(Flag!=NULL)
	{
		if(Compare(Temps,Temp->M)==2)
		{
			Insert=(PNode)malloc(sizeof(struct Node));
			Insert->Lchild=NULL;
			Insert->Sibling=Temp;
			Insert->M=Temps;
			Dictionary->Lchild=Insert;
		}
		if(Compare(Temps,Temp->M)==3)
		{
			Insert=Temp;
		}
		
	

	if(Compare(Temps,Temp->M)==1)
	{
	if(Flag->Sibling!=NULL)
	{
	while(Temp->Sibling!=NULL)
	{
		if(Compare(Temps,Temp->Sibling->M)==2||Compare(Temps,Temp->Sibling->M)==3)
			break;
		Temp=Temp->Sibling;
	}
	}
	if(Temp->Sibling!=NULL&&Compare(Temps,Temp->Sibling->M)==3)
	{
		Insert=Temp->Sibling;
	}
	else
	{
		Insert=(PNode)malloc(sizeof(struct Node));
		Insert->Sibling=Temp->Sibling;
		Temp->Sibling=Insert;
		Insert->M=Temps;
		Insert->Lchild=NULL;
	}
	}
	}
	InsertToDic(Insert,Message,i+1);
}

void PrintDic(Dic Dictionary,int Level)
{
	if(Dictionary==NULL)
		return;
	for(int i=0;i<Level;i++)
	{
		printf("  ");
	}
	printf("%s\n",Dictionary->M.Name);
	PrintDic(Dictionary->Lchild,Level+1);
	PrintDic(Dictionary->Sibling,Level);
}

int Compare(Info A,Info B)
{
	if(A.Tag<B.Tag)
		return 2;
	if(A.Tag>B.Tag)
		return 1;
	if(A.Tag==B.Tag)
	{
		if(strcmp(A.Name,B.Name)==0)
			return 3;
		if(strcmp(A.Name,B.Name)>0)
			return 1;
		if(strcmp(A.Name,B.Name)<0)
			return 2;
	}
}