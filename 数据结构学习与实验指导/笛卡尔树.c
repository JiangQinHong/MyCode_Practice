#include<stdlib.h>
#include<stdio.h>
#define MAX_NUM 1002
typedef struct node
{
int K1;
int K2;
int Lchild;
int Rchild;  
int Tag;        /*用于判断是否为根节点*/ 
}Node;
int Record=0;
int M_Travel[MAX_NUM];
void TravelAndJudge_K1(Node *Tree,int Root);
void TravelAndJudge_K2(Node *Tree,int Root);
void InsertAndJudge(int Value);
int main()
{
int N;
scanf("%d",&N);
Node Tree[MAX_NUM];
int K1,K2,Lchild,Rchild;
int i;
for(i=0;i<N;i++)
Tree[i].Tag=1;
for(i=0;i<N;i++)
{
scanf("%d%d%d%d",&K1,&K2,&Lchild,&Rchild);
Tree[i].K1=K1;
Tree[i].K2=K2;
Tree[i].Lchild=Lchild;
Tree[i].Rchild=Rchild;
if(Lchild!=-1)
Tree[Lchild].Tag=0;
if(Rchild!=-1)
Tree[Rchild].Tag=0;
}
int Root;
for(i=0;i<N;i++)
{
if(Tree[i].Tag==1)
{
Root=i;
break;
}
}

TravelAndJudge_K1(Tree,Root);
TravelAndJudge_K2(Tree,Root);
printf("YES\n");

return 0;
}

void TravelAndJudge_K1(Node *Tree,int Root)
{
if(Root==-1)
return;
int Lchild=Tree[Root].Lchild;
int Rchild=Tree[Root].Rchild;
int K1=Tree[Root].K1;
TravelAndJudge_K1(Tree,Lchild);
InsertAndJudge(K1);
TravelAndJudge_K1(Tree,Rchild);
}


void TravelAndJudge_K2(Node *Tree,int Root)
{
int Value=Tree[Root].K2;
if(Tree[Root].Lchild!=-1)
{
int LValue=Tree[Tree[Root].Lchild].K2;
if(Value>=LValue)
{
printf("NO\n");
exit(0);
}
TravelAndJudge_K2(Tree,Tree[Root].Lchild);
}
if(Tree[Root].Rchild!=-1)
{
int RValue=Tree[Tree[Root].Rchild].K2;
if(Value>=RValue)
{
printf("NO\n");
exit(0);
}
TravelAndJudge_K2(Tree,Tree[Root].Rchild);
}

}

void InsertAndJudge(int Value)
{
if(Record==0)
M_Travel[Record]=Value;
else
{
if(Value<M_Travel[Record-1])
{
printf("NO\n");
exit(0);
}
M_Travel[Record]=Value;
}
Record++;
}


















