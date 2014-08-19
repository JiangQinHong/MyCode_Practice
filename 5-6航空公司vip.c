#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define credit_length 19
#define list_size 99997
typedef struct node *pnode;
struct node
{
char credit[credit_length];
int distance;
pnode next;
};
typedef struct h
{
int total;
pnode next;
}head;
void insert(char* credit,int distance,head* store);
void search(char* credit,head* store);
int get_index(char* credit);
int main()
{
int N,K;
scanf("%d%d",&N,&K);
head store[list_size]={0,NULL};
int distance;
char credit[credit_length];
int i;
for(i=0;i<N;i++)
{
scanf("%s%d",&credit,&distance);
if(distance<K)
distance=K;
insert(credit,distance,store);
}
int M;
scanf("%d",&M);
for(i=0;i<M;i++)
{
scanf("%s",&credit);
search(credit,store);
}
return 0;
}

void insert(char* credit,int distance,head* store)
{
int index=get_index(credit);
int found=0;
pnode temp;
temp=store[index].next;
while(temp!=NULL)
{
if(strcmp(credit,temp->credit)==0)
{
temp->distance+=distance;
found=1;
break;
}
temp=temp->next;
}
if(!found)
{
pnode in;
in=(pnode)malloc(sizeof(struct node));
strcpy(in->credit,credit);
in->distance=distance;
in->next=store[index].next;
store[index].next=in;
store[index].total+=1;
}
}

void search(char* credit,head* store)
{
int index=get_index(credit);
int found=0;
pnode temp;
temp=store[index].next;
while(temp!=NULL)
{
if(strcmp(credit,temp->credit)==0)
{
found=1;
printf("%d\n",temp->distance);
break;
}
temp=temp->next;
}
if(!found)
printf("No Info\n");
}

int get_index(char* credit)
{
int index;
index=(credit[9]-'0')*10+(credit[11]-'0');
index=index*10+credit[12]-'0';
index=index*10+credit[15]-'0';
index=index*10+credit[16]-'0';
index=index*10+((credit[17]=='x')?10:(credit[17]-'0'));
index=index%list_size;
return index;
}

