#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int N;
	int Num[100],Sequence[100],Container[100];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		Container[i]=100;
	}
	int NInput;
	int Count=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&NInput);
		Num[i]=NInput;
		for(int k=0;k<N;k++)
		{
			if(NInput<=Container[k])
			{
				if(Container[k]==100)
					Count++;
				Sequence[i]=k+1;
				Container[k]-=NInput;
				break;
			}
		}

	}
	for(int i=0;i<N;i++)
	{
	printf("%d %d\n",Num[i],Sequence[i]);
	}
	printf("%d\n",Count);
	system("pause");
	return 0;

}