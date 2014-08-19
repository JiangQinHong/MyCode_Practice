#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int A,N;
	scanf("%d%d",&A,&N);
	int Num[100001];
	int Temp=0;
	int Advance=0;
	int Remain;
	if(N==0)
		printf("0");
	for(int i=0;i<N;i++)
	{
		Temp=(N-i)*A+Advance;
		Remain=Temp%10;
		Advance=(Temp-Remain)/10;
		Num[i]=Remain;
	}
	int index=N;
	while(Advance!=0)
	{
		Remain=Advance%10;
		Advance=(Advance-Remain)/10;
		Num[index]=Remain;
		index++;
	}
	for(int i=index-1;i>=0;i--)
	{
		printf("%d",Num[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
