#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void FindAndChange(int Turn,int Diamond);
void ChangeHalf(int Num[],int Count);
int Allocate[101][101]={0};
int main()
{
	int D,P;
	scanf("%d%d",&D,&P);
	for(int i=1;i<P;i++)
	{
		FindAndChange(i,D);
	}
	int Allocated;
	Allocated=Allocate[P-2][P-1];
	printf("%d\n",Allocated);
	system("pause");
	return 0;
}
void FindAndChange(int Turn,int Diamond)
{
	if(Turn==1)
	{
		Allocate[0][0]=Diamond;
		Allocate[0][1]=0;
	}
	else
	{
		int Index[101];
		int TempValue[101];
		for(int i=0;i<Turn;i++)
		{
			Index[i]=i;
			TempValue[i]=Allocate[Turn-2][i];
		}
		for(int j=Turn-1;j>0;j--)
		{
			int Exchange=0;
			for(int i=0;i<j;i++)
			{
				if(TempValue[i]>TempValue[i+1])
				{
					int TempIndex=Index[i];
					Index[i]=Index[i+1];
					Index[i+1]=TempIndex;
					int Temp=TempValue[i];
					TempValue[i]=TempValue[i+1];
					TempValue[i+1]=Temp;
					Exchange=1;
				}
			}
			if(Exchange==0)
				break;
		}
		int WillChange;
		WillChange=(Turn+1)/2;
		int Allocated=0;
		for(int i=0;i<WillChange;i++)
		{
			Allocate[Turn-1][Index[i]]=Allocate[Turn-2][Index[i]]+1;
			Allocated+=Allocate[Turn-1][Index[i]];
		}
		for(int i=WillChange;i<Turn;i++)
			Allocate[Turn-1][Index[i]]=0;
		Allocate[Turn-1][Turn]=Diamond-Allocated;
	}
}