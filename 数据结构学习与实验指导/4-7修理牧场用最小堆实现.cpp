#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10005
struct List
{
	int R[MAX_LENGTH];
	int Length;
};
typedef struct List *Heap;
void HeadBuild(Heap H);
void HeadAdjust(Heap H,int S);
int main()
{
	int N;
	scanf("%d",&N);
	Heap Store;
	Store=(Heap)malloc(sizeof(struct List));
	Store->Length=N;
	int Input;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&Input);
		Store->R[i+1]=Input;
	}
	HeadBuild(Store);
	int Sum;
	int Temp;
	int Total=0;
	while(Store->Length>1)
	{
		Sum=Store->R[1];
		Store->R[1]=Store->R[Store->Length--];
		HeadAdjust(Store,1);
		Sum+=Store->R[1];
		Store->R[1]=Sum;
		Total+=Sum;
		HeadAdjust(Store,1);
	}
	if(N==1)
		printf("0\n");
	else
	printf("%d\n",Total);
	system("pause");
	return 0;
}

void HeadBuild(Heap H)
{
	for(int i=H->Length/2;i>0;i--)
		HeadAdjust(H,i);
}

void HeadAdjust(Heap H,int S)
{
	int Temp;
	Temp=H->R[S];
	for(int j=2*S;j<=H->Length;j*=2)
	{
		if(j<H->Length&&(H->R[j+1]<H->R[j]))
			++j;
		if(H->R[j]>=Temp)break;
		H->R[S]=H->R[j];
		S=j;
	}
	H->R[S]=Temp;
}