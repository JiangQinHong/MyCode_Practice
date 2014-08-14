#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct Node *TreeNode;
#define MAX_LENGTH 15
#define MAX_MEMBER 110
#define MAX_SENTENCE 75
int GetSpaceCount(char *S);
void InitNode(TreeNode T_Node);
void CreateNode(TreeNode T_Node,char *S);
TreeNode CreateTree(TreeNode* NodeArray,int Index,int NumOfNode);
void MakeJudge(TreeNode Tree,char *A);
int Find(TreeNode Tree,char *A,int Relation,char *B);
TreeNode FindSencond(TreeNode Node,char *S);
struct Node
{
	char Name[MAX_LENGTH];
	int SpaceCount;
	TreeNode Lchild;
	TreeNode Sibling;
};
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	TreeNode FamilyMember[MAX_MEMBER];
	char Input[MAX_LENGTH+200];
	char C;
	int Count=0;
	for(int i=0;i<N;i++)
	{
		FamilyMember[i]=(TreeNode)malloc(sizeof(struct Node));
		InitNode(FamilyMember[i]);
		fflush(stdin);
		scanf("%c",&C);
		while(C!='\n')
		{
			Input[Count]=C;
			Count++;
			scanf("%c",&C);
		}
		Input[Count]='\0';
		Count=0;
		CreateNode(FamilyMember[i],Input);
	}
	TreeNode Root;
	Root=FamilyMember[0];
	Root=CreateTree(FamilyMember,0,N);
	char Sentence[110][MAX_SENTENCE];
	Count=0;
	for(int i=0;i<M;i++)
	{
		fflush(stdin);
		while((C=getchar())!='\n')
		{
			Sentence[i][Count]=C;
			Count++;
		}
		Sentence[i][Count]='\0';
		Count=0;
	}
	for(int i=0;i<M;i++)
	{
		MakeJudge(Root,Sentence[i]);
	}
	system("pause");
	return 0;
}

int GetSpaceCount(char *S)
{
	int Count=0;
	while(*S!='\0')
	{
		if(*S==' ')
			Count++;
		S++;
	}
	return Count;
}

void InitNode(TreeNode T_Node)
{
	T_Node->Lchild=NULL;
	T_Node->Sibling=NULL;
	T_Node->SpaceCount=0;
}

void CreateNode(TreeNode T_Node,char *S)
{
	int Count=GetSpaceCount(S);
	T_Node->SpaceCount=Count;
	int i=0;
	while(S[Count]!='\0')
	{
		T_Node->Name[i]=S[Count];
		i++;
		Count++;
	}
	T_Node->Name[i]=S[Count];
}

TreeNode CreateTree(TreeNode* NodeArray,int Index,int NumOfNode)
{

	if(Index>NumOfNode)
		return NULL;
	TreeNode Root;
	Root=NodeArray[Index];
	for(int i=Index+1;i<NumOfNode;i++)
	{
		if(NodeArray[i]->SpaceCount-2==Root->SpaceCount)
		{
			Root->Lchild=CreateTree(NodeArray,i,NumOfNode);
			break;
		}
		if(NodeArray[i]->SpaceCount<Root->SpaceCount)
		{
			Root->Lchild=NULL;
			break;
		}
	}
	for(int i=Index+1;i<NumOfNode;i++)
	{
		if(NodeArray[i]->SpaceCount==Root->SpaceCount)
		{
			Root->Sibling=CreateTree(NodeArray,i,NumOfNode);
		    break;
		}
		if(NodeArray[i]->SpaceCount<Root->SpaceCount)
		{
			Root->Sibling=NULL;
			break;
		}
		
	}
	return Root;
}

void MakeJudge(TreeNode Tree,char *A)
{
	char S[MAX_LENGTH];
	char B[MAX_LENGTH];
	char Relation[15];
	int Count1=0;
	int Count2=0;
	int Count3=0;
	int SpaceCount=0;
	int Total=0;
	while(A[Total]!='\0')
	{
		if(A[Total]==' ')
		{
			SpaceCount++;
			Total++;
			continue;
		}
		if(SpaceCount==0)
		{
			S[Count1]=A[Total];
			Count1++;
			Total++;
			continue;
		}
		if(SpaceCount==3)
		{
			Relation[Count2]=A[Total];
			Count2++;
			Total++;
			continue;
		}
		if(SpaceCount==5)
		{
			B[Count3]=A[Total];
			Count3++;
			Total++;
			continue;
		}
		Total++;
	}
	S[Count1]='\0';
	Relation[Count2]='\0';
	B[Count3]='\0';
	int Situation;
	if(Relation[0]=='c')
		Situation=0;
	if(Relation[0]=='p')
		Situation=1;
	if(Relation[0]=='s')
		Situation=2;
	if(Relation[0]=='d')
		Situation=3;
	if(Relation[0]=='a')
		Situation=4;
	int Judge;
	Judge=Find(Tree,S,Situation,B);
	if(Judge==1)
		printf("True\n");
	else
		printf("False\n");
}

int Find(TreeNode Tree,char *A,int Relation,char *B)
{
	int ReturnValue=0;
	TreeNode Older;
	TreeNode Temp;
	if(Relation==0)
	{
		Older=FindSencond(Tree,B);
		Temp=Older->Lchild;
		while(Temp!=NULL)
		{
			if(strcmp(Temp->Name,A)==0)
			{
				ReturnValue=1;
				return ReturnValue;
			}
			Temp=Temp->Sibling;
		}
	}
	if(Relation==1)
	{
		Older=FindSencond(Tree,A);
		Temp=Older->Lchild;
		while(Temp!=NULL)
		{
			if(strcmp(Temp->Name,B)==0)
			{
				ReturnValue=1;
				return ReturnValue;
			}
			Temp=Temp->Sibling;
		}
	}
	if(Relation==2)
	{
		Older=FindSencond(Tree,A);
		Temp=Older->Sibling;
		while(Temp!=NULL)
		{
			if(strcmp(Temp->Name,B)==0)
			{
				ReturnValue=1;
				return ReturnValue;
			}
			Temp=Temp->Sibling;
		}
		Older=FindSencond(Tree,B);
		Temp=Older->Sibling;
		while(Temp!=NULL)
		{
			if(strcmp(Temp->Name,A)==0)
			{
				ReturnValue=1;
				return ReturnValue;
			}
			Temp=Temp->Sibling;
		}
	}
	if(Relation==3)
	{
		Older=FindSencond(Tree,B);
		Temp=Older->Lchild;
		if(FindSencond(Temp,A))
		{
			ReturnValue=1;
			return ReturnValue;
		}
	}
	if(Relation==4)
	{
		Older=FindSencond(Tree,A);
		Temp=Older->Lchild;
		if(FindSencond(Temp,B))
		{
			ReturnValue=1;
			return ReturnValue;
		}
	}
	return ReturnValue;
}

TreeNode FindSencond(TreeNode Node,char *S)
{
	if(Node==NULL)
		return NULL;
	if(strcmp(Node->Name,S)==0)
		return Node;
	TreeNode Node1,Node2;
	Node1=FindSencond(Node->Lchild,S);
	if(Node1)
		return Node1;
	Node2=FindSencond(Node->Sibling,S);
	if(Node2)
		return Node2;
	return NULL;
		
}