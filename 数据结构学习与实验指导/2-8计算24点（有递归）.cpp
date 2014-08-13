#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Compute(int A,int B,char Operator);
void GetPerm(int *List,int Position,int End);
void Swap(int *A,int *B);
int Store[100][4]={0};
int Count=0;
bool Flag=true;
int main()
{
	char Operator[4];
	Operator[0]='+';
	Operator[1]='-';
	Operator[2]='*';
	Operator[3]='/';
	int Num[4];
	scanf("%d%d%d%d",&Num[0],&Num[1],&Num[2],&Num[3]);
	int Operand1,Operand2,Operand3,Operand4;
	char Operator1,Operator2,Operator3;
	GetPerm(Num,0,3);
	for(int i=0;i<Count;i++)
				{
					Operand1=Store[i][0];
					Operand2=Store[i][1];
					Operand3=Store[i][2];
					Operand4=Store[i][3];
					for(int u=0;u<4;u++)
						for(int v=0;v<4;v++)
							for(int p=0;p<4;p++)
							{
								Operator1=Operator[u];
								Operator2=Operator[v];
								Operator3=Operator[p];
							int Result,Result1,Result2;
							Result1=Compute(Operand1,Operand2,Operator1);
							if(Flag==true)
							Result2=Compute(Result1,Operand3,Operator2);
							if(Flag==true)
							Result=Compute(Result2,Operand4,Operator3);
							if(Result==24&&Flag==true)
							{
								printf("((%d%c%d)%c%d)%c%d\n",Operand1,Operator1,Operand2,Operator2,Operand3,Operator3,Operand4);
								system("pause");
								return 0;
							}
							Flag=true;
							Result1=Compute(Operand1,Operand2,Operator1);
							if(Flag==true)
							Result2=Compute(Operand3,Operand4,Operator3);
							if(Flag==true)
							Result=Compute(Result1,Result2,Operator2);
							if(Result==24&&Flag==true)
							{
								printf("(%d%c%d)%c(%d%c%d)\n",Operand1,Operator1,Operand2,Operator2,Operand3,Operator3,Operand4);
								system("pause");
								return 0;
							}
							Flag=true;
							Result1=Compute(Operand2,Operand3,Operator2);
							if(Flag==true)
							Result2=Compute(Operand1,Result1,Operator1);
							if(Flag==true)
							Result=Compute(Result2,Operand4,Operator3);
							if(Result==24&&Flag==true)
							{
								printf("(%d%c(%d%c%d))%c%d\n",Operand1,Operator1,Operand2,Operator2,Operand3,Operator3,Operand4);
								system("pause");
								return 0;
							}
							Flag=true;
							Result1=Compute(Operand2,Operand3,Operator2);
							if(Flag==true)
							Result2=Compute(Result1,Operand4,Operator3);
							if(Flag==true)
							Result=Compute(Operand1,Result2,Operator1);
							if(Result==24&&Flag==true)
							{
								printf("%d%c((%d%c%d)%c%d)\n",Operand1,Operator1,Operand2,Operator2,Operand3,Operator3,Operand4);
								system("pause");
								return 0;
							}
							Flag=true;
							Result1=Compute(Operand3,Operand4,Operator3);
							if(Flag==true)
							Result2=Compute(Operand2,Result1,Operator2);
							if(Flag==true)
							Result=Compute(Operand1,Result2,Operator1);
							if(Result==24&&Flag==true)
							{
								printf("%d%c(%d%c(%d%c%d))\n",Operand1,Operator1,Operand2,Operator2,Operand3,Operator3,Operand4);
								system("pause");
								return 0;
							}
							Flag=true;
							}

				}
				printf("-1");
				printf("\n");
				system("pause");
				return 0;
}
int Compute(int A,int B,char Operator)
{
	int result;
	switch(Operator)
	{
	case'+':
		result=A+B;
		break;
	case'-':
		result=A-B;
		break;
	case'*':
		result=A*B;
		break;
	case'/':
		{
		if(B==0||A%B!=0)
		{
			Flag=false;
			return 0;
		}
		result=A/B;
		}
		break;
	}
	return result;
}
void Swap(int *A,int *B)
{
	int Temp;
	Temp=*A;
	*A=*B;
	*B=Temp;
}
void GetPerm(int *List,int Position,int End)
{
	if(Position>End)
	{
		for(int i=0;i<=End;i++)
			Store[Count][i]=List[i];
		Count++;
	}
	else
	{
		for(int k=Position;k<=End;k++)
		{
			Swap(&List[Position],&List[k]);
			GetPerm(List,Position+1,End);
			Swap(&List[Position],&List[k]);
		}
	}
}