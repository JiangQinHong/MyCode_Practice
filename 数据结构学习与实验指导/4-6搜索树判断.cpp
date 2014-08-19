#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int PostFix[1001];
int PreFix[1001];
void JudgeAndCompute(int Flag,int Head,int End);
int Count;
int main()
{
	int N;
	scanf("%d",&N);
	Count=N-1;
	int Input;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&Input);
		PreFix[i]=Input;
	}
	JudgeAndCompute(3,0,N-1);
	printf("YES\n");
	printf("%d",PostFix[0]);
	for(int i=1;i<N;i++)
	{
		printf(" %d",PostFix[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void JudgeAndCompute(int Flag,int Head,int End)
{
	int LHead,LEnd,RHead,REnd;
	int MFlag;
	int ToBe=1;
	PostFix[Count]=PreFix[Head];
	Count--;
	if(Head==End)
	{
		return;
	}
	if(PreFix[Head]>PreFix[Head+1])
		MFlag=1;
	else
		MFlag=2;
	LHead=Head+1;
	LEnd=Head;
	RHead=REnd=LHead;
	int Tag=0;
	for(int i=Head+1;i<=End;i++)
	{
		if(MFlag==1)
		{
			if(PreFix[i]<PreFix[Head])
			{
				LEnd++;
				if(Tag==1)
				{
					ToBe=0;
					break;
				}
			}
			else
			{
				if(Tag==0)
				{
					RHead=i;
					Tag=1;
				}
				if(Tag==1)
				{
					REnd=i;
				}
			}
		}

		if(MFlag==2)
		{
			if(PreFix[i]>=PreFix[Head])
			{
				LEnd++;
				if(Tag==1)
				{
					ToBe=0;
					break;
				}
			}
			else
			{
				if(Tag==0)
				{
					RHead=i;
					Tag=1;
				}
				if(Tag==1)
				{
					REnd=i;
				}
			}
		}

	}//end of for
	if(RHead==LHead)
		MFlag=3;
	if(!ToBe||(MFlag!=Flag&&Flag!=3&&MFlag!=3))
	{
		printf("NO\n");
		exit(0);
	}
	if(RHead!=LHead)
	JudgeAndCompute(MFlag,RHead,REnd);

	JudgeAndCompute(MFlag,LHead,LEnd);

}