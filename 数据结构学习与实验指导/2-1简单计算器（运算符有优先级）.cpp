#include<stdio.h>
int main()
{
	int result,input1,temp;
	int ncount=-1;
	int ocount=-1;
	int num[100];
	char oper[100];
	for(int i=0;i<100;i++)
	{
		num[i]=0;
		oper[i]=NULL;
	}
	char deal;
	scanf("%d%c",&input1,&deal);
	temp=input1;
	while(deal!='=')
	{
		scanf("%d",&input1);
		switch(deal){
		case'+':
			num[ncount+1]=temp;
			oper[ocount+1]=deal;
			temp=input1;
			ocount++;
			ncount++;
			break;
		case'-':
			num[ncount+1]=temp;
			oper[ocount+1]=deal;
			temp=input1;
			ocount++;
			ncount++;;
			break;
		case'*':
			temp*=input1;
			break;
		case'/':
			if(input1==0)
			{
				printf("除法分母不能为零！");
				return 0;
			}
			temp/=input1;
			break;
		default:
			printf("非运算符，不允许！");
			return 0;
		}
		scanf("%c",&deal);
	}
	num[ncount+1]=temp;
	result=num[0];
	for(int i=0;i<=ocount;i++)
	{
		switch(oper[i]){
		case'+':
			result+=num[i+1];
			break;
		case'-':
			result-=num[i+1];
			break;
		}
	}
	printf("%d\n",result);
	return 0;
}