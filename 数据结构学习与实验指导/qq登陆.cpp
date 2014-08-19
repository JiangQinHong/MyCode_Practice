/*本题用散列做好了，冲突后采取链表的方式，链接在最前面一个节点上*/
/*散列函数就为随机取（2-6）5位对9997求余，作为映射，因为输入最大才为10的5次方，能满足需要*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define Max_name 11/*用户名长度*/
#define Max_pass 17/*密码长度*/
#define Max_length 10001/*散列表长度*/
typedef struct Node *PNode;
struct Node
{
char Name[Max_name];/*存储QQ号码*/
char Password[Max_pass];/*存储密码*/
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
/*建立数据库*/
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







