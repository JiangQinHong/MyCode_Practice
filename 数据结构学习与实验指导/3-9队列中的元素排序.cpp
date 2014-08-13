#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node *Queen;
struct Node
{
	int head;
	int end;
	int Value[100002];
};
int IsEmpty(Queen S);
void AddQ(int Value,Queen S);
int DeleteQ(Queen S);
int main()
{
	int N;
	scanf("%d",&N);
	Queen S1,S2;
	S1=(Queen)malloc(sizeof(struct Node));
	S2=(Queen)malloc(sizeof(struct Node));
	S1->end=S1->head=0;
	S2->end=S2->head=0;
	for(int i=0;i<N;i++)
	{
		int Temp;
		scanf("%d",&Temp);
		AddQ(Temp,S1);
	}
	int Mini;
	int Hold=1;
	int Count;
	for(int i=0;i<N;i++)
	{
	Mini=DeleteQ(S1);
	Count=(S1->end)-(S1->head);
	while(Count!=0)
	{
		int Temp;
		Temp=DeleteQ(S1);
		if(Temp<Mini)
		{
			int Tempv;
			Tempv=Mini;
			Mini=Temp;
			Temp=Tempv;
			Hold=0;
		}
		AddQ(Temp,S1);
		Count--;
	}
	AddQ(Mini,S2);
	if(Hold==1)
		break;
	}
	if(Hold==1)
	{
		int Value;
		while(!IsEmpty(S1))
		{
			Value=DeleteQ(S1);
			AddQ(Value,S2);
		}
		Value=DeleteQ(S2);
		printf("%d",Value);
		while(!IsEmpty(S2))
		{
			AddQ(Value,S1);
			Value=DeleteQ(S2);
			printf(" %d",Value);
		}
	}
	else
	{
	int Value;
	Value=DeleteQ(S2);
	printf("%d",Value);
	while(!IsEmpty(S2))
	{
		AddQ(Value,S1);
		Value=DeleteQ(S2);
		printf(" %d",Value);
	}
	}
	printf("\n");
	system("pause");
	return 0;
	
}
int IsEmpty(Queen S)
{
	if(S->end==S->head)
		return 1;
	else
		return 0;
}

void AddQ(int Value,Queen S)
{
	S->Value[S->end]=Value;
	S->end+=1;
	S->end=(S->end)%100002;
}

int DeleteQ(Queen S)
{
	int R;
	R=S->Value[S->head];
	S->head+=1;
	S->head=(S->head)%100002;
	return R;
}

