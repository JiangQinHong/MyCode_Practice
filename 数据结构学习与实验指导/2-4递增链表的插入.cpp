#include<stdio.h>
#include<stdlib.h>
typedef struct node *Nnode;
struct node{
	int num;
	Nnode next;
};
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	Nnode head;
	head=(Nnode)malloc(sizeof(struct node));
	head->next=NULL;
	Nnode rear=head;
	int num;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num);
		Nnode temp;
		temp=(Nnode)malloc(sizeof(struct node));
		temp->next=NULL;
		temp->num=num;
		rear->next=temp;
		rear=temp;
	}
	Nnode temp=head;
	while(temp->next!=NULL&&M>temp->next->num)
	{
		temp=temp->next;
	}
	Nnode insert;
	insert=(Nnode)malloc(sizeof(struct node));
	insert->num=M;
	insert->next=temp->next;
	temp->next=insert;
	temp=head;
	printf("%d",temp->next->num);
	temp=temp->next;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf(" %d",temp->num);
	}
	printf("\n");
	system("pause");
	return 0;
}