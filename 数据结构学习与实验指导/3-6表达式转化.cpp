#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct stack *Stack;
struct stack
{
	char Operator[21];
	int End;
};
int GetValue(char Operator);
void Push(Stack PostFix,char Operator);
void Pop(Stack PostFix);
int IsEmpty(Stack PostFix);
void DoStack(Stack PostFix,char Operator);
char GetTopOfStack(Stack PostFix);
int main()
{
	Stack PostFix;
	PostFix=(Stack)malloc(sizeof(struct stack));
	PostFix->End=-1;
	char In;
	int IsNum=0;
	int FirstStation=1;
	int count=1;
	while((In=getchar())!='\n')
	{
		if(FirstStation==1&&In=='-')
		{
			if(count!=1)
			printf(" %c",In);
			else
				printf("%c",In);
			IsNum=1;
			FirstStation=0;
			count=0;
			continue;
		}

		if(FirstStation==1&&In=='+')
		{
			if(count!=1)
				printf(" ");
			IsNum=1;
			FirstStation=0;
			count=0;
			continue;
		}
		if(FirstStation==1&&count==1&&In=='(')
		{
			IsNum=0;
			FirstStation=1;
			DoStack(PostFix,In);
			count=1;
		}

		if(In>='0'&&In<='9')
		{
			if(count==1)
				printf("%c",In);
			else
			{
			if(IsNum)
				printf("%c",In);
			else
			{
				printf(" %c",In);
			}	
			}
			IsNum=1;
			FirstStation=0;
			count=0;
		}

		if(FirstStation==0)
		{
			if(In=='.')
				printf(".");
			if(In=='+'||In=='-'||In=='*'||In=='/'||In==')')
			{
				IsNum=0;
				DoStack(PostFix,In);
			}
			if(In=='(')
			{
				IsNum=0;
				FirstStation=1;
				DoStack(PostFix,In);
			}
		count=0;
		}
		

	}//end of while
	while(!IsEmpty(PostFix))
	{
		Pop(PostFix);
	}
	printf("\n");
	system("pause");
	return 0;
}

int GetValue(char Operator)
{
	int Value;
	switch(Operator)
	{
	case'+':
	case'-':
		Value=2;
		break;
	case'*':
	case'/':
		Value=3;
		break;
	case'(':
		Value=4;
		break;
	case')':
		Value=1;
		break;
	case'n':
		Value=0;
		break;
	}
	return Value;
}

void Push(Stack PostFix,char Operator)
{
	PostFix->End++;
	int Index;
	Index=PostFix->End;
	PostFix->Operator[Index]=Operator;
}

void Pop(Stack PostFix)
{
	int Index;
	Index=PostFix->End;
	int Value;
	Value=GetValue(PostFix->Operator[Index]);
	if(Value!=4)
	printf(" %c",PostFix->Operator[Index]);
	PostFix->End--;
}

char GetTopOfStack(Stack PostFix)
{
	if(PostFix->End==-1)
		return 'n';
	else
	return(PostFix->Operator[PostFix->End]);
}


void DoStack(Stack PostFix,char Operator)
{
	int Value;
	Value=GetValue(Operator);
	int TopValue;
	TopValue=GetValue(GetTopOfStack(PostFix));
	while(Value<=TopValue)
	{
		
		if(TopValue==4)
		{
			if(Value==1)
				Pop(PostFix);
			break;
		}
		else
		{
		Pop(PostFix);
		TopValue=GetValue(GetTopOfStack(PostFix));
		}
	}
	if(Value!=1)
		Push(PostFix,Operator);

}

int IsEmpty(Stack PostFix)
{
	if(PostFix->End==-1)
		return 1;
	else
		return 0;
}