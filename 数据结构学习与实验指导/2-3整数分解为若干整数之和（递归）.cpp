#include<stdio.h>
#include<stdlib.h>
void seperateto(int start,int remainder,int nterm);
int N,count;
int Num[30];
int main()
{
	scanf("%d",&N);
	count=0;
	seperateto(1,N,0);
	if(count%4!=0)
		printf("\n");
	system("pause");
	return 0;
}
void seperateto(int start,int remainder,int nterm)
{
	int i;
	if(remainder==0)
	{
		count++;
		if(count%4!=1)
			printf(";");
		printf("%d=%d",N,Num[0]);
		for( i=1;i<nterm;i++)
			printf("+%d",Num[i]);
		if(count%4==0)
			printf("\n");
	}
	else{
	for(i=start;i<=remainder;i++)
	{
		Num[nterm]=i;
		seperateto(i,remainder-i,nterm+1);
	}
	
	}

}