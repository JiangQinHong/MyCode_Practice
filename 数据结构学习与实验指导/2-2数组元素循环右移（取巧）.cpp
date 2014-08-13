#include<stdio.h>
int main()
{
int Num[100];
int N,M,temp,index;
scanf("%d%d",&N,&M);
M%=N;
for(int i=0;i<N;i++)
{
	scanf("%d",&temp);
    index=(i+M)%N;
	Num[index]=temp;
}
for(int i=0;i<N;i++)
{
	printf("%d ",Num[i]);
}
return 0;
}