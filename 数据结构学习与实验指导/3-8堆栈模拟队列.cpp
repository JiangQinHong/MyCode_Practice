#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node *Stack;
struct Node
{
	int End;
	int Capacity;
	double Value[101];
};
void Push(int Value,Stack S);
int Pop(Stack S);
int IsEmpty(Stack S);
int IsFull(Stack S);
void AddQ(int Value,Stack S1,Stack S2);
void DeleteQ(Stack S1,Stack S2);
int main()
{
	int N1,N2;
	scanf("%d%d",&N1,&N2);
	if(N2<N1)
	{
		int Temp;
		Temp=N1;
		N1=N2;
		N2=Temp;
	}
	Stack S1,S2;
	S1=(Stack)malloc(sizeof(struct Node));
	S2=(Stack)malloc(sizeof(struct Node));
	S1->Capacity=N1;
	S2->Capacity=N2;
	S1->End=-1;
	S2->End=-1;
	char Input;
	int BeginNum=0;
	int SpaceCount=0;
	int Num=0;
	while((Input=getchar())!='T')
	{
		if(Input=='A')
		{
			BeginNum=1;
			continue;
		}
		if(BeginNum==1)
		{
			if(Input==' ')
				SpaceCount++;
			if(SpaceCount==2)
			{
				AddQ(Num,S1,S2);
				BeginNum=0;
				SpaceCount=0;
				Num=0;
			}
			if(Input>='0'&&Input<='9')
				Num=Num*10+Input-48;
		}
		if(Input=='D')
			DeleteQ(S1,S2);
	}
	system("pause");
	return 0;
}


int IsEmpty(Stack S)
{
	if(S->End==-1)
		return 1;
	else
		return 0;
}

int IsFull(Stack S)
{
	if(S->End==S->Capacity-1)
		return 1;
	else
		return 0;
}
void Push(int Value,Stack Stack)
{
	Stack->End++;
	Stack->Value[Stack->End]=Value;
}

int Pop(Stack Stack)
{
	int Value;
	Value=Stack->Value[Stack->End];
	Stack->End--;
	return Value;
}

void AddQ(int Value,Stack S1,Stack S2)
{
	if(IsFull(S1))
	{
		printf("ERROR:Full\n");
		return;
	}
	else
	{
		S1->Value[++S1->End]=Value;
		if(IsFull(S1)&&IsEmpty(S2))
		{
			while(!IsEmpty(S1))
			{
				int Temp;
				Temp=Pop(S1);
				Push(Temp,S2);
			}
		}
	}

}

void DeleteQ(Stack S1,Stack S2)
{
	if(IsEmpty(S2))
	{
		if(IsEmpty(S1))
		{
			printf("ERROR:Empty\n");
			return;
		}
		else
		{
			while(!IsEmpty(S1))
			{
				int Temp;
				Temp=Pop(S1);
				Push(Temp,S2);
			}
		}
	}
	int Value;
	Value=Pop(S2);
	printf("%d\n",Value);
	if(IsEmpty(S2))
	{
		while(!IsEmpty(S1))
		{
			int Temp;
			Temp=Pop(S1);
			Push(Temp,S2);
		}
	}
}


