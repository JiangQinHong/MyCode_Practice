#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node *PNode;
struct Node
{
	int End;
	double Value[30];
};
void Push(double Value,PNode Stack);
double Pop(PNode Stack);
double Compute(double A,double B,char Operator);
double GetValue(char *Store,int Count);
int main()
{
	char Store[31];
	char Input;
	int Index;
	Index=0;
	while((Input=getchar())!='\n')
	{
		Store[Index]=Input;
		Index++;
	}
	PNode Stack;
	Stack=(PNode)malloc(sizeof(struct Node));
	Stack->End=-1;
	char Get;
	char CharHold[20];
	int Count=0;
	for(int i=Index-1;i>=-1;i--)
	{
		Get=Store[i];
		if(Get!=' '&&i!=-1)
		{
			CharHold[Count]=Store[i];
			Count++;
		}
		else
		{
			if((CharHold[Count-1]>='0'&&CharHold[Count-1]<='9')||Count>1)
			{
				double Temp;
				Temp=GetValue(CharHold,Count);
				Push(Temp,Stack);
				Count=0;
			}
			else
			{
				char Operator=CharHold[Count-1];
				double A,B;
				A=Pop(Stack);
				B=Pop(Stack);
				double Temp;
				Temp=Compute(A,B,Operator);
				Push(Temp,Stack);
				Count=0;
			}
		}

	}
	double OutPut;
	OutPut=Pop(Stack);
	printf("%.1f\n",OutPut);
	system("pause");
	return 0;
}

void Push(double Value,PNode Stack)
{
	Stack->End++;
	Stack->Value[Stack->End]=Value;
}

double Pop(PNode Stack)
{
	double Value;
	Value=Stack->Value[Stack->End];
	Stack->End--;
	return Value;
}

double Compute(double A,double B,char Operator)
{
	double Result;
	switch(Operator)
	{
	case'+':
		Result=A+B;
		break;
	case'-':
		Result=A-B;
		break;
	case'*':
		Result=A*B;
		break;
	case'/':
		{
			if(B==0)
			{
				printf("ERROR\n");
				exit(1);
			}
			else
			{
			Result=A/B;
			}
		}
		break;
	}
	return Result;
}

double GetValue(char *Store,int Count)
{
	double Value=0;
	int meetpoint=0;
	int flag=0;
	for(int i=Count-1;i>=0;i--)
	{
		int Temp;
		if(Store[i]=='.')
		{
			meetpoint=1;
			continue;
		}
		if(Store[i]=='+')
		{
			flag=0;
			continue;
		}
		if(Store[i]=='-')
		{
			flag=1;
			continue;
		}
		if(!meetpoint)
		{
			Temp=Store[i]-48;
			Value=Value*10+Temp;
		}
		else
		{
			Temp=Store[i]-48;
			Value=Value+Temp*pow(10.0,-meetpoint);
			meetpoint++;
		}
	}
	if(flag==1)
		Value=-Value;
	return Value;
}

