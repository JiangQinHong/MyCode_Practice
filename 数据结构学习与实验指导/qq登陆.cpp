/*������ɢ�������ˣ���ͻ���ȡ����ķ�ʽ����������ǰ��һ���ڵ���*/
/*ɢ�к�����Ϊ���ȡ��2-6��5λ��9997���࣬��Ϊӳ�䣬��Ϊ��������Ϊ10��5�η�����������Ҫ*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define Max_name 11/*�û�������*/
#define Max_pass 17/*���볤��*/
#define Max_length 10001/*ɢ�б���*/
typedef struct Node *PNode;
struct Node
{
char Name[Max_name];/*�洢QQ����*/
char Password[Max_pass];/*�洢����*/
PNode Next;
};
typedef struct head
{
int Total;
PNode Next;
}Head;
int Remain=9997;
void Land(char *Name,char *Password,Head *Db);
void New(char *Name,char *Password,Head *Db);
int Get_index(char *Name);
int main()
{
/*�������ݿ�*/
Head Db[Max_length]={0,NULL};
int N;
scanf("%d",&N);
char Operation[2];
char Name[Max_name];
char Password[Max_pass];
int i;
for(i=0;i<N;i++)
{
scanf("%s%s%s",&Operation,&Name,&Password);
if(strcmp(Operation,"L")==0)
Land(Name,Password,Db);
if(strcmp(Operation,"N")==0)
New(Name,Password,Db);
}
return 0;
}

void Land(char *Name,char *Password,Head *Db)
{
int Index=Get_index(Name);
if(Db[Index].Total==0)
{
printf("ERROR: Not Exist\n");
}
else
{
int Found=0;
int Right=0;
PNode Temp=Db[Index].Next;
while(Temp!=NULL)
{
if(strcmp(Name,Temp->Name)==0)
{
Found=1;
if(strcmp(Password,Temp->Password)==0)
Right=1;
break;
}
Temp=Temp->Next;
}
if(!Found)
printf("ERROR: Not Exist\n");
else
{
if(!Right)
printf("ERROR: Wrong PW\n");
else
printf("Login: OK\n");
}

}
}

void New(char *Name,char *Password,Head *Db)
{
int Index=Get_index(Name);
if(Db[Index].Total==0)
{
PNode Insert;
Insert=(PNode)malloc(sizeof(struct Node));
strcpy(Insert->Name,Name);
strcpy(Insert->Password,Password);
Insert->Next=NULL;
Db[Index].Next=Insert;
Db[Index].Total+=1;
printf("New: OK\n");
}
else
{
PNode Temp;
Temp=Db[Index].Next;
int Found=0;
while(Temp!=NULL)
{
if(strcmp(Name,Temp->Name)==0)
{
Found=1;
break;
}
Temp=Temp->Next;
}
if(Found)
printf("ERROR: Exist\n");
else
{
PNode Insert;
Insert=(PNode)malloc(sizeof(struct Node));
strcpy(Insert->Name,Name);
strcpy(Insert->Password,Password);
Insert->Next=Db[Index].Next;
Db[Index].Next=Insert;
Db[Index].Total+=1;
printf("New: OK\n");
}
}
}

int Get_index(char *Name)
{
int Index=0;
if(strlen(Name)<5)
{
int i;
for(i=0;i<strlen(Name);i--)
{
Index=Index*10+Name[i]-'0';
}
}
else
{
int i=1;
while(i!=6&&Name[i]!='\0')
{
Index=Index*10+Name[i]-'0';
i++;
}
}
Index=Index%Remain;
return Index;
}







