#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int N;
	scanf("%d",&N);
	int Num[10001];
	int Input;
	int Sum=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&Input);
		Num[i]=Input;
		Sum+=Input;
	}
	double Averrage;
	Averrage=Sum/N;
	double TempSum=0;
	for(int i=0;i<N;i++)
	{
		TempSum+=(Num[i]-Averrage)*(Num[i]-Averrage);
	}
	TempSum/=N;
	double Answer;
	Answer=sqrt(TempSum);
	printf("%.5f",Answer);
	system("pause");
	return 0;
}