#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void FindAndPrint(long int N,long int Start);
int main()
{
	long int N;
	scanf("%ld",&N);
	printf("%ld=",N);
	FindAndPrint(N,2);
	printf("\n");
	system("pause");
	return 0;
}
void FindAndPrint(long int N,long int Start)
{
	long int Tdiv=2;
	for( Tdiv=Start;Tdiv<(N/2+1);Tdiv++)
	{
		if(N%Tdiv==0)
			break;
	}
	if(Tdiv>N/2)
		printf("%ld",N);
	else
	{
		long int Div;
		Div=Tdiv;
		int power=0;
		while(N!=1)
		{
			if(N%Div==0)
			{
				N=N/Div;
				power++;
			}
			else
				break;
		}
		if(power==1)
			printf("%ld",Div);
		else
			printf("%ld^%d",Div,power);
		if(N!=1)
		{
			printf("*");
			FindAndPrint(N,Div);	
		}
	}
}
